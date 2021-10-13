/*
 * esqueleto.h
 *
 *  Created on: 13 oct. 2021
 *      Author: mati_
 */

#ifndef ESQUELETO_H_
#define ESQUELETO_H_

#define OCUPADO 0
#define VACIO 1
typedef struct {

	int type;// 0 lcd 1 plasma
	float price;
	int id;
	char name[128];
	char addres[128];
	int flagEmpty;
}Esqueleto;

int esqueleto_inicializarArray( Esqueleto lista[],int len);
int esqueleto_alta( Esqueleto lista[],int len);
int esqueleto_buscarLugarLibre(Esqueleto lista[],int len);
int dameUnIdNuevo(void);
void esqueleto_mostrarStructura(Esqueleto mostrar [],int len);
int esqueleto_buscarId(Esqueleto listado[],int len, int id);
int esqueleto_menuModificar(Esqueleto lista[],int len,int indice);
int esqueleto_modificar(Esqueleto lista[],int len);
void esqueleto_mostrarUno(Esqueleto lista[],int indice);
int esqueleto_bajaMenu(Esqueleto lista[],int len,int indice);
int esqueleto_baja(Esqueleto lista[],int len);

#endif /* ESQUELETO_H_ */
