#include "Canvas.h"

int main() {
    Canvas canvas(50, 20);

    canvas.DrawRect(2, 2, 10, 6, '#');

    canvas.FillRect(15, 2, 25, 6, '*');

    canvas.DrawCircle(40, 5, 4, 'O');

    canvas.FillCircle(10, 15, 3, '@');

    canvas.DrawLine(20, 10, 45, 18, '+');

    canvas.SetPoint(48, 2, 'X');
    canvas.Print();

    //canvas.Clear();
    //canvas.Print();

    return 0;
}