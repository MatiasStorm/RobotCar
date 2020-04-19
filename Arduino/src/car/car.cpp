#include <Arduino.h>
#include <car/car.h>

/*
2 s forward:
150 = 75
200 = 91
235 = 103
255 = 120 cm.

.5 s = 90 degrees.
1 s = 180 degrees
1625 = 360 degrees.
*/



Car::Car(int n1, int n2, int enableA, int n3, int n4, int enableB){
    pinMode(n1, OUTPUT);
    pinMode(n2, OUTPUT);
    pinMode(n3, OUTPUT);
    pinMode(n4, OUTPUT);
    pinMode(enableA, OUTPUT);
    pinMode(enableB, OUTPUT);

    this->n1 = n1;
    this->n2 = n2;
    this->n3 = n3;
    this->n4 = n4;
    this->leftMotor.setPins(n1, n2, enableA);
    this->rightMotor.setPins(n3, n4, enableB);
    this->activity = CarActivity::STOP;
}

void Car::reverse(int speed){
    if(activity != CarActivity::REVERSE){
        leftMotor.reverse(speed);
        rightMotor.reverse(speed);
        activity = CarActivity::REVERSE;
    }
}

void Car::forward(int speed){
    if(activity != CarActivity::FORWARD){
        leftMotor.forward(speed);
        rightMotor.forward(speed);
        activity = CarActivity::FORWARD;
    }
}


void Car::stop(){
    if(activity != CarActivity::STOP){
        leftMotor.stop();
        rightMotor.stop();
        activity = CarActivity::STOP;
    }
}

void Car::right(int speed){
    if(activity != CarActivity::RIGHT){
        leftMotor.forward(speed);
        rightMotor.reverse(speed);
        activity = CarActivity::RIGHT;
    }
}

void Car::left(int speed){
    if(activity != CarActivity::LEFT){
        leftMotor.reverse(speed);
        rightMotor.forward(speed);
        activity = CarActivity::LEFT;
    }
}

void Car::move(int leftMotorSpeed, int rightMotorSpeed){
    if(activity == CarActivity::MOVE) return;
    if(rightMotorSpeed > 0){
        rightMotor.forward(rightMotorSpeed);
    } else{
        rightMotor.reverse(abs(rightMotorSpeed));
    }
    if(leftMotorSpeed > 0){
        leftMotor.forward(leftMotorSpeed);
    } else{
        leftMotor.reverse(abs(leftMotorSpeed));
    }
    activity = CarActivity::MOVE;
}

CarActivity Car::getActivity(){
    return this->activity;
}
