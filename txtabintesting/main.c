#include <stdio.h>
#include <stdlib.h>
#include "empleadostruct.h"
#define TAM_EMPLEADOS 6
int main()
{
//////////////////////////////////////////////////////////////PLACEHOLDER DE ARCHIVO BINARIO///////////////////////////////////////////////////////////////////////////////
    FILE* archivoBinarioEsc = fopen("empleados.bin","wb");

    FILE* archivoDeTexto = fopen("empleados.txt","wt");



    if(!archivoDeTexto || !archivoBinarioEsc)
    {
        return 1;
    }

    Empleado empleadoBin[TAM_EMPLEADOS] =
    {
        {42646860,"Alejo Burnowicz",{6,6,2000},'M',80000.50},
        {11223344,"Armando Esteban",{1,8,1980},'C',180000.50},
        {22334455,"Armando paredes",{2,7,1975},'B',280000.50},
        {33445566,"Cabeza de huevo",{3,6,1200},'D',810000.50},
        {44556677,"El masca pito",{4,5,1600},'E',85000.50},
        {55667788,"jonhy me la lavo",{5,3,1900},'F',80070.50},
    };

    fwrite(&empleadoBin,sizeof(Empleado),TAM_EMPLEADOS,archivoBinarioEsc);
    fclose(archivoBinarioEsc);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FILE* archivoBinario = fopen("empleados.bin","rb");

    if(!archivoBinario)
    {
        return 1;
    }




////////////////////////////////////////////////////////////////DE BINARIO A TEXTO VARIABLE/////////////////////////////////////////////////////////////////////////////
    const char* textoVariable = "%d|%s|%d/%d/%d|%c|%.2f";
    Empleado empleadoBuffer;
    fread(&empleadoBuffer,sizeof(Empleado),1,archivoBinario);
    while(!feof(archivoBinario))
    {

        fprintf(archivoDeTexto,textoVariable,empleadoBuffer.dni,empleadoBuffer.apyn,empleadoBuffer.fNacimiento.dia,empleadoBuffer.fNacimiento.mes,empleadoBuffer.fNacimiento.anio,empleadoBuffer.sexo,empleadoBuffer.sueldo);
        fread(&empleadoBuffer,sizeof(Empleado),1,archivoBinario);
    }

    fclose(archivoBinario);
    fclose(archivoDeTexto);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////DE BINARIO A TEXTO FIJO////////////////////////////////////////////////////////////////////////////////


    FILE* archivoDeTextoFijo = fopen("empleadosfijo.txt","wt");
    FILE* archivoBinarioFijo = fopen("empleados.bin","rb");

    Empleado empleadoBuffer2;

    const char* textoFijo = "%08d%-200s%c%02d%02d%04d%010.2f";
    fread(&empleadoBuffer2,sizeof(Empleado),1,archivoBinarioFijo);

    while(!feof(archivoBinarioFijo))
    {

        fprintf(archivoDeTextoFijo,textoFijo,empleadoBuffer2.dni,empleadoBuffer2.apyn,empleadoBuffer2.fNacimiento.dia,empleadoBuffer2.fNacimiento.mes,empleadoBuffer2.fNacimiento.anio,empleadoBuffer2.sexo,empleadoBuffer2.sueldo);
        fread(&empleadoBuffer2,sizeof(Empleado),1,archivoBinarioFijo);

    }

    fclose(archivoBinarioFijo);
    fclose(archivoDeTextoFijo);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////DE TEXTO A BINARIO/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





    return 0;
}
