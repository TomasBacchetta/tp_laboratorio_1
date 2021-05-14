/*
 * arraySectores.c
 *
 *  Created on: 13 may. 2021
 *      Author: tomas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utnInput.h"
#include "arraySectores.h"


int mostrarSectores(eSector sector[], int tam){
    int allRight = -1;
    if (sector != NULL && tam > 0){
        printf("\nLista de sectores:\n");
        printf("\nID ||  Descripcion\n");
        for (int x = 0; x < tam; x++){
           mostrarSector(sector[x]);
        }
        printf("\n");
        allRight = 0;
    }
    return allRight;
}

void mostrarSector(eSector sector){
    printf("\n%d    %s", sector.id, sector.descripcion);
}

int buscarSector(eSector sector[], int tamsec, int idSector){
    int indice = -1;
    for (int x = 0; x < tamsec; x++){
        if (sector[x].id == idSector){
            indice = x;
        }
    }
    return indice;
}


