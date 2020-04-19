#include <Arduino.h>
#include <car/motor.h>

Motor::Motor(){
    this->pin1 = -1;
    this->pin2 = -1;
}

void Motor::stop(){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    analogWrite(enablePin, 0);
}

void Motor::forward(int speed){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    speed = speed > 255 ? 255 : speed;
    speed = speed < 0 ? 0 : speed; 
    analogWrite(enablePin, speed);
}

void Motor::reverse(int speed){
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    speed = speed > 255 ? 255 : speed;
    speed = speed < 0 ? 0 : speed;  
    analogWrite(enablePin, speed);
}

void Motor::setPins(int pin1, int pin2, int enablePin){
    this->pin1 = pin1;
    this->pin2 = pin2;
    this->enablePin = enablePin;
}