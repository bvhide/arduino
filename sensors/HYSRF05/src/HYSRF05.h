/*
  HYSRF05.h - Library for using HY-SRF05 ultrasonic sensor.
  Created by Vitaly V. Basov, August 15, 2017.
  Released into the public domain.
*/
#ifndef HYSRF05_h
#define HYSRF05_h
 
#include "Arduino.h"

#define CM 0
#define INCH 1

class HYSRF05 {
	
	public:
		HYSRF05(int triggerPin, int echoPin);
		float getDistance(int measurement);
		
	private:
		
		int _triggerPin;
		int _echoPin;
		int _type;
};

#endif