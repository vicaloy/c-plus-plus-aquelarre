#ifndef CAPALOGICA_H_INCLUDED
#define CAPALOGICA_H_INCLUDED
#include "TipoError.h"
#include "Bruja.h"
#include "Brujas.h"
#include "Suprema.h"
#include "Comun.h"
#include "Hechizo.h"
#include "Iterador.h"
#include "String.h"

class CapaLogica
{
private:
    Brujas dicc;

public:

    CapaLogica ();

    void registrarBruja (Suprema *, TipoError &);

    void asignarSupremaAComun (String, Comun *, TipoError &);

    void listarBrujas (Iterador &);

    void ptosDePoder(String, Bruja * &, Suprema * &, int&, int&, TipoError&);

    void brujaMasAntigua(Suprema * &s, TipoError&);

    void registrarHechizo(String, Hechizo*, TipoError&);

    void listarHechizo(String, int, TipoError&, Hechizo * & );

    void contarHechizoBruja(String, int&, int&, TipoError&);

};



#endif // CAPALOGICA_H_INCLUDED
