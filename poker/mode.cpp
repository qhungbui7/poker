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
		cout << "(" << faces[hand[i] % 13] << "," << suits[hand[i] / 13] << ")    ";
	}
}
void printHandRanking(int* hand, int size) {
	cout << "Your hand rankings : "; 
	if (isStraightFlush(hand, size)) {
		cout << "Straigt Flush";
		return; 
	}
	if (isFourOfAKind(hand, size)) {
		cout << "Four of A Kind";
		return;
	}
	if (isStraightFlush(hand, size)) {
		cout << "Straigt Flush";
		return;
	}
	if (isFullHouse(hand, size)) {
		cout << "Full House";
		return;
	}
	if (isFlush(hand, size)) {
		cout << "Flush";
		return;
	}
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