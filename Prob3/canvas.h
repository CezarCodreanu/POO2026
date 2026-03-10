#ifndef CANVAS_H
#define CANVAS_H

class Canvas {
private:
    int lines, columns;
    char** matrix;

public:
    Canvas(int lines, int columns);
    ~Canvas(); // decs

    void set_pixel(int x, int y, char value);
    void set_pixels(int count, ...);
    void clear();
    void print() const;
};

#endif