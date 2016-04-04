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

// instantiate board objects
DBControl boardController();
// DB1 board1();
// DB2 board2();
// DB3 board3();
// DB4 board4();
DB5 board5();
// DB6 board6();
// DB7 board7();

// number of the daughterboard that's currently attached
int boardNum = 0; // 0 signifies no board attached

// setup runs once when Arduino is powered on
void setup() {
  Serial.begin(9600);  

  // Determine which board is plugged in
  boardController.readreadBoardID();
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
  else if (boardID == "Board_ID,00000100") {
    board4.configurePins();
  }
  */
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
  boardController.Serial_Control();

  /*if (boardNum == 1) {
    board1.execute();
  }
  else if (boardNum == 2) {
    board2.execute();
  }
  else if (boardNum == 3) {
    board3.execute();
  }
  else if (boardNum == 4) {
    board4.execute();
  }
  */
  else if (boardNum == 5) {
    board5.execute();
  }
  /*
  if (boardNumardID == 6) {
    board6.execute();
  }
  if (boardNum == 6) {
    board7.execute();
  }
  */
  else {
    Serial.println("Frror recognizing board."); // MAY HAVE TO CHANGE THIS LINE LATER
  }
  
  boardController.Safety_Check();   
}


