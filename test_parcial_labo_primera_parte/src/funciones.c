/*
 * funciones.c
 *
 *  Created on: 9 sep. 2021
 *      Author: palom
 *      setbuf(stdout, NULL);
 */
static int myGets(char pResultado[], int len);
#include "funciones.h"
#include "cliente.h"

static int myGets(char pResultado[], int len)
{
    int retorno=-1;
    int indexFinal;
    fflush(stdin);
    if(fgets(pResultado,len,stdin)!=NULL)
    {
        indexFinal = strlen(pResultado)-1;
        if(pResultado[indexFinal] == '\n')
        {
            pResultado[indexFinal] = '\0';
        }
        retorno = 0;

    }
    return retorno;
}



int inicializadorArrayFloat( float array[],int len,int valorInicial)
{
	int retorno=-1;
	for(int i=0;i<len;i++)
		{
			array[i]=valorInicial;
			retorno=0;
		}
	return retorno;
}
int inicializadorArrayInt( float array[],int len,int valorInicial)
{
	int retorno=-1;
	for(int i=0;i<len;i++)
		{
			array[i]=valorInicial;
			retorno=0;
		}
	return retorno;
}
void imprimirFloatArray(float array[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("indice %d, valor %f\n",i+1,array[i]);
	}

}
int pedirFloatArray(float arrayFloat[],int len)
{
	int retorno =-1;
	for(int i=0;i<len;i++)
	{
		printf("ingrese los numeros para meter en el array");
		fflush(stdin);
		scanf("%f",&arrayFloat[i]);
		retorno=0;
	}
	return retorno;
}
int pedirIntArray(int arrayFloat[],int len)
{
	int retorno =-1;
	for(int i=0;i<len;i++)
	{
		printf("ingrese los numeros para meter en el array");
		fflush(stdin);
		scanf("%d",&arrayFloat[i]);
		retorno=0;
	}
	return retorno;
}
void imprimirIntArray(int arrayImprimir[],int len)
{
	if(arrayImprimir!=NULL&&len>=0)
	{
		for(int i=0;i<len;i++)
		{
			printf("indice %d, valor %d\n\n",i,arrayImprimir[i]);
		}

	}
}
int filtrarParArray(int arrayPar [],int len)
{
	int retorno=-1;
	if(arrayPar!=NULL&&len>=0)
	{
		for(int i=0;i<len;i++)
		{
			if(arrayPar[i]% 2== 0 )
			//	if(array[i]% 2 != 0 )impar
			{
				arrayPar[i]=0;
				retorno =0;
			}
		}
	}
	imprimirIntArray(arrayPar, len);
	return retorno;
}
int ordenarArrayIntSegunCriterio(int arrayParaOrdenar[], int len) {
	int aux;
	int contador = 0;
	int criterioParaOrdenar;
	int flagSwap;

	criterioParaOrdenar = pedirMensajeParaOrdenerArrays();

	do
	{
		flagSwap = 0;
		if (criterioParaOrdenar == 1)
		{
			for (int i = 0; i < len - 1; i++)
			{
				if (arrayParaOrdenar[i] < arrayParaOrdenar[i + 1])
				{

					flagSwap = 1;
					aux = arrayParaOrdenar[i];
					arrayParaOrdenar[i] = arrayParaOrdenar[i + 1];
					arrayParaOrdenar[i + 1] = aux;
				}

			}
		}
		else
		{
			for (int i = 0; i < len - 1; i++)
						{
							if (arrayParaOrdenar[i] > arrayParaOrdenar[i + 1])
							{
								flagSwap = 1;
								aux = arrayParaOrdenar[i];
								arrayParaOrdenar[i] = arrayParaOrdenar[i + 1];
								arrayParaOrdenar[i + 1] = aux;
							}

						}



		}
		contador++;

	} while (flagSwap == 1);
	imprimirIntArray(arrayParaOrdenar, len);
	return contador;

}
int pedirMensajeParaOrdenerArrays()
{
	int retorno;
	int opcion;
	do{
	printf("Aprete 1 si quiere ordenar de mayor a menor\n");
	printf("Aprete 2 si quiere ordenar de menor a mayor \n");
	fflush(stdin);
	scanf("%d",&opcion);
	switch(opcion)
	{
	case 1:
		retorno=1;
		break;
	case 2:
		retorno=2;
		break;
	default:
		printf("error datos incorrectos reingrese \n");

	}
	}while(opcion!=1&&opcion!=2);
	return retorno;
}

int max(int num1, int num2)
{
   int result;
   if (num1 > num2)
      {
	   result = num1;
      }
   else
      result = num2;
   return result;
}


/*int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt,mensaje) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}*/
int esNumerico(char str[])
{

	 int i=0;
	 if (str[i] == '-')
	 	{
	 		i = 1;
	 	}
	   while(str[i] != '\0')
	   {
	       if(str[i] < '0' || str[i] > '9')
	           return 0;
	       i++;
	   }

	   return 1;

}
int esNumericoFlotante(char str[])
{

	 int i=0;
	 int contadorDePuntos=0;
	 if (str[i] == '-')
	 	{
	 		i = 1;
	 	}
	   while(str[i] != '\0')
	   {
	       if((str[i] < '0' || str[i] > '9')&& str[i]!='.')
	           return 0;
	       if(str[i]=='.')
	    	   contadorDePuntos++;
	       i++;
	   }
	 if(contadorDePuntos==1)
		 return 1;

	   return 0;

}
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

int pedirMensaje (char pResultado[], int len,char mensaje[])
{

	int retorno = -1;

	if (pResultado != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		if (fgets(pResultado, len, stdin) != NULL)
		{
			retorno = 0;
		}
	}
	return retorno;
}

char getAlfaNumerico(char cadena[],char *retorno)
{

	char auxiliarChar[500];
	printf(cadena);
	if (myGets(auxiliarChar, sizeof(auxiliarChar)) == 0)
	{
		while (!esSoloLetras(auxiliarChar))
		{
			printf("error ingrese solo alfaNumerico ");
			myGets(auxiliarChar, sizeof(auxiliarChar));
		}
	}
	strcpy(retorno, auxiliarChar);

	return *retorno;

}
int getFloat(char *mensaje,float* resultado)
 {
	int retorno=-1;
	char auxiliarChar[50];
	if(resultado !=NULL)
	{

	printf(mensaje);
	myGets(auxiliarChar,sizeof(auxiliarChar));
	while (!esNumericoFlotante(auxiliarChar))
	{

		printf("error reingrese ");
		myGets(auxiliarChar,sizeof(auxiliarChar));
	}
	}
	retorno=1;
	*resultado= atof(auxiliarChar);

	return retorno;
}
int getInt(char *mensaje,int* resultado)
 {
	int retorno=-1;
	char auxiliarChar[50];
	if(resultado !=NULL)
	{

	printf(mensaje);
	myGets(auxiliarChar,sizeof(auxiliarChar));
	while (!esNumerico(auxiliarChar))
	{

		printf("error reingrese ");
		myGets(auxiliarChar,sizeof(auxiliarChar));
	}
	}
	retorno=1;
	*resultado= atoi(auxiliarChar);

	return retorno;
}
char getString(char cadena[],char *retorno)
{


	char auxiliarChar[500];
		printf(cadena);
		if(myGets(auxiliarChar, sizeof(auxiliarChar))==0)
		{
			while(!esSoloLetras(auxiliarChar))
			{
				printf("error ingrese un mail valido");
				myGets(auxiliarChar, sizeof(auxiliarChar));
			}
		}
		strcpy(retorno,auxiliarChar);

		return *retorno;
}


int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

int esEmail(char str[])
{
   int i=0;
   int contadorArrobas=0;
   int contadorDePuntos=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] == '@') && (str[i] < '0' || str[i] > '9')&&(str[i]=='.'))
           return 0;
       if(str[i] == '@')
            contadorArrobas++;
       if(str[i] == '.')
    	   contadorDePuntos++;

       i++;

   }
   if(contadorArrobas==1&&contadorDePuntos==1) // debe tener un punto y arroba
        return 1;

    return 0;
}
char getEmail(char cadena[],char *retorno)
{


	char auxiliarChar[500];
	printf(cadena);
	if(myGets(auxiliarChar, sizeof(auxiliarChar))==0)
	{
		while(!esEmail(auxiliarChar))
		{
			printf("error ingrese un mail valido");
			myGets(auxiliarChar, sizeof(auxiliarChar));
		}
	}
	strcpy(retorno,auxiliarChar);

	return *retorno;

}

char getTelefono(char cadena[],char *retorno)
{


	char auxiliarChar[500];
	printf(cadena);
	if(myGets(auxiliarChar, sizeof(auxiliarChar))==0)
	{
		while(!esTelefono(auxiliarChar))
		{
			printf("error ingrese un mail valido");
			myGets(auxiliarChar, sizeof(auxiliarChar));
		}
	}
	strcpy(retorno,auxiliarChar);

	return *retorno;
}

/*int getString(char cadena[],char *retorno[])
{

	int contador;
	char auxiliarChar[500];

	pedirMensaje(cadena, auxiliarChar);
	while(!esSoloLetras(auxiliarChar))
	{
		pedirMensaje(" error solo letras", auxiliarChar);
	}
	strcpy(*retorno,auxiliarChar);

	return contador;
	//return *retorno;
}


*/
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
    int retorno = -1;
    int bufferInt;
    int i;
    char bufferCadenaAux[16];
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        for(i=0; i<=reintentos; i++)
        {
            printf("%s", mensaje);
            fflush(stdin);
            //if(scanf("%d", &bufferInt)==1)
            if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
            {

                // lo valido, para ver si los simbolos ingresados son numericos
                if(esNumerico(bufferCadenaAux)==1)
                {
                    // si son numericos, convierto la cadena a INT
                    bufferInt = atoi(bufferCadenaAux);
                    if(bufferInt >= minimo && bufferInt <= maximo){
                        *pResultado = bufferInt;
                        retorno = 0;
                        break;
                    }else{
                        printf("%s", mensajeError);
                    }
                }
                else {
                    printf("%s", mensajeError);
                }
            }
            else {
                printf("%s", mensajeError);
            }
        }
    }
    return retorno;
}

float utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
    float retorno = -1;
    float bufferInt;
    int i;
    char bufferCadenaAux[16];
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        for(i=0; i<=reintentos; i++)
        {
            printf("%s", mensaje);
            fflush(stdin);
            //if(scanf("%d", &bufferInt)==1)
            if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
            {
                // el usuario ingreso algo
                // lo valido, para ver si los simbolos ingresados son numericos
                if(esNumerico(bufferCadenaAux)==1)
                {
                    // si son numericos, convierto la cadena a INT
                    bufferInt = atof(bufferCadenaAux);
                    if(bufferInt >= minimo && bufferInt <= maximo){
                        *pResultado = bufferInt;
                        retorno = 0;
                        break;
                    }else{
                        printf("%s", mensajeError);
                    }
                }
                else {
                    printf("%s", mensajeError);
                }
            }
            else {
                printf("%s", mensajeError);
            }
        }
    }
    return retorno;
}

