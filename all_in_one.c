#include <stdint.h>
#include <math.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image/stb_image_resize.h"

int main() {
    // Load image
    int width, height, channels;
    const char* const path = "images/image.png";
    const char* const path_gray = "images/image_gray.png";

    uint8_t* image = stbi_load(path, &width, &height, &channels, 0);
    if (image == NULL) {
        printf("Error while loading the an image!\n");
        exit(1);
    }
    printf("Loaded image with a width of %dpx, a height of %dpx and %dpx channels.\n", width, height, channels);

    // To grayscale
    size_t image_size = width * height * channels;
    int gray_channels = channels == 4 ? 2 : 1;
    size_t gray_image_size = width * height * gray_channels;
    
    uint8_t* gray_image = malloc(gray_image_size);
    if (gray_image == NULL) {
        printf("Unable to allocate memory for grayscale image.\n");
        exit(1);
    }

    for (uint8_t *p = image, *pg = gray_image;
         p != image + image_size;
         p += channels, pg += gray_channels) {
             *pg = (*p + (*p + 1) + (*p + 2)) / channels;
             if (channels == 4) {
                 *(pg + 1) = *(p + 3);
             }
         }

    // Save gray image
    stbi_write_png(path_gray, width, height, gray_channels, gray_image, width*gray_channels);

    // Release memory
    stbi_image_free(image);
    free(gray_image);

    return 0;
}
