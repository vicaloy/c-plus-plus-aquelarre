#include "CapaLogica.h"
#include <iostream>
using namespace std;

CapaLogica :: CapaLogica (): dicc()
{
}
void CapaLogica :: registrarBruja (Suprema * s, TipoError &error)
{
    error = SIN_ERROR;
    String id = s->getIdentificador();
    if (dicc.member(id))
        error = BRUJA_YA_EXISTE;
    else
        dicc.Insert(s);
}

void CapaLogica ::asignarSupremaAComun (String id, Comun * comun, TipoError & error)
{

    error = SIN_ERROR;

    if (!dicc.member(id))
    {
        error=SUPREMA_NO_EXISTE;
    }
    else
    {
        Bruja *b=dicc.Find(id);
        Suprema *s=(Suprema *)b;
        if(!s->esSuprema()){
            error=BRUJA_NO_ES_SUPREMA;
        }else{


            if(dicc.member(comun->getIdentificador())){
                error=COMUN_YA_EXISTE;
            }else{
                comun->setSuprema(s);
                dicc.Insert(comun);
            }
        }

    }
}

void CapaLogica ::listarBrujas (Iterador & iter)
{
    dicc.listarBrujas(iter);
}
void CapaLogica ::brujaMasAntigua(Suprema * & s, TipoError& error)
{
    if(dicc.brujaMasAntigua()==NULL){
        error = DICCIO_VACIO;
    }else{
        s=dicc.brujaMasAntigua();
    }
}
void CapaLogica ::registrarHechizo(String str, Hechizo *h, TipoError &error)
{
    error = SIN_ERROR;
    if (!dicc.member(str))
        error = BRUJA_NO_EXISTE;
    else{
        Bruja * b=dicc.Find(str);
        if(b->largoHechizos()==20){
            error=BRUJA_NO_MAS_HECHIZOS;
        }else{
            b->agregarHechizo(h);
        }

    }
}

void CapaLogica ::listarHechizo(String str, int nroH, TipoError& error, Hechizo * & h)
{
    error = SIN_ERROR;
    if (!dicc.member(str))
        error = BRUJA_NO_EXISTE;
    else{
        Bruja * b=dicc.Find(str);

        if(!b->perteneceHechizo(h->getNumero())){
            error=NO_EXISTE_HECHIZO;
        }else{
           h= b->obtenerPorNro(h->getNumero());
        }

    }
}


void CapaLogica ::contarHechizoBruja(String str, int &comun, int &especial, TipoError &error)
{
    error = SIN_ERROR;
    if (!dicc.member(str))
        error = BRUJA_NO_EXISTE;
    else{
        Bruja * b=dicc.Find(str);
        b->contarHechizos(comun, especial);
    }
}

void CapaLogica :: ptosDePoder(String str, Bruja *& b, Suprema *& s, int& poder,
                               int& poderSup, TipoError& error)
{
    error = SIN_ERROR;
    if (!dicc.member(str))
        error = BRUJA_NO_EXISTE;
    else{
        b=dicc.Find(str);
        poder=b->cantPtosPoder();
        if(!b->esSuprema()){
            Comun * c=(Comun *)b;
            s=c->getSuprema();
            poderSup=s->cantPtosPoder();
        }else{
            s=NULL;
        }
    }
}




