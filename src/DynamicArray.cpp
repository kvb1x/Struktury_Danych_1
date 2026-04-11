#include <DynamicArray.hpp>

DynamicArray::DynamicArray(int capacity) : m_size{0}, m_capacity{capacity}, m_array{new int[capacity]} {};
DynamicArray::~DynamicArray() { delete[] m_array; }

int DynamicArray::getSize() { return m_size; }

void DynamicArray::addLast(int element)
{

    if (m_capacity == m_size)
    {
        resize();
    }

    m_array[m_size] = element; // tutaj m_size bo index tablicy od 0 startuje a by dodajemy na miejsce m_size +1 wiec nie potrzeba robic m_array[m_size-1]
    ++m_size;
}

void DynamicArray::addFirst(int element)
{
    if (m_capacity == m_size)
    {
        resize();
    }
    for (int i = m_size; i > 0; --i)
    {
        m_array[i] = m_array[i - 1];
    }

    m_array[0] = element;
    ++m_size;

    // sczyt glupoty |
    //               v
    //  for (int i = 0; i < m_size; ++i)
    //  {
    //      m_array[m_size - i] = m_array[m_size - i - 1]; // [m_size - i] zmienia pozycje co iteracje a [m_size - 1] przypisuje poprzednia wartosc
    //  }
}
void DynamicArray::add(int index, int element)
{
    if (index < 0 || index > m_size)
    {
        std::cerr << "Tablica jest pusta lub index wykracza poza zakres!\n";
        return;
    }
    if (m_capacity == m_size)
    {
        resize();
    }
    for (int i = m_size; i > index; --i)
    {
        m_array[i] = m_array[i - 1];
    }
    m_array[index] = element;
    ++m_size;
}

void DynamicArray::removeLast()
{

    if (m_size == 0)
    {
        std::cerr << "Tablica jest pusta! Nie możesz usunąć nic z pustej tablicy.\n";
        return;
    }

    --m_size;
}
void DynamicArray::removeFirst()
{
    if (m_size == 0)
    {
        std::cerr << "Tablica jest pusta! Nie możesz usunąć nic z pustej tablicy.\n";
        return;
    }

    for (int i = 0; i < m_size - 1; ++i) // m_size -1 bo max index(size) jest poza tablica o 1 miejsce wiec zatzrymujemy sie wczesniej
    {
        m_array[i] = m_array[i + 1]; // tu petla z lewj do prawej idzie
    }

    --m_size;
}
void DynamicArray::remove(int index)
{
    if (index < 0 || index >= m_size)
    {
        std::cerr << "Tablica jest pusta lub index wykracza poza zakres!\n";
        return;
    }

    for (int i = index; i < m_size - 1; ++i)
    {
        m_array[i] = m_array[i + 1];
    }

    --m_size;
}

int DynamicArray::find(int value)
{
    for (int i = 0; i < m_size; ++i)
    {
        if (m_array[i] == value)
        {
            std::cout << "twoja watrosc znajduje sie pod indexem: " << i << '\n';
            return i;
        }
    }
    std::cerr << "Brak takiej warosci w tablicy!\n";
    return -1;
}

void DynamicArray::resize()
{

    m_capacity = m_capacity * 2;
    int *resizedArray = new int[m_capacity];

    for (int i = 0; i < m_size; ++i)
    {
        resizedArray[i] = m_array[i];
    }
    delete[] m_array;
    m_array = resizedArray;
}

void DynamicArray::shrink()
{

    // if ((static_cast<double>(m_size) / static_cast<double>(m_capacity)) <= 0.25) // ten przypadek jest wolniejszy ale mozliwy do uzycia

    //          tutaj 4  | to pojemnosc startowa capacity
    //                   v
    if ((m_size > 0) && (4 <= m_capacity / 2) && m_size <= m_capacity / 4) // (m_size <= m_capacity / 4) sprawdz czy tablica zawiera mniej niz 25 capacity w celu optymalizacji zajmowanej pamieci
    {
        m_capacity = m_capacity / 2;
        int *shrinkedArray = new int[m_capacity];

        for (int i = 0; i < m_size; ++i)
        {
            shrinkedArray[i] = m_array[i];
        }
        delete[] m_array;
        m_array = shrinkedArray;
    }
}

void DynamicArray::print()
{
    std::cout << "[ ";
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_array[i] << " ";
    }
    std::cout << "] | ROZMIAR: " << m_size << "| POJEMNOSC: " << m_capacity << "| \n";
}
