#pragma once
#include "Servo.h"
#include "ExpressionState.h"

class ArmModule {
public:
    ArmModule(int servo1Pin, int servo2Pin);
    void begin();
    void setPose(ExpressionState state);

private:
    Servo arm1;
    Servo arm2;
};