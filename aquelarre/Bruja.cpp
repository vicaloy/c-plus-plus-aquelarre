#include "Bruja.h"

Bruja :: Bruja (String identif, String nom): id(identif),
nombre(nom), hechizos()
{
}
Bruja :: ~Bruja ()
{
}
void Bruja :: setIdentificador(String iden){
    id=iden;
}

String Bruja :: getIdentificador()
{
    return id;
}

void Bruja:: setNombre(String nom){
    nombre=nom;
}

String Bruja :: getNombre ()
{
    return nombre;
}

void Bruja :: agregarHechizo(Hechizo *h){
    hechizos.insertar(h);
}

int Bruja ::largoHechizos(){
    return hechizos.largo();
}

Hechizo * Bruja :: hechizoPorNro(int nro){
    return hechizos.kEsimo(nro);
}



void Bruja :: contarHechizos(int &comun, int &especial){
    hechizos.contarHechizos(comun, especial);
}

bool Bruja :: perteneceHechizo(int nro){
    return hechizos.perteneceHechizo(nro);
}

Hechizo* Bruja :: obtenerPorNro(int nro){
    return hechizos.obtenerPorNro(nro);
}


