#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include "image.h"
#include "stdio.h"
#include "string.h"

int main (int argc, char* argv[]) {
    if (argc != 3) {
        printf("Missing arguments!");
        exit(1);
    }
    else {
        Image image;
        Image gray_image;

        const char* const original_image_path = argv[1];
        const char* const gray_image_path_to_save = argv[2];

        char* gray_copy = (char*)(malloc(strlen(gray_image_path_to_save)));
        strcpy(gray_copy, gray_image_path_to_save);
        strcat(gray_copy, "gray_image.png");

        image_load(&image, original_image_path);
        image_to_grayscale(&image, &gray_image, gray_copy);

        free(gray_copy);
        free(image.data);
        free(gray_image.data);
    }

    return 0;
}
