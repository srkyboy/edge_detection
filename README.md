# Edge Detection
## About
<p>Load image, convert to grayscale and save.</p>

## Used libs
STB
https://github.com/nothings/stb/blob/master/LICENSE

## Build
### Build with gcc
```gcc main.c image.c -lm -o main```

### Build for debug mode with gcc
```gcc main.c image.c -g -lm -o main```<br/>
```gdb ./main```

### Build with bazel
```bazel build //main:main```

### Clean


## Run
```./main images/image.png images/```

## Run memory check
```valgrind --leak-check=full ./main```