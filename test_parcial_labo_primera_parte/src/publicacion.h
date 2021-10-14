/*
 * publicacion.h
 *
 *  Created on: 13 oct. 2021
 *      Author: mati_
 */

#ifndef PUBLICACION_H_
#define PUBLICACION_H_
#include "cliente.h"
#include "funciones.h"
#define OCUPADO 0
#define VACIO 1
#define PAUSADA 2
typedef struct {

	int idCliente;
	int id;
	int numeroDeRubro;
	char textoDelAviso[64];
	int flagEmpty;
}Publicacion;

int publicacion_inicializarArray( Publicacion lista[],int len);
int publicacion_alta( Publicacion lista_publicacion[],int len,Cliente lista[],int lenCliente);
int publicacion_buscarLugarLibre(Publicacion lista[],int len);
int publicacion_dameIdNuevo(void);
void publicacion_mostrarStructura(Publicacion mostrar [],int len);
int publicacion_buscarId(Publicacion listado[],int len, int id,int* indice);
int publicacion_menuModificar(Publicacion lista[],int len,int indice);
int publicacion_modificar(Publicacion lista[],int len);
void publicacion_mostrarUno(Publicacion lista[],int indice);
int publicacion_pausarMenu(Publicacion lista[],int len,int indice);
int publicacion_pausar(Publicacion lista[],int len,Cliente cliente_lista[],int lenCliente);
int publicacion_buscarCliente(Publicacion listado[],int len, int indice,Cliente cliente_lista[]);
void publicacion_mostrarPausada(Publicacion mostrar [],int len);
int publicacion_contadorAvisos(Publicacion lista_publicacion[], int len_publicacion,Cliente lista_cliente[],int len_clinente);


#endif /* PUBLICACION_H_ */
