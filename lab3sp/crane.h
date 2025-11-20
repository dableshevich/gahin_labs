#ifndef CRANE_H
#define CRANE_H

#include <iostream>
using namespace std;

class Crane {
private:
    int height;
    int rotationAngle;
    int loadWeight;
    bool isWorking;

public:
    Crane(int h = 50);

    void turnOn();
    void turnOff();
    void rotate(int angle);
    void raiseLoad(int weight);
    void dropLoad();
    void status() const;
};

#endif
