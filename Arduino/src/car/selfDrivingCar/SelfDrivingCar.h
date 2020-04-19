#if !defined(SELF_DRIVING_CAR_H)
#define SELF_DRIVING_CAR_H

#include "car/car.h"
#include "car/RunnableCar.h"
#include "UltrasonicSensor.h"

class SelfDrivingCar : public RunnableCar{
    private:
        int isObstacle = 0;
        int distanceToObstacle = 0;
        int startSearchTime = 0;
        int distanceThreashold = 25;
        // int distanceBeforeSearch = 0;

        int distanceRight = 0;
        int distanceLeft = 0;

        char statusMessage[34];

        Car car;
        UltrasonicSensor ultrasonicSensor;
        void search();

    public:
        void run();
        char* getStatusMessage();
        SelfDrivingCar(Car &car, UltrasonicSensor &ultrasonicSensor);
        int getDistanceToObstacle();
        int getDistanceLeft();
        int getDistanceRight();
};


#endif // SELF_DRIVING_CAR_H


