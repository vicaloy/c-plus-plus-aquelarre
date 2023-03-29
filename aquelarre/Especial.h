#ifndef ESPECIAL_H_INCLUDED
#define ESPECIAL_H_INCLUDED
#include "String.h"
#include "Hechizos.h"

class Especial: public Hechizo
{
private:
    int anioManif;
    String descrip;
public:
    Especial (String,int, int, String);

    int getAnioManif();
    void setAnioManif(int);
    String getDescrip();
    void setDescrip(String);

    bool esEspecial();


};



#endif // ESPECIAL_H_INCLUDED
