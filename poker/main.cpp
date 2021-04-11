#include"ohama.h"
#include"mode.h"
int main() {
	srand(time(NULL)); 
	int deck[CARDS]; 
	string suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" }; 
	string faces[FACES] = { "2", "3", "4", "5" ,"6" , "7" ,"8", "9", "10", "J", "Q", "K", "A" }; 
	int mode = 1; 
	while (mode) {
		shuffleCards(deck);
		printCardsShuffling(deck, suits, faces);
		mode = displayMenu();
		if (mode == 1) {
			singlePlayer(deck,suits,faces); 
		}
		else if (mode == 2) {
			multiPlayer(deck); 
		}
		else if (mode == 3) {
			vsDealer(deck) ; 
		} 
		else if (mode == 4) {
			humanVsAI(deck) ; 
		}
		cout << endl << endl; 
	}
	return 0; 
}