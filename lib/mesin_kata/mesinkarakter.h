/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_



#include "../boolean/boolean.h"

#define MARK '.'
/* State Mesin */
extern char currentChar;
extern boolean EOP;
void start();
void adv();
void startfile();
void advfile();
void close();
void closeFile();
void readLine(char placeholder[50]);


#endif