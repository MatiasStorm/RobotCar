#include <Arduino.h>
#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin){
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    this->trigPin = trigPin;
    this->echoPin = echoPin;
}

int UltrasonicSensor::getCmToObstacle(int nReads=15){
    long duration = 0;
    for(int i = 0; i < nReads; i++){
        // Clears the trigPin
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);

        // Sets the trigPin on HIGH state for 10 micro seconds
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        // Reads the echoPin, returns the sound wave travel time in microseconds
        duration += pulseIn(echoPin, HIGH);
    }
    // duration = pulseIn(echoPin, HIGH);
    duration = duration / nReads;
    // Calculating the distance
    return duration*0.034/2;
}