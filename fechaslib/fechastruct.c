#include <stdio.h>
#include "fechastruct.h"

#define TEXTO_MES "mes"
#define TEXTO_DIA "dia"
#define TEXTO_ANIO "anio"
#define ANIO_BASE 1601
#define VERDADERO 1
#define FALSO 0

void InputValidation(int *number, char message[])
{
    do

    {
        printf("Ingrese %s: ", message);
        fflush(stdin);
        scanf("%d", number);

        if (*number <= 0)
        {
            printf("El %s ingresado es negativo o invalido, ingrese un numero nuevamente\n", message);
        }
    }
    while (*number <= 0);
}

void InputDay(Fecha *fecha)
{
    static int validDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    InputValidation(&fecha->dia, TEXTO_DIA);

    if (esBisiesto(fecha))
    {
        validDays[1] = 29;
    }
    else
    {
        validDays[1] = 28;
    }

    while (fecha->dia <= 0 || fecha->dia > validDays[(fecha->mes) - 1])
    {
        printf("el dia ingresado no es valido para este mes\n");
        InputValidation(&fecha->dia, TEXTO_DIA);
    }
}

void InputMonth(Fecha *fecha)
{
    InputValidation(&fecha->mes, TEXTO_MES);
    while (fecha->mes <= 0 || fecha->mes >= 13)
    {
        printf("el mes ingresado no es valido\n");
        InputValidation(&fecha->mes, TEXTO_MES);
    }
}

void InputYear(Fecha *fecha)
{
    InputValidation(&fecha->anio, TEXTO_ANIO);
    while (fecha->anio < ANIO_BASE)
    {
        printf("el anio ingresado es menor a 1601 ingrese nuevamente\n");
        InputValidation(&fecha->anio, TEXTO_ANIO);
    }
}

void assignDate(Fecha *fecha)
{
    InputDay(fecha);
    InputMonth(fecha);
    InputYear(fecha);
}

int esBisiesto(const Fecha *fecha)
{
    if ((fecha->anio % 4 == 0 && fecha->anio % 100 == 0) || fecha->anio % 400 == 0)
    {
        return VERDADERO;
    }
    else
    {
        return FALSO;
    }
}


int esBisiestoNoPointer(const int anio)
{
    if ((anio % 4 == 0 && anio % 100 == 0) || anio % 400 == 0)
    {
        return VERDADERO;
    }
    else
    {
        return FALSO;
    }
}



int daysInTheMonth(const Fecha *fecha)
{
    int diasEnMeses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (esBisiesto(fecha) && fecha->mes == 2)
    {
        return diasEnMeses[fecha->mes - 1] + 1;
    }
    return diasEnMeses[fecha->mes - 1];
}

int daysInTheMonthNoPointer(int month,int year)
{
    int diasEnMeses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (esBisiestoNoPointer(year) && month == 2)
    {
        return diasEnMeses[month - 1] + 1;
    }
    return diasEnMeses[month - 1];
}

void showFecha(const Fecha *fecha)
{
    printf("La fecha ingresada es: %d/%d/%d", fecha->dia, fecha->mes, fecha->anio);
}

/**
 * @brief
 *
 * @param fecha1 una fecha ya validada
 * @param fecha2 otra fecha ya validada
 * @return la diferencia en dias entre las dos fechas
 */
int dateDifferenceInDays(const Fecha *fechaMenor, const Fecha *fechaMayor)
{
    int dif = (fechaMayor->dia) - (fechaMenor->dia);
    int mesActual;
    int anioActual;

    for(mesActual = fechaMenor->mes, anioActual = fechaMenor -> anio;
            anioActual < fechaMayor -> anio || mesActual < fechaMayor -> mes;
            anioActual += mesActual / 12, mesActual+= mesActual %12 +1  )
    {
        dif+= daysInTheMonthNoPointer(mesActual, anioActual);
    };
    printf("\ndiferencia en dias:%d",dif);
    return dif;
}
