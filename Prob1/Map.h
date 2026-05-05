#include <iostream>
#include <cstring>
using namespace std;

template <typename K, typename V>
class Map {
private:
    struct Entry {
        K key;
        V value;
    };

    Entry* data;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        Entry* newData = new Entry[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

    int findIndex(const K& key) const {
        for (int i = 0; i < size; i++) {
            if (data[i].key == key)
                return i;
        }
        return -1;
    }

public:
    Map() {
        capacity = 10;
        size = 0;
        data = new Entry[capacity];
    }

    ~Map() {
        delete[] data;
    }

    V& operator[](const K& key) {
        int idx = findIndex(key);
        if (idx != -1)
            return data[idx].value;

        if (size == capacity)
            resize();

        data[size].key = key;
        data[size].value = V(); // default
        size++;
        return data[size - 1].value;
    }

    void Set(const K& key, const V& value) {
        (*this)[key] = value;
    }

    bool Get(const K& key, V& value) const {
        int idx = findIndex(key);
        if (idx == -1)
            return false;
        value = data[idx].value;
        return true;
    }

    int Count() const {
        return size;
    }

    void Clear() {
        size = 0;
    }

    bool Delete(const K& key) {
        int idx = findIndex(key);
        if (idx == -1)
            return false;

        data[idx] = data[size - 1];
        size--;
        return true;
    }

    bool Includes(const Map<K, V>& map) const {
        for (int i = 0; i < size; i++) {
            if (map.findIndex(data[i].key) == -1)
                return false;
        }
        return true;
    }

    struct Iterator {
        Entry* ptr;
        int index;

        struct Proxy {
            K& key;
            V& value;
            int index;
        };

        Proxy operator*() {
            return {ptr->key, ptr->value, index};
        }

        Iterator& operator++() {
            ptr++;
            index++;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    Iterator begin() { return {data, 0}; }
    Iterator end()   { return {data + size, size}; }
};