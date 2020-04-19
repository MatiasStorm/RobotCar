#if !defined(DISPLAY_H)
#define DISPLAY_H   

#include <Arduino.h>
#include <LiquidCrystal.h>

class Display{
    private:
        LiquidCrystal lcd;
        char value[2][16];

        
    public:
        Display(LiquidCrystal &lcd);
        void update();
        void setRows(char *value);
        void setFirstRow(char *value);
        void setSecondRow(char *value);
        void clear();
        void clearRows();
};


#endif // DISPLAY_H
