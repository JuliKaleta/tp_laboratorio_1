/*
 ============================================================================
 Name        : TRABAJO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "JKutn.h"
#include "JKArrayEmployee.h"
#define CANT_EMPLEADOS 1000

int main() {

	setbuf(stdout, NULL);

	int opcionesDelMenu;
	eDatosEmpleados empleados[CANT_EMPLEADOS];
	int id = 0;

	initEmployees(empleados,CANT_EMPLEADOS);

	do
	{
		opcionesDelMenu = menubasico();
		switch(opcionesDelMenu)
		{

		case 1:
			dataEmployees(empleados,CANT_EMPLEADOS,&id);
			break;

		case 2:
			if(id>0){
			modifyEmployee(empleados,CANT_EMPLEADOS);
			}
			else{
			printf("*************************************************************\n");
			printf("   Primero debe dar de alta un empleado\n");
			}
			break;

		case 3:
			if(id>0){
			removeEmployee(empleados,CANT_EMPLEADOS,getId(empleados,CANT_EMPLEADOS));
			}else{
				printf("*************************************************************\n");
				printf("   Primero debe dar de alta un empleado\n");
			}
			break;

		case 4:
			if(id>0){
			menuOptions(empleados,CANT_EMPLEADOS,id);
			}
			else{
				printf("*************************************************************\n");
				printf("   Primero debe dar de alta un empleado\n");
			}
			break;

		case 5:
			break;
		}

	}while(opcionesDelMenu!=5);


	return 0;
}
