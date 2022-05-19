#include <string.h>
#include "Cadena.h"

Cadena::Cadena()
{
    cadena = new char[1];
    cadena[0] = '\0';
}

Cadena::~Cadena()
{
    delete [] cadena;
}

Cadena::Cadena(const char* cadena)
{
    this->cadena = new char [strlen(cadena)+1];
    strcpy(this->cadena,cadena);
}


Cadena::Cadena(const Cadena& other)
{
    this->cadena = new char [strlen(other.cadena)+1];
    strcpy(this->cadena,other.cadena);
}

Cadena& Cadena::operator=(const Cadena& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
