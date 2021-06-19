#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "BacchettaInput.h"
#include "Controller.h"


/** \brief devuelve el id mas alto de los archivos data.bin y data.csv y tambien los cargados en memoria
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve el id, o devuelve -1 si no encontro nada o si hubo error
 *
 */
int controller_loadToCheckLastId(char* pathT, char* pathB, LinkedList* pArrayListEmployee){
    int idText = -1;
    int idBin = -1;
    int idRam = -1;
    int id = -1;
    FILE* pArchivo = NULL;

    if((pArchivo = fopen(pathT, "r"))!= NULL){//trata de abrir archivo en modo texto
        idText = parser_FindIdOfLastEmployerFromText(pArchivo);
        fclose(pArchivo);
    }
    if((pArchivo = fopen(pathB,"rb"))!= NULL){//trata de abrir archivo en modo binario
        idBin = parser_FindIdOfLastEmployerFromBinary(pArchivo);
        fclose(pArchivo);
    }
    idRam = employee_SearchHighestId(pArrayListEmployee);
    if (idText >= idBin && idText >= idRam){
        id = idText;
    } else {
        if (idBin >= idText && idBin >= idRam){
            id =idBin;
        } else {
            id = idRam;
        }
    }
    return id;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int allRight = 0;

    FILE* pArchivo = NULL;

    if ((pArchivo = fopen(path, "r")) == NULL){//si el archivo no existe
        printf("\nNo existe el archivo. Puede crear uno con la opcion guardar\n");
        system("pause");
    } else {
        if (parser_EmployeeFromText(pArchivo, pArrayListEmployee) < 0){//se llama a la funcion de parser de texto
            allRight = -1;
        }
        if(fclose(pArchivo) == -1){//se cierra el archivo
            printf("\nError al cerrar el archivo!\n");
            allRight = -1;
        }
    }
    return allRight;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int allRight = -1;
    FILE* pArchivo = NULL;
    if (path != NULL && pArrayListEmployee != NULL){
        if ((pArchivo = fopen(path, "rb")) == NULL){//si el archivo no existe
            printf("\nNo existe el archivo. Puede crear uno con la opcion guardar\n");
        } else {
            if (parser_EmployeeFromBinary(pArchivo, pArrayListEmployee) < 0){
                allRight = -1;
                printf("\nallRight: %d\n", allRight);
            }
            if(fclose(pArchivo) == -1){//se cierra el archivo
                printf("\nError al cerrar el archivo!\n");
                allRight = -1;
            }
        }
        allRight = 0;
    }
    return allRight;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int allRight = -1;
    int id;
    char nombreIngresado[128];
    char horasTraIngresadas[128];
    char sueldoIngresado[128];
    //fabricar una funcion para obtener el nuevo id
    Employee* nuevoEmpleado = employee_new();

     if (pArrayListEmployee != NULL && nuevoEmpleado != NULL){
        system("cls");
        printf("Ingrese nombre\n");
        while(fixedGets(nombreIngresado, 128) < 0 ||
              employee_setNombre(nuevoEmpleado, nombreIngresado) < 0){
            printf("\nError!Ingrese nombre valido\n");
        }
        printf("Ingrese horas trabajadas (entre 20 y 500)\n");
        while(fixedGets(horasTraIngresadas, 128) < 0 ||
              employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTraIngresadas)) < 0){
            printf("\nError!Ingrese horas validas\n");
        }
         printf("Ingrese sueldo (desde 5000 hasta 300000\n");
        while(fixedGets(sueldoIngresado, 128) < 0 ||
              employee_setSueldo(nuevoEmpleado, atoi(sueldoIngresado)) < 0){
            printf("\nError!Ingrese sueldo valido\n");
        }
        system("cls");
        id = controller_loadToCheckLastId("data.csv", "data.bin", pArrayListEmployee);
        if (id == -1){
            //el id va a ser el primero de la empresa, 1
            printf("Primer empleado registrado.\nSe le asignara el id 1.\n");
            id = 1;
        //si consigue id
        } else {
            printf("Segun los empleados guardados en sistema y en archivos, el id mas alto es: %d.\n", id);
            id++;
            printf("\nSe le asignara al nuevo empleado el id %d.\n", id);
        }
        if (employee_setId(nuevoEmpleado, id) < 0 ||
            ll_add(pArrayListEmployee, nuevoEmpleado) < 0){
            allRight = 1;
        } else {
            allRight = 0;
        }
    }
    return allRight;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int allRight = -1;
    char id[10];
    int option;
    char nombreIngresado[128];
    char horasTraIngresadas[128];
    char sueldoIngresado[128];
    char respuesta = 'n';

    //Employee * auxEmp = NULL;//creo un auxiliar intermediario de la asignacion solo porque facilita validar con while
    Employee * empModif = employee_new();
    Employee * pEmpLista = NULL;

    if (pArrayListEmployee != NULL && empModif != NULL){
        allRight = 0;
        if (!ll_isEmpty(pArrayListEmployee)){
            controller_ListEmployee(pArrayListEmployee);
            printf("\nSeleccione un ID de empleado a modificar:");
            while(fixedGets(id, 10) < 0 || (pEmpLista = employee_findEmployeeById(pArrayListEmployee, atoi(id))) == NULL){
                printf("\nNo se encuentra ese id. Seleccione un id valido\n");
            }
            *empModif = *pEmpLista;//me interesa asignar el valor, no la direccion
            system("cls");
            printf("Este es el empleado a modificar:\n");
            printf("\nID  ||  Nombre  ||     Horas Trabajadas     ||     Sueldo\n");
            controller_showEmployee(empModif);
            do{
                printf("\n\n\nQue valor desea modificar?");
                printf("\n1. Nombre");
                printf("\n2. Horas Trabajadas");
                printf("\n3. Sueldo");
                printf("\n\nSeleccione una opcion: ");
                scanf("%d", &option);
                switch (option){
                case 1:
                    printf("Ingrese nuevo nombre\n");
                    while(fixedGets(nombreIngresado, 128) < 0 ||
                        employee_setNombre(empModif, nombreIngresado) < 0){
                    printf("\nError!Ingrese nombre valido\n");
                    }
                    break;
                case 2:
                    printf("Ingrese nuevas horas trabajadas\n");
                    while(fixedGets(horasTraIngresadas, 128) < 0 ||
                          employee_setHorasTrabajadas(empModif, atoi(horasTraIngresadas)) < 0){
                        printf("\nError!Ingrese horas validas\n");
                    }
                    break;
                case 3:
                     printf("Ingrese nuevo sueldo\n");
                    while(fixedGets(sueldoIngresado, 128) < 0 ||
                          employee_setSueldo(empModif, atoi(sueldoIngresado)) < 0){
                        printf("\nError!Ingrese sueldo valido\n");
                    }
                    break;
                default:
                    printf("\nOpcion incorrecta\n");
                }
            }while(option != 1 && option != 2 && option != 3);
            system("cls");
            printf("Asi se ve el empleado ahora:\n");
            printf("\nID  ||  Nombre  ||     Horas Trabajadas     ||     Sueldo\n");
            controller_showEmployee(empModif);
            respuesta = confirmar();
            if (respuesta == 's'){
                if ((pEmpLista = employee_findEmployeeById(pArrayListEmployee, atoi(id))) == NULL ||
                ll_set(pArrayListEmployee, ll_indexOf(pArrayListEmployee, pEmpLista), empModif) < 0){
                    allRight = -1;
                }
                employee_delete(pEmpLista);
            } else {
                allRight = -1;
            }
        } else {
            printf("\nNo hay empleados que modificar\n\n");
            allRight = -1;
        }
    }
    return allRight;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int allRight = -1;
    char id[10];
    char respuesta;
    int indiceABorrar;
    Employee * empBorrar = NULL;

    if (pArrayListEmployee != NULL){
        allRight = 0;
        if (!ll_isEmpty(pArrayListEmployee)){
            controller_ListEmployee(pArrayListEmployee);
            printf("\nSeleccione un ID de empleado a eliminar:");
            while(fixedGets(id, 10) < 0 || (empBorrar = employee_findEmployeeById(pArrayListEmployee, atoi(id))) == NULL){
                printf("\nNo se encuentra ese id. Seleccione un id valido\n");
            }
            system("cls");
            printf("Este es el empleado a eliminar:\n");
            printf("\nID  ||  Nombre  ||     Horas Trabajadas     ||     Sueldo\n");
            controller_showEmployee(empBorrar);
            respuesta = confirmar();
            if (respuesta == 's'){
                indiceABorrar = ll_indexOf(pArrayListEmployee, empBorrar);
                employee_delete(empBorrar);
                ll_remove(pArrayListEmployee, indiceABorrar);

            } else {
                allRight = -1;
            }
        } else {
            printf("\nNo hay empleados que eliminar\n\n");
            allRight = -1;
        }

    }
    return allRight;
}

/** \brief muestra a todos los empleados de una linkedList
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int allRight = -1;
    if (pArrayListEmployee != NULL){
        if (!ll_isEmpty(pArrayListEmployee)){
            Employee * auxEmpleado;
            printf("\nID  ||  Nombre  ||     Horas Trabajadas     ||     Sueldo\n");
            for (int x = 0; x < ll_len(pArrayListEmployee); x++){
                auxEmpleado = (Employee *) ll_get(pArrayListEmployee, x);
                if (auxEmpleado == NULL ||
                    controller_showEmployee(auxEmpleado) < 0){
                    printf("Error al mostrar linea");
                }
                printf("\n\n");
            }
        }else{
            printf("\nNo hay empleados que mostrar\n\n");
        }
        allRight = 1;
    }
    return allRight;
}


/** \brief muestra un empleado
 *
 * \param emp Employee*
 * \return int
 *
 */
int controller_showEmployee(Employee * emp){
    int allRight = -1;
    int id;
    char nombre[128];
    int horasTrab;
    int sueldo;

    if (emp != NULL){
        if (!employee_getId(emp, &id) &&
        !employee_getNombre(emp, nombre) &&
        !employee_getHorasTrabajadas(emp, &horasTrab) &&
        !employee_getSueldo(emp, &sueldo)){
            printf("%4d  %10s         %10d            %10d", id, nombre, horasTrab, sueldo);
            allRight = 0;
        }
    }
    return allRight;
}


/** \brief ordena empleados de la lista linkedlist
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int allRight = -1;
    int opcion;
    int (*pFuncion) (void*, void*) = NULL;
    int orden;

    if (pArrayListEmployee != NULL){
        allRight = 0;
        if (ll_len(pArrayListEmployee) > 1){
            do{
                printf("\nOrdenar lista de empleados: \n");
                printf("\n1. Por id\n");
                printf("\n2. Por nombre\n");
                printf("\n3. Por horas trabajadas\n");
                printf("\n4. Por sueldo\n");
                printf("\n\nSeleccione una opcion: ");
                scanf("%d", &opcion);

                switch(opcion){
                case 1:
                    pFuncion = employee_CompareId;
                    break;
                case 2:
                    pFuncion = employee_CompareNombre;
                    break;
                case 3:
                    pFuncion = employee_CompareHorasTra;
                    break;
                case 4:
                    pFuncion = employee_CompareSueldo;
                    break;
                default:
                    printf("\nOpcion incorrecta\n");
                }
            }while (opcion !=1 &&
                    opcion !=2 &&
                    opcion !=3 &&
                    opcion !=4);
            system("cls");
            do{
                printf("Seleccione orden:\n");
                printf("\nAscendente (1)\n");
                printf("Descendente (0)\n");
                printf("\n\nSeleccione una opcion: ");
                scanf("%d", &orden);
                if (orden != 0 && orden != 1){
                    printf("\nOpcion incorrecta");
                }

            }while(orden != 0 && orden != 1);
            system("cls");
            printf("Ordenando... espere unos instantes\n");
            if (ll_sort(pArrayListEmployee, pFuncion, orden) < 0){
                allRight = -1;
            }
            system("cls");
        } else {
            printf("No hay suficientes empleados para ordenar\n\n");
            allRight = -1;
        }
    }
    return allRight;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *         para ver el por que del ordenamiento previo, consultar funcion parser_FindIdOfLastEmployerFromText()
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si se exitoso, -1 si hubo algun problema
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int allRight = -1;
    int id;
    char nombre[128];
    int horasTra;
    int sueldo;
    char buffer[3][128];
    FILE * pArchivo = NULL;
    Employee* auxEmp = employee_new();
    Employee * empleadoCarga = employee_new();

    if (path != NULL && pArrayListEmployee != NULL && auxEmp != NULL){
        allRight = 0;
        if (!ll_isEmpty(pArrayListEmployee)){
            if ((pArchivo = fopen(path, "w"))== NULL){//se crea un nuevo archivo
                printf("\nError al generar el archivo\n");
                allRight = -1;
            }
            //se ordena antes de guardar para que siempre el ultimo elemento del archivo tenga el id mas alto
            printf("\nOrdenando antes por id de guardar... espere unos instantes\n");
            if (ll_sort(pArrayListEmployee, employee_CompareId,1) < 0 && ll_len(pArrayListEmployee) > 1){
                allRight = -1;
            } else {
                printf("\nOrdenado satisfactorio. Gracias por esperar\n");
                fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");//se escribe la primera linea si recien se creo el archivo
                for (int x = 0; x < ll_len(pArrayListEmployee); x++){
                    auxEmp = (Employee *)ll_get(pArrayListEmployee, x);
                    if (auxEmp != NULL){
                        *empleadoCarga = *auxEmp;
                        if (employee_getId(empleadoCarga, &id) < 0 ||
                            employee_getNombre(empleadoCarga, nombre) < 0 ||
                            employee_getHorasTrabajadas(empleadoCarga, &horasTra) < 0 ||
                            employee_getSueldo(empleadoCarga, &sueldo) < 0){
                        allRight = -1;
                        break;
                        } else {
                            fprintf(pArchivo, "%s,%s,%s,%s\n", itoa(id, buffer[0], 10), nombre, itoa(horasTra, buffer[1], 10), itoa(sueldo, buffer[2], 10));
                        }
                    } else {
                        allRight = -1;
                        break;
                    }
                }
                if(fclose(pArchivo) == -1){//se cierra el archivo en modo escritura
                    printf("\nError al cerrar el archivo!\n");
                    allRight = -1;
                }
            }
        } else {
            printf("\nNo hay empleados que guardar\n");
            allRight = -1;
        }
    }
    employee_delete(empleadoCarga);

    return allRight;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *         para ver el por que del ordenamiento previo, consultar funcion parser_FindIdOfLastEmployerFromBinary()
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si se exitoso, -1 si hubo algun problema
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int allRight = -1;
    FILE * pArchivo = NULL;
    Employee* auxEmp = NULL;
    Employee * empleadoCarga = employee_new();

    if (path != NULL && pArrayListEmployee != NULL && empleadoCarga != NULL){
        allRight = 0;
        if (!ll_isEmpty(pArrayListEmployee)){
            if ((pArchivo = fopen(path, "wb"))== NULL){//se crea un nuevo archivo
                printf("\nError al generar el archivo\n");
                allRight = -1;
            }
            //se ordena antes de guardar para que siempre el ultimo elemento del archivo tenga el id mas alto
            printf("\nOrdenando por id antes de guardar.. espere unos instantes");
            if (ll_sort(pArrayListEmployee, employee_CompareId,1) < 0 && ll_len(pArrayListEmployee) > 1){
                allRight = -1;
            } else {
                printf("\nOrdenado satisfactorio. Gracias por esperar");
                for (int x = 0; x < ll_len(pArrayListEmployee);x++){
                    auxEmp = (Employee *)ll_get(pArrayListEmployee, x);
                    if (empleadoCarga != NULL){
                        *empleadoCarga = *auxEmp;
                        fwrite(empleadoCarga, sizeof(Employee), 1, pArchivo);
                    } else {
                        allRight = -1;
                        break;
                    }
                }
                if(fclose(pArchivo) == -1){//se cierra el archivo en modo escritura
                    printf("\nError al cerrar el archivo!\n");
                allRight = -1;
                }
             }
        } else {
            printf("\nNo hay empleados que guardar\n");
            allRight = -1;
        }
    }
    employee_delete(empleadoCarga);
    return allRight;
}




