#include "ExpressionModule.h"

ExpressionModule::ExpressionModule(int servo1Pin, int servo2Pin)
    : arms(servo1Pin, servo2Pin), currentState(ExpressionState::NEUTRAL) {}

void ExpressionModule::begin() {
    arms.begin();
    setState(currentState);
}

void ExpressionModule::setState(ExpressionState state) {
    currentState = state;
    arms.setPose(state);
}

ExpressionState ExpressionModule::getState() const {
    return currentState;
}
