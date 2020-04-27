#if !defined(BLUETOOTH_CAR_H)
#define BLUETOOTH_CAR_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "car/car.h"
#include "car/RunnableCar.h"
#include "settings.h"


class BluetoothCar : public RunnableCar{
    private:
        Car car;
        SoftwareSerial *bluetoothModule;
        int data;
        char statusMessage[32];
        long lastRecieveTime;
        const unsigned int recieveTime = 300;

    public:
        void run();
        void handleInterrupt();
        char* getStatusMessage();
        BluetoothCar(Car &_car);

};


#endif // BLUETOOTH_CAR_H
