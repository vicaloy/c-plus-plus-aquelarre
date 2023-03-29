#ifndef ITERADOR_H_INCLUDED
#define ITERADOR_H_INCLUDED
#include <iostream>
#include "Bruja.h"

class Iterador
{
private:

    struct Nodo
    {
        Bruja * info; //iterador de punteros a brujas
        Nodo * sig;
    };
    Nodo * prim;
    Nodo * ulti;
    Nodo * actual;

public:
    Iterador ();

    void insertar (Bruja*);
    bool hayMasBrujas ();
    Bruja * proximoBruja ();

};

#endif // ITERADOR_H_INCLUDED
