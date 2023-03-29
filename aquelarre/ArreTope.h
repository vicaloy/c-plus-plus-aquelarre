#ifndef ARRETOPE_H_INCLUDED
#define ARRETOPE_H_INCLUDED
#include "Hechizo.h"

const int TAMANIO = 20;
public class ArreTope
{
private:
typedef struct { Hechizo *arre[TAMANIO];
 int tope;
 } arreTope;

public:
    Hechizos();
    bool esVacia();
    int largo();
     Hechizo kesimo(int);
     Hechizo primero();
     void insertar(Hechizo);
     void contarHechizos(&int,&int);

};

#endif // ARRETOPE_H_INCLUDED
