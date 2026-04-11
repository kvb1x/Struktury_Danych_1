#include <iostream>
#include <fstream>
#include <string>
#include <utility.hpp>
#include <DynamicArray.hpp>

int main()
{
    char yourChoice{};

    while (true)
    {
        std::cout << "Wybierz strukture danych ktora chcesz przetestowac\n";
        std::cout << "1 | TABLICA DYNAMICZNA -> wpisz 1\n";
        std::cout << "2 | LISTA JEDNOKIERUNKOWA -> wpisz 2\n";
        std::cout << "3 | LISTA DWUKIERUNKOWA -> wpisz 3\n";
        std::cout << " Jesli chcesz opuscic program -> wpisz q\n";
        std::cout << "TWOJ WYBOR: ";
        std::cin >> yourChoice;
        std::cout << "\n";

        if (yourChoice == 'q')
        {
            std::cout << "Opuszczasz program... \n";
            break;
        }

        switch (yourChoice)
        {

        case '1':
        {
            DynamicArray arr(4);
            char nextChoice1{};
            while (true)
            {
                std::cout << ">| TABLICA DYNAMICZNA |<\n";
                std::cout << "Wybierz metode ktora chcesz przetestowac\n"; // zrobic tak aby kazda opcja miala Wyswietl tablice

                std::cout << ">| Dodawanie \n";
                std::cout << "1 | Dodaj element na koniec\n";
                std::cout << "2 | Dodaj element na poczatku\n";
                std::cout << "3 | Dodaj element w losowe miejse struktury\n";

                std::cout << ">| Usuwanie \n";
                std::cout << "4 | Usun ostatni element\n";
                std::cout << "5 | Usun pierwszy element\n";
                std::cout << "6 | Usun element z losowego miejsca w strukturze\n";

                std::cout << ">| Wyszukiwanie \n";
                std::cout << "7 | Wyszukaj element w strukturze (wygeneruj)\n";
                std::cout << "8 | Wyszukaj element w strukturze (wpisz)\n";

                std::cout << ">| Uzupelnianie struktury \n";
                std::cout << "9 | Zbuduj z pliku\n";
                std::cout << "10 | Zbuduj losowo\n";

                std::cout << "q | Powrot do menu glownego\n";

                std::cout << "TWOJ WYBOR: ";
                std::cin >> nextChoice1;

                if (nextChoice1 == 'q')
                {

                    break;
                }

                switch (nextChoice1)
                {
                case '1': // addLast(int element)
                {
                    int element1{};
                    std::cout << "Podaj wartosc jaka chcesz dodac na koniec tablicy: ";
                    std::cin >> element1;
                    std::cout << "\n";
                    arr.addLast(element1);
                    arr.print();
                    break;
                }
                case '2': // addFirst(int element)
                {
                    int element2{};
                    std::cout << "Podaj wartosc jaka chcesz dodac na poczatek tablicy: ";
                    std::cin >> element2;
                    std::cout << "\n";
                    arr.addFirst(element2);
                    arr.print();
                    break;
                }
                case '3': // add(int index, int element)
                {
                    // <- tu zrobic generacje losowego miejsca tablicy gdzie trzeba znac size tablicy aby nie wyszlo poza zakres
                    int min{0};
                    int max{arr.getSize()};
                    int index1{getRandom(min, max)};
                    int element3{};
                    std::cout << "Podaj wartosc jaka chcesz dodac do losowego miejsca w tablicy: ";
                    std::cin >> element3;
                    std::cout << "\n";
                    arr.add(index1, element3);
                    arr.print();
                    break;
                }
                case '4': // removeLast()
                {
                    arr.removeLast();
                    arr.print();
                    break;
                }
                case '5': // removeFirst()
                {
                    arr.removeFirst();
                    arr.print();
                    break;
                }
                case '6': // remove(int index)
                {
                    int min{0};
                    int max{arr.getSize() - 1};
                    int index2{getRandom(min, max)}; // <- tu zrobic generacje losowego miejsca tablicy gdzie trzeba znac size tablicy aby nie wyszlo poza zakres
                    arr.getSize();
                    arr.remove(index2);
                    arr.print();
                    break;
                }
                case '7': // find(int value)
                {

                    int min{0};
                    int max{100000};
                    int value1{getRandom(min, max)}; // <- tu zrobic generacje value
                    std::cout << "Wylosowana liczba to: " << value1 << '\n';
                    arr.find(value1);
                    arr.print();
                    break;
                }
                case '8': // find(int value)
                {
                    int value2{};
                    std::cout << "Wpisz wartosc jakiej szukasz:";
                    std::cin >> value2;
                    std::cout << '\n';
                    arr.find(value2);
                    arr.print();
                    break;
                }
                case '9': // buduj z pliku (najpierw usunąć poprzednie dane przed wczytaniem nowych)
                {
                    std::string fileName{};
                    std::cout << "Podaj naze pliku z ktorego chcesz zaimportowac dane: \n";
                    std::cin >> fileName;
                    std::cout << "\n";

                    std::ifstream file(fileName); // otwieranie pliku

                    if (file.is_open())
                    {
                        arr.clear();
                        int value{};
                        while (file >> value) // wykonuje sie dopoki nie wczytaja sie wszystkie elementy pliku
                        {
                            arr.addLast(value);
                        }
                        file.close();
                        std::cout << "Wczytano wszystkie dane!\n";
                        arr.print();
                    }
                    else
                    {
                        std::cerr << "Blad odczytu pliku o nazwie" << fileName << "!\n";
                    }

                    break;
                }
                case '10': // buduj losowo (zapytaj o wielkosc)
                {
                    int min{1};
                    int max{100000};
                    int size{};
                    std::cout << "Podaj rozmiar tablicy: ";
                    std::cin >> size;
                    std::cout << "\n";
                    arr.clear();

                    for (int i = 0; i < size; ++i)
                    {
                        arr.addLast(getRandom(min, max));
                    }

                    arr.print();
                    break;
                }

                default:
                    std::cerr << "Tablica nie zawiera takiej metody!";
                    break;
                }
            }

            break;
        }

        case '2':
        {
            char nextChoice2{};
            while (true)
            {
                std::cout << ">| LISTA JEDNOKIERUNKOWA |<\n";
                std::cout << "Wybierz metode ktora chcesz przetestowac\n";

                std::cout << ">| Dodawanie \n";
                std::cout << "1 | Dodaj element na koniec\n";
                std::cout << "2 | Dodaj element na poczatku\n";
                std::cout << "3 | Dodaj element w losowe miejse struktury\n";

                std::cout << ">| Usuwanie \n";
                std::cout << "4 | Usun ostatni element\n";
                std::cout << "5 | Usun pierwszy element\n";
                std::cout << "6 | Usun element z losowego miejsca w strukturze\n";

                std::cout << ">| Wyszukiwanie \n";
                std::cout << "7 | Wyszukaj element w strukturze (wygeneruj)\n";
                std::cout << "8 | Wyszukaj element w strukturze (wpisz)\n";

                std::cout << "q | Powrot do menu glownego\n";

                std::cout << "TWOJ WYBOR: ";
                std::cin >> nextChoice2;

                if (nextChoice2 == 'q')
                {

                    break;
                }

                switch (nextChoice2)
                {
                case '1':
                    /* code */
                    break;
                case '2':
                    /* code */
                    break;
                case '3':
                    /* code */
                    break;

                default:
                    std::cerr << "Lista nie zawiera takiej metody!";
                    break;
                }
            }

            break;
        }
        case '3':
        {
            char nextChoice3{};
            while (true)
            {
                std::cout << ">| LISTA DWUKIERUNKOWA |<\n";
                std::cout << "Wybierz metode ktora chcesz przetestowac\n";

                std::cout << ">| Dodawanie \n";
                std::cout << "1 | Dodaj element na koniec\n";
                std::cout << "2 | Dodaj element na poczatku\n";
                std::cout << "3 | Dodaj element w losowe miejse struktury\n";

                std::cout << ">| Usuwanie \n";
                std::cout << "4 | Usun ostatni element\n";
                std::cout << "5 | Usun pierwszy element\n";
                std::cout << "6 | Usun element z losowego miejsca w strukturze\n";

                std::cout << ">| Wyszukiwanie \n";
                std::cout << "7 | Wyszukaj element w strukturze (wygeneruj)\n";
                std::cout << "8 | Wyszukaj element w strukturze (wpisz)\n";

                std::cout << "q | Powrot do menu glownego\n";

                std::cout << "TWOJ WYBOR: ";
                std::cin >> nextChoice3;

                if (nextChoice3 == 'q')
                {

                    break;
                }

                switch (nextChoice3)
                {
                case '1':
                    /* code */
                    break;
                case '2':
                    /* code */
                    break;
                case '3':
                    /* code */
                    break;

                default:
                    std::cerr << "Lista nie zawiera takiej metody!";
                    break;
                }
            }

            break;
        }
        default:
        {
            std::cerr << "Nieznana opcja. Wybierz 1, 2, 3 lub q.\n";
            break;
        }
        }
    }

    // std::cout << "utworzenei tablicy!\n";
    // DynamicArray arr(4);
    // arr.print();

    // std::cout << "TEST #1 | dodawanie na koniec tablicy!\n";
    // arr.addLast(10);
    // arr.addLast(20);
    // arr.addLast(30);
    // arr.print();

    // std::cout << "TEST #2 | przekroczenie pojemnosci oraz zwiekszernie rozmiaru tablicy\n";
    // arr.addLast(40);
    // arr.addLast(50);
    // arr.print();

    // std::cout << "TEST #3 | dodanie na poczatek\n";
    // arr.addFirst(1);
    // arr.print();

    // std::cout << "TEST #4 | dodanie na srodek\n";
    // arr.add(2, 2);
    // arr.print();

    // std::cout << "TEST #5 | szukanie tego samego elementu\n";
    // arr.find(2);
    // arr.find(12);

    // std::cout << "TEST #5 | kasacja\n";
    // arr.removeFirst();
    // arr.removeLast();
    // arr.remove(1);
    // arr.print();

    return 0;
}
