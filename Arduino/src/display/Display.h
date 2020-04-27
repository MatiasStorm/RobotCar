#if !defined(DISPLAY_H)
#define DISPLAY_H   

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "settings.h"

class Display{
    private:
        char value[2][16];
        LiquidCrystal *lcd;

        
    public:
        Display();
        void update();
        void setRows(char *value);
        void setFirstRow(char *value);
        void setSecondRow(char *value);
        void clear();
        void clearRows();
        void write(char *message);
        LiquidCrystal* getLCD();
};


#endif // DISPLAY_H
