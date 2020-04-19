#if !defined(ULTRASONIC_SENSOR_H)
#define ULTRASONIC_SENSOR_H

class UltrasonicSensor {
    private:
        int trigPin;
        int echoPin;

    public:
        UltrasonicSensor(int trigPin, int echoPin);
        int getCmToObstacle(int nReads=15);
};


#endif // ULTRASONIC_SENSOR_H

