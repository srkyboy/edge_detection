#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <stdint.h>
#include <stddef.h> 
#include <math.h>

#include "lib/utils.h"
typedef struct {
    int width;
    int height;
    int channels;
    size_t size;
    uint8_t* data;
} Image;

void image_load(Image* image, const char* const path);
void image_save_png(const Image* image, const char* const path);
void image_to_grayscale(const Image* image, Image* gray_image, const char* const path_to_save);
void image_free(Image* stbi_image, Image* image_free);

#endif