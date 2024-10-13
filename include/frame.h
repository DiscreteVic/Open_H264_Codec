
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Custom libraries
#include <img.h>

#ifndef FRAME_LIB
#define FRAME_LIB


typedef struct {
    uint8_t blue; 
    uint8_t green; 
    uint8_t red; 
} Pixel;

typedef struct {
    uint16_t width;
    uint16_t height;
    Pixel* data;
    long size;    
} Frame;


int get_frame(int idx, Frame* frame);
int free_frame(Frame frame);

#endif