#ifndef BRUJA_H_INCLUDED
#define BRUJA_H_INCLUDED
#include "String.h"
#include "Hechizos.h"

class Bruja
{
private:
    String id;
    String nombre;
    Hechizos hechizos;
public:
    Bruja (String, String);

    virtual ~Bruja ();

    String getIdentificador ();

    String getNombre ();

    void setIdentificador(String);

    void setNombre(String);

    void agregarHechizo(Hechizo*);

    int largoHechizos();

    Hechizo * hechizoPorNro(int);

    void contarHechizos(int &comun, int &especial);

    bool perteneceHechizo(int nro);

    Hechizo* obtenerPorNro(int nro);

    virtual int cantPtosPoder() = 0;

    virtual bool esSuprema () = 0;

};


#endif // BRUJA_H_INCLUDED
