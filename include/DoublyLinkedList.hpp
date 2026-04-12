#pragma once

class DoublyLinkedList
{
private:
    struct Node
    {
        int value{};
        Node *next{};
        Node *prev{};
    };

    int m_size{0};

    Node *head{nullptr};

    Node *tail{nullptr};

public:
    // DoublyLinkedList() = default;
    DoublyLinkedList(int size = 0);
    ~DoublyLinkedList();

    int getSize();

    void addLast(int element);
    void addFirst(int element);
    void add(int index, int element);

    void removeLast();
    void removeFirst();
    void remove(int index);
    int find(int value);

    void clear();
    void print();
};
