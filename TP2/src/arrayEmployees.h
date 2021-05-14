/*
 * arrayEmployees.h
 *
 *  Created on: 13 may. 2021
 *      Author: tomas
 */

#include "arraySectores.h"
#include "utnInput.h"
#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

struct {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef employee;


#endif // ARRAYEMPLOYEES_H_INCLUDED

int imprimirMenu();
int initEmployees(employee * lista, int tam);
int addEmployee(employee nomina[], int tam, int *pId, eSector sector[], int tamsec);
void printEmployee(employee emp, eSector sectores[], int tamsec);
void printEmployees(employee lista[], int tam, eSector sectores[], int tamsec);
int removeEmployee(employee lista[], int tam, eSector sector[], int tamsec);
int findEmployeeById(employee lista[], int tam, int legajo);
int sortEmployees(employee lista[], int tam, eSector sectores[], int tamsec);
int buscarLibre(employee lista[], int tam);
int buscarEmpleado(employee lista[], int tam, int legajo);
int hayEmpleado(employee lista[], int tam);
int obtenerSector(eSector sector[], int tamsec, int * idSector);
int modificarEmpleado(employee lista[], int tam, eSector sector[], int tamsec);
int menuInformes(employee lista[], int tam, eSector sectores[], int tamsec);
int totalPromedioSalarios(employee lista[], int tam);
int menuPrincipal(employee lista[], int tam, eSector sectores[], int tamSec, int * proxId);
