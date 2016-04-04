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
// Change structure of Serial_Control function in dbControl so it returns a string that gets parsed outside
// figure out what temp variable means and rename it
// create case statement inside Main instead of in dbContol
// check signatures of functions inside all .h files to make sure no const, private, &, etc. are missing

#include <dbControl.h>
#include <db5.h>

DBControl boardController();
DB5 board5();

void setup() {
  Serial.begin(9600);  
  
  //board_5: start
  //R1
  pinMode(board5.switch2_In4, OUTPUT);
  //R2
  pinMode(board5.switch2_In3, OUTPUT);
  //R3
  pinMode(board5.switch1_In1, OUTPUT);
  //C1
  pinMode(board5.switch2_In1, OUTPUT);
  //C2
  pinMode(board5.switch2_In2, OUTPUT);
  //board_5: end
  
  //board_ID: start
  pinMode(boardController.buttonPin_A, INPUT);  
  pinMode(boardController.buttonPin_B, INPUT); 
  pinMode(boardController.buttonPin_C, INPUT);
  pinMode(boardController.buttonPin_D, INPUT);  
  pinMode(boardController.buttonPin_E, INPUT); 
  pinMode(boardController.buttonPin_F, INPUT);
  pinMode(boardController.buttonPin_G, INPUT);  
  pinMode(boardController.buttonPin_H, INPUT); 
  //board_ID: end
  
  // Need to include power regulator stuff here later, but not now for testing a few boards only
  Serial.println("Finished Setup successfully.");
}

// the loop routine runs over and over again forever
void loop() {
    boardController.Serial_Control();

      //Serial.print("Board ID: "); // DELETE THIS LINE LATER IF WEIRD SERIAL PRINT THINGS ARE HAPPENING!!!!!
 // Serial.println(boardID); // AND THIS ONE TOO!!!!
    boardController.Safety_Check();   
}


