#include"ohama.h"
int face(int card) {
	return card / 4; 
}
int suit(int card) {
	return card % 4; 
}
int displayMenu() {
	int mode;
	system("color 0B");
	system("cls"); 
	do {
		cout << "Welcome to Miracle Generation of Poker" << endl;
		cout << "Select mode (Type 0 - 5 )" << endl;
		cout << "1. Singleplayer" << endl;
		cout << "2. Multiplayer" << endl;
		cout << "3. \"Dealer simulation\" mode" << endl;
		cout << "4. Player vs Dealer" << endl;
		cout << "5. Experimental functions\n";
		cout << "0 : Leave " << endl;
		cout << "Your choice : \n>> ";
		cin >> mode;
		system("cls");
	} while (mode > 5 || mode < 0); 
	return mode;
}
void shuffleCards(int* deck) {
	bool* check = new bool[CARDS];
	for (int i = 0; i < CARDS; i++)
		check[i] = true;
	for (int i = 0; i < CARDS; i++) {
		int num;
		do {
			num = rand() % CARDS;
		} while (!check[num]); 
		deck[i] = num;
		check[num] = false; 
	}
	delete[] check;
}
void printCardsShuffling(int deck[], string faces[] , string suits[]) {
	cout << "Deck :"; 
	for (int i = 0; i < CARDS; i++) {
		if (i % 4 == 0) {
			cout << endl;
		}
		cout << "(" << faces[face(deck[i])] << "," << suits[suit(deck[i])] << ")\t";
	}
}
int *createHandTest(int *deck, int a[],string faces[], string suits[]) {
	for (int i = 0; i < 5; i++) {
		string fac, sui;
		int fa, su; 
		cout << "Type faces for the card number " << i + 1 <<" (type 2..10, J, Q, K, A ) :\n>> ";
		cin >> fac; 
		for (int j = 0; j < FACES; j++)
			if (fac == faces[j])
				fa = j; 
		cout << "Type faces for the card number " << i + 1 << " (type H for Hearts, D for Diamonds, C for Clubs, S for Spades) :\n>> ";
		cin >> sui; 
		if (sui == "H")
			su = 0;
		else if (sui == "D")
			su = 1;
		else if (sui == "C")
			su = 2;
		else if (sui == "S")
			su = 3; 
		a[i] = fa * SUITS + su; 
	}
	return a;
}
bool isFourOfAKind(int* hand, int size) {
	int faceCount[FACES];
	for (int i = 0; i < FACES; i++) {
		faceCount[i] = 0; 
	}
	for (int i = 0; i < size; i++) {
		int faceCard = face(hand[i]);  
		if (++faceCount[faceCard] == 4)
			return true; 
	}
	return false; 
}
bool isFullHouse(int* hand, int size) {
	int faceCount[FACES];
	for (int i = 0; i < FACES; i++) 
		faceCount[i] = 0;
	bool pair = false, toak = false;
	for (int i = 0; i < size; i++)
		faceCount[face(hand[i])]++; 
	for (int i = 0; i < FACES; i++) {
		if (faceCount[i] == 2)
			pair = true;
		if (faceCount[i] == 3)
			toak = true; 
	}
	return (pair && toak); 
}
bool isFlush(int* hand, int size) {
	int suitCount[SUITS]; 
	for (int i = 0; i < SUITS; i++)
		suitCount[i] = 0 ;
	for (int i = 0; i < size; i++)
		if (++suitCount[suit(hand[i])] == 5)
			return true; 
	return false; 
}
bool isStraight(int* hand, int size) {
	int faceCount[FACES];
	for (int i = 0; i < FACES; i++) {
		faceCount[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		faceCount[face(hand[i])]++;
	}
	int cnt = 0; 
	for (int i = 0; i < FACES; i++) {
		if (faceCount[i] == 0) 
			cnt = 0;
		else cnt++; 
		if (cnt == 5) 
			return true; 
	}
	return false; 
}
void save(int& cnt, int size, int* per, int** sav) {
	for (int i = 0; i < size; i++) {
		//cout << cnt << " " <<i <<"\t";
		sav[cnt-1][i] = per[i];
	}
	//cout << endl; 
}
void backTracking(int* per, int **sav,  int* hand, bool *check, int k, int size, int &cnt) {
	for (int i = 0 ; i < size ; i++)
		if (check[i]) {
			check[i] = false; 
			per[k++] = hand[i];
			if (k == size) save(++cnt,size, per,sav) ; else backTracking(per, sav, hand, check, k, size, cnt);
			check[i] = true; 
			k--; 
		}
}
int factory(int a) {
	int mul = 1; 
	for (int i = 2; i <= a; i++)
		mul *= i;
	return mul; 
}
bool isStraightFlush(int* hand, int size) { 
	int straightSize = 5, cnt = 0, fac = 1, per[5] ;
	int numPermutation = factory(size) / factory(size - straightSize); 
	int maxPermutation = factory(straightSize + 3) / factory((straightSize + 3) - straightSize);
	bool check[5], res = false ;
	for (int i = 0; i < 5; i++)
		check[i] = true;
	int **sav = new int*[maxPermutation];
	for (int i = 0; i < maxPermutation; i++)
		sav[i] = new int[straightSize + 3]; 
	backTracking(per, sav, hand, check, 0, 5, cnt);
	for (int i = 0; i < cnt; i++) {
			if (isStraight(sav[i], straightSize) && isFlush(sav[i], straightSize))
				res =  true;
	}


	return res; 

	
	//for (int i = 0; i < size - straightSize + 1; i++)
	//	if (isStraight(hand + i, straightSize) && isFlush(hand + i, straightSize))
	//		return true; 
	
}
bool isThreeOfAKind(int* hand, int size) {
	int faceCount[FACES];
	for (int i = 0; i < FACES; i++) {
		faceCount[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		int faceCard = face(hand[i]);
		if (++faceCount[faceCard] == 3)
			return true;
	}
	return false;
}
bool isTwoPairs(int* hand, int size) {
	int faceCount[FACES];
	for (int i = 0; i < FACES; i++) {
		faceCount[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		int faceCard = face(hand[i]);
		++faceCount[faceCard]; 
	}
	int count = 0; 
	for (int i = 0; i < FACES; i++) {
		if (faceCount[i] >= 2)
			count++; 
	}
	return count >= 2;
}
bool isPairs(int* hand, int size) {
	int faceCount[FACES];
	for (int i = 0; i < FACES; i++) {
		faceCount[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		int faceCard = face(hand[i]);
		if (++faceCount[faceCard] == 2)
			return true; 
	}
	return false; 
}
int highestCard(int* hand, int size) {
	int maxx = 1; 
	for (int i = 0; i < size; i++) {
		maxx = (face(hand[i]) > maxx) ? face(hand[i]) : maxx; 
	}
	return maxx + 1;
}