#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

class Nodo{
    public:
        string Palabra;
        int frecuencia;
        Nodo* izq;
        Nodo* der;

        Nodo();
        virtual ~Nodo();
        Nodo(string);
};

#endif  //NODO_H