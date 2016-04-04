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

/********************** Assign private variables******************************/
// variables to hold input from UI
String temp = "null";
int test = 0;
int test1 = 0;

String serial_message = "null";
String serial_message_num = "null";

// variables to hold Board ID
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



// class constructor
DBControl::DBControl() {
  
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
private void test_message(){
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

