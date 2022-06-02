#include <stdio.h>
#include <stdlib.h>
#include "../TDAListaSimpleDinamica/lista.h"


void imprimirInt(void* elem, size_t tamElem, void* datosAccion)
{
    printf("%d ",*(int*)elem);
}


int compararInt(const void* a,const void*b)
{
    return *(int*)a - *(int*)b;
}




int main()
{
    Lista lista1,lista2;
    crearLista(&lista1);
    crearLista(&lista2);
    int vec[] = {7,10,325,5,6,87};
    insertarEnListaAlPrincipio(&lista1,&vec[0],sizeof(int));
    insertarEnListaAlPrincipio(&lista1,&vec[1],sizeof(int));
    insertarEnListaAlPrincipio(&lista1,&vec[2],sizeof(int));
    insertarEnListaAlPrincipio(&lista1,&vec[3],sizeof(int));
    insertarEnListaAlPrincipio(&lista1,&vec[4],sizeof(int));
    insertarEnListaAlPrincipio(&lista1,&vec[5],sizeof(int));
    ordenarLista(&lista1,&compararInt);
    recorrerLista(&lista1,&imprimirInt,NULL);
    puts("");
    insertarEnListaAlFinal(&lista2,&vec[0],sizeof(int));
    insertarEnListaAlFinal(&lista2,&vec[1],sizeof(int));
    insertarEnListaAlFinal(&lista2,&vec[2],sizeof(int));
    insertarEnListaAlFinal(&lista2,&vec[3],sizeof(int));
    insertarEnListaAlFinal(&lista2,&vec[4],sizeof(int));
    insertarEnListaAlFinal(&lista2,&vec[0],sizeof(int));
    insertarEnListaAlFinal(&lista2,&vec[0],sizeof(int));
    insertarEnListaAlFinal(&lista2,&vec[5],sizeof(int));
    ordenarLista(&lista2,&compararInt);
    eliminarDeListaDesordenada(&lista2,&vec[0],sizeof(int),&compararInt);
    recorrerLista(&lista2,&imprimirInt,NULL);

    return 0;
}
