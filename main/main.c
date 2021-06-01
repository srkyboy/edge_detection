#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include "image.h"

int main() {
    Image image;
    Image gray_image;

    const char* const image_path = "images/image.png";
    const char* const gray_image_path_to_save = "images/gray_image.png";

    image_load(&image, image_path);
    image_to_grayscale(&image, &gray_image, gray_image_path_to_save);

    free(image.data);
    free(gray_image.data);

    return 0;
}
