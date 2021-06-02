# About
Load image, convert to grayscale and save.

# Used libs
https://github.com/nothings/stb/blob/master/LICENSE
# Build with gcc
gcc main.c image.c -lm -o main

# Build for debug mode with gcc
gdb ./main
gcc main.c image.c -g -lm -o main 

# Build with bazel
bazel build //src/main:main

# Run
./main images/image.png images/

# Run memory check
valgrind --leak-check=full ./main