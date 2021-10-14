/*
 ============================================================================
 Name        : test_parcial_labo_primera_parte.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "cliente.h"
#include "publicacion.h"
#define CLIENTE_LEN 100
#define PUBLICACION_LEN 1000
int main(void) {
	setbuf(stdout, NULL);
	char seguir= 's';
	//Display displaysList[DISPLEYS_LEN];
	//disp_initList(displaysList,DISPLEYS_LEN);
	//char test[20];
	int opcion;

	Cliente lista_clientes[CLIENTE_LEN];
	cliente_inicializarArray(lista_clientes, CLIENTE_LEN);
	Publicacion lista_publicacion[PUBLICACION_LEN];
	publicacion_inicializarArray(lista_publicacion, PUBLICACION_LEN);

	cliente_altaHardcodeada(lista_clientes, "matias", "a", 1231214, OCUPADO,CLIENTE_LEN,0);
	cliente_altaHardcodeada(lista_clientes, "gonzalo", "v", 441214, OCUPADO,CLIENTE_LEN,1);
	cliente_altaHardcodeada(lista_clientes, "palomo", "s", 11213, OCUPADO,CLIENTE_LEN,2);
	cliente_altaHardcodeada(lista_clientes, "gomez", "b", 121454, OCUPADO,CLIENTE_LEN,3);
	cliente_altaHardcodeada(lista_clientes, "asd", "g", 142314, OCUPADO,CLIENTE_LEN,4);
	int retornoAdd=1;
	//int contador=0;

	do{
		utn_getInt(&opcion, "\n 1-Dar de Alta\n 2-Modificar\n 3-Dar de baja \n 7-Salir\n", "error ingrese numeros validos", 1, 7, 8);
		switch(opcion)
				{
				case 1:
					retornoAdd=cliente_alta(lista_clientes, CLIENTE_LEN);
					cliente_mostrarStructura(lista_clientes, CLIENTE_LEN);
					break;
				case 2:
					if(retornoAdd==1)
						cliente_modificar(lista_clientes, CLIENTE_LEN);
					else
						printf("no hay datos cargados \n");
					break;
				case 3:
					if(retornoAdd==1)
						cliente_baja(lista_clientes, CLIENTE_LEN);
					else
						printf("no hay datos cargados \n");
					break;
				case 4:
					if(retornoAdd==1)
					{
						publicacion_alta(lista_publicacion, PUBLICACION_LEN, lista_clientes,CLIENTE_LEN);

					}
					else
						printf("no hay datos cargados \n");
					break;
				case 5:
					if(retornoAdd==1)
						{
							publicacion_pausar(lista_publicacion, PUBLICACION_LEN, lista_clientes,CLIENTE_LEN);
							publicacion_mostrarPausada(lista_publicacion, PUBLICACION_LEN);
						}
					else
					{
						printf("no hay datos cargados \n");
					}
					break;
				case 6:
					publicacion_contadorAvisos(lista_publicacion, PUBLICACION_LEN, lista_clientes, CLIENTE_LEN);
					break;
				case 7:
					seguir='n';
				}
	}while(seguir=='s');
	return EXIT_SUCCESS;
}
