#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"
#include <iostream>
#include <string>

using namespace std;

class ArbolBinario {
public:
    Nodo *raiz;
    int count;
    
    ArbolBinario() {
        raiz = NULL;
        count = 0;
    }
    
    void agregaNodo(int dato, Nodo *&tmp) {
        if(tmp == NULL) {
            tmp = new Nodo(dato);
            return;
        } else if (dato > tmp->dato) {
            agregaNodo(dato, tmp->derecho);
        } else if (dato < tmp->dato) {
            agregaNodo(dato, tmp->izquierdo);
        }
    }
    
    void infijo(Nodo *tmp, int **array) {
        if(tmp->izquierdo != NULL){
            infijo(tmp->izquierdo, array);
        }
        array[0][count++] = tmp->dato;
        if(tmp->derecho != NULL){
            infijo(tmp->derecho, array);
        }
    }
};

#endif
