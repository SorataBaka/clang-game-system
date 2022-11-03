#include <stdio.h>
#include <stdlib.h>

#include "../lib/array_dynamic/array_dynamic.c"
#include "../lib/boolean/boolean.h"
#include "../lib/mesin_kata/mesinkarakter.h"
#include "../lib/mesin_kata/mesin_kata.h"

#include "game_handler.h"


// GAME LIST, PLEASE REPLACE WITH FINAL GAME FUNCTION IN PRODUCTION
void GameMaintenance(char gameName[50]){
  printf("\nGame %s masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.\n\n", gameName);
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

// FIXED GAMES LIST, PLEASE MOVE TO HEADER FILE WHEN OTHER GAME FILES HAS BEEN RECEIVED.
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
/**
 * Read configuration file and make sure to take into account the amount of games read as well as if its is a deletable game
 * Initialize the first 5 values of the map with all available games. Make sure to set the deletable value of the struct as false
 * 
 * Loop over the rest of the read games and assign it as deletable and add it the maintenance value
 * 
 * @param {ArrayDin *} games POINTER TO Dynamic Array of empty uninitialized games.
 * @returns {void}
*/
void InitializeGames(ArrayDin * games){
  /**
   * Initialize the games array
   * */

  *games = MakeArrayDin();
  startfile("./config.txt");

  char gameLengthLineRead[50];
  readLine(gameLengthLineRead);

  int gameLength = gameLengthLineRead[0] - 48;

  for(int i = 0; i < 5; i++){
    char placeholder[50];
    readLine(placeholder);

    // TAMBAH INI KALO JUMLAH GAMENYA NAMBAH
    for(int j = 0; j < 5; j++){
      if(stringIsMatch(placeholder, fixedGames[j].name)){
        InsertLast(games, fixedGames[j]);
        break;
      }
    }
  }
  
  int customGameLength = gameLength - 5;
  for(int i = 0 ; i < customGameLength; i++){
    ElType newGame =  {
      name: "",
      deletable: true,
      execute: GameMaintenance,
    };
    readLine(newGame.name);
    InsertLast(games, newGame);
  }
}

/**
 * Read input and store in a variable named selectedGames
 * games.value(selectedGames)
 * currentGames.A[selectedGame-1].execute();
 * 
 * @param {ArrayDin} currentGames Currently available Dynamic Array of games which has been initialized and hydrated
 * @returns {void}
*/
void SelectGame(ArrayDin currentGames){
  ListGame(currentGames);
  printf("Masukkan nomor game yang ingin dipilih: ");

  int selectedGame;
  readStdLineInt(&selectedGame);
  
  while(selectedGame < 1 || selectedGame > Length(currentGames)){
    printf("Mohon masukkan angka yang benar.\n");
    printf("Masukkan nomor game yang ingin dipilih: ");
    readStdLineInt(&selectedGame);
  }
  currentGames.A[selectedGame-1].execute();
}

/**
 * Read input and store in a variable named deleteGame
 * Check if the game is deletable by checking the deletable property
 * if not deletable, fail delete game
 * DeleteAt(currentGames, deleteGame);
 * 
 * @param {ArrayDin *} currentGames POINTER TO Currently available Dynamic Array of games which has been initialized and hydrated.
 * @returns {void}
 * 
*/
void DeleteGame(ArrayDin * currentGames){
  ListGame(*currentGames);
  printf("Masukkan nomor game yang akan dihapus: ");
  int deleteGame;
  readStdLineInt(&deleteGame);
  deleteGame = deleteGame - 1;
  //Check if its deletable;
  if(deleteGame+1 >= 1 && deleteGame+1 <= Length(*currentGames) && currentGames->A[deleteGame].deletable){
    DeleteAt(currentGames, deleteGame);
    printf("\nGame berhasil dihapus\n");
  }else{
    printf("\nGame gagal dihapus\n");
  }
  return;
}

/**
 * Loop over the games array and print the name property of each value
 * 
 * @param {ArrayDin} currentGames Currently available Dynamic Array of games which has been initialized and hydrated
 * @returns {void}
*/
void ListGame(ArrayDin currentGames){
  printf("Berikut adalah daftar game yang tersedia\n");
  for(int i = 0; i < Length(currentGames); i++){
    printf("   %d. %s\n", i+1, currentGames.A[i].name);
  }
}

/**
 * Create a new struct object with name newGame.
 * Prefill the deletable and execute property.
 * Read user input from stdin and put in newGame.name property
 * 
 * @param {ArrayDin *} currentGames POINTER TO Currently available Dynamic Array of games which has been initialized and hydrated.
 * @returns {void}
*/
void CreateGame(ArrayDin * currentGames){
  printf("Masukkan nama game yang akan ditambahkan: ");
  ElType newGame = {
    name: "",
    deletable: true,
    execute: GameMaintenance,
  };
  readStdLineString(newGame.name);
  InsertLast(currentGames, newGame);
}