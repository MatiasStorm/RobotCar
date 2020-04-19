#if !defined(MOTOR_H)
#define MOTOR_H

class Motor {
    private:
        int pin1;
        int pin2;
        int enablePin;
    public:
        void stop();
        void forward(int speed);
        void reverse(int speed);
        Motor();
        void setPins(int pin1, int pin2, int enablePin);
};

#endif // MOTOR_H
