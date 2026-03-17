#pragma once
#include <vector>
#include <string>
#include <initializer_list>
#include <cstdarg>

using namespace std;

class Sort
{
private:
    int* elements;
    int  count;

    int  Partition(int* arr, int low, int high, bool ascendent);
    void QuickSortHelper(int* arr, int low, int high, bool ascendent);

public:
    Sort(int elements_count, int minimum, int maximum);
    Sort(initializer_list<int> list);
    Sort(vector<int> vec, int elements_count);
    Sort(int elements_count, ...);
    Sort(string list);

    ~Sort();

    void BubbleSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void InsertSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};