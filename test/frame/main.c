
#include <stdio.h>
#include <stdint.h>

// Custom libraries
#include <frame.h>


int main() {
    

    Frame frame;
    (void)get_frame(0, &frame);
   
    printf("Size: %d, Width: %d, Height: %d\n", frame.size, frame.width, frame.height);
    printf("First 3 pixels (in BGR format):\n");
    for (int i = 0; i < 3 * 3; i += 3) {
        printf("Pixel %d - B: %u, G: %u, R: %u\n", i / 3, frame.data->blue, frame.data->green, frame.data->red);
    }
    free_frame(frame);
    return 0;
}
