/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean/boolean.h"
#include "mesinkarakter.h"

#define CAPACITY 50
#define BLANK ' '


typedef struct
{
   char contents[CAPACITY]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;
void startWord();
void advWord();
void copyWord();
void ignoreBlankF();
void startWordFile();
void advWordFile();
void copyWordFile();
Word takeWord(Word word);
boolean isWordString(Word word, char string[]);
int takeNum(Word word);
void takeString(Word word, char string[]);
void stringCat(char string1[], char string2[]);
int stringLen(char string[]);
void readStdLineString(char placeholder[50]);
void readStdLineInt(int * placeholder);
#endif