/*
 * JKArrayEmployee.h
 *
 *  Created on: 5 may. 2020
 *      Author: usuario
 */

#ifndef JKARRAYEMPLOYEE_H_
#define JKARRAYEMPLOYEE_H_

//*************************************************************************//
//Definicion de estructura//

typedef struct {

	char nombre[20];
	char apellido[20];
	float salario;
	int id;
	int sector;
	int isEmpty;

	} eDatosEmpleados;

//*************************************************************************//
//Prototipo de funciones dadas//

int initEmployees(eDatosEmpleados* list, int len);

int addEmployee (eDatosEmpleados* list, int len, int id, char name[], char lastName[], float salary, int sector);

int findEmployeeById (eDatosEmpleados* list,int len,int id);

int removeEmployee(eDatosEmpleados* list, int len, int id);

int sortEmployees (eDatosEmpleados * list, int len, int order);

int printEmployees (eDatosEmpleados* list,int len);

//*************************************************************************//
//Prototipo de funciones propias//

void menuOptions(eDatosEmpleados *list, int len, int id);

int dataEmployees (eDatosEmpleados* list,int len, int* pId);

int modifyEmployee(eDatosEmpleados* list, int len);

int getId(eDatosEmpleados* list, int len);

void getPromedio (eDatosEmpleados *list, int len);

//*************************************************************************//

#endif /* JKARRAYEMPLOYEE_H_ */
