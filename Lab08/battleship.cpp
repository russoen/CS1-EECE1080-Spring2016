// Author: <fill in your name>
// Source File: battleship.cpp
// Description: Helper functions for the battleship game.
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>

using namespace std;

// Constants representing characters in the arrays
const int BOARD_SIZE = 10;
const char HIT = 'X';
const char MISS = 'o';
const char BOAT = 'B';
const char EMPTY = ' ';


// Creates the boat at position x,y, (0 based) with orientation, and length.  This should
// return true if the boat could be placed (*and change the array*), but if the
// boat could not be placed, either *because a boat is in its path* or the boat goes
// outside the bounds, then return false and be sure NOT to change the array.
// Orientation 0 is horizontal (right), and 1 is vertical (down)
bool createBoat(char boatArray[][BOARD_SIZE],int x, int y, int orientation, int boat_length){
  //FALSE
  if(orientation!=0 && orientation!=1){return false;}
  if((x<0||y<0)||(x>(BOARD_SIZE) || y>(BOARD_SIZE))){return false;}
  if(orientation == 0 && (x+1+boat_length)>BOARD_SIZE){return false;}//boat outside bounds(too far right)
  if(orientation == 1 && (y+1+boat_length)>BOARD_SIZE){return false;}//boat outside bounds(too far down)
  if(orientation == 0){
    for(int l=x;l<=(x+boat_length-1);l++){
      if (boatArray[y][l]==BOAT){return false;}
    }
  }
  if(orientation == 1){
    for(int h=y;h<=(y+boat_length-1);h++){
      if(boatArray[h][x]==BOAT){return false;}
    }
  }

  //TRUE
  if(orientation == 0){//boat oriented to right fits on board 
    for(int l=x;l<=(x+boat_length-1);l++){
      boatArray[y][l]=BOAT;
    }
  }
  if(orientation == 1){//boat oriented downwards fits on board 
    for(int h=y;h<=(y+boat_length-1);h++){
      boatArray[h][x]=BOAT;
    }
  }
  return true;
}




// Places 4 boats on the board randomly.  One of size 5,4,3,2, in any orientation.
// Return true if successful, and false ONLY if there is no way to place boats.
// It is OK to try to place boats for a limited (large) amount of tries and then
// give up.
bool placeAIBoats(char boatArray[][BOARD_SIZE]){
  srand(time(0));
  for(int size=5;size>=2;size--){
    unsigned int f=0;
    while(!(createBoat(boatArray,rand()%BOARD_SIZE, rand()%BOARD_SIZE,rand()%2,size))){
      f++;
      if(f>=1000){return false;}
    }
  }
  return true;
}


// Returns true if no more boats (BOAT characters) exist on the board.
bool hasLost(char boatArray[][BOARD_SIZE]){
  for(int r=0;r<BOARD_SIZE;r++){
    for(int c=0;c<BOARD_SIZE;c++){
      if(boatArray[r][c]==BOAT){return false;}
    }
  }
  return true;   // if no boat is found, someone has lost!
}

// Returns true if a boat was hit in that spot for the first time.  
// If x or y are outside the bounds of the board, return false.  
// If that x,y was previously chosen (either a hit or a miss) or no boat is there, return false.  
// This should change the array if a hit was done, or a miss on a un-missed spot.
// Note to use HIT, MISS, and BOAT char constants in the array.
// It is OK to cout a message to the user, but not required.
bool isHit(char boatArray[][BOARD_SIZE],int x, int y){
  if(x>BOARD_SIZE || x<0 || y>BOARD_SIZE || y<0){return false;}
  if(boatArray[y][x]==HIT||boatArray[y][x]==MISS){return false;}
  
  if(boatArray[y][x]!=BOAT){
    boatArray[y][x]=MISS;
    return false;
  }
  else if(boatArray[y][x]==BOAT){
    boatArray[y][x]=HIT;
    return true;
  }
  return true;
}



