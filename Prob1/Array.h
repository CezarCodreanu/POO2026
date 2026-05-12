#pragma once
#include <iostream>
#include <exception>
using namespace std;

class IndexOutOfRangeException : public exception {
public:
    virtual const char* what() const throw() {
        return "Negasit in domeniu";
    }
};

class InvalidCapacityException : public exception {
public:
    virtual const char* what() const throw() {
        return "Capacitate prea mica";
    }
};

class EmptyArrayException : public exception {
public:
    virtual const char* what() const throw() {
        return "Array gol";
    }
};

class ElementNotFoundException : public exception {
public:
    virtual const char* what() const throw() {
        return "Negasit";
    }
};

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T> class Array;

template<class T>
class ArrayIterator {
private:
    const Array<T>* arr;
    int Current;

public:
    ArrayIterator() : arr(nullptr), Current(0) {}

    ArrayIterator(const Array<T>* a, int index) : arr(a), Current(index) {}

    ArrayIterator& operator++() {
        ++Current;
        return *this;
    }

    ArrayIterator& operator--() {
        --Current;
        return *this;
    }

    ArrayIterator& operator=(const ArrayIterator<T>& other) {
        arr = other.arr;
        Current = other.Current;
        return *this;
    }

    bool operator==(const ArrayIterator<T>& other) const {
        return Current == other.Current;
    }

    bool operator!=(const ArrayIterator<T>& other) const {
        return Current != other.Current;
    }
    T& GetElement() const;
};


template<class T>
class Array {
    friend class ArrayIterator<T>;

private:
    T** List;
    int Capacity;  
    int Size; 

    void Resize() {
        int newCap  = (Capacity == 0) ? 1 : Capacity * 2;
        T** newList = new T*[newCap];
        for (int i = 0; i < Size; ++i)
            newList[i] = List[i];
        for (int i = Size; i < newCap; ++i)
            newList[i] = nullptr;
        delete[] List;
        List= newList;
        Capacity = newCap;
    }

    void Clear() {
        for (int i = 0; i < Size; ++i) {
            delete List[i];
            List[i] = nullptr;
        }
        delete[] List;
        List  nullptr;
        Capacity = 0;
        Size = 0;
    }

    void QuickSort(int lo, int hi, int(*cmp)(const T&, const T&)) {
        if (lo >= hi) return;
        T pivot = *List[(lo + hi) / 2];
        int i = lo, j = hi;
        while (i <= j) {
            while (cmp(*List[i], pivot) < 0) ++i;
            while (cmp(*List[j], pivot) > 0) --j;
            if (i <= j) {
                T* tmp = List[i]; List[i] = List[j]; List[j] = tmp;
                ++i; --j;
            }
        }
        QuickSort(lo, j, cmp);
        QuickSort(i, hi, cmp);
    }

    void QuickSortComp(int lo, int hi, Compare* comparator) {
        if (lo >= hi) return;
        T pivot = *List[(lo + hi) / 2];
        int i = lo, j = hi;
        while (i <= j) {
            while (comparator->CompareElements((void*)List[i], (void*)&pivot) < 0) ++i;
            while (comparator->CompareElements((void*)List[j], (void*)&pivot) > 0) --j;
            if (i <= j) {
                T* tmp = List[i]; List[i] = List[j]; List[j] = tmp;
                ++i; --j;
            }
        }
        QuickSortComp(lo, j, comparator);
        QuickSortComp(i, hi, comparator);
    }

public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    explicit Array(int capacity) : List(nullptr), Capacity(0), Size(0) {
        if (capacity <= 0) throw InvalidCapacityException();
        List = new T*[capacity];
        Capacity = capacity;
        for (int i = 0; i < Capacity; ++i)
            List[i] = nullptr;
    }
    //pt copy
    Array(const Array<T>& other) : List(nullptr), Capacity(0), Size(0) {
        if (other.Capacity > 0) {
            List = new T*[other.Capacity];
            Capacity = other.Capacity;
            Size = other.Size;
            for (int i = 0; i < Size; ++i)
                List[i] = new T(*other.List[i]);
            for (int i = Size; i < Capacity; ++i)
                List[i] = nullptr;
        }
    }

    ~Array() { Clear(); }

    T& operator[](int index) {
        if (index < 0 || index >= Size) throw IndexOutOfRangeException();
        return *List[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= Size) throw IndexOutOfRangeException();
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) {
        if (Size == Capacity) Resize();
        List[Size++] = new T(newElem);
        return *this;
    }

    bool operator=(const Array<T>& other) {
        if (this == &other) return true;
        Clear();
        if (other.Capacity > 0) {
            List = new T*[other.Capacity];
            Capacity = other.Capacity;
            Size = other.Size;
            for (int i = 0; i < Size; ++i)
                List[i] = new T(*other.List[i]);
            for (int i = Size; i < Capacity; ++i)
                List[i] = nullptr;
        }
        return true;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size) throw IndexOutOfRangeException();
        if (Size == Capacity) Resize();
        for (int i = Size; i > index; --i)
            List[i] = List[i - 1];
        List[index] = new T(newElem);
        ++Size;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (index < 0 || index > Size) throw IndexOutOfRangeException();
        for (int k = 0; k < otherArray.Size; ++k)
            Insert(index + k, *otherArray.List[k]);
        return *this;
    }

    const Array<T>& Delete(int index) {
        if (Size == 0) throw EmptyArrayException();
        if (index < 0 || index >= Size) throw IndexOutOfRangeException();
        delete List[index];
        for (int i = index; i < Size - 1; ++i)
            List[i] = List[i + 1];
        List[--Size] = nullptr;
        return *this;
    }

    void Sort() {
        Sort([](const T& a, const T& b) -> int {
            if (a < b)  return -1;
            if (a > b)  return  1;
            return 0;
        });
    }

    void Sort(int(*compare)(const T&, const T&)) {
        if (Size > 1) QuickSort(0, Size - 1, compare);
    }

    void Sort(Compare* comparator) {
        if (Size > 1) QuickSortComp(0, Size - 1, comparator);
    }

    int BinarySearch(const T& elem) {
        return BinarySearch(elem, [](const T& a, const T& b) -> int {
            if (a < b)  return -1;
            if (a > b)  return  1;
            return 0;
        });
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        int lo = 0, hi = Size - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int cmp = compare(*List[mid], elem);
            if (cmp == 0) return mid;
            else if (cmp < 0) lo = mid + 1;
            else 
                hi = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator) {
        int lo = 0, hi = Size - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int cmp = comparator->CompareElements((void*)List[mid], (void*)&elem);
            if (cmp == 0) return mid;
            else if (cmp < 0) lo = mid + 1;
            else              
                hi = mid - 1;
        }
        return -1;
    }


    int Find(const T& elem) {
        for (int i = 0; i < Size; ++i)
            if (*List[i] == elem) return i;
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; ++i)
            if (compare(*List[i], elem) == 0) return i;
        return -1;
    }

    int Find(const T& elem, Compare* comparator) {
        for (int i = 0; i < Size; ++i)
            if (comparator->CompareElements((void*)List[i], (void*)&elem) == 0) return i;
        return -1;
    }


    int GetSize() const { return Size; }
    int GetCapacity() const { return Capacity; }


    ArrayIterator<T> GetBeginIterator() const {
        return ArrayIterator<T>(this, 0);
    }

    ArrayIterator<T> GetEndIterator() const {
        return ArrayIterator<T>(this, Size);
    }
};

template<class T>
T& ArrayIterator<T>::GetElement() const {
    if (arr == nullptr || Current < 0 || Current >= arr->Size)
        throw IndexOutOfRangeException();
    return *arr->List[Current];
}