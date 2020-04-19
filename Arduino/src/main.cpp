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
// // Car pins:
// const int EN_A = 6;
// const int N1 = A0;
// const int N2 = A1;
// const int N3 = A2;
// const int N4 = A3;
// const int EN_B = 5;

// Car CAR(N1, N2, EN_A, N3, N4, EN_B);

// Ultrasonic sensor:
const int trigPin = 9;
const int echoPin = 10;
UltrasonicSensor ultrasonicSensor(trigPin, echoPin);


RunnableCar *car;

const int RS = 13;
const int ENABLE = 12;
const int D_4 = 8;
const int D_5 = 7;
const int D_6 = 4;
const int D_7 = 2;

LiquidCrystal *lcd = new LiquidCrystal(RS, ENABLE, D_4, D_5, D_6, D_7);
#define LCD_REFRESH_TIME 500

long displayLastRefresh = 0;

Display *display = new Display(*lcd);
CarModeManager *carManager = new CarModeManager();

int TX = 10;
int RX = 11;
SoftwareSerial MyBlue(TX, RX);

void setup() {
    MyBlue.begin(38400); 
    Serial.begin(9600); 

}

int readByte = 0;

void loop() {
    if(MyBlue.available()){
        lcd->clear();
        while(MyBlue.available()){
            readByte = MyBlue.read();
            Serial.write(readByte);
            lcd->write(readByte);
        }
    }
    while(Serial.available()){
        MyBlue.write(Serial.read());
    }





    // car = carManager->pickCar(*display);

    // while(1){
    //     car->run();
    //     if(millis() - displayLastRefresh >= LCD_REFRESH_TIME){
    //         display->setRows(car->getStatusMessage());
    //         display->update();

    //         displayLastRefresh = millis();
    //     }
    // }
}





/*
    carModeManager.pickCar();
    display.mainMenu();

    While(running){ // Runing = false from interrupt.
        car.run();
        display.update();
    }

*/



/*

Define different states:
Running.
Stoped (Menu active).


Pick option on menu.
car begins driving.
LCD updates stats from the driving car mode.
At any moment the car can be stopped by an interrupt.
LCD displays menu again.

*/
