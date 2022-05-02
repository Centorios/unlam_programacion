#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliares.h"

#define PARAM_PRODUCTOS 1
#define PARAM_MOVIMIENTOS 2


int main(int argc, char *argv[])
{

    generarProductos(argv[1]);
    generarMovimientos(argv[2]);
    puts("Productos\n");
    mostrarArchivo(argv[PARAM_PRODUCTOS]);
    puts("\nMovimientos\n");
    mostrarArchivo(argv[PARAM_MOVIMIENTOS]);
    actualizarProductos(argv[PARAM_PRODUCTOS], argv[PARAM_MOVIMIENTOS]);
    puts("\nProductos Actualizados\n");
    mostrarArchivo(argv[PARAM_PRODUCTOS]);

    return TODO_OK_MAIN;
}
