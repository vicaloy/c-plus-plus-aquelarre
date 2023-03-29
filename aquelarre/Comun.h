#ifndef COMUN_H_INCLUDED
#define COMUN_H_INCLUDED
#include "String.h"
#include "Hechizos.h"
#include "Bruja.h"
#include "Suprema.h"

class Comun: public Bruja
{
private:
    String relOrig;
    bool vuelaEscoba;
    Suprema * suprema;

public:
    Comun (String, String, String, bool, Suprema*);

    String getRelOrig();
    void setRelOrg(String);

    bool getVuelaEscoba();
    void setVuelaEscoba(bool);
    Suprema* getSuprema();
    void setSuprema(Suprema*);


    bool esSuprema();

    int cantPtosPoder();

};


#endif // COMUN_H_INCLUDED
