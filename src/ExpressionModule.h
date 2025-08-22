#pragma once
#include "ExpressionState.h"
#include "ArmModule.h"
#include "FaceModule.h"

class ExpressionModule {
public:
    ExpressionModule(int servo1Pin, int servo2Pin);
    void begin();
    void setState(ExpressionState state);
    ExpressionState getState() const;

private:
    ArmModule arms;
    ExpressionState currentState;
};
