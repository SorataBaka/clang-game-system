#ifndef _GAME_HANDLER_
#define _GAME_HANDLER_
#include "../lib/array_dynamic/array_dynamic.h"
#define InitialSize 10

typedef int IdxType;
typedef void (*func_type)(void);
typedef struct {
  char name[50];
  boolean deletable;
  func_type execute;
} GameValue;
typedef GameValue ElType;
typedef struct {
    ElType *A;
    int Capacity;
    int Neff;
} ArrayDin;

void InitializeGames(ArrayDin * games);
void SelectGame();
void DeleteGame();
void ListGame();
void CreateGame();
#endif
