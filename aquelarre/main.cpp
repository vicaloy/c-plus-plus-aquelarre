#include <iostream>
#include <stdio.h>
#include "CapaLogica.h"
#include "String.h"
#include "Especial.h"

using namespace std;

void mostrarRegistroDeDatos(int &opcion)
{
    cout << ("\n\n-------------MENU PRINCIPAL---------------\n\n");
    cout <<("1- Registre nueva bruja suprema que se incorpora al aquelarre \n\n");
    cout <<("2- Dados el id de una bruja suprema y los datos de una nueva bruja comun que se incorpora al aquelarre, registrar la bruja comun en el aquelarre, asignandole la suprema con dicho identificador  \n\n");
    cout <<("3- Listado simple de todas las brujas registradas en el aquelarre, ordenado alfabeticamente por identificador de bruja. De cada bruja se listara su identificador, su nombre y su tipo de bruja (comun o suprema). \n\n");
    cout <<("4- Dado el identificador de una bruja, listar en detalle todos sus datos junto con sus puntos de poder. En caso de que sea una bruja comun, listar tambien los datos de la bruja suprema a la cual responde junto con los puntos de poder de la suprema.  \n\n");
    cout <<("5- Listar los datos de la mayor bruja suprema registrada en el aquelarre \n\n");
    cout <<("6- Dados el id de una bruja y los datos de un nuevo hechizo, registrar el nuevo hechizo para dicha bruja. \n\n");
    cout <<("7- Dados el id de una bruja y un numero de hechizo, listar los datos del hechizo de dicha bruja \n\n");
    cout <<("8- Dados el id de una bruja, contar cantidad de hechizos comunes y especiales \n\n");
    cin>>(opcion);
}

void errores(TipoError error)
{
    switch(error)
    {
    case SIN_ERROR:
        cout <<("\n\nCorrecto\n\n\n");
        break;
    case BRUJA_YA_EXISTE:
        cout <<("\n\nLa bruja ya existe\n\n\n");
        break;
    case BRUJA_NO_EXISTE:
        cout <<("\n\nLa bruja no existe\n\n\n");
        break;
    case BRUJA_NO_ES_SUPREMA:
        cout <<("\n\nLa bruja no es suprema\n\n\n");
        break;
    case COMUN_NO_EN_DICCIO:
        cout <<("\n\nBruja comun no se encuentra en diccionario\n\n\n");
        break;
    case DICCIO_VACIO:
        cout <<("\n\nDiccionario vacio\n\n\n");
        break;
    case BRUJA_NO_MAS_HECHIZOS:
        cout <<("\n\nLa bruja no puede tener mas hechizos\n\n\n");
        break;
    case NO_EXISTE_HECHIZO:
        cout <<("\n\nNo existe hechizo\n\n\n");
        break;
    case SUPREMA_NO_EXISTE:
        cout <<("\n\nLa bruja suprema no existe\n\n\n");
        break;
    case COMUN_YA_EXISTE:
        cout <<("\n\nLa bruja comun ya existe\n\n\n");
        break;
    case FECHA_INVALIDA:
        cout <<("\n\nFecha invalida\n\n\n");
        break;
    }

}

int main()
{
    CapaLogica capaLogica;
    int opcion=0;
    TipoError error;
    //Iterador iter;

    do
    {
        mostrarRegistroDeDatos(opcion);

        fflush(stdin);
        if(opcion==1)
        {

            cout << "Identificador: ";
            String id("");
            id.scan();

            cout << "Nombre: ";
            String nom("");
            nom.scan();

            int dia, mes, anio, poder;
            cout << "Dia nac: ";
            cin>>dia;
            cout << "Mes nac: ";
            cin>>mes;
            cout << "Anio nac: ";
            cin>>anio;
            Fecha fecha(dia, mes, anio);
            cout << "Cant poder: ";
            cin>>poder;

            if(fecha.esValida())
            {

                Suprema * suprema= new Suprema(id, nom, fecha, poder);
                capaLogica.registrarBruja(suprema, error);
                errores(error);
            }
            else
            {
                error=FECHA_INVALIDA;
                errores(error);
            }

        }
        else if(opcion==2)
        {
            cout << "Id: ";
            String id("id");
            id.scan();

            cout << "Nombre: ";
            String nom("");
            nom.scan();

            cout << "Religion: ";
            String rel("");
            rel.scan();

            cout << "Id suprema: ";
            String sup("");
            sup.scan();

            cout << "Vuela escoba: ";
            bool vuela;
            cin>>vuela;

            Suprema *s;

            Comun * comun= new Comun(id, nom, rel, vuela, s);
            capaLogica.asignarSupremaAComun(sup, comun, error);
            errores(error);
        }
        else if(opcion==3)
        {
            Iterador iter;
            capaLogica.listarBrujas(iter);

            while(iter.hayMasBrujas())
            {
                Bruja *bruja=iter.proximoBruja();
                cout<<" Nombre: ";
                bruja->getNombre().print();
                cout<<" Id: ";
                bruja->getIdentificador().print();
                Suprema * sup = (Suprema *)bruja;
                if(sup->esSuprema())
                {
                    cout<<" Tipo de bruja: Suprema\n\n\n";

                }
                else
                {
                    cout<<" Tipo de bruja: Comun\n\n\n";

                }


            }
        }
        else if(opcion==4)
        {
            cout << "Id: ";
            String id("id");
            id.scan();
            Bruja *b;
            Suprema *s;
            int poder;
            int poderSup;

            capaLogica.ptosDePoder(id, b, s, poder, poderSup, error);
            errores(error);
            if(error==SIN_ERROR)
            {
                cout<<" Nombre: ";
                b->getNombre().print();
                cout<<" Id: ";
                b->getIdentificador().print();
                cout<<" Puntos de poder: ";
                cout<<poder;

                Suprema * sup = (Suprema *)b;
                Comun * com = (Comun *)b;
                if(sup->esSuprema())
                {
                    cout<<"Cant poder: ";
                    cout<<sup->getCantPod();
                    cout<<"Fecha nac: ";
                    cout<<sup->getFechaNac().getDia();
                    cout<<"/";
                    cout<<sup->getFechaNac().getMes();
                    cout<<"/";
                    cout<<sup->getFechaNac().getAnio();
                    cout<<" Tipo de bruja: Suprema\n\n\n";


                }
                else
                {
                    cout<<" Religion: ";
                    com->getRelOrig().print();
                    cout<<" Vuela escoba: ";
                    cout<<com->getVuelaEscoba();
                    if(s!=NULL)
                    {
                        cout<<" Datos de suprema: \n";

                        cout<<" Nombre: ";
                        s->getNombre().print();
                        cout<<" Id: ";
                        s->getIdentificador().print();
                        cout<<" Puntos de poder: ";
                        cout<<poderSup;
                        cout<<" Cant poder: ";
                        cout<<s->getCantPod();
                        cout<<" Fecha nac: ";
                        cout<<s->getFechaNac().getDia();
                        cout<<"/";
                        cout<<s->getFechaNac().getMes();
                        cout<<"/";
                        cout<<s->getFechaNac().getAnio();

                    }

                    cout<<" Tipo de bruja: Comun\n\n\n";

                }
            }


        }
        else if(opcion==5)
        {
            Suprema *s;
            capaLogica.brujaMasAntigua(s,error);


            cout<<" Nombre: ";
            s->getNombre().print();
            cout<<" Fecha nacimiento: ";
            cout<<s->getFechaNac().getDia();
            cout<<"/";
            cout<<s->getFechaNac().getMes();
            cout<<"/";
            cout<<s->getFechaNac().getAnio();
            cout<<" Id: ";
            s->getIdentificador().print();
        }

        else if(opcion==6)
        {


            cout<<" Id bruja: ";
            String s("");
            s.scan();
            cout<<" Nombre: ";
            String nom("");
            nom.scan();
            cout<<" Numero: ";
            int nro;
            cin>>nro;

            cout<<" Comun-0 Especial-1: ";
            int esp;
            cin>>esp;

            Hechizo * h=new Hechizo(nom, nro);
            if(esp==1)
            {
                fflush(stdin);
                cout<<" Descripcion: ";
                String d("");
                d.scan();
                cout<<" Anio manifestacion: ";
                int anio;
                cin>>anio;
                Especial * especial=new Especial(s, nro, anio, d);
                capaLogica.registrarHechizo(s, especial, error);
            }
            else
            {
                capaLogica.registrarHechizo(s, h, error);
            }




            errores(error);
        }
        else if(opcion==7)
        {
            cout<<" Id bruja: ";
            String s("");
            s.scan();
            cout<<" Numero: ";
            int nro;
            cin>>nro;


            Hechizo *h=new Hechizo(s, nro);
            capaLogica.listarHechizo(s, nro, error, h);


            errores(error);

            if(error==SIN_ERROR)
            {
                cout<<" Nombre: ";
                h->getNombre().print();
                cout<<" Numero: ";
                int n=h->getNumero();
                cout<<n;



                if(h->esEspecial())
                {
                    Especial * e=(Especial *)h;
                    cout<<" Descripcion: ";
                    e->getDescrip().print();
                    cout<<" Anio: ";
                    int a=e->getAnioManif();
                    cout<<a;
                }
            }
        }
        else if(opcion==8)
        {
            cout<<" Id bruja: ";
            String s("");
            s.scan();
            int especial=0;
            int comun=0;
            capaLogica.contarHechizoBruja(s, comun, especial, error);

            cout<<" Especial: ";
            cout<<especial;
            cout<<" Comun: ";
            cout<<comun;
            errores(error);
        }


    }
    while(opcion!=9);

    return 0;
}


