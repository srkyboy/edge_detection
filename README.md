# About
Load image, convert to grayscale and save.

# Used libs
https://github.com/nothings/stb/blob/master/LICENSE
# Build
gcc main.c image.c -lm -o main

# Run
./main

# Build for debug mode
gdb ./main
gcc main.c image.c -g -lm -o main 

# Build with bazel
bazel build //src/main:main

# Run memory check
valgrind --leak-check=full ./main