#include <stdio.h>
#include "array_dynamic.c"
#include "boolean.h"
#include <stdlib.h>



//Create map here that stores a key value of pair of a string and a game_value
ArrayDin games;
void game_maintenance(){
  printf("Sorry, this game is currently under maintenance and thus is unavailable to be played.\nPlease try again next time!\n");
  printf("Press any key to continue.\n");
  getchar();
  return;
}
void initialize_games(){
  // Initialize the games map and make sure they are available to take in func_type as their value;
  games = MakeArrayDin();
  

  // Read configuration file and make sure to take into account the amount of games read as well as if its is a deletable game

  for(int i = 0; i < 10; i++){
    ElType newGame;
    newGame.deletable = false;
    printf("Please enter a new name:\n");
    scanf(" %s", &newGame.name);
    newGame.execute = game_maintenance;
    InsertLast(&games, newGame);

  }

  // Initialize the first 5 values of the map with all available games. Make sure to set the deletable value of the struct as false

  // Loop over the rest of the read games and assign it as deletable and add it the maintenance value
}

void select_game(){
  // Read input and store in a variable named game_name.
  // games.value(game_name).execute();
  // This means that we get a game from the games map using the key game_name and immediately execute the game function
}

void delete_game(){
  // Read input and store in a variable name game_name
  // Check if the game is deletable by checking the deletable property
  // If not deletable. then handle error.
  // games.delete(game_name)
  // delete the game from the map.

  // Write intothe configuration file ()

}

void list_game(){
  // Loop over the games map and print the key values as the game names.
}

void create_game(){
  // Read input and store in a variable name game_name
  // insert into game_name and set the value as game_maintenance

}


void test_game1(){
  printf("This is the first game\n");
  return;
}


// TESTS
int main(){
  initialize_games();



  ElType selectedGame = games.A[SearchArrayDin(games, "2")];


  printf("Game name is %s\n", selectedGame.name);
  printf("Is this game deletable? %s\n", selectedGame.deletable? "yes" : "no");
  printf("Executing....\n");
  selectedGame.execute();






  return 0;
}