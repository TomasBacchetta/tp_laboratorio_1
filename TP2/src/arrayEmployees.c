/*
 * arrayEmployees.c
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

int imprimirMenu(){
        int opcion;
        printf("\t\t***Menu principal***");
        printf("\n1. ALTAS");
        printf("\n2. MODIFICAR");
        printf("\n3. BAJA");
        printf("\n4. INFORMAR");
        printf("\n5. SALIR");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        system("cls");
        return opcion;
}

int menuPrincipal(employee lista[], int tam, eSector sectores[], int tamSec, int * proxId){
    int allRight = 0;
    char respuesta = 'n';

        do{
            switch(imprimirMenu()){
            case 1:
                addEmployee(lista, tam, proxId, sectores, tamSec);
                system("pause");
                break;
            case 2:
                printEmployees (lista, tam, sectores, tamSec);
                modificarEmpleado(lista, tam, sectores, tamSec);
                system("pause");
                break;
            case 3:
                printEmployees (lista, tam, sectores, tamSec);
                removeEmployee(lista, tam, sectores, tamSec);
                system("pause");
                break;
            case 4:
                menuInformes(lista, tam, sectores, tamSec);
                system("pause");
                break;
            case 5:
                respuesta = salir();
                break;
            default:
                printf("\nOpcion incorrecta!\n");
                system("pause");
            }

            system("cls");
        } while (respuesta == 'n');
    return allRight;
}





int menuInformes(employee lista[], int tam, eSector sectores[], int tamsec){
    int allRight = 0;
    int opcion;
    int respuesta = 'n';

    if (!hayEmpleado(lista, tam)){
            printf("\nNo hay empleados cargados en sistema.\n");
    } else {
        do{
        printf("\t\t***Menu de informes***");
        printf("\n1. Lista de empleados");
        printf("\n2. Total y promedio salarios");
        printf("\n3. Salir");
        printf("\nSeleccione una opción: ");
        scanf("%d", &opcion);
        system("cls");
            switch(opcion){
            case 1:
                sortEmployees(lista, tam, sectores, tamsec);
                printEmployees (lista, tam, sectores, tamsec);
                system("pause");
                break;
            case 2:
                totalPromedioSalarios(lista, tam);
                system("pause");
                break;
            case 3:
                respuesta = salir();
                break;
            default:
                printf("\nOpcion invalida!\n");
                allRight = -1;
            }
            system("cls");
        }while (respuesta == 'n');
}
return allRight;
}

int initEmployees(employee * lista, int tam){
    int allRight = -1;
    if (lista != NULL && tam > 0){
        for (int x = 0; x < tam; x++){
            lista[x].isEmpty = 1;
            allRight = 0;
        }
    }
    return allRight;
}

int addEmployee(employee nomina[], int tam, int *pId, eSector sector[], int tamsec){
    int allRight = 0;
    int indice;
    employee nuevoEmpleado; //esto es un auxiliar de seguridad que toma todos los datos

    if (nomina != NULL && tam > 0 && pId != NULL){
        indice =  buscarLibre(nomina, tam);
        if (indice >= 0){
                nuevoEmpleado.id = *pId;
                fflush(stdin);

                printf("Ingrese nombre\n");
                fflush(stdin);
                while(obtenerNombre(nuevoEmpleado.name) < 0 && formatearNombre(nuevoEmpleado.name)){
                    printf("\nError!Ingrese nombre correcto\n");
                }

                printf("Ingrese apellido\n");
                fflush(stdin);
                while(obtenerNombre(nuevoEmpleado.lastName) < 0 && formatearNombre(nuevoEmpleado.name)){
                    printf("\nError!Ingrese nombre correcto\n");
                }

                fflush(stdin);
                printf("Ingrese sueldo\n");
                while (obtenerSueldo(&nuevoEmpleado.salary) < 0){
                        printf("Error! Ingrese sueldo valido\n");

                }

                printf("\nIngreso de sector:\n");
                if (mostrarSectores(sector, tamsec) < 0){
                    printf("\nHubo un problema inesperado\n");
                    allRight = 0;
                } else {
                printf("\n\nSeleccione uno: ");
                while(obtenerSector(sector, tamsec, &nuevoEmpleado.sector) < 0){
                   printf("\nError!Ingrese sector real!\n");
                }
                system("cls");

                nuevoEmpleado.isEmpty = 0;

                nomina[indice] = nuevoEmpleado;

                printf("\nA %s %s se le ha asignado el legajo N %d\n", nomina[indice].name, nomina[indice].lastName, nomina[indice].id);

                (*pId)++;

                allRight = 1;
                }
        } else {
            printf("Superada la capacidad maxima de 1000 empleados. No hay lugar libre!\n");
            allRight = 0;
        }
    }
    return allRight;
}

int buscarLibre(employee lista[], int tam){
    int index = -1;
    if (lista != NULL && tam > 0){
        for (int x = 0; x < tam; x++){
            if (lista[x].isEmpty){
                index = x;
            }
        }
    }
    return index;
}

int buscarEmpleado(employee lista[], int tam, int legajo){
    int indice = -1;
    for (int x = 0; x < tam; x++){
        if (lista[x].id == legajo && lista[x].isEmpty == 0){
            indice = x;
            break;
        }
    }
    return indice;
}

int hayEmpleado(employee lista[], int tam){
    int allRight = 0;
    if (lista != NULL && tam > 0){
       for (int x = 0; x < tam; x++){
            if (lista[x].isEmpty == 0){
                allRight = 1;
                break;
            }
        }
    }
    return allRight;
}

int obtenerSector(eSector sector[], int tamsec, int * idSector){
    int allRight = -1;
    char buffer[64];

    if (idSector != NULL && sector != NULL && tamsec > 0){
        if (fixedGets(buffer, sizeof(buffer)) == 0 && esEntero(buffer)){
            *idSector = atoi(buffer);
            if (*idSector >= sector[0].id && *idSector <= sector[tamsec-1].id){//si es un sector real
                allRight = 0;
            }
        }
    }
    return allRight;
}

void printEmployee (employee emp, eSector sectores[], int tamsec){
    int indiceSec;

    indiceSec = buscarSector(sectores, tamsec, emp.sector);
    printf("\n  %d    %10s %10s    %9.2f  %s ",
       emp.id,
       emp.name,
       emp.lastName,
       emp.salary,
       sectores[indiceSec].descripcion

    );
}

void printEmployees (employee lista[], int tam, eSector sectores[], int tamsec){
        int flag = 0;
        printf("N° Legajo || Nombre || Apellido || Sueldo || Sector\n");
        for (int y = 0; y < tam; y++){
            if (!lista[y].isEmpty){
                flag = 1;
                printEmployee(lista[y], sectores, tamsec);
                printf("\n");
            }
        }
        if (!flag){
            printf("\nNo hay empleados que mostrar!\n");
        }
        printf("\n");
}

int findEmployeeById(employee lista[], int tam, int legajo){
    int indice = -1;
    for (int x = 0; x < tam; x++){
        if (lista[x].id == legajo && lista[x].isEmpty == 0){
            indice = x;
            break;
        }
    }
    return indice;
}

int modificarEmpleado(employee lista[], int tam, eSector sector[], int tamsec){
    int allRight = 0;
    int legajo;
    int opcion;
    int indice;
    if (lista != NULL && tam > 0){
        if (!hayEmpleado(lista, tam)){
            printf("\nNo hay empleados cargados en sistema.\n");
        } else {
            printf("\nIngrese el legajo del cliente a modificar\n");
            scanf("%d", &legajo);
            indice = findEmployeeById(lista, tam, legajo);
            system("cls");
            if (indice == -1){
            printf("\nNo existe empleado con ese N de legajo\n");
            } else {
                printf("\n");
                printf("N° Legajo || Nombre || Apellido || Sueldo || Sector\n");
                printEmployee(lista[indice], sector, tamsec);
                printf("\n\n1.Modificar nombre\n");
                printf("2.Modificar Apellido\n");
                printf("3.Modificar salario\n");
                printf("4.Modificar sector\n");
                printf("\nIngrese opcion:\n");
                scanf("%d", &opcion);
                fflush(stdin);
            switch(opcion){
                case 1:
                    printf("Ingrese nuevo nombre\n");
                    while(obtenerNombre(lista[indice].name) < 0){
                        printf("\nError!Ingrese nombre correcto\n");
                    }
                break;
                case 2:
                    printf("Ingrese nuevo apellido\n");
                    while(obtenerNombre(lista[indice].lastName) < 0){
                        printf("\nError!Ingrese nombre correcto\n");
                    }
                break;
                case 3:
                    printf("Ingrese nuevo sueldo\n");
                    while (obtenerSueldo(&lista[indice].salary) < 0){
                    printf("Error! Ingrese sueldo valido\n");
                    }
                break;
                case 4:
                    printf("\nIngreso nuevo sector:\n");
                    mostrarSectores(sector, tamsec);
                    printf("\n\nSeleccione uno: ");
                    while(obtenerSector(sector, tamsec, &lista[indice].sector) < 0){
                    printf("\nError!Ingrese sector real!\n");
                    }
                break;
                default:
                    printf("\nOpcion incorrecta!\n");
            }
            system("cls");
            printf("\nModificacion exitosa\n");
            printf("N° Legajo || Nombre || Apellido || Sueldo || Sector\n");
            printEmployee(lista[indice], sector, tamsec);
            printf("\n");
            allRight = 1;
            }
        }
    }
    return allRight;
}

int removeEmployee(employee lista[], int tam, eSector sector[], int tamsec){
    int allRight = 0;
    int legajo;
    char respuesta;
    int indice;
    if (lista != NULL && tam > 0){
        if (!hayEmpleado(lista, tam)){
            printf("\nNo hay empleados cargados en sistema.\n");
        } else {
            printf("\nIngrese el legajo del cliente a eliminar\n");
            scanf("%d", &legajo);
            indice = findEmployeeById(lista, tam, legajo);
            system("cls");
            if (indice == -1){
            printf("\nNo existe empleado con ese N de legajo\n");
            } else {
                printf("\n");
                printf("N° Legajo || Sector || Nombre || Edad || Sexo || Sueldo|| Fecha\n");
                printEmployee(lista[indice], sector, tamsec);
                printf("\nRealmente quiere dar de baja el empleado? (s/n)\n");
                while (respuesta != 's' && respuesta != 'n'){
                    fflush(stdin);
                    scanf("%c", &respuesta);
                }
                if (respuesta == 's'){
                    lista[indice].isEmpty = 1;
                    allRight = 1;
                } else {
                    printf("\nNo se ha dado de baja.\n");
                }
            }
        }
    } else {
        printf("\n Hubo un problema con la baja\n");
    }
    return allRight;
}

int sortEmployees(employee lista[], int tam, eSector sectores[], int tamsec){
    int allRight = 0;
    employee auxEmpleado;
    int indiceSectorAnterior;
    int indiceSectorSiguiente;

    for (int x = 0; x < tam-1; x++){

        if (lista[x].isEmpty == 0){
            for (int y = x + 1; y < tam; y++){
               if (lista[y].isEmpty == 0){
                   indiceSectorAnterior = buscarSector(sectores, tamsec, lista[x].sector);
                   indiceSectorSiguiente = buscarSector(sectores, tamsec, lista[y].sector);
                    if ((strcmp(sectores[indiceSectorAnterior].descripcion, sectores[indiceSectorSiguiente].descripcion) > 0)
                        || (strcmp(sectores[indiceSectorAnterior].descripcion, sectores[indiceSectorSiguiente].descripcion) == 0 && strcmp(lista[x].lastName, lista[y].lastName) > 0)){
                        auxEmpleado = lista[x];
                        lista[x] = lista[y];
                        lista[y] = auxEmpleado;
                    }
                }
            }
        }

    }
    return allRight;
}

int totalPromedioSalarios(employee lista[], int tam){
    int allRight = 0;
    float acumuladorSalario = 0;
    float promedio;
    int contadorEmpleados = 0;
    int contadorRicos = 0;
    for (int x = 0; x < tam; x++){
        if (lista[x].isEmpty == 0){
            contadorEmpleados++;
            acumuladorSalario += lista[x].salary;
        }
    }
    promedio = (float) acumuladorSalario / contadorEmpleados;

    for (int z = 0; z < tam; z++){
        if (lista[z].isEmpty == 0 && lista[z].salary > promedio){
            contadorRicos++;
        }
    }

    printf("\n\nEl total de los salarios es de $%.2f, haciendo un promedio de $%.2f por empleado, \ny %d empleado/s supera/n ese promedio\n\n",
           acumuladorSalario, promedio, contadorRicos);

    return allRight;
}



