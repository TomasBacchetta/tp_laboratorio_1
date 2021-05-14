/*
 * arraySectores.h
 *
 *  Created on: 13 may. 2021
 *      Author: tomas
 */

#ifndef ARRAYSECTORES_H_INCLUDED
#define ARRAYSECTORES_H_INCLUDED

struct{
    int id;
    char descripcion[20];
}typedef eSector;


#endif // ARRAYSECTORES_H_INCLUDED

void mostrarSector(eSector sector);
int mostrarSectores(eSector sector[], int tam);
int buscarSector(eSector sector[], int tamsec, int idSector);
