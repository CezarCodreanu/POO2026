#pragma once

class Sort
{
private:
    int* elements;
    int elements_count;

public:
    Sort(int elements_count, int minimum, int maximum);

    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};