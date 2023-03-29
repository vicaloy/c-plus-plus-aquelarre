#ifndef HECHIZOS_H_INCLUDED
#define HECHIZOS_H_INCLUDED
#include "Hechizo.h"
const int TAMANIO = 20;
class Hechizos
{
private:
    typedef struct
    {
        Hechizo *arreglo[TAMANIO];
        int tope;
    } arreTope;

    arreTope arre;
public:
    Hechizos();
    bool esVacia();
    int largo();
    Hechizo* kEsimo(int);
    Hechizo* primero();
    void insertar(Hechizo*);
    void contarHechizos(int&,int&);
    bool perteneceHechizo(int nro);
    Hechizo* obtenerPorNro(int nro);

};

#endif // HECHIZOS_H_INCLUDED
