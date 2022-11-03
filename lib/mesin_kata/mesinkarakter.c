/* File: charmachine.c */
/* Implementasi Character Engine */

#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean eot;

FILE * tape;
FILE * filetape;
static int retval;

void start(char * filename) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

 /* Algoritma */
 tape = stdin;
 adv();
}

void adv() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
        Jika  currentChar = MARK maka EOP akan menyala (true) */

 /* Algoritma */
 retval = fscanf(tape,"%c",&currentChar);
}

void startfile(char fileloc[]) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

 /* Algoritma */
 filetape = fopen(fileloc, "r");
}

void advfile() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
        Jika  currentChar = MARK maka EOP akan menyala (true) */

 /* Algoritma */
 retval = fscanf(filetape,"%c",&currentChar);
}

void close(){
   fclose(tape);
}

void closeFile(){
   fclose(filetape);
}

void readLine(char placeholder[50]){
   fscanf(filetape, " %[^\n]", placeholder);
}