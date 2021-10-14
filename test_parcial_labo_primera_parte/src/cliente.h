/*
 * cliente.h
 *
 *  Created on: 13 oct. 2021
 *      Author: mati_
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define OCUPADO 0
#define VACIO 1
typedef struct {

	int cuit;// 0 lcd 1 plasma
	int id;
	char nombre[128];
	char apellido[128];
	int flagEmpty;
}Cliente;

int cliente_inicializarArray( Cliente lista[],int len);
int cliente_alta( Cliente lista[],int len);
int cliente_buscarLugarLibre(Cliente lista[],int len);
int cliente_dameIdNuevo(void);
void cliente_mostrarStructura(Cliente mostrar [],int len);
int cliente_buscarId(Cliente listado[],int len, int id,int* idCliente);
int cliente_menuModificar(Cliente lista[],int len,int indice);
int cliente_modificar(Cliente lista[],int len);
void cliente_mostrarUno(Cliente lista[],int indice);
int cliente_bajaMenu(Cliente lista[],int len,int indice);
int cliente_baja(Cliente lista[],int len);
void transefrirDatos(Cliente listado  [],Cliente auxiliarListado  [],int len);
char esqueleto_reemplazarTipo(int tipo,char *retorno,int len);
int cliente_ordenarArraySegunCriterio(Cliente lista [], int len, int orden);
int cliente_altaHardcodeada(Cliente lista[],char* nombre,char * direccion,int cuil,int flagEmpty,int len,int indice);


#endif /* CLIENTE_H_ */
