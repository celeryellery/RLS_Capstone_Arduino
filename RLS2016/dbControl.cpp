/******************************************************************************
  dbControl.cpp
  This implementation file contains code that is common to all daughterboards
  that are part of the Remote Lab System at the University of
  Washington Bothell. See dbControl.cpp for implementation.
  This code is designed to run on an Arduino Mega 2560.
  
  Created by Ellery Walsh, March 2016
  Reseased into the public domain.
******************************************************************************/

#include "Arduino.h"
#include "dbControl.h"

// Pins of Board ID are Arduino Mega's analog input pins
const int boardIdPins[8] = {51, 49, 47, 45, 43, 41, 39, 37};
int boardIdPinState[8] = {0};

// class constructor
DBControl::DBControl() {
  
}

// Serial control returns the number of the board plugged in, 
// or -1 if the board ID was just determined or if there was an error
int DBControl::serialControl() {
      if (Serial.available()) 
      {
        String outputFromUI = Serial.readString();
        String boardIDsubstring = outputFromUI.substring(0,7);
        if (outputFromUI == "boardID") //Board ID is requested
        {
          readBoardID();
          stringifyBoardID();
          Serial.print("Board ID: "); // DELETE THIS LINE LATER IF WEIRD SERIAL PRINT THINGS ARE HAPPENING!!!!!
          Serial.println(boardID); 
          return -1;
        }
        else if (boardIDsubstring == "board_1") //Board_1 is addressed
        {
          Serial.println(outputFromUI); 
          return 1; //Configure board_1 (the default message is board_1,01,1,4,4,01,01)
        }      
        else if (boardIDsubstring == "board_2")//Board 2 is addressed
        {
          Serial.println(outputFromUI); 
          return 2; //Configure board_2 (the default message is board_2,1,1,1,1,1,1,01,01)
        }
        else if (boardIDsubstring == "board_5")//Board 5 is addressed
        {
          Serial.println(outputFromUI);           
          return 5; //Configure board_5
        }
        /*
        else if(outputFromUI.substring(0,9) == "power_reg")
        {
          Power_Regulation(outputFromUI); //power_reg,111
        }
        */
        else
        {
          Safety_Check();
          Serial.println("error");
          return -1;
        }
      }
}

//Check if the daughter board is present,
//if it isnt, disable the Power Regulator relay
void DBControl::safetyCheck(){
    readBoardID();
    int sumOfIdStates = 0;
    for (int i = 0; i < 8; i++) {
      sumOfIdStates += boardIdPinState[i];
    }
    if (sumOfIdStates == 0)
    {
      Serial.println("No board in place!!");
      //digitalWrite(Power_Relay_Enable, LOW);
    }
 }

void DBControl::readBoardID() {
  // Read the voltage on all 8 pins of the board ID
  // and save their state into the array boardIDPinState
  for (int i = 0; i < 8; i++) {
    boardIdPinState[i] = digitalRead(boardIdPins[i]));
  }
}

String DBControl::stringifyBoardID() {
  // Build up a string from all the board ID pin states
  boardID = "Board_ID,";
  for (int i = 0; i < 8; i++) {
     boardID = boardID + String(boardIdPinState[i]);
  }
  return boardID;
}

void DBControl::configureBoardIdPins() {
  for (int i = 0; i < 8; i++) {
     pinMode(boardIdPins[i], INPUT);
  }
}

