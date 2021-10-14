/*
 * funciones.h
 *
 *  Created on: 9 sep. 2021
 *      Author: palom
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#ifndef FUNCIONES_H_
#define FUNCIONES_H_
int myGets(char* cadena, int longitud);
int getInt(char *cadena,int* aux);
int pedirMensaje (char pResultado[], int len,char mensaje[]);
int max(int num1, int num2);
void imprimirFloatArray(float array[],int len);
int inicializadorArrayFloat( float array[],int len,int valorInicial);
int inicializadorArrayInt( float array[],int len,int valorInicial);
void imprimirIntArray(int arrayImprimir[],int len);
int filtrarParArray(int arrayPar [],int len);
int pedirFloatInt(int arrayFloat[],int len);
int pedirFloatArray(float arrayFloat[],int len);
int pedirMensajeParaOrdenerArrays();
int ordenarArrayIntSegunCriterio(int arrayParaOrdenar[], int len);
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int esNumerico(char str[]);
int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);
char getString(char cadena[],char retorno[]);
char getAlfaNumerico(char cadena[],char *retorno);
int esTelefono(char str[]);
int esEmail(char str[]);
char getEmail(char cadena[],char *retorno);
int getFloat(char *mensaje,float* resultado);
int esNumericoFlotante(char str[]);
float utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

//int getString(char cadena[],char *retorno[]);

#endif /* FUNCIONES_H_ */
