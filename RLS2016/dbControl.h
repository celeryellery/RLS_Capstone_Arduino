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
  int serialControl();
  void safetyCheck();
  void readBoardID();
  String stringifyBoardID();
  void configureBoardIdPins();
  
  private:
  // Arduino Pins used for reading Board ID
  const int boardIdPins[8];
  int boardIdPinState[8];
};

#endif
