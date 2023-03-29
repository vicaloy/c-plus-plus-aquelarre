#ifndef BRUJAS_H_INCLUDED
#define BRUJAS_H_INCLUDED
#include "Bruja.h"
#include "Iterador.h"
#include "Suprema.h"

class Brujas
{
private:
    struct Nodo
    {
        Bruja * info;
        Nodo * hizq;
        Nodo * hder;
    };
    Nodo * ABB;

    void destruirArbol (Nodo * &);

    bool perteneceEnArbol (Nodo *, String);

    void insertEnArbol (Nodo * &, Bruja *);

    Bruja * obtenerEnArbol (Nodo *, String);

    void cargarIterador (Nodo *, Iterador &);

    Suprema * brujaMasAntig(Nodo * a);

public:
    Brujas ();

    ~Brujas ();

    bool member (String);

    void Insert (Bruja *);

    Bruja * Find (String);

    void listarBrujas (Iterador &);

    Suprema * brujaMasAntigua();



};

#endif // BRUJAS_H_INCLUDED
