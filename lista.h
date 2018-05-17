//
// Created by K i D on 17.05.2018.
//

#ifndef CLION_LISTA_H
#define CLION_LISTA_H

#include <string>

struct dluznik
{
    std::string imie;
    double dlug;
};

typedef dluznik Item;

static const int SIZE = 5;

class Lista
{
private:
    Item lista[SIZE];
    int ilosc;
public:
    Lista();
    Lista(const Item &);
    void add(const Item &);
    bool isEmpty() const;
    bool isFull() const;
    void visit(void(*pf)(Item &));
};

#endif //CLION_LISTA_H
