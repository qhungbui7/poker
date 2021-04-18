#include"ohama.h"
#include"mode.h"
#include"main.h"

int main() {
	srand(time(NULL)); 
	int* deck = new int[CARDS]; 
	string faces[FACES] = { "2", "3", "4", "5" ,"6" , "7" ,"8", "9", "10", "J", "Q", "K", "A" };
	string suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	int mode = 1; 
	while (mode) {
		mode = displayMenu();
		if (mode == 1) {
			singlePlayer(deck,  faces, suits);
		}
		else if (mode == 2) {
			multiPlayer(deck,  faces, suits);
		}
		else if (mode == 3) {
			dealerSimulation(deck, faces, suits); 
		}
		else if (mode == 4) {
			vsDealer(deck) ; 
		} 
		else if (mode == 5) {
			experiment(deck); 
		}
		cout << endl << endl; 
	}
	delete[] deck;
	return 0; 
}