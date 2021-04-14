#include"mode.h"
int* dealingForHand(int *deck, int *top, int size) { // a little bit change in parameter for reusing later
	int* hand = new int[size+3];  // get from top 
	for (int i = 0; i < size; i++)
		hand[i] = deck[(*top)++]; 
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
int** dealingForHands(int *deck, int n, int &top,int size){
	int** hands = new int* [n];
	for (int i = 0; i < n; i++) {
		hands[i] = new int[5];
	}
	for (int i = 0 ; i < n ; i++)
		for (int j = 0; j < 5; j++) {
			hands[i][j] = deck[j * n + i]; 
		}
	top = n * 5;
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
void outHandRanking(string name, int status) {
	cout << name << " has "; 
	if (status == 8) {
		cout << "Straight Flush"; 
	}
	else if (status == 7) {
		cout << "Four of a kind"; 
	}
	else if (status == 6) {
		cout << "Full House"; 
	}
	else if (status == 5) {
		cout << "Flush"; 
	}
	else if (status == 4) {
		cout << "Straight"; 
	}
	else if (status == 3) {
		cout << "Three of a kind";
	}
	else if (status == 2) {
		cout << "Two pair"; 
	}
	else if (status == 1) {
		cout << "Pair"; 
	}
	else if (status == 0) {
		cout << "High card"; 
	}
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
int *evaluateHand(int s, handTracer **rank, int n) {
	int* point = new int[n];
	for (int i = 0; i < n; i++) 
		point[i] = 0; 
	for (int k = 0; k < s; k++) {
		int points = n; 
		point[rank[k][0].add] += points;
		for (int i = 1; i < n; i++) {
			points = (rank[k][i].val == rank[k][i - 1].val) ? points : (n - i);
			point[rank[k][i].add] += points;
		}
	}
	int maxScore = 0;
	int cnt = 0; 
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "Scoreboard of the matchs : " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Player " << i << " : " << point[i] << endl;
		if (point[i] > maxScore)
			maxScore = point[i]; 
	}
	cout << "Congratulations"; 
	for (int i = 0; i < n; i++)
		if (point[i] == maxScore)
			cout << " Player " << i; 
	cout << " with " << maxScore << " points" << endl;
	return point; 
}
void multiPlayer(int* deck, string faces[FACES], string suits[SUITS]) {
	int n, s, top = 0, size = 5;
	handTracer** rank = new handTracer * [size]; 
	cout << "Enter number of players ( 5 players is maximum since number of cards is limit) : \n>> "; 
	cin >> n; 
	cout << "Enter number of rounds you want to play  : \n>> "; 
	cin >> s;

	for (int k = 0; k < s; k++) {
		cout << "-------------------------------------------------------------------------------------" << endl; 
		cout << "ROUND " << k + 1 <<endl <<endl  ; 
		shuffleCards(deck);
		// printCardsShuffling(deck, faces, suits);
		int** hands = dealingForHands(deck, n, top, size);
		int points = n;
		rank[k] = rankingHands(hands, n, faces, suits);
		cout << "Rankings of round " << k + 1 << " : " <<endl <<endl;
		for (int i = 0; i < n; i++){
			if (i == 0) {
				cout << "Player " << rank[k][i].add << " gets " << points << " points" << endl;
				continue;
			}
			points = (rank[k][i].val == rank[k][i - 1].val) ? points : (n - i);
			cout <<"Player " << rank[k][i].add <<" gets "<< points  <<" points"<<endl ;
		}
		for (int i = 0; i < n; i++)
			delete[] hands[i];
		delete[] hands;
	}
	int *point = evaluateHand(s, rank, n);
	delete[] point; 
}
void dealerSimulation(int* deck, string faces[FACES], string suits[SUITS]) {
	shuffleCards(deck);
	// printCardsShuffling(deck, faces, suits);
	int top = 0, cmd = 1;
	int size = 5, turn = MAX_TURN;
	int* hand = dealingForHand(deck, &top, size);
	printHand(hand, size, faces, suits);
	printHandRanking(hand, size);
	while (turn > 0) {
		cout << "Wanna draw one more, don't you ? ( 0 for no, 1 for yes, " <<turn <<" left) \n >> ";
		cin >> cmd;
		if (!cmd) break; 
		turn--;
		hand[size++] = deck[top++];
		printHand(hand, size, faces, suits);
		printHandRanking(hand, size);
	}
	delete[] hand;
}
void vsDealer(int* deck) {
	int s, level, top = 0; 
	cout << "How many rounds do you want to play ? \n>> ";
	cin >> s;
	int dealerPoint = s * POINT_PER_ROUND, playerPoint = s * POINT_PER_ROUND;
	cout << "In this mode, dealer and you start with " << playerPoint << " points" <<endl;
	cout << "You and dealer can draw more 0 - 3 cards, for each card is drawed, the owner of it lose 200 points \n";
	cout << "Dummy bot will randomly draw 0 - 3 cards and replace with random card in it's hand\n"; 
	cout << "Insane bot will draw 3 cards without losing points and choose the best rank\n";
	cout << "Agressive bot will deliberately daw 0 - 3 cards with statistic and probability analysis then will be trained by machine learning algorithm \n";
	cout << "Agressive bot's name is Turing, He is trained by Neural Network - implemented from scratch - and some optimization method.\n"; 
	cout << "Turing can extract information from your hand so you should draw card carefully :) \n";
	cout << "Choose level \n 1 : Dummy bot \n 2 : Insane bot \n 3 : Agressive bot\n>> ";
	cin >> level; 
	if (level == 1) {
		dummyBot(deck, s); 
	}
	else if (level == 2) {
		insaneBot(deck, s); 
	}
	else {
		turing(deck, s);
	}
}