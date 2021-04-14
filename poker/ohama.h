#ifndef _OHAMA_H_
#define _OHAMA_H_


#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std; 
#define SUITS 4 
#define FACES 13
#define CARDS 52
#define MAX_TURN 3 
#define POINT_PER_ROUND 1000 
#define POINT_PER_DRAW 200
#define WINNING_POINT 1000 


struct handTracer {
	int add;
	int val;
};
void shuffleCards(int* deck); 
void printCardsShuffling(int deck[], string faces[],string suits[]);
int displayMenu();
int face(int card);
int suit(int card);
bool isFourOfAKind(int* hand, int size);
bool isFullHouse(int* hand, int size);
bool isFlush(int* hand, int size);
bool isStraight(int* hand, int size);
bool isStraightFlush(int* hand, int size);
bool isThreeOfAKind(int* hand, int size);
bool isTwoPairs(int* hand, int size);
bool isPairs(int* hand, int size);
int highestCard(int* hand, int size); 
#endif // !_OHAMA_H_
