/*
 ============================================================================
 Name        : TP2.c
 Author      : tomas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "arraySectores.h"
#include "utnInput.h"
#define TAM 1000
#define TAMSEC 5 //cantidad de sectores de la empresa

int menuInformes(employee lista[], int tam, eSector sectores[], int tamsec);

int main()
{
	setbuf(stdout, NULL);
    employee lista[TAM];

    eSector sectores[TAMSEC] ={
        {500, "Deposito"},
        {501, "Comercial"},
        {502, "RRHH"},
        {503, "Administracion"},
        {504, "Seguridad"}
    };

    int proxId = 10000;

    if (initEmployees(lista, TAM) < 0){
        printf("\nError inesperado\n");
    } else {
        menuPrincipal(lista, TAM, sectores, TAMSEC, &proxId);
    }
    return 0;
}

