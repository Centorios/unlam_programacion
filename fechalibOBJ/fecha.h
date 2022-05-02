#ifndef FECHA_H
#define FECHA_H


namespace fecha
{
    class Fecha
    {
    private:
        int diaRel;

    public:
        Fecha();
        Fecha(int dia, int mes, int anio);
        Fecha sumarDias(int dias) const;
        int difEnDias(Fecha *otraFecha) const;
        int operator-(const Fecha *otraFecha) const; // el const al final es para que no se pueda modificar el objeto llamador
        int operator+(const Fecha *otraFecha) const;
        int operator+(const int num) const;
    };
}

#endif // FECHA_H
