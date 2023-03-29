#include "Suprema.h"
Suprema :: Suprema  (String identif, String nom,
                     Fecha nacimiento, int cantidad):Bruja(identif,nom)
{
    fechaNac=nacimiento;
    cantPod=cantidad;
}
Suprema :: ~Suprema ()
{
}


int Suprema :: getCantPod ()
{
    return cantPod;
}

void Suprema:: setCantPod(int cant)
{
    cantPod=cant;
}

Fecha Suprema:: getFechaNac()
{
    return fechaNac;
}

void Suprema:: setFechaNac(Fecha fecha)
{
    fechaNac=fecha;
}

bool Suprema :: esSuprema ()
{
    return true;
}

int Suprema:: cantPtosPoder(){
    int comun=0;
    int especial=0;
    int cantidad=0;
    contarHechizos(comun, especial);
    cantidad=comun*2+especial*4+cantPod;
    Fecha siglo20(1, 1, 2001);
    Fecha siglo19(1, 1, 1900);
    if(fechaNac<siglo20 && siglo19<fechaNac)
    {
        cantidad=cantidad+5;
    }
    return cantidad;
}
