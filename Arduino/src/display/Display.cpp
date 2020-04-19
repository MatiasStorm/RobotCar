#include "Display.h"

Display::Display(LiquidCrystal &_lcd):lcd(_lcd){
    this->lcd.begin(16,2);
};

void Display::update(){
    lcd.clear();
    lcd.print(value[0]);
    lcd.setCursor(0,1);
    lcd.print(value[1]);
}

void Display::setRows(char *newValue){
    clearRows();
    if(newValue == NULL) return;
    
    char *delim = "\n";
    char valueCopy[34];
    strncpy(valueCopy, newValue, 34);
    
    char *token = strtok(valueCopy, delim);
    int i = 0;
    while(token != NULL){
        strncpy(this->value[i], token, 16);
        token = strtok(NULL, delim);
        i += 1;
    }
}

void Display::setFirstRow(char* newValue){
    strncpy(this->value[0], newValue, 16);
}

void Display::setSecondRow(char* newValue){
    strncpy(this->value[1], newValue, 16);
}

void Display::clear(){
    lcd.clear();
}

void Display::clearRows(){
    strcpy(this->value[0], "\0");
    strcpy(this->value[1], "\0");
}