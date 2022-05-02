#include <stdio.h>
#include <stdlib.h>
#include "empleadolib.h"
#define ARRAY_SIZE(arr)     (sizeof(arr) / sizeof((arr)[0]))
int aumentarSueldo(char originFilePath[], float porcentaje)
{
    FILE *empleadoFILE = fopen(originFilePath, "r+b");
    if (empleadoFILE == NULL)
    {
        puts("No se pudo abrir el archivo\n");
        return TODO_MAL;
    }

    Empleado empleado;

    fread(&empleado, sizeof(Empleado), 1, empleadoFILE);
    while (!feof(empleadoFILE))
    {
        empleado.sueldo += empleado.sueldo * porcentaje / 100;
        fseek(empleadoFILE, -sizeof(Empleado), SEEK_CUR);
        fwrite(&empleado, sizeof(Empleado), 1, empleadoFILE);
        fseek(empleadoFILE, 0, SEEK_CUR);
        fread(&empleado, sizeof(Empleado), 1, empleadoFILE);
    }
    fclose(empleadoFILE);
    return TODO_OK;
}

int escribirEmpleados(char originFilePath[], Empleado* empleados,int quantity)
{

    FILE *empleadoFILE = fopen(originFilePath, "wb");

    if (empleadoFILE == NULL)
    {
        puts("No se pudo abrir el archivo\n");
        return TODO_MAL;
    }

    fwrite(empleados, sizeof(Empleado),quantity, empleadoFILE);

    fclose(empleadoFILE);

    return TODO_OK;
}



void leerArchivo(char originFilePath[])
{
    Empleado empleadoBUFFER;
    FILE* empleadoFILE = fopen(originFilePath,"rb");

    if(empleadoFILE == NULL)
    {
        puts ("No se pudo abrir el archivo\n");
        return;
    }

    fread(&empleadoBUFFER,sizeof(Empleado),1,empleadoFILE);
    while(!feof(empleadoFILE))
    {
        printf("%d, %s, %d, %d, %d, %f, %c\n",empleadoBUFFER.dni,empleadoBUFFER.nombreyapellido, empleadoBUFFER.fNaicmiento.anio,empleadoBUFFER.fNaicmiento.mes,empleadoBUFFER.fNaicmiento.dia,empleadoBUFFER.sueldo,empleadoBUFFER.sexo);
        fread(&empleadoBUFFER,sizeof(Empleado),1,empleadoFILE);

    }

}
