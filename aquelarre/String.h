#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
const int MAX = 80;
class String
{
private:
    char * cadena;
public:
    String();
// constructor por defecto.
    String(char* s);
// constructor común
    String(const String &);
// constructor de copia
    ~String();
// destructor
    String operator=(const String &);
// sobrecarga de asignación
    bool operator==(String);
// compara dos strings por igualdad.
    bool operator< (String);
// compara dos strings alfabéticamente
    String operator+ (String);
// concatenación de strings.
    bool operator!=(String otro);

    void scan();
// lee un string desde la entrada estándar.
    void print();
// muestra un string en la salida estándar
};
#endif
