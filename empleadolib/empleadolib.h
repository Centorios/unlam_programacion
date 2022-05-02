#ifndef EMPLEADOLIB_H_INCLUDED
#define EMPLEADOLIB_H_INCLUDED

#include "E:\Facultad\Programacioncursada2\fechaslib\fechastruct.h"

#define TODO_MAL_MAIN 1
#define TODO_OK_MAIN 0

#define TODO_OK 1
#define TODO_MAL 0

typedef struct
{
    int dni;
    char nombreyapellido[50];
    Fecha fNaicmiento;
    float sueldo;
    char sexo;
} Empleado;

int aumentarSueldo(char originFilePath[], float porcentaje);
int escribirEmpleados(char originFilePath[], Empleado* empleados,int quantity);
void leerArchivo(char originFilePath[]);

#endif // EMPLEADOLIB_H_INCLUDED
