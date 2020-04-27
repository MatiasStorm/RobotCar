#include "CarModeManager.h"


CarModeManager::CarModeManager(){
    this->car = new Car(CAR_N1, CAR_N2, CAR_EN_A, CAR_N3, CAR_N4, CAR_EN_B);
    pinMode(BUTTON_1, INPUT);

    initializeSelfDrivingCar();
    initializeBluetoothCar();
}

void CarModeManager::initializeSelfDrivingCar(){
    this->ultrasonicSensor = new UltrasonicSensor(ULTRA_TRIG, ULTRA_ECHO);
    this->selfDrivingCar = new SelfDrivingCar(*(this->car), *(this->ultrasonicSensor));
}

void CarModeManager::initializeBluetoothCar(){
    this->bluetoothCar = new BluetoothCar(*(this->car));
}


RunnableCar* CarModeManager::pickCar(Display &display){
    int previousState = LOW;
    long lastButtonPressTime = 0;
    int pickHoldTime = 2000;
    displayOptions(display);
    int optionsLength = sizeof(carOptions) / sizeof(carOptions[0]);
    
    while(1){
        buttonValue = digitalRead(BUTTON_1);
        if(previousState == HIGH && buttonValue == LOW){
            selectedOptionIndex = (selectedOptionIndex + 1) % optionsLength;
            displayOptions(display);
            previousState = LOW;
            lastButtonPressTime = 0;
        }
        else if(previousState == LOW && buttonValue == HIGH){
            previousState = HIGH;
            lastButtonPressTime = millis();
        }
        else if(millis() - lastButtonPressTime > pickHoldTime && buttonValue == HIGH){
            break;
        }
        delay(50);
    }

    char *selectedCarOption = carOptions[selectedOptionIndex];
    if(selectedOptionIndex == 0){
        return (RunnableCar*) (this->selfDrivingCar);
    }
    else if(selectedOptionIndex == 1){
        return (RunnableCar*) (this->bluetoothCar);
    }

}

void CarModeManager::displayOptions(Display &display){
    char displayMessage[34];
    int optionsLength = sizeof(carOptions) / sizeof(carOptions[0]);

    sprintf(displayMessage, ">%s\n %s", carOptions[selectedOptionIndex], carOptions[(selectedOptionIndex + 1) % optionsLength]);
    display.setRows(displayMessage);
    display.update();
}

BluetoothCar* CarModeManager::getBluetoothCar(){
    return this->bluetoothCar;
}