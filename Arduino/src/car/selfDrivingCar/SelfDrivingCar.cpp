#include <Arduino.h>
#include "SelfDrivingCar.h"

SelfDrivingCar::SelfDrivingCar(Car &_car, UltrasonicSensor &_ultrasonicSensor): car(_car), ultrasonicSensor(_ultrasonicSensor){};

void SelfDrivingCar::run(){
    if(isObstacle){
        search();
    }
    else {
        car.forward(150);
        distanceToObstacle = ultrasonicSensor.getCmToObstacle();
        if(distanceToObstacle < distanceThreashold){
            isObstacle = 1;
        }
    }
}

char* SelfDrivingCar::getStatusMessage(){
    sprintf(statusMessage, "O: %d\nL: %d - R: %d", distanceToObstacle, distanceLeft, distanceRight);
    return statusMessage;
}

void SelfDrivingCar::search(){
    const int stopTime = 1000;
    const int reverseTime = 600;
    const int turnTime = 600;


    int currentTime = millis();
    int timeDelta = currentTime - startSearchTime;
    
    
    if(startSearchTime == 0){
        startSearchTime = currentTime;
        timeDelta = currentTime - startSearchTime;
        car.reverse(150);
    }

    switch (timeDelta) {
        case reverseTime ... reverseTime + turnTime - 1:
            car.left(200);
            break;
            
        case reverseTime + turnTime ... reverseTime + turnTime + stopTime - 1:
            car.stop();
            if(distanceLeft == 0){
                distanceLeft = ultrasonicSensor.getCmToObstacle(30);
            }
            break;

        case reverseTime + turnTime + stopTime ... reverseTime + (turnTime * 3) + stopTime - 1:
            car.right(200);
            break;

        case reverseTime + (turnTime * 3) + stopTime ... reverseTime + (turnTime * 3) + (stopTime * 2) - 1:
            car.stop();
            if(distanceRight == 0){
                distanceRight = ultrasonicSensor.getCmToObstacle(30);
            }
            break;

        case reverseTime + (turnTime * 3) + (stopTime * 2) ... reverseTime + (turnTime * 6) + (stopTime * 2):
            if(distanceLeft < distanceRight){
                distanceLeft = 0;
                distanceRight = 0;
                
                isObstacle = 0;
                startSearchTime = 0;
            }
            else if(timeDelta < reverseTime + (turnTime * 5) + (stopTime * 2)) {
                car.left(200);
            }
            else if(timeDelta >= reverseTime + (turnTime * 5) + (stopTime * 2)){
                distanceLeft = 0;
                distanceRight = 0;
                
                isObstacle = 0;
                startSearchTime = 0;
            }
            break;
    }
}

int SelfDrivingCar::getDistanceToObstacle(){
    return distanceToObstacle;
}
int SelfDrivingCar::getDistanceLeft(){
    return distanceLeft;
}
int SelfDrivingCar::getDistanceRight(){
    return distanceRight;
}