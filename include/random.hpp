#pragma once
#include <random>
int getRandom(int min, int max)
{
    ////////////////////LOSOWANIE///////////////////////////

    std::random_device rd;                             // zbieranie ziarna od OS
    static std::mt19937 gen(rd());                     // uruchomienei mt
    std::uniform_int_distribution<int> dist(min, max); // ustalenie min i max

    return dist(gen); // przypisanie losowej liczby do indexu
    //////////////////////////////////////////////
}
