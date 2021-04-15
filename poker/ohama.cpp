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
	cout << "Welcome to Miracle Generation of Poker" << endl;
	cout << "Select mode" << endl;
	cout << "1. Singleplayer" << endl;
	cout << "2. Multiplayer" << endl;
	cout << "3. \"Dealer simulation\" mode" << endl; 
	cout << "4. Player vs Dealer" << endl;
	cout << "5. Player vs AI " << endl;
	cout << "0 : Leave " << endl;
	cout << "Your choice : \n>> ";
	cin >> mode;
	system("cls"); 
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
int *createHandTest(int *deck, int *a) {
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
bool isStraightFlush(int* hand, int size) { 
	int straightSize = 5;
	for (int i = 0; i < size - straightSize + 1; i++)
		if (isStraight(hand + i, straightSize) && isFlush(hand + i, straightSize))
			return true; 
	return false; 
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