#include "lista.h"
#include <iostream>

Lista::Lista()
{
    ilosc = 0;
    lista[0].dlug = 0;
    lista[0].imie = "brak";
}

Lista::Lista(const Item & d)
{
    ilosc = 1;
    lista[0]= d;
}

void Lista::add(const Item & d)
{
    lista[ilosc] = d;
    ++ilosc;
}

bool Lista::isEmpty() const
{
    return ilosc == 0 ? true : false;
}
bool Lista::isFull() const
{
    return ilosc == SIZE ? true : false;
}
void Lista::visit(void(*pf)(Item &))
{
    for (int i = 0; i < ilosc; i++)
        pf(lista[i]);
}