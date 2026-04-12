#include "DoublyLinkedList.hpp"
#include <iostream>

DoublyLinkedList::DoublyLinkedList(int size) : m_size{0} {};
DoublyLinkedList::~DoublyLinkedList() {};

int DoublyLinkedList::getSize() { return m_size; }

void DoublyLinkedList::addLast(int element)
{

    Node *newNode = new Node; // tworzymy nowy wezel w pamieci
    newNode->value = element; // pakujemy wartosc do nowego wezla
    newNode->next = nullptr;  // nastepny to null bo dodajemy na sam koniec
    newNode->prev = nullptr;  // poprzedni na razie null

    if (head == nullptr) // sprawdzienie czy lista jest pusta
    {
        head = newNode; // jesli tak to zmieniamy nowy obiekt na startowy
        tail = newNode; // tail tez do tego przypisujemy bo to jedyno node w liscie
    }
    else
    {
        tail->next = newNode; // ustawiamy tail na nowy node jesli lista nie jest pusta
        newNode->prev = tail; // spinamy w tyl nowy wezel z aktualnym koncem
        tail = newNode;       // teraz tail jest nowym koncem listy
    }
    ++m_size;
};
void DoublyLinkedList::addFirst(int element)
{
    Node *newNode = new Node; // tworzymy nowy wezel
    newNode->value = element; // pakujemy wartosc do nowego wezla
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) // sprawdzienie czy lista jest pusta
    {
        head = newNode; // jesli tak to zmieniamy nowy obiekt na startowy
        tail = newNode; // tail tez do tego przypisujemy bo to jedyno node w liscie
    }
    else
    {
        newNode->next = head; // ustawiamy stary head jako nastepnik nowego wezla
        head->prev = newNode; // stary head musi wskazywac do tylu na nowy element
        head = newNode;       // teraz head jest poczatkiem listy
    }
    ++m_size;
};
void DoublyLinkedList::add(int index, int element)
{
    if (index < 0 || index > m_size)
    {
        std::cout << "Nieprawidlowy index!\n";
        return;
    }
    else if (head == nullptr) // sprawdzienie czy lista jest pusta
    {
        Node *newNode = new Node;
        newNode->value = element; // pakujemy wartosc do nowego wezla
        newNode->next = nullptr;
        newNode->prev = nullptr;

        head = newNode; // jesli tak to zmieniamy nowy obiekt na startowy
        tail = newNode; // tail tez do tego przypisujemy bo to jedyno node w liscie
    }
    else if (index == 0)
    {
        addFirst(element); // uzywamy gotowej funkcji jesli to poczatek
        return;
    }
    else if (index == m_size)
    {
        addLast(element); // uzywamy gotowej funkcji jesli to koniec
        return;
    }
    else
    {
        Node *newNode = new Node; // tworzymy nowy wezel
        Node *current = head;     // tworzymy wskaznik na aktualny node zeby zaczac szukac

        for (int i = 0; i < index - 1; ++i) // szukamy wezla o podanym indexie -1 (czyli poprzedniego od zadanego)
        {
            current = current->next; // przechodzimy na kolejny wezel w liscie
        }
        newNode->value = element;      // pakujemy wartosc
        newNode->next = current->next; // przyczepiamy node z prawej strony nowego wezla
        newNode->prev = current;       // podpinamy lewa strone nowego noda do currenta

        current->next->prev = newNode; // podpinamy sasiada z prawej zeby wskazywal w tyl na nowy node
        current->next = newNode;       // przyczepiamy stary node zeby wskazywal w przod na nowy node
    }

    ++m_size;
};

void DoublyLinkedList::removeLast()
{

    if (head == nullptr) // sprawdzienie czy lista jest pusta
    {
        std::cout << "Lista jest pusta!\n";
        return;
    }
    else if (tail == head) // tu sprawdzamy czy lista sklada sie tylko z jednego wezla
    {

        delete tail;    // usuwamy jedyny wezel
        tail = nullptr; // resetujemy tail
        head = nullptr; // resetujemy head
    }
    else
    {
        Node *current = tail->prev; // wykorzystujemy prev by uniknac przechodzenia pętla calej listy i od razu mamy przedostatni

        delete tail;    // usuwamy stary node z ostatniego miejsca listy
        tail = current; // ustawiamy przedostatni element jako nowy tail

        tail->next = nullptr; // ustawiamy nowy ostatni node zeby wskazywal w przod na null
    }
    --m_size;
};

void DoublyLinkedList::removeFirst()
{

    if (head == nullptr) // sprawdzienie czy lista jest pusta
    {
        std::cout << "Lista jest pusta!\n";
        return;
    }
    else
    {
        Node *temp = head; // tymczasowo przechowujemy aktualny head by go potem usunac
        head = head->next; // przesuwamy head na nastepny element w liscie

        delete temp;         // zwalniamy pamiec starego poczatku
        if (head == nullptr) // sprawdzamy czy lista zrobila sie pusta po usunieciu
        {
            tail = nullptr; // jak pusta to czyscimy tez tail
        }
        else
        {
            head->prev = nullptr; // czyscimy dowiazanie w tyl dla nowego poczatku listy
        }
    }

    --m_size;
};
void DoublyLinkedList::remove(int index)
{
    if (index < 0 || index > m_size - 1) // przy usuwaniu musi byc size -1 bo liczymy od zera
    {
        std::cout << "Nieprawidlowy index!\n";
        return;
    }
    else if (head == nullptr) // sprawdzienie czy lista jest pusta
    {

        std::cout << "Lista jest pusta!\n";
        return;
    }
    else if (index == 0)
    {
        removeFirst(); // gotowa funkcja dla pierwszego elementu
        return;
    }
    else if (index == m_size - 1) // tu tak samo przy usuwaniu size -1 dla ostatniego
    {
        removeLast(); // gotowa funkcja dla ostatniego elementu
        return;
    }
    else
    {

        Node *current = head; // tworzymy wskaznik na aktualny node

        for (int i = 0; i < index - 1; ++i) // szukamy wezla o podanym indexie -1 (czyli poprzedniego od zadanego)
        {
            current = current->next; // idziemy w przod listy
        }

        Node *temp = current->next;          // przechowanie tymczasowe wezla do usuniecia
        current->next = current->next->next; // lewy wezel musi przeskoczyc usuwany i wskazac na ten za nim
        current->next->prev = current;       // prawy wezel musi wskazac w tyl na ten z lewej (ominiety element)
        delete temp;                         // zwalniamy z pamieci ominiety wezel
    }

    --m_size;
};
int DoublyLinkedList::find(int value)
{
    if (head == nullptr) // sprawdzienie czy lista jest pusta
    {
        std::cout << "Lista jest pusta!\n";
        return -1;
    }
    else
    {
        Node *current = head;      // tworzymy wskaznik na aktualny node
        int counter{0};            // licznik do sprawdzania indexu
        while (current != nullptr) // przechodzimy przez wszystkie nody az do "pustego"
        {

            if (current->value == value) // jak trafimy na szukana wartosc
            {
                std::cout << "twoja wartosc znajduje sie pod indexem: " << counter << '\n';
                return counter; // zwracamy gdzie ja znalezlismy
            }
            current = current->next; // skaczemy na kolejny wezel
            ++counter;               // zwiekszamy licznik indexu
        }
    }
    std::cerr << "Brak takiej warosci w liscie!\n";
    return -1;
};

void DoublyLinkedList::clear()
{

    if (head == nullptr) // sprawdzienie czy lista jest pusta
    {

        std::cout << "Lista jest pusta!\n";
        return;
    }
    else
    {

        while (head != nullptr) // przechodzimy przez wszystkie nody az do "pustego"
        {

            removeFirst(); // po kolei usuwamy wszystko od poczatku az bedzie czysto
        }
    }
};

void DoublyLinkedList::print()
{

    if (head == nullptr) // sprawdzienie czy lista jest pusta
    {
        std::cout << "Lista jest pusta!\n";
        return;
    }
    else
    {
        Node *current = head;      // tworzymy wskaznik na aktualny node
        while (current != nullptr) // przechodzimy przez wszystkie nody az do konca
        {
            std::cout << "Wartosc wezla to " << current->value << '\n'; // wypisujemy to co w srodku wezla
            current = current->next;                                    // idziemy do nastepnego
        }
    }
};
