#include <stdint.h>
#include <math.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image/stb_image_resize.h"

uint8_t* read_image(const char* const path, int* height, int* width, int* channels) {
    uint8_t* image = stbi_load(path, width, height, channels, 0);
    if (image == NULL) {
        printf("Error while loading the an image!\n");
        exit(1);
    }
    printf("Loaded image with a width of %d, a height of %d and %d channels.\n", *width, *height, *channels);

    return image;
}

void write_image(uint8_t* image, const char* const path) {
    int width = 800;
    int height = 800;
    int channels = 3;

    image = malloc(width*height*3);
    stbi_write_png(path, width, height, channels, image, width*channels);
}

uint8_t* to_grayscale(uint8_t* image, int height, int width, int channels) {
    size_t image_size = width * height * channels;
    size_t gray_image_size = width * height;
    
    uint8_t* gray_image = malloc(gray_image_size);
    if (gray_image == NULL) {
        printf("Unable to allocate memory for grayscale image.\n");
        exit(1);
    }

    int i = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width*channels; x += channels) {
            int row_offset = y*width*channels;
            uint8_t r=image[row_offset +x];
            uint8_t g=image[row_offset+x+1];
            uint8_t b=image[row_offset+x+2];

            gray_image[i++] = (r + g + b) / 3;
            // gray_image[i++] = (b * 0.45 + g * 0.45 + g * 0.1);
        }
    }

    // for (int h = 0; h < image_size; h += channels) {
    //     gray_image[i++] = (image[h] + image[h+1] + image[h+2]) / 3;
    // }

    // Save gray image
    stbi_write_png("images/gray_image.png", width, height, 1, gray_image, width);

    return gray_image;
}

int main() {
    uint8_t* image = NULL;
    uint8_t* gray_image = NULL;
    int width = 0;
    int height = 0;
    int channels = 0;

    image = read_image("images/image.png", &height, &width, &channels);
    gray_image = to_grayscale(image, height, width, channels);
    // write_image(image, "images/image1.png");
    stbi_image_free(image);
    free(gray_image);

    return 0;
}
