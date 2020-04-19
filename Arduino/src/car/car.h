#if !defined(CAR_H)
#define CAR_H

#include <car/motor.h>


enum class CarActivity{REVERSE, FORWARD, STOP, RIGHT, LEFT, MOVE};

class Car {
    private:
        int n1;
        int n2;
        int n3;
        int n4;
        int enableA;
        int enableB;
        Motor leftMotor;
        Motor rightMotor;
        CarActivity activity;

    public:
        Car(int n1, int n2, int enableA, int n3, int n4, int enableB);
        void reverse(int speed=255);
        void forward(int speed=255);
        void stop();
        void right(int speed=255);
        void left(int speed=255);
        void move(int motorASpeed, int motorBSpeed);
        CarActivity getActivity();

};

#endif // CAR_H


