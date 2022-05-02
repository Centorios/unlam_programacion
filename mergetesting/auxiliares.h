#ifndef AUXILIARES_H_INCLUDED
#define AUXILIARES_H_INCLUDED


#define TODO_OK_MAIN 0
#define TODO_MAL_MAIN 1
#define ERROR_ARCHIVO 3
#define MAX_NOMBRE_ARCHIVO 100
#define MAX_DESCRIPCION_PRODUCTO 50
#define ERROR_EXTENSION 4

typedef struct
{
    int codigo;
    char nombre[MAX_DESCRIPCION_PRODUCTO];
    int cantidad;
    float precio;
} Producto;


int mostrarArchivo(const char *nombreArchivo);
int actualizarProductos(const char *nombreArchivoProductos, const char *nombreArchivoMovimientos);
int cambiarExtension(const char *nombreOrigen,char *nombreDestino,char *extension);
int generarProductos(const char *nombreDeArchivo);
int generarMovimientos(const char *nombreDeArchivo);

#endif // AUXILIARES_H_INCLUDED
