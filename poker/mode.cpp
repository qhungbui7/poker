#include"mode.h"
int* dealingForHand(int *deck, int *top, int size) { // a little bit change in parameter for reusing later
	int* hand = new int[size+1];  // get from top 
	for (int i = 0; i < size; i++)
		hand[i] = deck[(*top)++]; 
	top--; 
	return hand; 
}
void printHand(int *hand, int size, string faces[FACES], string suits[SUITS]) { // a little bit change in parameter for reusing later
	cout << "Your hand : "; 
	for (int i = 0; i < size; i++) {
		cout << "(" << faces[face(hand[i])] << "," << suits[suit(hand[i])] << ")    ";
	}
}
void printHandRanking(int* hand, int size) {
	cout <<endl << "Your hand rankings : "; 
	if (isStraightFlush(hand, size)) 
		cout << "Straigt Flush";
	else if (isFourOfAKind(hand, size)) 
		cout << "Four of A Kind";
	else if (isStraightFlush(hand, size))
		cout << "Straigt Flush";
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
	else if (isFlush(hand, size)) 
		cout << "Flush";
	else
		cout << highestCard(hand, size) ; 
	cout << endl;
}
void singlePlayer(int *deck, string faces[FACES], string suits[SUITS]) {
	int top = 0;
	int size = 5; 
	int *hand = dealingForHand(deck, &top, size);
	printHand(hand, size,  suits, faces); 
	printHandRanking(hand, size); 
	delete[] hand; 
}
void multiPlayer(int* deck) {

}
void vsDealer(int* deck) {

}
void humanVsAI(int* deck) {

}