#include "ExpressionModule.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "display_pins.h"

extern "C" void app_main(void) {
    ExpressionModule module(4, 5);
    module.begin();

    while (1) {
        module.setState(ExpressionState::HAPPY);
        vTaskDelay(pdMS_TO_TICKS(2000));

        module.setState(ExpressionState::NEUTRAL);
        vTaskDelay(pdMS_TO_TICKS(2000));

        module.setState(ExpressionState::SAD);
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
