#include <iostream>
#include <fstream>
#include <string>
#include "utility.hpp"
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include "DoublyLinkedList.hpp"

int main()
{
    char yourChoice{};

    while (true)
    {
        std::cout << "=== MENU GLOWNE ===\n";
        std::cout << "Wybierz strukture danych ktora chcesz przetestowac\n";
        std::cout << "1 | TABLICA DYNAMICZNA -> wpisz 1\n";
        std::cout << "2 | LISTA JEDNOKIERUNKOWA -> wpisz 2\n";
        std::cout << "3 | LISTA DWUKIERUNKOWA -> wpisz 3\n";
        std::cout << "4 | PRZEPROWADZ BADANIA  -> wpisz 4\n";
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

                std::cout << ">| Uzupelnianie struktury \n";
                std::cout << "9 | Zbuduj z pliku\n";
                std::cout << "0 | Zbuduj losowo\n";

                std::cout << "q | Powrot do menu glownego\n";

                std::cout << "TWOJ WYBOR: ";
                std::cin >> nextChoice1;

                if (nextChoice1 == 'q')
                    break;

                switch (nextChoice1)
                {
                case '1':
                {
                    int element1{};
                    std::cout << "Podaj wartosc jaka chcesz dodac na koniec tablicy: ";
                    std::cin >> element1;
                    std::cout << "\n";
                    arr.addLast(element1);
                    arr.print();
                    break;
                }
                case '2':
                {
                    int element2{};
                    std::cout << "Podaj wartosc jaka chcesz dodac na poczatek tablicy: ";
                    std::cin >> element2;
                    std::cout << "\n";
                    arr.addFirst(element2);
                    arr.print();
                    break;
                }
                case '3':
                {
                    int min{0};
                    int max{arr.getSize()};
                    int index1{getRandom(min, max)};
                    int element3{};
                    std::cout << "Podaj wartosc jaka chcesz dodac do losowego miejsca (" << index1 << ") w tablicy: ";
                    std::cin >> element3;
                    std::cout << "\n";
                    arr.add(index1, element3);
                    arr.print();
                    break;
                }
                case '4':
                {
                    arr.removeLast();
                    arr.print();
                    break;
                }
                case '5':
                {
                    arr.removeFirst();
                    arr.print();
                    break;
                }
                case '6':
                {
                    if (arr.getSize() > 0)
                    {
                        int min{0};
                        int max{arr.getSize() - 1};
                        int index2{getRandom(min, max)};
                        std::cout << "Usuwam z losowego indeksu: " << index2 << "\n";
                        arr.remove(index2);
                    }
                    else
                    {
                        std::cout << "Tablica jest pusta!\n";
                    }
                    arr.print();
                    break;
                }
                case '7':
                {
                    int min{0};
                    int max{100000};
                    int value1{getRandom(min, max)};
                    std::cout << "Wylosowana liczba to: " << value1 << '\n';
                    arr.find(value1);
                    break;
                }
                case '8':
                {
                    int value2{};
                    std::cout << "Wpisz wartosc jakiej szukasz: ";
                    std::cin >> value2;
                    std::cout << '\n';
                    arr.find(value2);
                    break;
                }
                case '9':
                {
                    std::string fileName{};
                    std::cout << "Podaj naze pliku z ktorego chcesz zaimportowac dane: \n";
                    std::cin >> fileName;
                    std::cout << "\n";

                    std::ifstream file(fileName);

                    if (file.is_open())
                    {
                        arr.clear();
                        int value{};
                        while (file >> value)
                            arr.addLast(value);
                        file.close();
                        std::cout << "Wczytano wszystkie dane!\n";
                        arr.print();
                    }
                    else
                    {
                        std::cerr << "Blad odczytu pliku o nazwie " << fileName << "!\n";
                    }
                    break;
                }
                case '0':
                {
                    int min{1};
                    int max{100000};
                    int size{};
                    std::cout << "Podaj rozmiar tablicy: ";
                    std::cin >> size;
                    std::cout << "\n";
                    arr.clear();

                    for (int i = 0; i < size; ++i)
                        arr.addLast(getRandom(min, max));
                    arr.print();
                    break;
                }
                default:
                    std::cerr << "Tablica nie zawiera takiej metody!\n";
                    break;
                }
            }
            break;
        }

        case '2':
        {
            LinkedList sll;
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
                std::cout << ">| Uzupelnianie struktury \n";
                std::cout << "9 | Zbuduj z pliku\n";
                std::cout << "0 | Zbuduj losowo\n";
                std::cout << "q | Powrot do menu glownego\n";
                std::cout << "TWOJ WYBOR: ";
                std::cin >> nextChoice2;

                if (nextChoice2 == 'q')
                    break;

                switch (nextChoice2)
                {
                case '1':
                {
                    int element1{};
                    std::cout << "Podaj wartosc: ";
                    std::cin >> element1;
                    sll.addLast(element1);
                    sll.print();
                    break;
                }
                case '2':
                {
                    int element2{};
                    std::cout << "Podaj wartosc: ";
                    std::cin >> element2;
                    sll.addFirst(element2);
                    sll.print();
                    break;
                }
                case '3':
                {
                    int min{0}, max{sll.getSize()};
                    int index1{getRandom(min, max)};
                    int element3{};
                    std::cout << "Podaj wartosc do dodania na indeksie " << index1 << ": ";
                    std::cin >> element3;
                    sll.add(index1, element3);
                    sll.print();
                    break;
                }
                case '4':
                    sll.removeLast();
                    sll.print();
                    break;
                case '5':
                    sll.removeFirst();
                    sll.print();
                    break;
                case '6':
                {
                    if (sll.getSize() > 0)
                    {
                        int index2{getRandom(0, sll.getSize() - 1)};
                        std::cout << "Usuwam z losowego indeksu: " << index2 << "\n";
                        sll.remove(index2);
                    }
                    else
                    {
                        std::cout << "Lista jest pusta!\n";
                    }
                    sll.print();
                    break;
                }
                case '7':
                {
                    int value1{getRandom(0, 100000)};
                    std::cout << "Szukam wylosowanej liczby: " << value1 << '\n';
                    sll.find(value1);
                    break;
                }
                case '8':
                {
                    int value2{};
                    std::cout << "Wpisz wartosc jakiej szukasz: ";
                    std::cin >> value2;
                    sll.find(value2);
                    break;
                }
                case '9':
                {
                    std::string fileName{};
                    std::cout << "Podaj naze pliku: ";
                    std::cin >> fileName;
                    std::ifstream file(fileName);
                    if (file.is_open())
                    {
                        sll.clear();
                        int value{};
                        while (file >> value)
                            sll.addLast(value);
                        file.close();
                        std::cout << "Wczytano dane!\n";
                        sll.print();
                    }
                    else
                    {
                        std::cerr << "Blad odczytu!\n";
                    }
                    break;
                }
                case '0':
                {
                    int size{};
                    std::cout << "Podaj rozmiar listy: ";
                    std::cin >> size;
                    sll.clear();
                    for (int i = 0; i < size; ++i)
                        sll.addLast(getRandom(1, 100000));
                    sll.print();
                    break;
                }
                default:
                    std::cerr << "Lista nie zawiera takiej metody!\n";
                    break;
                }
            }
            break;
        }

        case '3':
        {
            DoublyLinkedList dll;
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
                std::cout << ">| Uzupelnianie struktury \n";
                std::cout << "9 | Zbuduj z pliku\n";
                std::cout << "0 | Zbuduj losowo\n";
                std::cout << "q | Powrot do menu glownego\n";
                std::cout << "TWOJ WYBOR: ";
                std::cin >> nextChoice3;

                if (nextChoice3 == 'q')
                    break;

                switch (nextChoice3)
                {
                case '1':
                {
                    int element1{};
                    std::cout << "Podaj wartosc: ";
                    std::cin >> element1;
                    dll.addLast(element1);
                    dll.print();
                    break;
                }
                case '2':
                {
                    int element2{};
                    std::cout << "Podaj wartosc: ";
                    std::cin >> element2;
                    dll.addFirst(element2);
                    dll.print();
                    break;
                }
                case '3':
                {
                    int index1{getRandom(0, dll.getSize())};
                    int element3{};
                    std::cout << "Podaj wartosc do dodania na indeksie " << index1 << ": ";
                    std::cin >> element3;
                    dll.add(index1, element3);
                    dll.print();
                    break;
                }
                case '4':
                    dll.removeLast();
                    dll.print();
                    break;
                case '5':
                    dll.removeFirst();
                    dll.print();
                    break;
                case '6':
                {
                    if (dll.getSize() > 0)
                    {
                        int index2{getRandom(0, dll.getSize() - 1)};
                        std::cout << "Usuwam z losowego indeksu: " << index2 << "\n";
                        dll.remove(index2);
                    }
                    else
                    {
                        std::cout << "Lista jest pusta!\n";
                    }
                    dll.print();
                    break;
                }
                case '7':
                {
                    int value1{getRandom(0, 100000)};
                    std::cout << "Szukam wylosowanej liczby: " << value1 << '\n';
                    dll.find(value1);
                    break;
                }
                case '8':
                {
                    int value2{};
                    std::cout << "Wpisz wartosc jakiej szukasz: ";
                    std::cin >> value2;
                    dll.find(value2);
                    break;
                }
                case '9':
                {
                    std::string fileName{};
                    std::cout << "Podaj naze pliku: ";
                    std::cin >> fileName;
                    std::ifstream file(fileName);
                    if (file.is_open())
                    {
                        dll.clear();
                        int value{};
                        while (file >> value)
                            dll.addLast(value);
                        file.close();
                        std::cout << "Wczytano dane!\n";
                        dll.print();
                    }
                    else
                    {
                        std::cerr << "Blad odczytu!\n";
                    }
                    break;
                }
                case '0':
                {
                    int size{};
                    std::cout << "Podaj rozmiar listy: ";
                    std::cin >> size;
                    dll.clear();
                    for (int i = 0; i < size; ++i)
                        dll.addLast(getRandom(1, 100000));
                    dll.print();
                    break;
                }
                default:
                    std::cerr << "Lista nie zawiera takiej metody!\n";
                    break;
                }
            }
            break;
        }

        case '4':
        {
            std::cout << "\n=== START BADAN ===\n";

            // Wyciszanie konsoli na czas badan
            std::streambuf *oldCoutStreamBuf = std::cout.rdbuf();
            std::streambuf *oldCerrStreamBuf = std::cerr.rdbuf();
            std::ofstream nullStream;
            std::cout.rdbuf(nullStream.rdbuf());
            std::cerr.rdbuf(nullStream.rdbuf());

            int startSize = 5000;
            int maxSize = 100000;
            int step = 5000;
            int probes = 50;

            std::cout << "Parametry: Rozmiary od " << startSize << " do " << maxSize << "(krok" << step << "), " << probes << "prob dla kazdego pomiaru.\n";
            Timer timer;

            for (int size = startSize; size <= maxSize; size += step)
            {
                // Czasomierze Tablica
                long long t_DA_addF = 0, t_DA_addL = 0, t_DA_addR = 0;
                long long t_DA_remF = 0, t_DA_remL = 0, t_DA_remR = 0;
                long long t_DA_find = 0;

                // Czasomierze Lista 1kierunkowa
                long long t_SLL_addF = 0, t_SLL_addL = 0, t_SLL_addR = 0;
                long long t_SLL_remF = 0, t_SLL_remL = 0, t_SLL_remR = 0;
                long long t_SLL_find = 0;

                // Czasomierze Lista 2kierunkowa
                long long t_DLL_addF = 0, t_DLL_addL = 0, t_DLL_addR = 0;
                long long t_DLL_remF = 0, t_DLL_remL = 0, t_DLL_remR = 0;
                long long t_DLL_find = 0;

                for (int p = 0; p < probes; ++p)
                {
                    // twory wspolne dane
                    //  Generujemy tablicę N elementów, którą wczytamy do wszystkich 3 struktur
                    int *commonData = new int[size];
                    for (int i = 0; i < size; ++i)
                    {
                        commonData[i] = getRandom(1, 100000);
                    }

                    int valToFind = getRandom(1, 100000);
                    int valToAddF = getRandom(1, 100000);
                    int valToAddL = getRandom(1, 100000);
                    int valToAddR = getRandom(1, 100000);

                    int randIdxRem = getRandom(0, size - 1);
                    int randIdxAdd = getRandom(0, size - 1); // Indeks do dodania po usunięciu elementu

                    // TABLICA DYNAMICZNA
                    DynamicArray arr;
                    for (int i = 0; i < size; ++i)
                        arr.addLast(commonData[i]);

                    timer.start();
                    arr.find(valToFind);
                    t_DA_find += timer.stop();
                    timer.start();
                    arr.removeFirst();
                    t_DA_remF += timer.stop();
                    timer.start();
                    arr.addFirst(valToAddF);
                    t_DA_addF += timer.stop();
                    timer.start();
                    arr.removeLast();
                    t_DA_remL += timer.stop();
                    timer.start();
                    arr.addLast(valToAddL);
                    t_DA_addL += timer.stop();
                    timer.start();
                    arr.remove(randIdxRem);
                    t_DA_remR += timer.stop();
                    timer.start();
                    arr.add(randIdxAdd, valToAddR);
                    t_DA_addR += timer.stop();

                    //  LISTA JEDNOKIERUNKOWA
                    LinkedList sll;
                    for (int i = 0; i < size; ++i)
                        sll.addLast(commonData[i]);

                    timer.start();
                    sll.find(valToFind);
                    t_SLL_find += timer.stop();
                    timer.start();
                    sll.removeFirst();
                    t_SLL_remF += timer.stop();
                    timer.start();
                    sll.addFirst(valToAddF);
                    t_SLL_addF += timer.stop();
                    timer.start();
                    sll.removeLast();
                    t_SLL_remL += timer.stop();
                    timer.start();
                    sll.addLast(valToAddL);
                    t_SLL_addL += timer.stop();
                    timer.start();
                    sll.remove(randIdxRem);
                    t_SLL_remR += timer.stop();
                    timer.start();
                    sll.add(randIdxAdd, valToAddR);
                    t_SLL_addR += timer.stop();

                    //  LISTA DWUKIERUNKOWA
                    DoublyLinkedList dll;
                    for (int i = 0; i < size; ++i)
                        dll.addLast(commonData[i]);

                    timer.start();
                    dll.find(valToFind);
                    t_DLL_find += timer.stop();
                    timer.start();
                    dll.removeFirst();
                    t_DLL_remF += timer.stop();
                    timer.start();
                    dll.addFirst(valToAddF);
                    t_DLL_addF += timer.stop();
                    timer.start();
                    dll.removeLast();
                    t_DLL_remL += timer.stop();
                    timer.start();
                    dll.addLast(valToAddL);
                    t_DLL_addL += timer.stop();
                    timer.start();
                    dll.remove(randIdxRem);
                    t_DLL_remR += timer.stop();
                    timer.start();
                    dll.add(randIdxAdd, valToAddR);
                    t_DLL_addR += timer.stop();

                    // Zwalnianie tymczasowej pamięci po zakończonej próbie
                    delete[] commonData;
                }

                // Zapis DA
                saveResult("DA_addFirst.csv", size, t_DA_addF / probes);
                saveResult("DA_addLast.csv", size, t_DA_addL / probes);
                saveResult("DA_addRandom.csv", size, t_DA_addR / probes);
                saveResult("DA_removeFirst.csv", size, t_DA_remF / probes);
                saveResult("DA_removeLast.csv", size, t_DA_remL / probes);
                saveResult("DA_removeRandom.csv", size, t_DA_remR / probes);
                saveResult("DA_find.csv", size, t_DA_find / probes);

                // Zapis SLL
                saveResult("SLL_addFirst.csv", size, t_SLL_addF / probes);
                saveResult("SLL_addLast.csv", size, t_SLL_addL / probes);
                saveResult("SLL_addRandom.csv", size, t_SLL_addR / probes);
                saveResult("SLL_removeFirst.csv", size, t_SLL_remF / probes);
                saveResult("SLL_removeLast.csv", size, t_SLL_remL / probes);
                saveResult("SLL_removeRandom.csv", size, t_SLL_remR / probes);
                saveResult("SLL_find.csv", size, t_SLL_find / probes);

                // Zapis DLL
                saveResult("DLL_addFirst.csv", size, t_DLL_addF / probes);
                saveResult("DLL_addLast.csv", size, t_DLL_addL / probes);
                saveResult("DLL_addRandom.csv", size, t_DLL_addR / probes);
                saveResult("DLL_removeFirst.csv", size, t_DLL_remF / probes);
                saveResult("DLL_removeLast.csv", size, t_DLL_remL / probes);
                saveResult("DLL_removeRandom.csv", size, t_DLL_remR / probes);
                saveResult("DLL_find.csv", size, t_DLL_find / probes);
            }

            // Odwieszanie konsoli
            std::cout.rdbuf(oldCoutStreamBuf);
            std::cerr.rdbuf(oldCerrStreamBuf);

            std::cout << "\nBadania ukonczone! Przeanalizowano wszystkie wymagane operacje.\n";
            std::cout << "Wygenerowano 21 plikow CSV.\n\n";
            break;
        }

        default:
        {
            std::cerr << "Nieznana opcja. Wybierz 1, 2, 3, 4 lub q.\n";
            break;
        }
        }
    }

    return 0;
}
