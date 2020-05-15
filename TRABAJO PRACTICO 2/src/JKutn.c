/*
 * utn.c
 *
 *  Created on: 5 may. 2020
 *      Author: usuario
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "JKutn.h"
#define LEN_ARRAY 5000

//*************************************************************************//

int menubasico()
{
	int option;
	printf("\n*********************************************************************\n");
	getNumber(&option,"   BIENVENIDO!\n\n   1.   ALTA DE EMPLEADO\n   2.   MODIFICAR UN EMPLEADO\n   3.   BAJA DE UN EMPLEADO\n   4.   INFORME DE LOS EMPLEADOS INGRESADOS\n   5.   FIN\n\n","---ERROR, opcion inngresada incorrecta, vuelva a ingresar por favor---\n",1,5,2);
	return option;
}

//*************************************************************************//

int getNumber(int *pResultado, char *mensaje, char *mensajeError, int min, int max, int reintentos) {
	int ret=0;
	int num;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& min <= max && reintentos >= 0) {
		while (reintentos > 0) {
			printf("%s", mensaje);
			if (getInt(&num))  // si scanf =1 es porque pudo abrir la variable
			{
				if (num <= max && num >= min)
				{
					break;
				}
			}
			reintentos--;
			printf("%s", mensajeError);
		}
		if (reintentos > 0) {
			*pResultado = num; //se asigna en la direccion de memoria del parametro el valor del numero ingresado.
			ret = 1;
		}

	}
	return ret;
}

int getNumeroConComa(float *pResultado, char *mensaje, char *mensajeError,
		int min, int max, int reintentos) {
	int ret;
	float num;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& min <= max && reintentos >= 0) {
		while (reintentos > 0) {
			printf("%s", mensaje);
			if (getFloat(&num))  // si scanf =1 es porque pudo abrir la variable
					{
				if (num <= max && num >= min) {
					break;
				}
			}
			reintentos--;
			printf("%s", mensajeError);
		}
		if (reintentos == 0) {
			ret = -1;
		} else {
			*pResultado = num; //se asigna en la direccion de memoria del parametro el valor del numero ingresado.
			ret = 1;
		}
	}
	return ret;
}

int getString (char *cadena, char *mensaje, char *mensajeError, int len, int reintentos)
{
	int ret =0;
	char buffer [LEN_ARRAY];
	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && len >0 && reintentos >=0)
	{
		while(reintentos > 0)
		{
			printf("%s",mensaje);
			fflush(stdin);
			fgets(buffer,LEN_ARRAY,stdin);
			buffer[strlen(buffer)-1] = '\0';
			if(isChar(buffer))
			{
				if(strlen(buffer) == 1)
				{
					reintentos--;
					printf("%s",mensajeError);
					continue;
				}
				if(strlen(buffer) == 0)
				{
					reintentos--;
					printf("%s",mensajeError);
					continue;
				}
				if(strlen(buffer) <= len)
				{
					break;
				}
			}
			else
			{
				reintentos--;
				printf("%s",mensajeError);
			}
		}
		if(reintentos > 0)
		{
			strcpy(cadena , buffer);
			ret = 1;
		}
	}

	return ret;
}

int getInt(int *pResultado) {
	int ret = 0;
	char buffer[LEN_ARRAY];
	if (pResultado != NULL) {
		fflush(stdin);
		buffer[LEN_ARRAY] = '\0';
		fgets(buffer, LEN_ARRAY, stdin);
		if (isNumber(buffer)) {
			*pResultado = atoi(buffer);
			ret = 1;
		}
	}

	return ret;
}

int getFloat(float *pResultado) {
	int ret = -1;
	char buffer[LEN_ARRAY];
	if (pResultado != NULL) {
		fflush(stdin);
		fgets(buffer, LEN_ARRAY, stdin);
		if (isDecimalNumber(buffer)) {
			*pResultado = atof(buffer);
			ret = 1;
		}
	}
	return ret;
}

int isChar (char *cadena)
{
	int i=0;
	int ret=0 ;
	if(cadena != NULL)
	{
		for(i=0; cadena[i]!= '\0' ; i++)
		{
			if(cadena[i] >='A' && cadena[i] <='z')
			{
				continue;
			}
			if(cadena[i]>='0' && cadena[i]<='9')
			{
				break;
			}

		}
		if(cadena[i]=='\0')
		{
			ret=1;
		}


	}

	return ret;
}

int isNumber(char *cadena) {
	int ret=0;
	int i;
	if (cadena != NULL) {
		for (i = 0; cadena[i] != '\0'; i++) {
			if (i == 0 && cadena[i] == '-') {
				continue;
			}
			if(cadena[i]>='0' && cadena[i] <='9'){
				continue;
			}
			if ((cadena[i] <= '~' && cadena[i] >= ':')|| (cadena[i]<='/' && cadena[i]>='!')) //lo que hice fue poner como invalidos
			{
				break;
			}
		}
		if (cadena[i] == '\0') {
			ret = 1;
		}
	}
	return ret;
}

int isDecimalNumber(char *cadena) {
	int i;
	int ret = 1;
	if (cadena != NULL) {
		for (i = 0; cadena[i] != '\0'; i++) {
			if ((i == 0 && cadena[i] == '-') || cadena[i] == '.') {
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				ret = -1;
				break;
			}
		}

	}
	return ret;
}

//*************************************************************************//
