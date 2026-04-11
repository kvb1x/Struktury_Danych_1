#pragma once
#include <iostream>

class DynamicArray
{
private:
    int m_size{0};
    int m_capacity{0};
    int *m_array{nullptr};

public:
    DynamicArray() = default;
    DynamicArray(int capacity = 4);
    ~DynamicArray();

    int getSize();

    void addLast(int element);
    void addFirst(int element);
    void add(int index, int element);

    void removeLast();
    void removeFirst();
    void remove(int index);
    int find(int value);

    void resize();
    void shrink();
    void print();
};
