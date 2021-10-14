/*
 * publicacion.c
 *
 *  Created on: 13 oct. 2021
 *      Author: mati_
 */
#include <stdio.h>
#include <stdlib.h>
#include "publicacion.h"
#include "funciones.h"
#include "cliente.h"
#define PUASADA 2
//MENU
/*

	setbuf(stdout, NULL);
	char seguir= 's';
	//Display displaysList[DISPLEYS_LEN];
	//disp_initList(displaysList,DISPLEYS_LEN);
	//char test[20];
	int opcion;

	do{
		utn_getInt(&opcion, " 1-Dar de Alta\n 2-Modificar\n 3-Dar de baja\n 4-Salir\n", "error ingrese numeros validos", 1, 4, 4);
		switch(opcion)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			seguir='n';
			break;
		}
	}while(seguir=='s');
 *
 *
 */
int publicacion_inicializarArray( Publicacion lista[],int len)
{
	int retorno =-1;
	if(lista != NULL)
	{
		for(int i=0;i<len;i++)
		{
			lista[i].flagEmpty=VACIO;
			retorno=1;

		}
	}
	return retorno;

}
int publicacion_dameIdNuevo(void)
{
	static int contador=0;
	contador++;
	return contador;

}
int publicacion_buscarLugarLibre(Publicacion displaysList[],int len)
{

	int i;
	int indice=-1;
	for(i=0; i<len; i++)
	{
		if(displaysList[i].flagEmpty==VACIO)
		{
			indice=i;
			break;
		}
	}
	return indice;
}
void publicacion_mostrarStructura(Publicacion mostrar [],int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(mostrar[i].flagEmpty==OCUPADO)
        {
            printf("Id:%d texto de la publicacion: %s       numero de rubro: %d  idcliente: %d \n",mostrar[i].id,mostrar[i].textoDelAviso,mostrar[i].numeroDeRubro,mostrar[i].idCliente);

        }
    }

}
int publicacion_buscarId(Publicacion listado[],int len, int id,int* indice)
{
    int retorno = -1;
    int i;
    if(len > 0 && listado != NULL)
    {
        retorno = -1;
        for(i=0; i<len; i++)
        {
            if(listado[i].flagEmpty == 0 && listado[i].id == id)
            {
                retorno = 0;
                *indice=i;
                break;
            }
        }
    }
    return retorno;
}


int publicacion_alta( Publicacion lista_publicacion[],int len,Cliente lista[],int lenCliente)
{
	int retorno=0;
	int indice;
	int idCliente;
	int indiceCliente;
	int retornoOpcion;
	if (len!=0&&lista_publicacion!=NULL)
	{
		indice=publicacion_buscarLugarLibre(lista_publicacion, len);
		if(indice>=0)
		{
			cliente_mostrarStructura(lista, lenCliente);
			utn_getInt(&idCliente, "\ningrese el id del cliente \n", "error reingrese \n", 0, len, 10);
			retornoOpcion=cliente_buscarId(lista, len, idCliente,&indiceCliente);
			if(retornoOpcion!=-1)
			{
				lista_publicacion[indice].idCliente=idCliente;
				utn_getInt(&lista_publicacion[indice].numeroDeRubro, "ingrese el numero de rubro\n", "error reingrese\n", 1, 898989, 10);
				getString("ingrese texto de aviso \n",lista_publicacion[indice].textoDelAviso );
				lista_publicacion[indice].id=publicacion_dameIdNuevo();
				lista_publicacion[indice].flagEmpty=OCUPADO;
				printf("se cargo correctamente la publicacion: \n");
				publicacion_mostrarUno(lista_publicacion, indice);
				//lista[indiceCliente].contadorPublicacion=lista[indiceCliente].contadorPublicacion+1;

			}
			else
				printf("el id no existe \n");
		}
	}


	return retorno;
}
void publicacion_mostrarUno(Publicacion lista[],int i)
{
	 printf("Id:%d texto de la publicacion: %s         numero de rubro: %d  idcliente: %d \n",lista[i].id,lista[i].textoDelAviso,lista[i].numeroDeRubro,lista[i].idCliente);
}
int publicacion_modificar(Publicacion displaysList[],int len)
{
	int idAux;
	int retorno=0;
	int indice;
	int retornoId;
//	int auxContinuar=1;

	publicacion_mostrarStructura(displaysList, len);
	utn_getInt(&idAux, "ingrese el id a modidficar \n", "error ingrese un numero\n", 1, len, 5);
	retornoId=publicacion_buscarId(displaysList, len, idAux,&indice);
	if (len!=0&&displaysList!=NULL)
	{
			if(retornoId!=-1)
			{
			//	publicacion_menuModificar(displaysList, len, indice);
				retorno=1;
			//	indice=-1;
			}
			else
			{
				printf("no se encontro el id\n");
			}
	}
	return retorno;
	}


/*int deseaContinuar(void)
{
	int continuar;
	int retorno;
	utn_getInt(&continuar,"desea seguir modificando \n 1-si 2-no\n","error reingrese",1,2,4);
		if(continuar==1)
		{
			retorno=1;
		}
		else
			retorno=-1;

}*/
/*int publicacion_menuModificar(Publicacion displaysList[],int len,int indice)
{
	int retorno=-1;
	int opcion;
	char auxNombre[20];
	char auxDireccion[20];
	float precioAux;
	//int continuar;

	utn_getInt(&opcion, " Que desea modificar? \n 1-NOMBRE\n 2-PRECIO\n 3-DIRECCION\n", "error ingrese un numero valid\n", 1, len, 5);

	switch(opcion)
	{
	case 1:
		getString("ingrese el nuevo nombre", auxNombre);
		strncpy(displaysList[indice].name,auxNombre,sizeof(displaysList->name));
		break;
	case 2:
		utn_getFloat(&precioAux, "ingrese nuevo precio", "error ingrese numero validos", 1, 9999, 3);
		displaysList[indice].price=precioAux;
		break;
	case 3:
		getString("ingrese la nueva direccion", auxDireccion);
		strncpy(displaysList[indice].addres,auxDireccion,sizeof(displaysList->addres));
		break;
	default:
		printf("no es un numero valido \n");
		break;
	}


return retorno;
}
*/
int publicacion_buscarCliente(Publicacion listado[],int len, int indice,Cliente cliente_lista[])
{
    int retorno = -1;
    int i;
    if(len > 0 && listado != NULL)
    {
        retorno = -1;
        for(i=0; i<len; i++)
        {
            if(listado[indice].idCliente ==cliente_lista[i].id)
            {
            	cliente_mostrarUno(cliente_lista, i);
                retorno = 0;

                break;
            }
        }
    }
    return retorno;
}
void publicacion_mostrarPausada(Publicacion mostrar [],int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(mostrar[i].flagEmpty==PAUSADA)
        {
            printf("Id:%d texto de la publicacion: %s       numero de rubro: %d  idcliente: %d \n",mostrar[i].id,mostrar[i].textoDelAviso,mostrar[i].numeroDeRubro,mostrar[i].idCliente);

        }
    }

}
int publicacion_pausar(Publicacion lista[],int len,Cliente cliente_lista[],int lenCliente)
{
	int auxId;
	int retorno=0;
	int retornoId;
	//int idCliente;
	publicacion_mostrarStructura(lista, len);
	int indice;
	utn_getInt(&auxId, "ingrese el ide que quiere de dar de baja \n", "error ingrese un numero valido", 1, len, 4);

	if (len!=0&&lista!=NULL)
	{

			retornoId=publicacion_buscarId(lista, len, auxId,&indice);
			if(retornoId!=-1)
			{
				printf("cliente que usa este servicio \n");
				publicacion_buscarCliente(lista, lenCliente, indice, cliente_lista);
				publicacion_pausarMenu(lista, len, indice);
			//	lista[indiceCliente].contadorPublicacion=lista[indiceCliente].contadorPublicacion-1;
			//retorno=1;

			}
			else
			{
				printf("no existe el id\n");
			}

		}
	return retorno;
	}


int publicacion_pausarMenu(Publicacion lista[],int len,int indice)
{
	int auxBaja;
	int retorno=-1;

	if (len!=0&&lista!=NULL)
	{
		//publicacion_mostrarUno(displaysList, indice);
		utn_getInt(&auxBaja, "Aprete 1 para dar de baja 2 para cancelar\n", "error ingrese un numero valido\n", 1, 2, 3);

		if (auxBaja==1)
		{
			printf("se dio de baja\n");
			lista[indice].flagEmpty=PAUSADA;
			retorno=1;
		 }
		 else
		 {
			 printf("no se dio de baja\n");
			 retorno=0;
		 }

	}
	return retorno;
}
int publicacion_contadorAvisos(Publicacion lista_publicacion[], int len_publicacion,Cliente lista_cliente[],int len_clinente)
{
	int contador=0;


	for (int i=0;i<len_publicacion;i++)
	{
		for (int j=0;j<len_clinente;j++)
		{
			if(lista_publicacion[i].flagEmpty==OCUPADO&&lista_cliente[j].flagEmpty==OCUPADO)
			{
				if(lista_publicacion[i].idCliente==lista_cliente[j].id)
				{
					lista_cliente[j].contadorPublicacion++;
					contador++;
				}
			}
		}
	}
	cliente_mostrarStructura(lista_cliente, len_clinente);

	return contador;
}




















