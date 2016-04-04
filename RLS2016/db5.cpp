/******************************************************************************
	db5.h
	This implementation file contains code for Daugherboard 5,
	part of the Remote Lab System at the University of
	Washington Bothell. See db5.h.
	This code is designed to run on an Arduino Mega 2560.
	
	Created by Ellery Walsh, March 2016
	Reseased into the public domain.
******************************************************************************/

#include "Arduino.h"
#include "db5.h"

//set up connections between arduino and switches
//R1
const int switch2_In4 = 23;
//R2
const int switch2_In3 = 25;
//R3
const int switch1_In1 = 26;
//C1
const int switch2_In1 = 22;
//C2
const int switch2_In2 = 24;

// set up variables used for parsing input from interface
int top_resistor = 0;
int bottom_resistor = 0;
int capacitor = 0;

// class constructor
DB5::DB5() {
	
}

//TODO: clean up board_5 function and split into several helper methods

void configurePins() {
  pinMode(switch2_In4, OUTPUT); //R1
  pinMode(switch2_In3, OUTPUT); //R2
  pinMode(switch1_In1, OUTPUT); //R3
  pinMode(switch2_In1, OUTPUT); //C1
  pinMode(switch2_In2, OUTPUT); //C2
}

void execute(String Board_5_Serial) {
  // variables used for parsing input from interface
  board5_top_resistor = Board_5_Serial.substring(8,9).toInt();
  board5_bottom_resistor = Board_5_Serial.substring(9,10).toInt();
  board5_capacitor = Board_5_Serial.substring(10,11).toInt();
  
  // State of top resistor
  if(board5_top_resistor == 0) {
    digitalWrite(Board_5_Switch2_In4, HIGH);
    digitalWrite(Board_5_Switch2_In3, LOW);
    Serial.println("Board5 Top resistor value: ");
  }
  else if (board5_top_resistor == 1) {
    digitalWrite(Board_5_Switch2_In4, LOW);
    digitalWrite(Board_5_Switch2_In3, HIGH);
    Serial.println("Board5 Top resistor value: ");
  }

  
  // State of bottom resistor
  if(board5_bottom_resistor == 0) {
    digitalWrite(Board_5_Switch1_In1, LOW);
    Serial.println("Board5 Bottom resistor value: ");
  }
  else if (board5_bottom_resistor == 1) {
    digitalWrite(Board_5_Switch1_In1, HIGH);
    Serial.println("Board5 Bottom resistor value: ");
  }

  
  // State of capacitor
  if(board5_capacitor == 0) {
    digitalWrite(Board_5_Switch2_In1, LOW);
    digitalWrite(Board_5_Switch2_In2, HIGH);
    Serial.println("Board5 capacitor value: ");
  }
  else if (board5_capacitor == 1) {
    digitalWrite(Board_5_Switch2_In1, HIGH);
    digitalWrite(Board_5_Switch2_In2, LOW);
    Serial.println("Board5 capacitor value: ");
  }
}

