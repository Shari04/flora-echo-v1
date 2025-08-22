#pragma once
#include "lvgl.h"

class FaceModule {
public:
    FaceModule();
    void showImage(const void* img_src, int x, int y);
    
private:
    lv_obj_t *img;
};
