/*
 ============================================================================
 Name        : Trabajo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);

	int valorA=0, valorB=0, respuesta, opcion, resultadosuma, resultadoresta, resultadomultiplicacion, resultadofactorialA, resultadofactorialB;
	float resultadodivision;

	    do
	    {
	    	printf( "\n   -BIENVENIDO-");
	        printf( "\n   1. Ingresar el primer valor. (Primer valor= %d)", valorA);
	        printf( "\n   2. Ingresar el segundo valor. (Segundo valor= %d)", valorB);
	        printf( "\n   3. Calcular las operaciones basicas.");
	        printf( "\n   4. Mostrar el resultado de las operaciones basicas.");
	        printf( "\n   5. SALIR." );

	        respuesta = utn_getNumero(&opcion, "\n\n   Introduzca una opción (1-5): ","\n   ERROR, la opcion introducida no es valida\n",1,5,2);

	        switch ( opcion )
	        {
	            case 1:

	            	respuesta = utn_getNumero(&valorA, "\n   Ingrese el primer valor: ", "   ERROR, El valor ingresado es incorrecto \n", 0 ,101, 2 );

	            							if (respuesta==0)
	            							{
	            								printf ("\n   El primer valor fue ingresado\n");
	            							}
	            							else
	            							{
	            								printf ("\nERROR\n");
	            							}
	                    break;

	            case 2:

	            	respuesta = utn_getNumero(&valorB, "\n   Ingrese el segundo valor: ", "   ERROR, El valor ingresado es incorrecto \n", 0 ,199, 2 );

	            							if (respuesta==0)
	            							{
	            								printf ("\n   El segundo valor fue ingresado\n");
	            							}
	            							else
	            							{
	            								printf ("\nERROR\n");
	            							}
	                    break;

	            case 3:

	            	resultadosuma= suma(valorA,valorB);                       //Calculo SUMA
	            	resultadoresta= resta(valorA,valorB);                     //Calculo RESTA
	            	resultadomultiplicacion= multiplicacion(valorA,valorB);   //Calculo MULTIPLICACION
	                resultadofactorialA= factorial(valorA);                   //Calculo el factorial del primer numero ingresado
	            	resultadofactorialB= factorial(valorB);                   //Calculo el factorial del segundo numero ingresado

	            	if (valorB != 0) {

	            	resultadodivision = division(valorA, valorB);     //Calculo DIVISION cuando el divisor es distinto a 0
	            					 }
	            	printf("\n   Todas las operaciones basicas fueron calculadas.\n");

	                    break;

	            case 4:

	            	printf("\n   El resultado de %d+%d es: %d \n",valorA, valorB, resultadosuma);
	            	printf("   El resultado de %d-%d es: %d \n",valorA, valorB, resultadoresta);
	            	printf("   El resultado de %d*%d es: %d \n",valorA, valorB, resultadomultiplicacion);

	        		if (valorB != 0) {
	            	printf("   El resultado de %d/%d es: %.2f \n",valorA, valorB, resultadodivision);

	        		} else {
	            		    printf("   No se puede dividir por 0 \n");
	            			}

	            	printf("   El factorial de %d es %d y el factorial de %d es %d \n",valorA , resultadofactorialA, valorB, resultadofactorialB);

	                    break;

	            case 5:

	                    break;
	        }
	    } while ( opcion != 5 );
	    {
	    }

}

