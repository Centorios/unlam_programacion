#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxiliares.h"

int cambiarExtension(const char *nombreOrigen,char *nombreDestino, char *extension)
{
    strcpy(nombreDestino, nombreOrigen);
    char *puntoDir = strrchr(nombreDestino, '.');
    if (puntoDir == NULL)
    {
        return ERROR_EXTENSION;
    }

    strcpy(puntoDir + 1, extension);

    return 1;
}

int mostrarArchivo(const char *nombreArchivo)
{
    FILE *archivo;
    Producto producto;

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        return ERROR_ARCHIVO;
    }
    else
    {
        while (fread(&producto, sizeof(Producto), 1, archivo) == 1)
        {
            printf("Codigo: %d ", producto.codigo);
            printf("Nombre: %s ", producto.nombre);
            printf("Cantidad: %d ", producto.cantidad);
            printf("Precio: %.2f ", producto.precio);
            puts("");
        }
        fclose(archivo);
    }
    return TODO_OK_MAIN;
}

int actualizarProductos(const char *nombreArchivoProductos, const char *nombreArchivoMovimientos)
{
    FILE *archivoProductos = fopen(nombreArchivoProductos, "rb");
    FILE *archivoMovimientos = fopen(nombreArchivoMovimientos, "rb");
    if (archivoProductos == NULL || archivoMovimientos == NULL)
    {
        printf("Error al abrir archivos\n");
        return ERROR_ARCHIVO;
    }

    char nombreTemporal[MAX_NOMBRE_ARCHIVO];
    cambiarExtension(nombreArchivoProductos, nombreTemporal, ".tmp");
    FILE *archivoProductosNuevo = fopen(nombreTemporal, "wb");

    if (archivoProductosNuevo == NULL)
    {
        printf("Error al abrir archivo temporal\n");
        return ERROR_ARCHIVO;
    }

    Producto prod1, prodNue, mov;
    int comp;

    fread(&prod1, sizeof(Producto), 1, archivoProductos);
    fread(&mov, sizeof(Producto), 1, archivoMovimientos);

    while (!feof(archivoProductos) && !feof(archivoMovimientos))
    {
        comp = prod1.codigo - mov.codigo;
        if (comp == 0) // El producto existe, actualizar stock
        {
            prod1.cantidad += mov.cantidad;
            fread(&mov, sizeof(Producto), 1, archivoMovimientos);
        }
        if (comp < 0) // Ese producto no tiene movimientos, lo grabo
        {
            fwrite(&prod1, sizeof(Producto), 1, archivoProductosNuevo);
            fread(&prod1, sizeof(Producto), 1, archivoProductos);
        }
        if (comp > 0) // Tengo un producto nuevo del lado de movimientos
        {
            prodNue = mov;
            fread(&mov, sizeof(Producto), 1, archivoMovimientos);
            while (!feof(archivoMovimientos) && mov.codigo == prodNue.codigo) // parche para contemplar movimientos repetidos no depurados
            {
                prodNue.cantidad += mov.cantidad;
                fread(&mov, sizeof(Producto), 1, archivoMovimientos);
            }
            fwrite(&prodNue, sizeof(Producto), 1, archivoProductosNuevo);
        }
    }

    while (!feof(archivoProductos)) // while para ver si me quedaron pendiente productos
    {
        fwrite(&prod1, sizeof(Producto), 1, archivoProductosNuevo);
        fread(&prod1, sizeof(Producto), 1, archivoProductos);
    }

    while (!feof(archivoMovimientos)) // while para ver si me quedaron pendiente movimientos
    {
        prodNue = mov;
        fread(&mov, sizeof(Producto), 1, archivoMovimientos);
        while (!feof(archivoMovimientos) && mov.codigo == prodNue.codigo) // parche para contemplar movimientos repetidos no depurados
        {
            prodNue.cantidad += mov.cantidad;
            fread(&mov, sizeof(Producto), 1, archivoMovimientos);
        }
        fwrite(&prodNue, sizeof(Producto), 1, archivoProductosNuevo);
    }

    fclose(archivoProductos);
    fclose(archivoMovimientos);
    fclose(archivoProductosNuevo);

    remove(nombreArchivoProductos);
    rename(nombreTemporal, nombreArchivoProductos);

    return 1;
}

int generarProductos(const char *nombreDeArchivo)
{
    FILE *archivoProductos = fopen(nombreDeArchivo, "wb");
    if (archivoProductos == NULL)
    {
        printf("Error al abrir archivo\n");
        return ERROR_ARCHIVO;
    }

    Producto producto;
    producto.codigo = 1;
    strcpy(producto.nombre, "Leche");
    producto.cantidad = 10;
    producto.precio = 2.5;
    fwrite(&producto, sizeof(Producto), 1, archivoProductos);

    producto.codigo = 2;
    strcpy(producto.nombre, "Pan");
    producto.cantidad = 10;
    producto.precio = 1.5;
    fwrite(&producto, sizeof(Producto), 1, archivoProductos);

    producto.codigo = 3;
    strcpy(producto.nombre, "Arroz");
    producto.cantidad = 10;
    producto.precio = 3.5;
    fwrite(&producto, sizeof(Producto), 1, archivoProductos);

    producto.codigo = 4;
    strcpy(producto.nombre, "Aceite");
    producto.cantidad = 10;
    producto.precio = 5.5;
    fwrite(&producto, sizeof(Producto), 1, archivoProductos);

    producto.codigo = 5;
    strcpy(producto.nombre, "Sal");
    producto.cantidad = 10;
    producto.precio = 1.5;
    fwrite(&producto, sizeof(Producto), 1, archivoProductos);

    producto.codigo = 6;
    strcpy(producto.nombre, "Azucar");
    producto.cantidad = 10;
    producto.precio = 1.5;
    fwrite(&producto, sizeof(Producto), 1, archivoProductos);

    producto.codigo = 35;
    strcpy(producto.nombre, "Palmitos");
    producto.cantidad = 40;
    producto.precio = 1.5;
    fwrite(&producto, sizeof(Producto), 1, archivoProductos);

    fclose(archivoProductos);

    return 1;
}

int generarMovimientos(const char *nombreDeArchivo)
{
    FILE *archivoMovimientos = fopen(nombreDeArchivo, "wb");
    if (archivoMovimientos == NULL)
    {
        printf("Error al abrir archivo\n");
        return ERROR_ARCHIVO;
    }

    Producto producto;
    producto.codigo = 1;
    strcpy(producto.nombre, "Leche");
    producto.cantidad = 10;
    producto.precio = 2.5;
    fwrite(&producto, sizeof(Producto), 1, archivoMovimientos);

    producto.codigo = 2;
    strcpy(producto.nombre, "Pan");
    producto.cantidad = 10;
    producto.precio = 1.5;
    fwrite(&producto, sizeof(Producto), 1, archivoMovimientos);

    producto.codigo = 3;
    strcpy(producto.nombre, "Arroz");
    producto.cantidad = 10;
    producto.precio = 3.5;
    fwrite(&producto, sizeof(Producto), 1, archivoMovimientos);

    producto.codigo = 3;
    strcpy(producto.nombre, "Arroz");
    producto.cantidad = 20;
    producto.precio = 3.5;
    fwrite(&producto, sizeof(Producto), 1, archivoMovimientos);

    producto.codigo = 4;
    strcpy(producto.nombre, "Aceite");
    producto.cantidad = 10;
    producto.precio = 5.5;
    fwrite(&producto, sizeof(Producto), 1, archivoMovimientos);

    producto.codigo = 4;
    strcpy(producto.nombre, "Aceite");
    producto.cantidad = -5;
    producto.precio = 5.5;
    fwrite(&producto, sizeof(Producto), 1, archivoMovimientos);

    producto.codigo = 5;
    strcpy(producto.nombre, "Sal");
    producto.cantidad = 10;
    producto.precio = 1.5;
    fwrite(&producto, sizeof(Producto), 1, archivoMovimientos);

    producto.codigo = 6;
    strcpy(producto.nombre, "Azucar");
    producto.cantidad = 10;
    producto.precio = 1.5;
    fwrite(&producto, sizeof(Producto), 1, archivoMovimientos);

    fclose(archivoMovimientos);

    return 1;
}
