#include "Fecha.h"

using namespace fecha;

Fecha::Fecha()
{
    this->diaRel = 1; // aca el this es opcional, es puntero a instancia
}

Fecha::Fecha(int dia, int mes, int anio)
{
    this->diaRel = dia;
}
Fecha Fecha::sumarDias(int dias) const
{
    Fecha fecha;
    fecha.diaRel = this->diaRel + dias;
    return fecha;
}
int Fecha::difEnDias(Fecha *otraFecha) const
{
    return this->diaRel - otraFecha->diaRel;
}
int Fecha::operator-(const Fecha *otraFecha) const
{
    return this->diaRel - otraFecha->diaRel;
} // el constal final es para que no se pueda modificar el objetollamador

int Fecha::operator+(const int num) const
{
    return this->diaRel + num;
}