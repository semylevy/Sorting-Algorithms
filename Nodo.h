#ifndef NODO_H
#define NODO_H

#include <iostream>

class Nodo {
public:
    Nodo(int datoTmp){
        dato = datoTmp;
        derecho = NULL;
        izquierdo = NULL;
    }
    Nodo *derecho;
    Nodo *izquierdo;
    int dato;
};

#endif
