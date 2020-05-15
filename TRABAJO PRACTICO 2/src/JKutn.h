/*
 * utn.h
 *
 *  Created on: 5 may. 2020
 *      Author: usuario
 */

//*************************************************************************//

#ifndef UTN_H_
#define UTN_H_
#define LEN_ARRAY 5000 //ajustar el len de los arrays de string si se desea tener mayor espacio.

//*************************************************************************//

int menubasico();

int getNumeroConComa(float* pResultado, char* mensaje, char* mensajeError, int min,int max, int reintentos);

int getNumber (int* pResultado, char* mensaje, char* mensajeError, int min, int max, int reintentos);

int getString (char* cadena, char* mensaje, char* mensajeError, int len, int reintentos);

int isDecimalNumber (char* cadena);

int isNumber (char* cadena);

int getInt (int* pResultado);

int getFloat (float* pResultado);

int getFloat (float* pResultado);

int isChar (char* cadena);

//*************************************************************************//

#endif /* JKUTN_H_ */
