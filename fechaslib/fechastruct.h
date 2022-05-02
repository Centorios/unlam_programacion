#ifndef FECHASTRUCT_H_INCLUDED
#define FECHASTRUCT_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

void InputValidation(int *number, char message[]);

void showFecha(const Fecha *fecha);

void InputDay(Fecha *fecha);

void InputMonth(Fecha *fecha);

void InputYear(Fecha *fecha);

int esBisiesto(const Fecha *fecha);

int daysInMonth(const Fecha *fecha);

int dateDifferenceInDays(const Fecha *fechaMenor, const Fecha *fechaMayor);

int daysInTheMonth(const Fecha *fecha);

int daysInTheMonthNoPointer(int month,int year);

int esBisiestoNoPointer(const int anio);

#endif // FECHASTRUCT_H_INCLUDED
