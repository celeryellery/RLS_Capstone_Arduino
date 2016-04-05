/******************************************************************************
	db7.h
	This header file contains code for Daugherboard 7,
	part of the Remote Lab System at the University of
	Washington Bothell. See db7.cpp for implementation.
	This code is designed to run on an Arduino Mega 2560.
	
	Created by Ellery Walsh, April 2016
	Reseased into the public domain.
******************************************************************************/


#ifndef db7_h
#define db7_h

#include "Arduino.h"

class DB7 {
	public: 
  void execute(String);
  void configurePins();
  
	private:

  
  // variables used for parsing input from user interface

};

#endif