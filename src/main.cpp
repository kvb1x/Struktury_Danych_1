#include <iostream>
#include <DynamicArray.hpp>

int main()
{
    std::cout << "utworzenei tablicy!\n";
    DynamicArray arr(4);
    arr.print();

    std::cout << "TEST #1 | dodawanie na koniec tablicy!\n";
    arr.addLast(10);
    arr.addLast(20);
    arr.addLast(30);
    arr.print();

    std::cout << "TEST #2 | przekroczenie pojemnosci oraz zwiekszernie rozmiaru tablicy\n";
    arr.addLast(40);
    arr.addLast(50);
    arr.print();

    std::cout << "TEST #3 | dodanie na poczatek\n";
    arr.addFirst(1);
    arr.print();

    std::cout << "TEST #4 | dodanie na srodek\n";
    arr.add(2, 2);
    arr.print();

    std::cout << "TEST #5 | szukanie tego samego elementu\n";
    arr.find(2);
    arr.find(12);

    std::cout << "TEST #5 | kasacja\n";
    arr.removeFirst();
    arr.removeLast();
    arr.remove(1);
    arr.print();

    return 0;
}
