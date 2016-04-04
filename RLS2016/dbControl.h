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
  void readBoardID();
  String stringifyBoardID();
  
  private:
  // variables to hold input from UI
  String temp = "null";
  int test;
  int test1;
  
  String serial_message;
  String serial_message_num;
  
  // Arduino Pins used for reading Board ID
  const int boardIdPins[8];
  int boardIdPinState[8];

  // helper functions and testing functions
  void test_message();

};

#endif
