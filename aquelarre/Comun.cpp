#include "Comun.h"

Comun::Comun (String iden, String nom, String rel, bool vuela, Suprema* s):Bruja(iden,nom), relOrig(rel)
{
    vuelaEscoba=vuela;
    suprema=s;

}
String Comun::getRelOrig()
{
    return relOrig;
}
void Comun::setRelOrg(String rel)
{
    relOrig=rel;
}

bool Comun::getVuelaEscoba()
{
    return vuelaEscoba;
}

void Comun::setVuelaEscoba(bool vuela)
{
    vuelaEscoba=vuela;
}

Suprema* Comun::getSuprema()
{
    return suprema;
}

void Comun::setSuprema(Suprema *s)
{
    suprema=s;
}


bool Comun::esSuprema()
{
    return false;
}

int Comun::cantPtosPoder()
{
    int comun=0;
    int especial=0;
    int cantidad=0;
    contarHechizos(comun, especial);
    cantidad=comun+especial*2;
    if(relOrig=="Salem")
    {
        cantidad=cantidad+1;
    }
    return cantidad;
}
