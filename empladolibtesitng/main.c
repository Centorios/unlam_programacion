#include <stdio.h>
#include <stdlib.h>
#include "../../Programacioncursada2/empleadolib/empleadolib.h"

int main(int argc,char* argv[])
{
    Empleado empleados[] = {
        {11223344, "Juan Perez", {1, 1, 1990}, 90000, 'M'},
        {22334455, "Armando Esteban", {2, 2, 1990}, 70000, 'F'},
        {33445566, "Armando Paredes", {3, 3, 1990}, 80000, 'M'},
        {44556677, "Esteban Quito", {4, 4, 1990}, 955000, 'X'},
        {55667788, "Jonhy Melalavo", {5, 5, 1990}, 90000.5, 'M'},
    };

    printf("%s\n",argv[1]);

    escribirEmpleados(argv[1], empleados,sizeof(empleados)/sizeof(*empleados));
    leerArchivo(argv[1]);

    return TODO_OK_MAIN;
}

