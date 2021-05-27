# Build
gcc main.c image.c -lm -o main

# Run
./main

# Build for debug mode
gdb ./main
gcc main.c image.c -g -lm -o main 

# Run memory check
valgrind --leak-check=full ./main