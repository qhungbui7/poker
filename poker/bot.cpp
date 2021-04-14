#include"bot.h"
int drawMoreForPlayer(int* hand, int* deck, int& top, int size, int &points) {
	int cmd, turnp = 3, stt = getStatusOfHand(hand, size);
	printHand(hand, size, faces, suits);
	outHandRanking("Player", stt);
	while (turnp > 0) {
		cout << "\nWanna draw one more, don't you ? ( 0 for no, 1 for yes, " << turnp << " left) \n>> ";
		cin >> cmd;
		if (!cmd) break;
		turnp--;
		hand[size++] = deck[top++];
		points -= POINT_PER_DRAW; 
		printHand(hand, size, faces, suits);
		stt = getStatusOfHand(hand, size);
		outHandRanking("Player", stt);
	}
	return stt; 
}

void bot(int* deck, int s, int level) {
	int top = 0; 
	int size = 5, pointsP = s * POINT_PER_ROUND, pointsS = s * POINT_PER_ROUND;
	// hand[0][i] : player
	// hand[1][i] : bot
	for (int i = 0; i < s; i++) {
		cout <<endl <<"------------------------------------------------------------------" <<endl; 
		cout << "ROUND " << i+1 << endl; 
		shuffleCards(deck);
		// printCardsShuffling(deck, faces, suits); 
		int** hand = dealingForHands(deck, 2, top, 5);
		int sttP = drawMoreForPlayer(hand[0], deck, top, size, pointsP);
		int sttB = 0 ;
		if (level == 1 )
			sttB = drawMoreForDummyBot(hand[1], deck, top, size, pointsS);
		else if (level == 2)
			sttB = drawMoreForInsaneBot(hand[1], deck, top, size, pointsS);
		else if (level == 3)
			sttB = drawMoreForTuring(hand[1], deck, top, size, pointsS); 
		if (sttP > sttB){
			pointsP += WINNING_POINT; 
		}
		else if (sttP < sttB) {
			pointsS += WINNING_POINT; 
		}
		else {
			pointsP += WINNING_POINT / 2;
			pointsS += WINNING_POINT / 2; 
		}
		cout << "\nBy now Player has " << pointsP <<" points and Dealer has "<< pointsS <<" points\n";
		system("pause");
	}
	if (pointsP > pointsS) cout << "Player win with " << pointsP << " points " << endl;
	else if (pointsP < pointsS)cout << "Dealer win with " << pointsS << " points " << endl;
	else cout << "Draw match, Player and Dealer have same points - " << pointsP << " points " << endl; 
}
int drawMoreForDummyBot(int* hand, int* deck, int& top, int size, int& points) {
	int d = getStatusOfHand(hand, size), turnd = rand() % 4, num;
	cout << "\n-----------------\nDealer :";
	printHand(hand, size, faces, suits);
	outHandRanking("Dealer", getStatusOfHand(hand, size));
	points -= POINT_PER_DRAW * turnd;
	for (int i = 0; i < turnd; i++) {
		num = rand() % size;
		hand[num] = deck[top++];
	}
	cout << endl << "Dealer draws " << turnd << " cards and gets new hand : ";
	printHand(hand, size, faces, suits);
	int stt = getStatusOfHand(hand, size);
	outHandRanking("Dealer", stt);

	return stt;
}
int drawMoreForInsaneBot(int* hand, int* deck, int& top, int size, int& points) {
	int d = getStatusOfHand(hand, size), turnd = 3, num;
	cout << "\nDealer : \n";
	printHand(hand, size, faces, suits);
	outHandRanking("Dealer", getStatusOfHand(hand, size));
	for (int i = 0; i < turnd; i++) {
		hand[size++] = deck[top++];
	}
	cout << endl << "Dealer draws " << turnd << " cards and gets new hand : ";
	printHand(hand, size, faces, suits);
	int stt = getStatusOfHand(hand, size);
	outHandRanking("Dealer", stt);

	return stt;
}
int drawMoreForTuring(int* hand, int* deck, int& top, int size, int& points) {
	int d = getStatusOfHand(hand, size), turnd = 3, num;
	cout << "\nDealer : \n";
	printHand(hand, size, faces, suits);
	outHandRanking("Dealer", getStatusOfHand(hand, size));
	for (int i = 0; i < turnd; i++) {
		hand[size++] = deck[top++];
	}
	cout << endl << "Dealer draws " << turnd << " cards and gets new hand : ";
	printHand(hand, size, faces, suits);
	int stt = getStatusOfHand(hand, size);
	outHandRanking("Dealer", stt);

	return stt;
}