#include "Especial.h"


Especial::Especial (String nom, int num, int anio, String desc) : Hechizo(nom,num), descrip(desc){
    anioManif=anio;
}


int Especial:: getAnioManif() {
    return anioManif;
}
void Especial:: setAnioManif(int a ) {
    anioManif=a;
}
String Especial:: getDescrip() {
    return descrip;
}
void Especial:: setDescrip(String d) {
    descrip=d;
}


bool Especial:: esEspecial() {
    return true;
}
