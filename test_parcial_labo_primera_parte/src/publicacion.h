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
int publicacion_buscarId(Publicacion listado[],int len, int id);
int publicacion_menuModificar(Publicacion lista[],int len,int indice);
int publicacion_modificar(Publicacion lista[],int len);
void publicacion_mostrarUno(Publicacion lista[],int indice);
int publicacion_bajaMenu(Publicacion lista[],int len,int indice);
int publicacion_baja(Publicacion lista[],int len);


#endif /* PUBLICACION_H_ */
