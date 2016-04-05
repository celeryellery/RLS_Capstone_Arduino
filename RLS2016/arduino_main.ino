/******************************************************************************
  arduino_main.ino
  This is the main Arduino code that calls all libraries
  needed to run the Remote Lab System project for the 
  Universtiy of Washington Bothell. 
  This code is designed to run on an Arduino Mega 2560.
  
  Created by Ellery Walsh, March 2016
  Reseased into the public domain.
******************************************************************************/

// TODO:
// Need to include power regulator stuff from original code but updated for new motherboard
// check pin numbers of arduino mega analog write pins
// check signatures of functions inside all .h files to make sure no const, private, &, etc. are missing
// refactor helper methods in DB5
// create configuration file to turn some functions orange

#include <dbControl.h>
#include <db5.h>
#include <db4.h>

// instantiate board objects
DBControl boardController;
// DB1 board1;
// DB2 board2;
// DB3 board3;
DB4 board4;
DB5 board5;
// DB6 board6;
// DB7 board7;


// setup runs once when Arduino is powered on
void setup() {
  Serial.begin(9600);  

  // Determine which board is plugged in
  boardController.readBoardID();
  String boardID = boardController.stringifyBoardID();

  // Configure pins correctly for the given board
  /*
  if (boardID == "Board_ID,00000001") {
    board1.configurePins();
  }
  else if (boardID == "Board_ID,00000010") {
    board2.configurePins();
  }
  else if (boardID == "Board_ID,00000011") {
    board3.configurePins();
  }
  else*/ if (boardID == "Board_ID,00000100") {
    board4.configurePins();
  }
  
  else if (boardID == "Board_ID,00000101") {
    board5.configurePins();
  }
  /*
  if (boardID == "Board_ID,00000110") {
    board6.configurePins();
  }
  if (boardID == "Board_ID,00000111") {
    board7.configurePins();
  }
  */
  boardController.configureBoardIdPins();
  
  // Need to include power regulator stuff here later, but not now for testing a few boards only
  Serial.println("Finished Setup successfully.");
}

// the loop routine runs over and over again forever
void loop() {
  String outputFromUI = boardController.serialControl();
  String boardIDsubstring = outputFromUI.substring(0,7);

  /*if (boardIDsubstring == "board_1") {
    board1.execute(outputFromUI);
  }
  else if boardIDsubstring == "board_2") {  
    board2.execute(outputFromUI);
  }
  else if (boardIDsubstring == "board_3") {
    board3.execute(outputFromUI);
  }
  else*/ if (boardIDsubstring == "board_4") {
    board4.execute(outputFromUI);
  }
  
  else if (boardIDsubstring == "board_5") {
    board5.execute(outputFromUI);
  }
  /*
  if (boardIDsubstring == "board_6") {
    board6.execute(outputFromUI);
  }
  if (boardIDsubstring == "board_7") {
    board7.execute(outputFromUI);
  }
  */
  else {
    Serial.println("Error recognizing board."); // MAY HAVE TO CHANGE THIS LINE LATER
  }
  
  boardController.safetyCheck();   
}


