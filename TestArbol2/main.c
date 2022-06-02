#include <stdio.h>
#include <stdlib.h>
#include "../TDAArbolImplDinamica/arbol.h"

int comparaInt(const void* a, const void* b)
{
    int* c = (int*)a;
    int* d = (int*)b;
    return *c - *d;

}


void imprimirEnteroArbol(void* elem,const void* dato,int nivel)
{
    int i;
    for(i = 0; i < nivel;i++)
    {
        putchar('\t');
    }
    printf("%d\n",*(int*)elem);
}


int main()
{
    Arbol arbol;
    crearArbol(&arbol);
    int arr [] = {70,80,90,85,50,60,40};
    insertarEnArbolRecursivo(&arbol,&arr[0],sizeof(int),&comparaInt,NULL);
    insertarEnArbolRecursivo(&arbol,&arr[3],sizeof(int),&comparaInt,NULL);
    insertarEnArbolRecursivo(&arbol,&arr[1],sizeof(int),&comparaInt,NULL);
    insertarEnArbolRecursivo(&arbol,&arr[2],sizeof(int),&comparaInt,NULL);
    insertarEnArbolRecursivo(&arbol,&arr[6],sizeof(int),&comparaInt,NULL);
    insertarEnArbolRecursivo(&arbol,&arr[4],sizeof(int),&comparaInt,NULL);
    insertarEnArbolRecursivo(&arbol,&arr[5],sizeof(int),&comparaInt,NULL);

    imprimirArbol(&arbol,imprimirEnteroArbol,NULL,0);

    return 0;
}

