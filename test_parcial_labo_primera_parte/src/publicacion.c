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
int publicacion_buscarId(Publicacion listado[],int len, int id)
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
                retorno = i;
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
	int existeId;
	if (len!=0&&lista_publicacion!=NULL)
	{
		indice=publicacion_buscarLugarLibre(lista_publicacion, len);
		if(indice>=0)
		{
			cliente_mostrarStructura(lista, lenCliente);
			printf("asd");
			utn_getInt(&idCliente, "ingrese el id del cliente \n", "error reingrese \n", 0, len, 10);
			existeId=cliente_buscarId(lista, len, idCliente,&existeId);
			if(existeId!=-1)
			{
				lista_publicacion[indice].idCliente=idCliente;
				utn_getInt(&lista_publicacion[indice].numeroDeRubro, "ingrese el numero de rubro\n", "error reingrese\n", 1, len, 10);
				getString("ingrese texto de aviso \n",lista_publicacion[indice].textoDelAviso );
				lista_publicacion[indice].id=publicacion_dameIdNuevo();
				lista_publicacion[indice].flagEmpty=OCUPADO;
				printf("se cargo correctamente la publicacion: \n");
				publicacion_mostrarUno(lista_publicacion, indice);

			}
			else
				printf("el id no existe \n");

			/*utn_getInt(&displaysList[indice].type, "ingrese 0 para lcd \ningrese 1 para led\n ", "error reingrese 0 para lcd \ningrese 1 para led\n ", 0, 1, 100);
			utn_getFloat(&displaysList[indice].price, "ingrese el precio", "error reingrese ", 1, 555555, 10);
			getString("ingrese el nombre",displaysList[indice].name );
			getString("ingrese la direccion",displaysList[indice].addres);
			displaysList[indice].id=publicacion_dameIdNuevo();
			retorno =1;
			displaysList[indice].flagEmpty=0;
			*/
		}
	}


	return retorno;
}
void publicacion_mostrarUno(Publicacion lista[],int i)
{
	 printf("Id:%d texto de la publicacion: %s       numero de rubro: %d  idcliente: %d \n",lista[i].id,lista[i].textoDelAviso,lista[i].numeroDeRubro,lista[i].idCliente);
}
int publicacion_modificar(Publicacion displaysList[],int len)
{
	int idAux;
	int retorno=0;
	int indice;
//	int auxContinuar=1;

	publicacion_mostrarStructura(displaysList, len);
	utn_getInt(&idAux, "ingrese el id a modificar \n", "error ingrese un numero\n", 1, len, 5);
	indice=publicacion_buscarId(displaysList, len, idAux);
	if (len!=0&&displaysList!=NULL)
	{
			if(indice!=-1)
			{
			//	publicacion_menuModificar(displaysList, len, indice);
				retorno=1;
				indice=-1;
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
/*int esqueleto_baja(Publicacion displaysList[],int len)
{
	int auxId;
	int retorno=0;
	publicacion_mostrarStructura(displaysList, len);
	int indice;
	utn_getInt(&auxId, "ingrese el ide que quiere de dar de baja \n", "error ingrese un numero valido", 1, len, 4);

	if (len!=0&&displaysList!=NULL)
	{

			indice=publicacion_buscarId(displaysList, len, auxId);
			if(indice!=-1)
			{

			publicacion_bajaMenu(displaysList, len, indice);
			retorno=1;

			}
			else
			{
				printf("no existe el id\n");
			}

		}
	return retorno;
	}
*/

/*int publicacion_bajaMenu(Publicacion displaysList[],int len,int indice)
{
	int auxBaja;
	int retorno;

	if (len!=0&&displaysList!=NULL)
	{
		publicacion_mostrarUno(displaysList, indice);
		utn_getInt(&auxBaja, "Aprete 1 para dar de baja 2 para cancelar", "error ingrese un numero valido", 1, 2, 3);

		if (auxBaja==1)
		{
			printf("se dio de baja\n");
			displaysList[indice].flagEmpty=2;
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
*/
