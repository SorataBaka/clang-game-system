#include "../src/game_handler.h"
#include "../lib/array_dynamic/array_dynamic.h"
#include <stdio.h>
ArrayDin games;

int main(){
  InitializeGames(&games);
  ElType selectedGame = games.A[1-1];
  printf("Game name is %s\n", selectedGame.name);
  printf("Is this game deletable? %s\n", selectedGame.deletable? "yes" : "no");
  printf("Executing....\n");
  selectedGame.execute();
  return 0;
}