/*
 * esqueleto.c
 *
 *  Created on: 13 oct. 2021
 *      Author: mati_
 */



// 0 lcd 1 led
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "funciones.h"

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
int cliente_inicializarArray( Cliente lista[],int len)
{
	int retorno =-1;
	if(lista != NULL)
	{
		for(int i=0;i<len;i++)
		{
			lista[i].flagEmpty=VACIO;
			lista[i].contadorPublicacion=0;
			retorno=1;

		}
	}
	return retorno;

}
int cliente_dameIdNuevo(void)
{
	static int contador=0;
	contador++;
	return contador;

}
int cliente_buscarLugarLibre(Cliente lista[],int len)
{

	int i;
	int indice=-1;
	for(i=0; i<len; i++)
	{
		if(lista[i].flagEmpty==VACIO)
		{
			indice=i;
			break;
		}
	}
	return indice;
}
void cliente_mostrarStructura(Cliente lista [],int len)
{
    int i;
    printf("id:\t    nombre:\t  apellido:\t cuit:\t");
    for(i=0; i<len; i++)
    {
        if(lista[i].flagEmpty==OCUPADO)
        {
        	 printf("\n%d\t     %s\t      %s\t        %d\t   %d\t",lista[i].id,lista[i].nombre,lista[i].apellido,lista[i].cuit,lista[i].contadorPublicacion);


        }
    }

}
int cliente_buscarId(Cliente listado[],int len, int id,int* indice)
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


int cliente_alta( Cliente lista[],int len)
{
	int retorno=0;
	int indice;
	if (len!=0&&lista!=NULL)
	{
		indice=cliente_buscarLugarLibre(lista, len);
		if(indice>=0)
		{
			getString("ingrese el nombre \n",lista[indice].nombre );
			getString("ingrese la direccion\n",lista[indice].apellido);
			utn_getInt(&lista[indice].cuit, "ingrese su cuit \n","error ingrese un cuil valido", 0, 9999999, 100);
			lista[indice].id=cliente_dameIdNuevo();
			retorno =1;
			lista[indice].flagEmpty=0;
			printf("se dio de alta el cliente: \n");
			cliente_mostrarUno(lista, indice);

		}
	}


	return retorno;
}
void cliente_mostrarUno(Cliente lista[],int i)
{
	printf("Id:%d NOMBRE: %s       DIRECCION: %s CUIL: %d\n",lista[i].id,lista[i].nombre,lista[i].apellido,lista[i].cuit);
}
int cliente_modificar(Cliente lista[],int len)
{
	//int idAux;
	int retorno=0;
	int indice;
	int idAux;



	cliente_mostrarStructura(lista, len);
	utn_getInt(&idAux, "\ningrese el id a modificar \n", "error ingrese un numero \n", 0, len, 5);
	idAux=cliente_buscarId(lista, len, idAux,&indice);
	if (len!=0&&lista!=NULL)
	{
			if(idAux!=-1)
			{
				cliente_menuModificar(lista, len, indice);
				retorno=1;
				//indice=-1;
				printf("se modifico correctamente el cliente \n");
				cliente_mostrarUno(lista, indice);
			}
			else
			{
				printf("no se encontro el id\n");
			}
	}
	return retorno;
	}

int cliente_menuModificar(Cliente lista[],int len,int indice)
{
	int retorno=-1;
	int opcion;
	char auxNombre[20];
	char auxApellido[20];
	int cuitAux;
	//int continuar;

	utn_getInt(&opcion, " Que desea modificar? \n 1-NOMBRE\n 2-APELLIDO\n 3-CUIT\n", "error ingrese un numero valid\n", 1, len, 5);

	switch(opcion)
	{
	case 1:
		getString("ingrese el nuevo nombre\n", auxNombre);
		strncpy(lista[indice].nombre,auxNombre,sizeof(lista->nombre));
		break;
	case 2:
		getString("ingrese el nuevo apellido \n", auxApellido);
		strncpy(lista[indice].apellido,auxApellido,sizeof(lista->apellido));
		break;
	case 3:
		utn_getInt(&cuitAux, "ingrese el nuevo cuit \n", "error ingrese un cuil valido", 1, 4554544, 2);
		lista[indice].cuit=cuitAux;

		break;
	default:
		printf("no es un numero valido \n");
		break;
	}


return retorno;
}

int cliente_baja(Cliente lista[],int len)
{
	int auxId;
	int retorno=0;
	cliente_mostrarStructura(lista, len);
	int indice;
	utn_getInt(&auxId, "ingrese el id que quiere de dar de baja \n", "error ingrese un numero valido\n", 0, len, 4);

	if (len!=0&&lista!=NULL)
	{

		auxId=cliente_buscarId(lista, len, auxId,&indice);
			if(auxId!=-1)
			{

			cliente_bajaMenu(lista, len, indice);
			retorno=1;

			}
			else
			{
				printf("no existe el id\n");
			}

		}
	return retorno;
	}


int cliente_bajaMenu(Cliente lista[],int len,int indice)
{
	int auxBaja;
	int retorno;

	if (len!=0&&lista!=NULL)
	{
		cliente_mostrarUno(lista, indice);
		utn_getInt(&auxBaja, "Aprete 1 para dar de baja 2 para cancelar", "error ingrese un numero valido", 1, 2, 3);

		if (auxBaja==1)
		{
			printf("se dio de baja\n");
			lista[indice].flagEmpty=2;
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
void transefrirDatos(Cliente listado  [],Cliente auxiliarListado  [],int len)
{
    int i;

    for(i=0;i<len;i++)
    {
       // if(listado[i].isEmpty==OCUPADO)
        {
          /*  listado[i].isEmpty=auxiliarListado[i].isEmpty;
            listado[i].id=auxiliarListado[i].id;
            listado[i].salary=auxiliarListado[i].salary;
            listado[i].sector=auxiliarListado[i].sector;
            strcpy(listado[i].name,auxiliarListado[i].name);
            strcpy(listado[i].lastName,auxiliarListado[i].lastName);*/
        }
    }
}
char esqueleto_reemplazarTipo(int tipo,char *retorno,int len)
{
	char aux[20];

	switch(tipo)
	{
	case 1:
		strncpy(aux,"administracion",sizeof(aux));
		break;
	case 2:
		strncpy(aux,"programacion",sizeof(aux));
		break;

	}
	strncpy(retorno,aux,len);
	return *retorno;

}
int cliente_ordenarArraySegunCriterio(Cliente lista [], int len, int orden)
{
	Cliente Aux;

	int contador = 0;
	char auxTipo[15];
	char auxTipoDos[15];
	switch (orden)
	{
	case 1:

		for (int i = 0; i < len - 1; i++)
		{
			if (lista[i].flagEmpty == OCUPADO)
			{
				if (stricmp(lista[i].nombre, lista[i + 1].nombre) > 0)// descendente
				{
					Aux = lista[i];
					lista[i] = lista[i + 1];
					lista[i + 1] = Aux;
					esqueleto_reemplazarTipo(lista[i].id, auxTipo, len);
					esqueleto_reemplazarTipo(lista[i + 1].id, auxTipoDos, len);
					if (stricmp(auxTipo, auxTipoDos) == 0)
					{
						Aux = lista[i];
						lista[i] = lista[i + 1];
						lista[i + 1] = Aux;
					}
				}
			}
		}
		break;

	case 2:

		for (int i = 0; i < len - 1; i++)// ascendente
		{
			if (lista[i].flagEmpty == OCUPADO)
			{
				if (stricmp(lista[i].nombre, lista[i + 1].nombre) < 0)
				{

					Aux = lista[i];
					lista[i] = lista[i + 1];
					lista[i + 1] = Aux;
					esqueleto_reemplazarTipo(lista[i].id, auxTipo, len);
					esqueleto_reemplazarTipo(lista[i + 1].id, auxTipoDos, len);
					if (stricmp(auxTipo, auxTipoDos) == 0)
					{
						Aux = lista[i];
						lista[i] = lista[i + 1];
						lista[i + 1] = Aux;
					}
				}
			}
		}
		break;
	}


	//falta imprimir array aca
	return contador;

}

/*
 *
 *
 * int type;// 0 lcd 1 plasma
	float price;
	int id;
	char name[128];
	char addres[128];
	int flagEmpty;
 */
int cliente_altaHardcodeada(Cliente lista[],char* nombre,char * direccion,int cuil,int flagEmpty,int len,int indice)
{
	int respuesta=-1;
	if(len > 0 && lista != NULL)
	{

		strncpy(lista[indice].nombre,nombre,sizeof(lista->nombre));
		strncpy(lista[indice].apellido,direccion,sizeof(lista->apellido));
		lista[indice].id=cliente_dameIdNuevo();
		lista[indice].flagEmpty=flagEmpty;
		lista[indice].cuit=cuil;
		respuesta= 0;

	}

	return respuesta;

}

