#include "image.h"

void image_load(Image* image, const char* const path) {
    image->data = stbi_load(path, &image->width, &image->height, &image->channels, 0);
    if (image->data == NULL) {
        printf("Error while loading the an image!\n");
        exit(1);
    }
    printf("Loaded image with a width of %d, a height of %d and %d channels.\n", image->width, image->height, image->channels);
}

void image_save_png(const Image* image, const char* const path) {
    if (image->data == NULL) {
        printf("Unable to save image.\n");
        exit(1);
    }
    stbi_write_png(path, image->width, image->height, 1, image->data, image->width * image->channels);
}

void image_to_grayscale(const Image* image, Image* gray_image, const char* const path_to_save) {
    gray_image->width = image->width;
    gray_image->height = image->height;
    gray_image->channels = 1;

    gray_image->data = malloc(image->width * image->height);

    if (gray_image->data == NULL) {
        printf("Unable to allocate memory for grayscale image.\n");
        exit(1);
    }

    int i = 0;

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width * image->channels; x += image->channels) {
            int row_offset = y * image->width * image->channels;
            uint8_t red = image->data[row_offset + x];
            uint8_t green = image->data[row_offset + x + 1];
            uint8_t blue = image->data[row_offset + x + 2];

            gray_image->data[i++] = (red + green + blue) / 3;
            // gray_image[i++] = (blue * 0.45 + green * 0.45 + red * 0.1);
        }
    }

    // for (int h = 0; h < image_size; h += channels) {
    //     gray_image[i++] = (image[h] + image[h+1] + image[h+2]) / 3;
    // }

    // Save gray image
    image_save_png(gray_image, path_to_save);
}
