#include "img.h"


int get_img(char* img_path, uint8_t** image_data, long* size) {
    // Open the BMP file in binary mode
    FILE *file = fopen(img_path, "rb");
    if (file == NULL) {
        printf("Could not open BMP file.\n");
        return 1;
    }

    // Mover el puntero al final del archivo
    fseek(file, 0, SEEK_END);
    
    // Obtener la posición actual del puntero (tamaño del archivo)
    *size = ftell(file);

    // Mover el puntero al final del archivo
    fseek(file, 0, SEEK_SET);

    // Allocate memory to store the entire image
    *image_data = (uint8_t*)malloc(*size);
    if (*image_data == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return 1;
    }

    // Read the entire image data into memory
    fread(*image_data, 1, *size, file);

    // Close the file
    fclose(file);

    // Now the image data is in 'image_data' in BGR format

    return 0;
}
