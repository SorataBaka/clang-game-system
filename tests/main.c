#include "../src/game_handler.h"
#include "../lib/array_dynamic/array_dynamic.h"
#include <stdio.h>
#include "../lib/mesin_kata/mesin_kata.h"
ArrayDin games;
int main(){
  InitializeGames(&games);


  
  SelectGame(games);
  DeleteGame(&games);
  DeleteGame(&games);
  ListGame(games);
  CreateGame(&games);
  ListGame(games);
  return 0;

}