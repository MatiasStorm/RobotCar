#if !defined(CAR_MODE_MANAGER_H)
#define CAR_MODE_MANAGER_H

#include "car/RunnableCar.h"
#include "car/selfDrivingCar/SelfDrivingCar.h"
#include "car/bluetoothCar/BluetoothCar.h"
#include "settings.h"
#include "display/Display.h"


class CarModeManager{
    private:
        UltrasonicSensor* ultrasonicSensor;
        RunnableCar *selfDrivingCar;
        BluetoothCar *bluetoothCar;
        Car *car;
        int buttonValue;
        int selectedOptionIndex = 0;

        char *carOptions[3] = {"Self driving", "Bluetooth", "Test"};

        void initializeCarOptions();
        void initializeSelfDrivingCar();
        void initializeBluetoothCar();

    public:
        CarModeManager();
        RunnableCar* pickCar(Display &display);
        void displayOptions(Display &display);
        BluetoothCar* getBluetoothCar();
};


#endif // CAR_MODE_MANAGER_H
