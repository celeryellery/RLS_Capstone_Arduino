/******************************************************************************
	db5.h
	This header file contains code for Daugherboard 5,
	part of the Remote Lab System at the University of
	Washington Bothell. See db5.cpp for implementation.
	This code is designed to run on an Arduino Mega 2560.
	
	Created by Ellery Walsh, March 2016
	Reseased into the public domain.
******************************************************************************/

#ifndef db5_h
#define db5_h

#include "Arduino.h"

class DB5 {
	public: 
  void board_5(String);
  
	private:
  //R1
  const int switch2_In4;
  //R2
  const int switch2_In3;
  //R3
  const int switch1_In1;
  //C1
  const int switch2_In1;
  //C2
  const int switch2_In2;
  
  // variables used for parsing input from interface
  int top_resistor;
  int bottom_resistor;
  int capacitor;
};

#endif
