#include <stdio.h>
#include <stdlib.h>
#include "../TDAPilaDinamicaCircular/pilacircular.h"
int main()
{
    printf("Hello world!\n");
    Pila p1;
    crearPila(&p1);
    int a = 45;
    int b = 40;
    int aux;
    apilar(&p1,&a,sizeof(int));
    apilar(&p1,&b,sizeof(int));
    desapilar(&p1,&aux,sizeof(int));
    printf("%d",aux);
    desapilar(&p1,&aux,sizeof(int));
        printf("%d",aux);
    return 0;
}
