/******************************************************************************
  dbControl.h
  This header file contains code that is common to all daughterboards
  that are part of the Remote Lab System at the University of
  Washington Bothell. See dbControl.cpp for implementation.
  This code is designed to run on an Arduino Mega 2560.
  
  Created by Ellery Walsh, March 2016
  Reseased into the public domain.
******************************************************************************/

#ifndef dbControl_h
#define dbControl_h

#include "Arduino.h"

class DBControl {
  public: 
  void Serial_Control();
  void Safety_Check();
  
  private:
  // variables to hold input from UI
  String temp = "null";
  int test;
  int test1;
  
  String serial_message;
  String serial_message_num;

  // variables to hold board ID
  const int buttonPin_A;    
  const int buttonPin_B;
  const int buttonPin_C;
  const int buttonPin_D; 
  const int buttonPin_E;
  const int buttonPin_F;
  const int buttonPin_G;
  const int buttonPin_H;
  String board_ID = "null";
  int buttonState_A;        
  int buttonState_B; 
  int buttonState_C;
  int buttonState_D;     
  int buttonState_E;
  int buttonState_F;
  int buttonState_G;
  int buttonState_H;

  // helper functions and testing functions
  void test_message();
  void Board_ID();

};

#endif
