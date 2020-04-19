#if !defined(RUNNABLE_CAR_H)
#define RUNNABLE_CAR_H

class RunnableCar{
    public:
        virtual void run() = 0;
        virtual char* getStatusMessage() = 0;
};


#endif // RUNNABLE_CAR_H
