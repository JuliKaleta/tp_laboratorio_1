/*
 * utn.c
 *
 *  Created on: 16 abr. 2020
 *      Author: usuario
 */

#include <stdio.h>
#include <stdlib.h>


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
				scanf("%d",&bufferInt);
				if (bufferInt >= minimo && bufferInt <= maximo)
				{
					*pResultado = bufferInt;
					retorno = 0;
					break;
				}
				else
				{
					printf ("%s", mensajeError);
					reintentos--;
				}
		}
				while(reintentos >= 0);
					{

					}
	}
	return retorno;
	}

int suma(int valorA, int valorB)
{
	int resultadosuma;
	resultadosuma= valorA+valorB;
	return resultadosuma;
}

int resta(int  valorA, int valorB)
{
	int resultadoresta;
	resultadoresta= valorA-valorB;
	return resultadoresta;
}

int multiplicacion(int  valorA, int valorB)
{
	int resultadomultiplicacion;
	resultadomultiplicacion= valorA*valorB;
	return resultadomultiplicacion;
}

float division(int  valorA, int valorB)
{
	float resultadodivision;
	resultadodivision=(float) valorA/(float) valorB;
	return resultadodivision;
}

int factorial(int valorC)
{
	int resultadofactorial;
	if( valorC==1 || valorC==0)
	return 1;
	resultadofactorial=valorC* factorial(valorC-1);
	return (resultadofactorial);

}


