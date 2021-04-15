#ifndef _BOT_H_
#define _BOT_H_
#include"ohama.h"
#include"mode.h"
#include"additionalFunction.h"
#include"utilities.h"
void bot(int* deck, int s, int level); 
int drawMoreForDummyBot(int* hand, int* deck, int& top, int size, int& points); 
int drawMoreForInsaneBot(int* hand, int* deck, int& top, int size, int& points); 
int drawMoreForAgressiveBot(int* hand, int* deck, int& top, int size, int& points);
int drawMoreForTuring(int* hand, int* deck, int& top, int size, int& points); 
#endif // !_BOT_H_
