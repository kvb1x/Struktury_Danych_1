#pragma once
#include <random>
#include <string>
#include <fstream>
int getRandom(int min, int max)
{
    ////////////////////LOSOWANIE///////////////////////////

    std::random_device rd;                             // zbieranie ziarna od OS
    static std::mt19937 gen(rd());                     // uruchomienei mt
    std::uniform_int_distribution<int> dist(min, max); // ustalenie min i max

    return dist(gen); // przypisanie losowej liczby do indexu
    //////////////////////////////////////////////
}

void generateFile(int size, std::string fileData)
{
    // int size{5000}; // size bierzemy z jakiegos zrodla
    int min{1};
    int max{100000};
    // std::string fileData{"SD/SD_1/data/test_data.txt"};
    std::ofstream file(fileData);
    if (file.is_open())
    {
        for (int i = 0; i < size; ++i)
        {
            int value{getRandom(min, max)};

            file << value << " ";
        }
        file.close();
        std::cout << "Wygenerowano nowe dane!\n";
    }
    else
    {
        std::cerr << "Blad zapisu pliku o nazwie" << fileData << "!\n";
    }
}
