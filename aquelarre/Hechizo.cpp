#include "Hechizo.h"
Hechizo::Hechizo(String nom,int num):nombre(nom)
{
    numero=num;
}
String Hechizo:: getNombre()
{
    return nombre;
}
int Hechizo::getNumero()
{
    return numero;
}
void Hechizo::setNumero(int num)
{
    numero=num;

}
void Hechizo::setNombre(String nom)
{
    nombre=nom;
}

bool Hechizo::esEspecial()
{
    return false;
}
