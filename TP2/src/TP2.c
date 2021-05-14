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
        {500, "Sistemas"},
        {501, "RRHH"},
        {502, "Cobranzas"},
        {503, "Legales"},
        {504, "Ventas"}
    };

    int proxId = 10000;

    if (initEmployees(lista, TAM) < 0){
        printf("\nError inesperado\n");
    } else {
    //HARDCODE

        char hNombres[10][20] = {"Johnny", "Jorge", "popo", "Paula", "Pedro", "Carlos", "Anna", "Alex", "Ramon", "Quico"};

        char hApellidos[10][20] = {"Rodriguez", "Perez", "Chong", "Bu", "Moulinzart", "Rossi", "Katz", "Capu", "Valdez", "Villagran"};

        float hSueldos[10] = {3000, 2000, 7000, 5500, 3200, 5000, 4800, 5000, 6100, 5000};

         int hIdSector[10] = {500, 501, 502, 503, 501, 500, 500, 501, 500, 502};

        for (int x = 0; x < 10; x++){
            lista[x].id = proxId;
            proxId++;
            strcpy(lista[x].name, hNombres[x]);
            strcpy(lista[x].lastName, hApellidos[x]);
            lista[x].salary = hSueldos[x];
            lista[x].sector = hIdSector[x];
            lista[x].isEmpty = 0;
        }
    //FIN HARDCODE
        menuPrincipal(lista, TAM, sectores, TAMSEC, &proxId);
    }
    return 0;
}

