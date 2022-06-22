#include <iostream>
#include <cstring>
#include <string>

#include "Nodo.h"
#include "Nodo.cpp"

using namespace std;

typedef Nodo * AB;

typedef struct estructura{
    char letra;
    AB Arbolito;
    int cantidad;
}Estructura[27];

void printBT(const std::string& prefix, AB &node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->Palabra << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->izq, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->der, false);
    }
}

void printBT(AB &node)
{
    printBT("", node, false);    
}

void Agregar(AB &Arbol_Binario, string Palabra_Ingresada)
{
    /* Agregamos */
    if(Arbol_Binario == NULL){
        Arbol_Binario = new Nodo(Palabra_Ingresada);
    }
    else{
        if(Arbol_Binario->Palabra == Palabra_Ingresada){
            Arbol_Binario->frecuencia += 1;
            cout << "Aumentamos la frecuencia de " << Arbol_Binario->Palabra << " a " << Arbol_Binario->frecuencia << endl;
        }
        else{
            char * cstr1 = new char[Arbol_Binario->Palabra.length() + 1];
            strcpy(cstr1, Arbol_Binario->Palabra.c_str());

            char * cstr2 = new char[Palabra_Ingresada.length() + 1];
            strcpy(cstr2, Palabra_Ingresada.c_str());

            if(strcmp(cstr2, cstr1) < 0){
                cout << "Ingresamos " << cstr2 << " por la izquierda de " << cstr1 << endl;
                Agregar(Arbol_Binario->izq, Palabra_Ingresada);
            }
            else{
                cout << "Ingresamos " << cstr2 << " por la derecha de " << cstr1 << endl;
                Agregar(Arbol_Binario->der, Palabra_Ingresada);
            }
        }
    }
}

void AgregarPalabra(Estructura &Diccionario)
{
    string Dato;

    cout << "Ingrese una palabra: ";
    cin >> Dato;

    for(int i = 0; i < 27; i++){
        if(Diccionario[i].letra == Dato[0]){
            Agregar(Diccionario[i].Arbolito, Dato);
            break;
        }
    }

    cout << "Palabra ingresada" << endl;
}

void Inicializar(Estructura &Diccionario)
{
    cout << "\tInicializando diccionario ..." << endl;

    
    for(int i = 0, j = 97; i < 27 && j < 123; i++, j++){
        Diccionario[i].letra = char(j);
        cout << "Asignando la letra \"" << Diccionario[i].letra << "\" a la posición " << i << endl;

        if(j == 122){
            Diccionario[26].letra = char(164);
            cout << "Asignando la letra \"" << Diccionario[26].letra << "\" a la posición " << 26 << endl;
        }
    }

    cout << "\tDiccionario inicializado." << endl;
}

int main()
{
    Estructura MiDiccionario;

    Inicializar(MiDiccionario);

    int i;

    AgregarPalabra(MiDiccionario);
    AgregarPalabra(MiDiccionario);
    AgregarPalabra(MiDiccionario);
    AgregarPalabra(MiDiccionario);
    AgregarPalabra(MiDiccionario);
    AgregarPalabra(MiDiccionario);
    AgregarPalabra(MiDiccionario);
    AgregarPalabra(MiDiccionario);
    AgregarPalabra(MiDiccionario);
    AgregarPalabra(MiDiccionario);
    

    for(i = 0; i < 27; i++){
        cout << MiDiccionario[i].letra << endl;
        printBT(MiDiccionario[i].Arbolito);
    }
}