#include "Canvas.h"
#include <cstdio>
#include <cstdarg>
Canvas::Canvas(int lines, int columns) {
    Canvas::clear();
    if (lines < 300)
        height = lines;
    if (columns < 300)
        width = columns;
}

void Canvas::set_pixel(int x, int y, char value) {
    if (x < height and y < width)
        drawing[x][y] = value;
}

void Canvas::set_pixels(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        int value = va_arg(args, char);
        Canvas::set_pixel(x, y, value);
    }
    va_end(args);
}

void Canvas::clear() {
    for (int i = 0; i < 300; i++)
        for (int j = 0; j < 300; j++)
            drawing[i][j] = ' ';
    width = 0;
    height = 0;
}

void Canvas::print() const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            printf("%c", drawing[i][j]);
        printf("\n");
    }
}
