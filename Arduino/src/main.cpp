/*
BLUETOOTH: +ADDR:98d3:11:fc129a
00:19:C1:6B:8B:E4 Sony PLAYSTATION(R)3 Controller
*/

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include "car/car.h"
#include "car/selfDrivingCar/SelfDrivingCar.h"
#include "display/Display.h"
#include "car/carModeManager/CarModeManager.h"
#include "settings.h"

#define LCD_REFRESH_TIME 500

long displayLastRefresh = 0;

RunnableCar *car;
Display *display = new Display();
CarModeManager *carManager = new CarModeManager();


void setup() {
} 


void loop() {
    car = carManager->pickCar(*display);
    while(1){
        car->run();
        if(millis() - displayLastRefresh >= LCD_REFRESH_TIME){
            display->setRows(car->getStatusMessage());
            display->update();

            displayLastRefresh = millis();
        }
    }
}









/*
// TEST:
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include "car/car.h"
#include "car/selfDrivingCar/SelfDrivingCar.h"
#include "display/Display.h"
#include "car/carModeManager/CarModeManager.h"
#include "settings.h"

#define LCD_REFRESH_TIME 500

long displayLastRefresh = 0;

Car *car = new Car(CAR_N1, CAR_N2, CAR_EN_A, CAR_N3, CAR_N4, CAR_EN_B);

SoftwareSerial *bluetoothModule = new SoftwareSerial(BLUETOOTH_RX, BLUETOOTH_TX);
LiquidCrystal *lcd = new LiquidCrystal(LCD_RS, LCD_EN, LCD_D_4, LCD_D_5, LCD_D_6, LCD_D_7);


void setup() {
    lcd->begin(16,2);
    bluetoothModule->begin(38400);
} 

int readByte = 0;

void loop() {
    if(bluetoothModule->available()){
        readByte = bluetoothModule->read();
        // switch (readByte)
        // {
        // case 'w':

        //     break;
        // case 'a':
        //     car->left(200);
        //     break;
        // case 's':
        //     car->reverse(200);
        //     break;
        // case 'd':
        //     car->right(200);
        //     break;
        // case 'q':
        //     car->stop();
        //     break;
        // }
    }
    if(millis() - displayLastRefresh >= LCD_REFRESH_TIME){
        lcd->clear();
        lcd->write(readByte);
        displayLastRefresh = millis();
        car->forward(200);
        delay(500);
        car->stop();
    }
}*/