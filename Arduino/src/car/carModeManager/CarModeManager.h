#if !defined(CAR_MODE_MANAGER_H)
#define CAR_MODE_MANAGER_H

#include "car/RunnableCar.h"
#include "car/selfDrivingCar/SelfDrivingCar.h"
#include "settings.h"
#include "display/Display.h"


class CarModeManager{
    private:
        UltrasonicSensor* ultrasonicSensor;
        RunnableCar *selfDrivingCar;
        Car *car;
        int buttonValue;
        int selectedOptionIndex = 0;

        char *carOptions[3] = {"Self driving", "Bluetooth", "Test"};

        void initializeCarOptions();
    public:
        CarModeManager();
        RunnableCar* pickCar(Display &display);
        void displayOptions(Display &display);
};


#endif // CAR_MODE_MANAGER_H
