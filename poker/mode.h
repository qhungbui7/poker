#ifndef _MODE_H_
#define _MODE_H_
#include"ohama.h"
#include"additionalFunction.h"
void singlePlayer(int *deck, string faces[FACES], string suits[SUITS]);
void multiPlayer(int* deck, string faces[FACES], string suits[SUITS]);
void vsDealer(int* deck);
void humanVsAI(int *deck);
#endif 
