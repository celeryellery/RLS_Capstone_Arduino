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
const int Board_5_Switch2_In4 = 23;
//R2
const int Board_5_Switch2_In3 = 25;
//R3
const int Board_5_Switch1_In1 = 26;
//C1
const int Board_5_Switch2_In1 = 22;
//C2
const int Board_5_Switch2_In2 = 24;

// set up variables used for parsing input from interface
int board5_top_resistor = 0;
int board5_bottom_resistor = 0;
int board5_capacitor = 0;

// class constructor
DB5::DB5() {
	
}


String temp = "null";
int test = 0;
int test1 = 0;

String serial_message = "null";
String serial_message_num = "null";

//board_5 setup: start
//R1
const int Board_5_Switch2_In4 = 23;
//R2
const int Board_5_Switch2_In3 = 25;
//R3
const int Board_5_Switch1_In1 = 26;
//C1
const int Board_5_Switch2_In1 = 22;
//C2
const int Board_5_Switch2_In2 = 24;
// variables used for parsing input from interface
int board5_top_resistor = 0;
int board5_bottom_resistor = 0;
int board5_capacitor = 0;
//board_5 setup: end


//board_ID: start
const int buttonPin_A = 51;// A0;     
const int buttonPin_B = 49;//A1;
const int buttonPin_C = 47; //A2;
const int buttonPin_D = 45; //A3;     
const int buttonPin_E = 43;//A4;
const int buttonPin_F = 41;//A5;
const int buttonPin_G = 39;//A6;
const int buttonPin_H = 37;//A7;
String board_ID = "null";
int buttonState_A = 0;         
int buttonState_B = 0; 
int buttonState_C = 0;
int buttonState_D = 0;     
int buttonState_E = 0;
int buttonState_F = 0;
int buttonState_G = 0;
int buttonState_H = 0;
//board_ID: end


// Need to include power regulator stuff here later, but not now for testing Board 5 only





void setup() {
  Serial.begin(9600);  
  
  //board_5: start
  //R1
  pinMode(Board_5_Switch2_In4, OUTPUT);
  //R2
  pinMode(Board_5_Switch2_In3, OUTPUT);
  //R3
  pinMode(Board_5_Switch1_In1, OUTPUT);
  //C1
  pinMode(Board_5_Switch2_In1, OUTPUT);
  //C2
  pinMode(Board_5_Switch2_In2, OUTPUT);
  //board_5: end
  
  //board_ID: start
  pinMode(buttonPin_A, INPUT);  
  pinMode(buttonPin_B, INPUT); 
  pinMode(buttonPin_C, INPUT);
  pinMode(buttonPin_D, INPUT);  
  pinMode(buttonPin_E, INPUT); 
  pinMode(buttonPin_F, INPUT);
  pinMode(buttonPin_G, INPUT);  
  pinMode(buttonPin_H, INPUT); 
  //board_ID: end
  
  // Need to include power regulator stuff here later, but not now for testing Board 5 only
  Serial.println("Finished Setup successfully.");
}

// the loop routine runs over and over again forever:
void loop() {
    Serial_Control();
    Safety_Check();
    //do a safety check for the board     
}

void Serial_Control() {
      if (Serial.available()) 
      {
        temp = Serial.readString();
        if (temp == "read")
        {
          test_message();
        }
        else if (temp == "boardID") //Board ID is requested
        {
          Board_ID();
        }
        else if (temp.substring(0,7) == "board_1") //Board_1 is addressed
        {
          serial_message = temp;
          Serial.println(serial_message); //testting
          board_1(temp); //Configure board_2 (the default message is board_1,01,1,4,4,01,01)
        }      
        else if (temp.substring(0,7) == "board_2")//Board 2 is addressed
        {
          Serial.println(temp); //testting
          board_2(temp); //Configure board_2 (the default message is board_2,1,1,1,1,1,1,01,01)
        }
        else if (temp.substring(0,7) == "board_5")//Board 5 is addressed
        {
          Serial.println(serial_message); //testting          THIS MAY NEED TO BE CHANGED TO TAKE IN TEMP LATER INSTEAD OF SERIAL MESSAGE
          board_5(temp); //Configure board_5
        }
        /*
        else if(temp.substring(0,9) == "power_reg")
        {
          Power_Regulation(temp); //power_reg,111
        }
        */
        else
        {
          serial_message = temp;
        }
      }
}

 //This function exists only for testting purposes, it sends the user the last message
//that the MEGA board received
void test_message(){
  Serial.println(serial_message);
}

  //Check if the daughter board is present,
  //if it isnt, disable the Power Regulator relay
void Safety_Check(){
    buttonState_A = digitalRead(buttonPin_A);
    buttonState_B = digitalRead(buttonPin_B);
    buttonState_C = digitalRead(buttonPin_C);
    buttonState_D = digitalRead(buttonPin_D);
    buttonState_E = digitalRead(buttonPin_E);
    buttonState_F = digitalRead(buttonPin_F);
    buttonState_G = digitalRead(buttonPin_G);
    buttonState_H = digitalRead(buttonPin_H);
    if ((buttonState_A == 0)
        &(buttonState_B == 0)
        &(buttonState_C == 0)
        &(buttonState_D == 0)
        &(buttonState_E == 0)
        &(buttonState_F == 0)
        &(buttonState_G == 0)
        &(buttonState_H == 0))
    {
      Serial.println("No board in place!!");
      //digitalWrite(Power_Relay_Enable, LOW);
    }
 }

void Board_ID()
  {
    buttonState_A = digitalRead(buttonPin_A);
    buttonState_B = digitalRead(buttonPin_B);
    buttonState_C = digitalRead(buttonPin_C);
    buttonState_D = digitalRead(buttonPin_D);
    buttonState_E = digitalRead(buttonPin_E);
    buttonState_F = digitalRead(buttonPin_F);
    buttonState_G = digitalRead(buttonPin_G);
    buttonState_H = digitalRead(buttonPin_H);
  
    board_ID ="Board_ID," 
              +String(buttonState_A)
              +String(buttonState_B)
              +String(buttonState_C)
              +String(buttonState_D)
              +String(buttonState_E)
              +String(buttonState_F)
              +String(buttonState_G)
              +String(buttonState_H);
    Serial.print("Board ID: ");
    Serial.println(board_ID);
}

void board_1(String Board_1_Serial) {

}

void board_2(String Board_2_Serial) {
  
}

void board_5(String Board_5_Serial) {
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
