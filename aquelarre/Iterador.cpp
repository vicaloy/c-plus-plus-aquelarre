#include "Iterador.h"
#include <cstddef>
#include "Bruja.h"
#include <iostream>


Iterador::Iterador ()
{
    prim = NULL;
    ulti = NULL;
    actual = NULL;
}


void Iterador :: insertar (Bruja * b)
{
    Nodo * nuevo = new Nodo;
    nuevo -> info = b;
    nuevo -> sig = NULL;
    if (prim == NULL)
    {
        prim = nuevo;
        ulti = nuevo;
        actual = nuevo;
    }
    else
    {
        ulti -> sig = nuevo;
        ulti = ulti -> sig;
    }
}
bool Iterador :: hayMasBrujas()
{
    bool hay=(bool) (actual != NULL);

    return hay;
}
Bruja * Iterador :: proximoBruja()
{
    Bruja * resu = actual -> info;
    actual = actual -> sig;
    return resu;
}





