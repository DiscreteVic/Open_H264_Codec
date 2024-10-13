
#include <stdio.h>
#include <stdint.h>

// Custom libraries
#include <img.h>

int main() {
    
    uint8_t* image = NULL;
    long image_size;
    char* image_path = "../../dataset/video0/frame0000.bin";

    (void)get_img(image_path, &image, &image_size);

    // Example: Display the values of the first few pixels (BGR)
    printf("Size: %d Bytes, First 3 pixels (in BGR format):\n", image_size);
    for (int i = 0; i < 3 * 3; i += 3) {
        printf("Pixel %d - B: %u, G: %u, R: %u\n", i / 3, image[i], image[i + 1], image[i + 2]);
    }
    free(image);

    return 0;
}
