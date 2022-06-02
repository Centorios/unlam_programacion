#include <stdio.h>
#include <stdlib.h>
#include "../TDAArbolImplDinamica/arbol.h"

int comparaInt(const void* a, const void* b)
{
    int* c = (int*)a;
    int* d = (int*)b;
    return *c - *d;

}



int main()
{
    Arbol arbol;
    crearArbol(&arbol);
    int arr [] = {70,80,90,85,50,60,40};
    insertarEnArbolRecursivo(&arbol,&arr[0],sizeof(int),&comparaInt,NULL);
    insertarEnArbolRecursivo(&arbol,&arr[1],sizeof(int),&comparaInt,NULL);
    insertarEnArbolRecursivo(&arbol,&arr[2],sizeof(int),&comparaInt,NULL);
    insertarEnArbolRecursivo(&arbol,&arr[3],sizeof(int),&comparaInt,NULL);
    insertarEnArbolRecursivo(&arbol,&arr[4],sizeof(int),&comparaInt,NULL);
    insertarEnArbolRecursivo(&arbol,&arr[5],sizeof(int),&comparaInt,NULL);
    insertarEnArbolRecursivo(&arbol,&arr[6],sizeof(int),&comparaInt,NULL);
    int dato;
    if(buscarNodo(&arbol,&arr[6],sizeof(int),&comparaInt,&dato))
    {
        printf("%d",(int)dato);
    }
    else
    {
        puts("no se encontro el elemento");
    }

    int falopa = 120;
    if(buscarNodo(&arbol,&falopa,sizeof(int),&comparaInt,&dato))
    {
        printf("%d",(int)dato);
    }
    else
    {
        puts("no se encontro el elemento");
    }
    return 0;
}
