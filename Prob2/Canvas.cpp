#include <bits/stdc++.h>
#include "Canvas.h"

using namespace std;

Canvas::Canvas(int width, int height){
    matrix = new char*[height];
    for(int i=0; i < height; i++){
        matrix[i] = new char[width];
    }
    Clear();
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch){
    //punctul de start / stop
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    //pentru directia liniei
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int eroare = dx + dy;
}