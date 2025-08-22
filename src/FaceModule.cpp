#include "FaceModule.h"
#include "lvgl.h"
#include "lvgl_helpers.h"

FaceModule::FaceModule() {
    lv_init();
    lvgl_driver_init();
    img = lv_img_create(lv_scr_act());
}

void FaceModule::showImage(const void* img_src, int x, int y) {
    lv_img_set_src(img, img_src);
    lv_obj_set_pos(img, x, y);
    lv_obj_set_size(img, 100, 100);
    lv_obj_add_flag(img, LV_OBJ_FLAG_CLICKABLE);
}
