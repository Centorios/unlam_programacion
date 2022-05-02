#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../SolucionParcialBanco/Transferencia.h"
#include "../SolucionParcialBanco/SolucionParcialBanco.h"
#include "main.h"
int txtVarABin(char* linea, Transferencia* transf);
//BURNOWICZ ALEJO 42646860
int main()
{
    generarArchivos();

	puts("Antes de actualizar:\n");

	int ret;

	ret = mostrarCuentas(NOMBRE_CUENTAS);

	if(ret != TODO_OK)
		return ret;

	ret = mostrarTransferencias(NOMBRE_TRANSF);

	if(ret != TODO_OK)
		return ret;
/*
    ret = procesarTransferencias(NOMBRE_TRANSF, NOMBRE_TRANSF_SENTANDER_TXT, NOMBRE_TRANSF_YCBC_TXT, NOMBRE_CUENTAS,
		NOMBRE_TRANSF_SENTANDER_ESTADO, NOMBRE_TRANSF_YCBC_ESTADO);
*/
	/****** DESCOMENTE ESTE CÓDIGO Y COMENTE EL DE ARRIBA PARA PROBAR SU CÓDIGO **********/

    ret = procesarTransferencias_alu(NOMBRE_TRANSF, NOMBRE_TRANSF_SENTANDER_TXT, NOMBRE_TRANSF_YCBC_TXT, NOMBRE_CUENTAS,
		NOMBRE_TRANSF_SENTANDER_ESTADO, NOMBRE_TRANSF_YCBC_ESTADO);


	if(ret != TODO_OK)
		return ret;

	puts("Despues de actualizar:\n");

	ret = mostrarCuentas(NOMBRE_CUENTAS);

	if(ret != TODO_OK)
		return ret;

	ret = mostrarTransferencias(NOMBRE_TRANSF);

    return ret;
}


int procesarTransferencias_alu(
	const char* nombreTransf, const char* nombreTransfSentander, const char* nombreTransfYCBC, const char* nombreCuentas,
	const char* nombreTransfSantanderEstado, const char* nombreTransfYCBCEstado)
{
    convertirTxtABinario_alu(nombreTransfSentander,NOMBRE_TRANSF_SENTANDER_BIN);
    convertirTxtABinario_alu(nombreTransfYCBC,NOMBRE_TRANSF_YCBC_BIN);

    mergeTransfer( NOMBRE_TRANSF_SENTANDER_BIN, NOMBRE_TRANSF_YCBC_BIN, NOMBRE_TRANSF_MERGED1 ); //primer merge entre sentander y ycbc (esto se castea adentro de actualizarcuentaytrasnferencias)

    actualizarCuentasYTransferencias(NOMBRE_TRANSF_MERGED1,nombreCuentas,nombreTransfSantanderEstado,nombreTransfYCBCEstado,nombreTransf);
    return 1;
}


int convertirTxtABinario_alu(const char* nombreTransfTxt, const char* nombreTransfBin)
{
    FILE* bin=fopen(nombreTransfBin,"wb");

    if(!bin)
        return 0;

    FILE* txt = fopen(nombreTransfTxt,"rt");

    if(!txt)
        {
        fclose(bin);
        return 0;
        }

    char linea[TAM_LINEA];
    Transferencia transf;

    fgets(linea,TAM_LINEA,txt); //este lee el header
    fgets(linea,TAM_LINEA,txt); //este salta el header

    //aca adentro tengo que eliminar la primera linea si es que estoy en alguno de los archivos con trasnferencias header

    while(!feof(txt))
    {
        if(txtVarABin(linea,&transf)==ERR_LINEA_LARGA)
            {
            fclose(bin);
            fclose(txt);
            return ERR_LINEA_LARGA;
            }

        fwrite(&transf,sizeof(Transferencia),1,bin);
        fgets(linea,TAM_LINEA,txt);
    }

    fclose(bin);
    fclose(txt);

    return TODO_OK;

}


int mergeTransfer_alu(const char* nombreTransf1, const char* nombreTransf2, const char* nombreTransfMerge)
{
	//PRIMERO ENTRE LAS TRANSFERENCIAS Y DESPUES CONTRA BANCO PATAGANIA (RESULTADO DEL ARCHIVO : BIANRIO)
    return 0;
}


int actualizarCuentasYTransferencias_alu(
	const char* nombreTransfMerge, const char* nombreCuentas, const char* nombreTransfSantanderEstado, const char* nombreTransfYCBCEstado,
	const char* nombreTransf)
{
	mergeTransfer(NOMBRE_TRANSF_MERGED1,nombreTransf,NOMBRE_TRANSF_MERGED2); //segundo merge entre el archivo anterior y lo de patagonia (esto se castea adentro de actualizarcuentaytrasnferencias)
    Transferencia transf;

    FILE* Actualizar = fopen(NOMBRE_TRANSF_MERGED2,"rb");

    if(!Actualizar)
    {
        return 0;
    }

    FILE* cuentas = fopen(nombreCuentas,"rb");

    if(!Actualizar)
    {
        return 0;
    }


    fread(&transf,sizeof(Transferencia),1,Actualizar);

    Lista pl;
    crearLista(&pl); //ACA CAE EL ACTUALIZAR

    Lista pl2;
    crearLista(&pl2);//ACA CAE EL CUENTAS.DAT

    while(!feof(cuentas))
    {
        if(!insertarEnListaAlFinal(&pl2,&Cuenta,sizeof(Cuenta)))
        {
            return 0;
        }
    }



    while(!feof(Actualizar))
    {
        Fecha aux;
        aux.anio=transf.fecha.anio;
        aux.mes=transf.fecha.mes;
        aux.dia=transf.fecha.dia;
        if(!insertarEnListaAlFinal(&pl,&transf,sizeof(transf)))
        {
            return 0;
        }
        fread(&transf,sizeof(Transferencia),1,Actualizar);

        while(difEnDiasEntreFechas(aux,transf.fecha)== 0)
        {
                    if(!insertarEnListaAlFinal(&pl,&transf,sizeof(transf)))
                    {
                        return 0;
                    }
                    fread(&transf,sizeof(Transferencia),1,Actualizar);
        }


    }



    return 0;
}


    int txtVarABin(char* linea, Transferencia* transf)
{
    char* act = strchr(linea, '\n'); //busca el caracter en linea, si lo encuentra me devuelve su posicion.
                                    //busco de derecha a izq, por eso busco el fin de cadena.
    if(!act)
        return ERR_LINEA_LARGA;

    *act = '\0';
                                    //deberia checkear que la la cantidad de '|' sea campos la linea - 1.
    act = strrchr(linea, '|');      //la version que tiene doble "r" me devuelve la posicion del ultimo '|' encontrado, no del primero.

    sscanf(act+1, "%lf", &transf->monto);
    *act = '\0';
    //PRIMER CAMPO

    act = strrchr(linea, '|');
    strncpy(transf->bancoDest,act +1, 50);
    *act = '\0';
    //SEGUNDO CAMPO

    act = strrchr(linea, '|');
    strncpy(transf->cuentaDest,act +1,50);
    *act = '\0';
    //TERCER CAMPO


    act = strrchr(linea, '|');
    strncpy(transf->bancoOrig, act + 1, 50);
    *act = '\0';


    act = strrchr(linea, '|');
    strncpy(transf->cuentaOrig, act + 1, 50);
    *act = '\0';

    sscanf(linea,"%d-%d-%d",&transf->fecha.dia,&transf->fecha.mes,&transf->fecha.anio);

    return TODO_OK;
}



//PONER APELLIDO_NOMBRE_DNI_PARCIAL1    (LA ETREGA SE HACE EN LA PARTE PRACTICAS DE MIEL)
