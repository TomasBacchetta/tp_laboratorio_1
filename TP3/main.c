#include <stdio.h>
#include <stdlib.h>


#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "BacchettaInput.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{

    int option = 0;
    char respuesta = 'n';
    LinkedList* listaEmpleados = ll_newLinkedList();

    setbuf(stdout, NULL);
    do{
        system("cls");
        printf("\t\t\t\tMenu Principal\n\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf("3. Alta de empleado (no es necesario cargar archivo antes).\n");
        printf("4. Modificar datos de empleado.\n");
        printf("5. Baja de empleado.\n");
        printf("6. Listar empleados.\n");
        printf("7. Ordenar empleados.\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10. Salir\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &option);
        system("cls");

        switch(option)
        {
            case 1:
                if (controller_loadFromText("data.csv",listaEmpleados) < 0){
                    printf("\nError inesperado al cargar archivo data.csv\n");
                } else {
                    printf("\nCarga de texto exitosa\n");
                }
                system("pause");
                break;
            case 2:
                if (controller_loadFromBinary("data.bin", listaEmpleados) < 0){
                    printf("\nError inesperado al cargar archivo data.bin\n");
                } else {
                    printf("\nCarga binaria exitosa\n");
                }
                system("pause");
                break;
            case 3:
                if (controller_addEmployee(listaEmpleados) < 0){
                    printf("\nError inesperado al intentar dar de alta\n");
                } else {
                    printf("\nAlta exitosa\n");
                }
                system("pause");
                break;
            case 4:
                if (controller_editEmployee(listaEmpleados) < 0){
                    printf("\nNo se modifico empleado\n");
                } else {
                    printf("\nModificacion exitosa\n");
                }
                system("pause");
                break;
            case 5:
                if (controller_removeEmployee(listaEmpleados) < 0){
                    printf("\nNo se elimino empleado\n");
                } else {
                    printf("\nEliminacion exitosa\n");
                }
                system("pause");
                break;
            case 6:
                if (controller_ListEmployee(listaEmpleados) < 0){
                    printf("\nError inesperado al intentar mostrar empleados\n");
                }
                system("pause");
                break;
            case 7:
                if (controller_sortEmployee(listaEmpleados) < 0){
                    printf("\nNo se ordeno la lista de empleados\n");
                } else {
                    printf("Ordenamiento exitoso\n");
                }
                system("pause");
                break;
            case 8:
                //para que funcione mi metodo se deben guardar ordenados por id ascendente
                if (controller_saveAsText("data.csv" , listaEmpleados) < 0){
                    printf("\nNo se guardo en data.csv\n");
                } else {
                    printf("Guardado en formato texto exitoso\n");
                }
                system("pause");
                break;
            case 9:
                //para que funcione mi metodo se deben guardar ordenados por id ascendente
                if (controller_saveAsBinary("data.bin", listaEmpleados) < 0){
                    printf("\nNo se guardo en data.bin\n");
                } else {
                    printf("\n\nGuardado en formato binario exitoso\n\n");
                }
                system("pause");
                break;
            case 10:
                respuesta = salir();
                break;
            default:
                printf("Opcion invalida\n");
                system("pause");
                break;
        }
    }while(respuesta == 'n');
    //TAMBIEN HAY QUE BORRAR A CADA EMPLEADO
    employee_deleteAll(listaEmpleados);
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}

