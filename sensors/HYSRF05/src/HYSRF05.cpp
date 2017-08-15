/*
  HYSRF05.cpp - Library for using HY-SRF05 ultrasonic sensor.
  Created by Vitaly V. Basov, August 15, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "HYSRF05.h"

HYSRF05::HYSRF05(int triggerPin, int echoPin){  
	
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);
  
	_triggerPin = triggerPin;
	_echoPin = echoPin;
}

float HYSRF05::getDistance(int measurement){
	
	long duration;

	float distance;
   
	digitalWrite(_triggerPin, LOW);
	delayMicroseconds(2);
	digitalWrite(_triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(_triggerPin, LOW);
	
	duration = pulseIn(_echoPin, HIGH);
	
	if(measurement == CM){
		distance = duration/29.1/2;
	}
	else if(measurement == INCH){
		distance = duration/73.9/2;
	}
  
	if (distance < 0){
		distance = 0;
	}
	
	
	/*
    
    	And to finish off here comes a bit more about how to calculate the distance based on the time for the sound:

		c = 331.3 + 0.606 × Temperature_in_C

		so for 20 degrees it would be

		c = 331.3 + 0.606 × 20 = 343.42 m/s

		Distance (in cm) = (elapsed time * sound velocity (340 m/s)) / 100 / 2

    */
	
	
	return distance;
}