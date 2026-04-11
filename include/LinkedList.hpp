class LinkedList
{
private:
public:
    LinkedList() = default;
    LinkedList(int capacity = 4);
    ~LinkedList();

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
    void clear();
    void print();
};
