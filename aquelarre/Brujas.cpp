#include "Brujas.h"
#include <cstddef>
#include "Iterador.h"
#include <iostream>
#include <stdio.h>
#include "CapaLogica.h"
#include "String.h"
void Brujas :: destruirArbol (Nodo * &a)
{
    if (a != NULL)
    {
        destruirArbol(a->hizq);
        destruirArbol(a->hder);
        delete (a->info);
        delete (a);
        a = NULL;
    }
}

bool Brujas :: perteneceEnArbol (Nodo * a, String id)
{
    bool encontre = false;
    while (!encontre && a != NULL)
    {
        if (id == a->info->getIdentificador())
            encontre = true;
        else if (id < a->info->getIdentificador())
            a = a->hizq;
        else
            a = a->hder;
    }
    return encontre;
}

void Brujas :: insertEnArbol (Nodo * &a, Bruja * b)
{
    if (a == NULL)
    {
        a = new Nodo;
        a -> info = b;
        a -> hizq = NULL;
        a -> hder = NULL;
    }
    else if (b->getIdentificador() < a->info->getIdentificador())
        insertEnArbol(a->hizq,b);
    else
        insertEnArbol(a->hder,b);
}
Bruja * Brujas :: obtenerEnArbol (Nodo * a, String id)
{
    bool encontre = false;

    while (!encontre && a != NULL)
    {
        if (id == a->info->getIdentificador())
            return a->info;
        else if (id < a->info->getIdentificador())
            a = a->hizq;
        else
            a = a->hder;
    }

    return NULL;



}
void Brujas :: cargarIterador (Nodo * a, Iterador &iter)
{
    if (a != NULL)
    {
        cargarIterador (a->hizq, iter);
        iter.insertar (a->info);
        cargarIterador (a->hder, iter);

    }
}

Suprema * Brujas :: brujaMasAntig(Nodo * a)
{
    if (a!=NULL)
    {
        Suprema * suprema=(Suprema *)a->info;
        Fecha fecha(suprema->getFechaNac());

        if(a->hizq != NULL )
        {
            Suprema * s = brujaMasAntig(a->hizq);
            if(s->esSuprema())
            {
                if(s->getFechaNac()<fecha)
                {
                    suprema=s;
                }
            }
        }

        if(a->hder != NULL)
        {
            Suprema * s = brujaMasAntig(a->hder);
            if(s->esSuprema())
            {
                if(s->getFechaNac()<fecha)
                {
                    suprema=s;
                }
            }
        }

        return suprema;
    }

    return NULL;
}


Brujas :: Brujas ()
{
    ABB = NULL;
}
Brujas :: ~Brujas ()
{
    destruirArbol(ABB);
}
bool Brujas :: member (String id)
{
    return perteneceEnArbol (ABB, id);
}

void Brujas :: Insert (Bruja * b)
{
    insertEnArbol (ABB, b);
}
Bruja * Brujas :: Find (String id)
{
    return obtenerEnArbol (ABB, id);
}
void Brujas :: listarBrujas (Iterador &iter)
{
    cargarIterador (ABB, iter);
}

Suprema * Brujas :: brujaMasAntigua()
{
    return brujaMasAntig(ABB);
}



