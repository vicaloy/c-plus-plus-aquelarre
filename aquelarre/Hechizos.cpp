#include "Hechizos.h"

Hechizos::Hechizos()
{
    arre.tope=0;
}
bool Hechizos::esVacia()
{
    if(arre.tope==0)
        return true;
    else
        return false;
}
int Hechizos::largo()
{
    return arre.tope;
}
Hechizo* Hechizos::kEsimo(int pos)
{
    return arre.arreglo[pos];
}
Hechizo* Hechizos::primero()
{
    return arre.arreglo[0];
}
void Hechizos::insertar(Hechizo * h)
{
    //h->setNumero(arre.tope);
    arre.arreglo[arre.tope]=h;
    arre.tope++;
}
void Hechizos::contarHechizos(int &comun, int &especial)
{
    comun=0;
    especial=0;

    for(int i=0; i<arre.tope; i++)
    {
        if(arre.arreglo[i]->esEspecial())
        {
            especial++;
        }
        else
        {
            comun++;
        }
    }
}

bool Hechizos::perteneceHechizo(int nro)
{
    int i=0;
    bool encontre=false;
    while(i<arre.tope && !encontre)
    {
        if(arre.arreglo[i]->getNumero()==nro)
        {
            encontre=true;
        }
        i++;
    }
}

Hechizo* Hechizos::obtenerPorNro(int nro){

    Hechizo * h=new Hechizo("", 0);
    int i=0;
    bool encontre=false;
    while(i<arre.tope && !encontre)
    {
        if(arre.arreglo[i]->getNumero()==nro)
        {
            h=(Hechizo *)arre.arreglo[i];
            encontre=true;
        }
        i++;
    }

    return h;
}
