#ifndef SUPREMA_H_INCLUDED
#define SUPREMA_H_INCLUDED
#include "Fecha.h"
#include "String.h"
#include "Hechizos.h"
#include "Bruja.h"

class Suprema : public Bruja
{
private:
    Fecha fechaNac;
    int cantPod;

public:
    Suprema (String, String, Fecha, int);
//Constructor común
    ~Suprema ();
//Destructor
    Fecha getFechaNac ();

    void setFechaNac (Fecha);

    void setCantPod (int);

    int getCantPod();

    bool esSuprema();

    int cantPtosPoder();

};

#endif // SUPREMA_H_INCLUDED
