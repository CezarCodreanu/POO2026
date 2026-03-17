#include "Sort.h"
#include <bits/stdc++.h>

using namespace std;

//generate random
Sort::Sort(int elements_count, int minimum, int maximum)
{
    count = elements_count;
    elements = new int[count];
    for (int i = 0; i < count; i++)
        elements[i] = minimum + (rand() % (maximum - minimum + 1));
}

//initializam lista
Sort::Sort(initializer_list<int> list)
{
    count = (int)list.size();
    elements = new int[count];
    for (int i = 0; i < count; i++)
        elements[i] = list.begin()[i];
}

//vector existent + nr de elemnte 
Sort::Sort(vector<int> vec, int elements_count)
{
    count = elements_count;
    elements = new int[count];
    for (int i = 0; i < count; i++)
        elements[i] = vec[i];
}

//sortare in functie de ...
Sort::Sort(int elements_count, ...)
{
    count    = elements_count;
    elements = new int[count];

    va_list args;
    va_start(args, elements_count);
    for (int i = 0; i < count; i++)
        elements[i] = va_arg(args, int);
    va_end(args);
}

//sortare dupa virgula + 1 element final
Sort::Sort(string list)
{
    int virg = (int)std::count(list.begin(), list.end(), ',');
    count    = virg + 1;
    elements = new int[count];

    //folosim stringstream, chit ca e altceva decat char
    stringstream ss(list);
    string token;
    int idx = 0;

    while (getline(ss, token, ','))
        elements[idx++] = stoi(token);
}

// destruct
Sort::~Sort()
{
    delete[] elements;
}

void Sort::BubbleSort(bool ascendent){
    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++){
            bool schimb = ascendent ? (elements[j] > elements[j + 1]) : (elements[j] < elements[j + 1]);
            if (schimb)
                swap(elements[j], elements[j + 1]);
        }
}

void Sort::InsertSort(bool ascendent){
    for (int i = 1; i < count; i++){
        int key = elements[i];
        int j   = i - 1;
        while (j >= 0 && (ascendent ? elements[j] > key : elements[j] < key)){
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = key;
    }
}

int Sort::Partition(int* arr, int low, int high, bool ascendent){
    int pivot = arr[high];
    int i     = low - 1;
    for (int j = low; j < high; j++){
        bool condition = ascendent ? (arr[j] <= pivot) : (arr[j] >= pivot);
        if (condition){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Sort::QuickSortHelper(int* arr, int low, int high, bool ascendent){
    if (low < high){
        int pi = Partition(arr, low, high, ascendent);
        QuickSortHelper(arr, low,    pi - 1, ascendent);
        QuickSortHelper(arr, pi + 1, high,   ascendent);
    }
}

void Sort::QuickSort(bool ascendent)
{
    QuickSortHelper(elements, 0, count-1, ascendent);
}

void Sort::Print()
{
    printf("[ ");
    for (int i = 0; i < count; i++)
        printf("%d ", elements[i]);
    printf("]\n");
}

int Sort::GetElementsCount()
{
    return count;
}

int Sort::GetElementFromIndex(int index)
{
    return elements[index];
}