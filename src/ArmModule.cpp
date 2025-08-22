#include "ArmModule.h"

ArmModule::ArmModule(int servo1Pin, int servo2Pin)
    : arm1(servo1Pin, LEDC_CHANNEL_0),
      arm2(servo2Pin, LEDC_CHANNEL_1) {}

void ArmModule::begin() {
    arm1.begin();
    arm2.begin();
}

void ArmModule::setPose(ExpressionState state) {
    switch (state) {
        case ExpressionState::HAPPY:
            arm1.setAngle(180);
            arm2.setAngle(180);
            break;
        case ExpressionState::SAD:
            arm1.setAngle(0);
            arm2.setAngle(0);
            break;
        case ExpressionState::NEUTRAL:
            arm1.setAngle(0);
            arm2.setAngle(180);
            break;
    }
}
