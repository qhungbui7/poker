#ifndef _MODE_H_
#define _MODE_H_
#include"ohama.h"
#include"additionalFunction.h"
#include"bot.h"
void singlePlayer(int *deck, string faces[FACES], string suits[SUITS]);
void multiPlayer(int* deck, string faces[FACES], string suits[SUITS]);
void dealerSimulation(int* deck, string faces[FACES], string suits[SUITS]); 
void vsDealer(int* deck);
int** dealingForHands(int* deck, int n, int& top, int size);
int getStatusOfHand(int* hand, int size); 
void outHandRanking(string name, int status); 
void printHand(int* hand, int size, string faces[FACES], string suits[SUITS]);
void experiment(int* deck); 
#endif 
