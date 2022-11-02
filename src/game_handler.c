#include <stdio.h>
#include <stdlib.h>
#include "../lib/array_dynamic/array_dynamic.c"
#include "../lib/boolean/boolean.h"
#include "../lib/string_match/string_match.h"
#include "game_handler.h"
// Game list, please replace with final game function in production
void GameMaintenance(){
  printf("Sorry, this game is currently under maintenance and thus is unavailable to be played.\nPlease try again next time!\n");
  printf("Press any key to continue.\n");
  getchar();
  return;
}
void RNG(){
  printf("This is the rng game\n");
}
void DinerDash(){
  printf("This is the diner dash game\n");
}
void DinosaurInEarth(){
  printf("This is the dinosaur in earth game\n");
}
void RiseWoman(){
  printf("This is the risewoman game\n");
}
void EiffelTower(){
  printf("This is the eiffel tower game\n");
}
ElType fixedGames[] = {
  {
    name: "RNG",
    deletable: false,
    execute: RNG,
  }, {
    name: "Diner DASH",
    deletable: false,
    execute: DinerDash,
  }, {
    name: "DINOSAUR IN EARTH",
    deletable: false,
    execute: DinosaurInEarth,
  }, {
    name: "RISEWOMAN",
    deletable: false,
    execute: RiseWoman,
  }, {
    name: "EIFFEL TOWER",
    deletable: false,
    execute: EiffelTower,
  }
};
void InitializeGames(ArrayDin * games){
  // Initialize the games map and make sure they are available to take in func_type as their value;
  *games = MakeArrayDin();
  FILE * ptr;
  ptr = fopen("./config.txt", "r");
  if (ptr == NULL) {
    printf("no such file.\n");
    return;
  }

  // Read configuration file and make sure to take into account the amount of games read as well as if its is a deletable game
  // Initialize the first 5 values of the map with all available games. Make sure to set the deletable value of the struct as false
  int gameLength;
  fscanf(ptr, "%d", &gameLength);
  for(int i = 0; i < gameLength; i++){
    char gameName[20];
    fscanf(ptr, " %[^\n]", gameName);
    for(int j = 0; j < 5; j++){
      if(MatchString(gameName, fixedGames[j].name)){
        InsertLast(games, fixedGames[j]);
        break;
      }
    }
  }
  // Loop over the rest of the read games and assign it as deletable and add it the maintenance value
  int customGameLength;
  fscanf(ptr, "%d", &customGameLength);
  for(int i = 0 ; i < customGameLength; i++){
    ElType newGame =  {
      name: "",
      deletable: true,
      execute: GameMaintenance,
    };
    fscanf(ptr, " %[^\n]", newGame.name);
    InsertLast(games, newGame);
  }
}

void SelectGame(ArrayDin currentGames){
  // Read input and store in a variable named game_name.
  // games.value(game_name).execute();
  // This means that we get a game from the games map using the key game_name and immediately execute the game function
  ListGame(currentGames);
  printf("Masukkan nomor game yang ingin dipilih: ");
  int selectedGame;
  scanf("%d", &selectedGame);
  if(selectedGame < 1 || selectedGame > Length(currentGames)){
    printf("Mohon masukkan angka yang benar.\n");
    SelectGame(currentGames);
  }else{
    currentGames.A[selectedGame-1].execute();
  }
}

void DeleteGame(){
  // Read input and store in a variable name game_name
  // Check if the game is deletable by checking the deletable property
  // If not deletable. then handle error.
  // games.delete(game_name)
  // delete the game from the map.

  // Write intothe configuration file ()

}

void ListGame(ArrayDin currentGames){
  // Loop over the games map and print the key values as the game names.
  printf("Berikut adalah daftar game yang tersedia\n");
  for(int i = 0; i < Length(currentGames); i++){
    printf("   %d. %s\n", i+1, currentGames.A[i].name);
  }
}

void CreateGame(){
  // Read input and store in a variable name game_name
  // insert into game_name and set the value as game_maintenance

}