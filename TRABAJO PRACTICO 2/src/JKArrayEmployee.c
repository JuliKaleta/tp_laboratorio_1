/*
 * JKArrayEmployee.c
 *
 *  Created on: 5 may. 2020
 *      Author: usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "JKutn.h"
#include "JKArrayEmployee.h"

//**************************************************************************************************************//

#define SALARY_MAX 50000
#define SALARY_MIN 1
#define SECTOR_MAX 5
#define SECTOR_MIN 1

//**************************************************************************************************************//
//Funciones dadas//

int initEmployees(eDatosEmpleados *list, int len) {
		int retorno=-1;
		    if(list!= NULL && len>0)
		    	{
		        	for(;len>0;len--)
		        	{
		        		list[len-1].isEmpty=1;
		        	}
		        retorno=0;
		    	}
		    return retorno;
	}

int addEmployee(eDatosEmpleados *list, int len, int id, char name[], char lastName[],float salary, int sector) {
	int ret = -1;
	int i;

		if(list != NULL && len >0 && name != NULL && lastName != NULL && salary >0 && sector > 0){

			for (i = 0; i < len; i++) {

				if (list[i].isEmpty == 1) {
						list[i].id = id +1;
						strcpy(list[i].nombre, name);
						strcpy(list[i].apellido, lastName);
						list[i].salario = salary;
						list[i].sector = sector;
						list[i].isEmpty = 0;
						ret = 0;
										  }
									   }
								   }
		return ret;
	}

int findEmployeeById(eDatosEmpleados *list, int len, int id) {
	int ret = -1;
	int i;

	if(list != NULL && len > 0 && id >= 0){
		printf(" .ID		  .NOMBRE	    .APELLIDO		 .SALARIO		  .SECTOR\n");
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 0 && list[i].id == id ) {
				printf("%d		%s		%s		%.2f	        %d\n", list[i].id, list[i].nombre,list[i].apellido, list[i].salario, list[i].sector);
				ret = 0;
				break;
			}
		}
	}

	return ret;
}

int removeEmployee(eDatosEmpleados *list, int len, int id) {
	int ret = -1;
	char respuesta[10];

	if(list != NULL && len > 0 ){

		if (findEmployeeById(list, len, id) == 0) {
			printf("************************************************************************\n");
			getString(respuesta, "Dar de baja empleado?\n [SI/NO]\n", "--Error, opcion incorrecta--\n", 10, 2);
			strupr(respuesta);

			if (strcmp(respuesta, "SI") == 0) {
				list[id-1].isEmpty = 1;
				printf("************************************************************************\n");
				printf("Empleado anulado \n");
				ret = 0;
			} else if (strcmp(respuesta, "NO") == 0) {
				printf("************************************************************************\n");
				printf("El empleado no ha sido anulado\n");
			}
		}
	}

	return ret;
}

int sortEmployees(eDatosEmpleados *list, int len, int order) {
	int flagDesordenado = 1;
	int ret = -1;
	int i;
	eDatosEmpleados auxEmployee;
	if(list != NULL && len > 0){
		switch(order) {

		case 1:
			do {
				flagDesordenado = 0;
				for (i = 0; i < len-1; i++) {
					if (strcmp(list[i].apellido,list[i+1].apellido)<0) {
						auxEmployee = list[i+1];
						list[i+1] = list[i];
						list[i] = auxEmployee;
						flagDesordenado = 1;
					}
					if (strcmp(list[i].apellido,list[i+1].apellido)==0
							&& list[i].sector < list[i+1].sector) {
						auxEmployee = list[i+1];
						list[i+1] = list[i];
						list[i] = auxEmployee;
						flagDesordenado = 1;
					}
					len--;
				}

			} while (flagDesordenado);
			ret = 0;
			break;

		case 0:
			do {
				flagDesordenado=0;
				for (i = 0; i < len-1; i++) {
					if (strcmp(list[i].apellido,list[i+1].apellido)>0) {
						auxEmployee = list[i+1];
						list[i+1] = list[i];
						list[i] = auxEmployee;
						flagDesordenado = 1;
					}
					if (strcmp(list[i].apellido,list[i+1].apellido)==0
							&& list[i].sector > list[i+1].sector) {
						auxEmployee = list[i+1];
						list[i+1] = list[i];
						list[i] = auxEmployee;
						flagDesordenado = 1;
					}
					len--;
				}

			} while (flagDesordenado);

			ret = 0;
			break;
		}
	}

	return ret;
}

int printEmployees(eDatosEmpleados *list, int len) {
	int ret = -1;
	int i;

	if(list != NULL && len > 0){
		printf(" .ID		  .NOMBRE	    .APELLIDO		 .SALARIO		  .SECTOR\n");
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 0) { printf("%d		%s		%s		%.2f	        %d\n", list[i].id, list[i].nombre,list[i].apellido, list[i].salario, list[i].sector);
			}
			ret = 0;
		}
	}

	return ret;
}

//**************************************************************************************************************//
//Funciones creadas//

void menuOptions(eDatosEmpleados *list, int len, int id) {
	int optionSort;
	int order;

	if(list != NULL && len > 0 && id > 0){

		do {
			getNumber(&optionSort,"   MENU INFORMES\n\n   1.   Ordenar listado\n   2.   Promedio de salarios\n   3.   Volver", "   Error, opcion invalida", 1, 3, 2);
			switch (optionSort) {

			case 1:
				if(id > 1){

					getNumber(&optionSort,"   ELIJA EL ORDEN\n\n   1.   Mayor a menor\n   2.   Menor a mayor","   Error, opcion invalida",1,2,2);
					if(optionSort== 1){
						order = 1;
					}else if(optionSort == 2){
						order = 0;
					}
					sortEmployees(list,len,order);
					printEmployees(list,len);
				}else{
					printf("   Debe agregar un empleado mas para poder ordenarlos\n");
				}
				break;

			case 2:
				getPromedio(list,len);
				break;

			case 3:
				break;
			}

		} while (optionSort != 3);
	}

}

int dataEmployees(eDatosEmpleados *list, int len, int* Id) {
	int ret = -1;
	char bufferName[51];
	char bufferLastName[51];
	float bufferSalary;
	int bufferSector;
	int bufferId;
	eDatosEmpleados empleadosAux;

	if(list != NULL && len >0 && *Id >=0){

			empleadosAux.isEmpty = 1;
			printf("************************************************************************");
			if (!getString(bufferName, "\n   Ingrese nombre del empleado\n", "ERROR, nombre invalido, vuelva a ingresar por favor\n", 51, 2)) {
				printf("Ingrese nuevamente\n");
			}
			printf("************************************************************************");
			if (!getString(bufferLastName, "\n   Ingrese apellido del empleado\n","ERROR, apelldo invalido, vuelva a ingresar por favor\n", 51, 2)) {
				printf("Ingrese nuevamente\n");
			}
			printf("************************************************************************");
			if(getNumeroConComa(&bufferSalary, "\n   Ingrese salario del empleado\n","ERROR, salario invalido, vuelva a ingresar por favor\n", SALARY_MIN, SALARY_MAX, 2)== -1) {
				printf("Ingrese nuevamente\n");
			}
			printf("************************************************************************");
			if (!getNumber(&bufferSector, "\n   Ingrese el sector en donde trabaja el empleado (sectores del 1-5)\n","ERROR, sector invalido, vuelva a ingresar por favor\n", SECTOR_MIN, SECTOR_MAX,2)) {
				printf("Ingrese nuevamente\n");
			}
			printf("************************************************************************");
			if (addEmployee(&empleadosAux, len, *Id, bufferName, bufferLastName,bufferSalary, bufferSector) == -1) {
				printf("ERROR");
			}
			list[*Id] = empleadosAux;
			bufferId = *Id;
			bufferId++;
			*Id = bufferId;

	ret = 0;
	}
	return ret;
}

int modifyEmployee(eDatosEmpleados *list, int len) {

	char bufferName[20];
	char bufferLastName[20];
	char respuesta[20];
	float bufferSalary;
	int bufferSector;
	int ret = -1;
	int option;
	int id = getId(list, len);
	int busqueda = findEmployeeById(list, len,id);

	if(list != NULL && len > 0){
		if ( busqueda == 0) {
			do{
				findEmployeeById(list,len,id);
				printf("************************************************************************\n");
				getNumber(&option, "  -Ingrese opcion a cambiar del empleado?- \n\n   1.   Nombre\n   2.   Apellido\n   3.   Salario\n   4.   Sector\n   5.   Atras\n","   --Error, opcion incorrecta--", 1, 5, 3);

				switch (option) {
				case 1:
					printf("************************************************************************\n");
					getString(bufferName, "Ingrese el nombre del empleado\n", "--Error, opcion incorrecta--\n", 51, 2);
					printf("************************************************************************\n");
					getString(respuesta, "Desea cambiar por la nuevo ingresado\n [SI/NO]\n", "--Error, opcion incorrecta--\n", 10, 2);
					strupr(respuesta);
					if (strcmp(respuesta, "SI") == 0) {
						strcpy(list[id-1].nombre, bufferName);
						printf("************************************************************************\n");
						printf("Cambio realizado\n");

						ret = 0;
					} else if (strcmp(respuesta, "NO") == 0) {
						printf("************************************************************************\n");
						printf("Cambio cancelado\n");
					}
					break;
				case 2:
					printf("************************************************************************\n");
					getString(bufferLastName, "Ingrese el apellido del empleado\n", "--Error, opcion incorrecta--\n", 51, 2);
					printf("************************************************************************\n");
					getString(respuesta, "Confirma la modificacion\n [SI/NO]\n", "--Error, opcion incorrecta--\n", 10, 2);
					strupr(respuesta);
					if (strcmp(respuesta, "SI") == 0) {
						strcpy(list[id - 1].apellido, bufferLastName);
						printf("************************************************************************\n");
						printf("Cambio realizado\n");

						ret = 0;
					} else if (strcmp(respuesta, "NO") == 0) {
						printf("************************************************************************\n");
						printf("Cambio cancelado\n");
					}
					break;
				case 3:
					getNumeroConComa(&bufferSalary, "Ingrese el salario", "--Error, opcion incorrecta--\n", SALARY_MIN, SALARY_MAX,2);
					printf("************************************************************************\n");
					getString(respuesta, "Confirma la modificacion\n [SI/NO]\n", "--Error, opcion incorrecta--\n", 10, 2);
					printf("************************************************************************\n");
					strupr(respuesta);
					if (strcmp(respuesta, "SI") == 0) {
						list[id - 1].salario = bufferSalary;
						printf("************************************************************************\n");
						printf("Cambio realizado\n");

						ret = 0;
					} else if (strcmp(respuesta, "NO") == 0) {
						printf("************************************************************************\n");
						printf("Cambio cancelado\n");
					}
					break;
				case 4:
					getNumber(&bufferSector, "Ingrese el sector", "--Error, opcion incorrecta--\n", SECTOR_MIN, SECTOR_MAX,2);
					printf("************************************************************************\n");
					getString(respuesta, "Confirma la modificacion\n [SI/NO]\n","--Error, opcion incorrecta--\n", 10, 2);
					strupr(respuesta);
					if (strcmp(respuesta, "SI") == 0) {
						list[id - 1].sector = bufferSector;
						printf("************************************************************************\n");
						printf("Cambio realizado\n");

						ret = 0;
					} else if (strcmp(respuesta, "NO") == 0) {
						printf("************************************************************************\n");
						printf("Cambio cancelado\n");
					}
					break;
				case 5:
					break;
					}
			}while (option != 5);
		}
	}
	return ret;
}

int getId(eDatosEmpleados *list, int len) {
	int ret = -1;
	int id;

	if (list != NULL && len > 0) {

		if (getNumber(&id, "Ingrese el ID\n", "Error, ID invalido\n", 0, len,2)) {
			if (list[id-1].isEmpty == 0) {
				ret = id;
			}
		}
	}

	return ret;
}

void getPromedio (eDatosEmpleados *list, int len){
	int i;
	float totalSalarios = 0;
	int cantTotalSalarios = 0;
	float promedioSalarios;

	if(list != NULL && len > 0){

		for(i=0;i<len;i++){
			if(list[i].isEmpty==0){
				totalSalarios = totalSalarios + list[i].salario;
				cantTotalSalarios++;
			}
		}
		promedioSalarios = totalSalarios / cantTotalSalarios;
		printf("************************************************************************\n");
		printf("TOTAL DE LOS SALARIO : %.2f\n",totalSalarios);
		printf("************************************************************************\n");
		printf("SALARIO PROMEDIO : %.2f\n",totalSalarios);
		printf("************************************************************************\n");
		printf("ID		NOMBRE		APELLIDO		SALARIO		SECTOR\n\n");
		for(i=0;i<len;i++){
			if(list[i].salario > promedioSalarios){
				printf("%d		%s		%s			%.2f		%d\n", list[i].id, list[i].nombre,list[i].apellido, list[i].salario, list[i].sector);
			}
		}
	}
}


