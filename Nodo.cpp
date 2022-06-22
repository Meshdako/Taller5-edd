#include "Nodo.h"

#include <iostream>

using namespace std;

Nodo::Nodo()
{
    Palabra = " ";
    frecuencia = 0;
    izq = NULL;
    der = NULL;
}


Nodo::~Nodo()
{
    /* Destructor */
}

Nodo::Nodo(string Palabra_Ingresada)
{
    Palabra = Palabra_Ingresada;
    frecuencia = 1;
    izq = NULL;
    der = NULL;
}