#include "BluetoothCar.h"


BluetoothCar::BluetoothCar(Car &_car):car(_car){
    this->bluetoothModule = new SoftwareSerial(BLUETOOTH_RX, BLUETOOTH_TX);
    bluetoothModule->begin(38400);
};

void BluetoothCar::run(){
    if(bluetoothModule->available()){
        data = bluetoothModule->read();
        lastRecieveTime = millis();
        int speed = 200;
        switch (data){
            case 'w':
                car.forward(speed);
                break;
            case 'a':
                car.left(speed);
                break;
            case 's':
                car.reverse(speed);
                break;
            case 'd':
                car.right(speed);
                break;
        }
    }
    else if(millis() - lastRecieveTime > recieveTime){
        car.stop();
    }
}

char* BluetoothCar::getStatusMessage(){
    sprintf(statusMessage, "%c", data);
    return statusMessage;
}