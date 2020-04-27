#if !defined(SETTIGS_H)
#define SETTIGS_H

#include <Arduino.h>

// Car pins:
const int CAR_EN_A = 6;
const int CAR_N1 = A0;
const int CAR_N2 = A1;
const int CAR_N3 = A2;
const int CAR_N4 = A3;
const int CAR_EN_B = 5;

// LCD:
const int LCD_RS = 13;
const int LCD_EN = 12;
const int LCD_D_4 = 8;
const int LCD_D_5 = 7;
const int LCD_D_6 = 4;
const int LCD_D_7 = 2;


// Ultrasonic sensor:
const int ULTRA_TRIG = 9;
const int ULTRA_ECHO = 10;

// Buttons
const int BUTTON_1 = A4;

// Bluetooth:
const int BLUETOOTH_TX = 10;
const int BLUETOOTH_RX = 3;


#endif // SETTIGS_H
