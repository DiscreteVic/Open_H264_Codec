#include "frame.h"

const uint16_t frame_width = 4096;
const uint16_t frame_height = 2160;

int get_frame(int idx, Frame* frame){
    
    uint8_t* image = NULL;
    long image_size;
    char* image_path = "../../dataset/video0/frame0000.bin";

    frame->width = frame_width;
    frame->height = frame_height;

    (void)get_img(image_path, &(frame->data), &frame->size);

    return 0;
}
int free_frame(Frame frame){
    free(frame.data);
    return 0;
}