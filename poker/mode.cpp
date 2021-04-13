#include"mode.h"
int* dealingForHand(int *deck, int *top, int size) { // a little bit change in parameter for reusing later
	int* hand = new int[size+1];  // get from top 
	for (int i = 0; i < size; i++)
		hand[i] = deck[(*top)++]; 
	top--; 
	return hand; 
}
void printHand(int *hand, int size, string faces[FACES], string suits[SUITS]) { // a little bit change in parameter for reusing later
	cout << endl << "Hand : "; 
	for (int i = 0; i < size; i++) {
		cout << "(" << faces[face(hand[i])] << "," << suits[suit(hand[i])] << ")    ";
	}
	cout << endl;
}
void printHandRanking(int* hand, int size) {
	cout <<endl << "Your hand rankings : "; 
	if (isStraightFlush(hand, size)) 
		cout << "Straigt Flush";
	else if (isFourOfAKind(hand, size)) 
		cout << "Four of A Kind";
	else if (isFullHouse(hand, size)) 
		cout << "Full House";
	else if (isFlush(hand, size)) 
		cout << "Flush";
	else if (isStraight(hand, size)) 
		cout << "Straight";
	else if (isThreeOfAKind(hand, size)) 
		cout << "Three of A Kind";
	else if (isTwoPairs(hand, size)) 
		cout << "Two Pairs";
	else if (isPairs(hand, size)) 
		cout << "Pair";
	else
		cout << highestCard(hand, size) ; 
	cout << endl;
}
void singlePlayer(int *deck, string faces[FACES], string suits[SUITS]) {
	shuffleCards(deck);
	printCardsShuffling(deck, faces , suits);
	int top = 0;
	int size = 5; 
	int *hand = dealingForHand(deck, &top, size);
	printHand(hand, size,  faces, suits); 
	printHandRanking(hand, size); 
	delete[] hand; 
}
int** dealingForHand(int *deck, int n, int &top,int size){
	int** hands = new int* [n];
	for (int i = 0; i < n; i++) {
		hands[i] = new int[5];
	}
	for (int i = 0 ; i < n ; i++)
		for (int j = 0; j < 5; j++) {
			hands[i][j] = deck[j * n + i]; 
		}
	return hands;
}
int getStatusOfHand(int *hand, int size) {
	int status = 0; 
	if (isStraightFlush(hand, size))
		status = 8;
	else if (isFourOfAKind(hand, size))
		status = 7;
	else if (isFullHouse(hand, size))
		status = 6;
	else if (isFlush(hand, size))
		status = 5;
	else if (isStraight(hand, size))
		status = 4;
	else if (isThreeOfAKind(hand, size))
		status = 3;
	else if (isTwoPairs(hand, size))
		status = 2;
	else if (isPairs(hand, size))
		status = 1;
	else
		status = 0;
		//cout << highestCard(hand, size);
	// cout << endl;
	return status; 
}
handTracer* rankingHands(int** hands, int n, string faces[FACES], string suits[SUITS]) {
	int *point = new int[n]; 
	handTracer *tracer = new handTracer[n]; 
	for (int i = 0; i < n; i++) {
		tracer[i].val = getStatusOfHand(hands[i], 5);
		tracer[i].add = i; 
	}
	for (int i = 0; i < n; i++) {
		cout << "Player " <<i<<" : "; 
		printHand(hands[i], 5, faces, suits);
		cout << endl;
	}
	heapSort(tracer, n); 
	return tracer; 
}
void multiPlayer(int* deck, string faces[FACES], string suits[SUITS]) {
	int n, s, top = 0, size = 5;
	cout << "Enter number of players ( 5 players is maximum since number of cards is limit) :  "; 
	cin >> n; 
	cout << "Enter number of rounds you want to play  : ";
	cin >> s;
	int* point = new int[n];
	for (int i = 0; i < n; i++)
		point[i] = 0; 
	for (int k = 0; k < s; k++) {
		cout << "-------------------------------------------------------------------------------------" << endl; 
		cout << "ROUND " << k + 1 <<endl <<endl  ; 
		shuffleCards(deck);
		// printCardsShuffling(deck, faces, suits);
		int** hands = dealingForHand(deck, n, top, size);
		handTracer* rank = rankingHands(hands, n, faces, suits);
		/*for (int i = 0; i < n; i++) {
			point[rank[i].add] += (rank[i].val == rank[i-1].val) ? point[rank[i-1].add] : (n - i) ;
		}*/
		cout << "Rankings of round " << k + 1 << " : " <<endl <<endl;
		for (int i = 0; i < n; i++) {
			int points = (rank[i].val == rank[i - 1].val) ? rank[i - 1].val : (n - i); 
			point[rank[i].add] += points; 
			cout <<"Player " << rank[i].add <<" gets "<< points <<" points"<<endl ;
		}
		for (int i = 0; i < n; i++)
			delete[] hands[i];
		delete[] hands;
	}
	int winner = 0; 
	int maxScore = 0; 
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "Scoreboard of the matchs : " << endl; 
	for (int i = 0; i < n; i++) {
		cout << "Player " << i << " : " << point[i] << endl;
		if (point[i] > maxScore) {
			maxScore = point[i]; 
			winner = i; 
		}
	}
	cout << "The winner is Player" << winner << " with " << maxScore << " points" << endl;
	delete[] point; 
}

void vsDealer(int* deck) {

}
void humanVsAI(int* deck) {

}