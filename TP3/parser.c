#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief busca el id del ultimo empleado de un archivo binario y lo devuelve,
 *         es el ultimo ya que al guardar cualquer tipo de archivo, este pasa por un
 *         ordenamiento previo en base a id de forma ascendente. Otra forma de encararlo es hacer
 *         una copia completa y utilizar la funcion employee_SearchHighestId() pero ambas
 *         tienen sus pro y sus contras en cuanto a performance
 * \param pFile FILE* el puntero al archivo a analizar
 * \return int devuelve el id mas alto encontrado, o -1 si no encontro (por no existir archivo) o si hubo error
 *
 */
int parser_FindIdOfLastEmployerFromBinary(FILE* pFile){
    int id =-1;
    int cant;

    if (pFile != NULL){
        do{
            Employee* auxEmp = employee_new();
            cant = fread(auxEmp, sizeof(Employee), 1, pFile);
            if (cant < 1){
                break;
            }
            employee_getId(auxEmp, &id);
            employee_delete(auxEmp);

        }while (!feof(pFile));
    }
    return id;
}

/** \brief busca el id del ultimo empleado de un archivo binario y lo devuelve,
 *         es el ultimo ya que al guardar cualquer tipo de archivo, este pasa por un
 *         ordenamiento previo en base a id de forma ascendente. Otra forma de encararlo es hacer
 *         una copia completa y utilizar la funcion employee_SearchHighestId() pero ambas
 *         tienen sus pro y sus contras en cuanto a performance
 * \param pFile FILE* el puntero al archivo a analizar
 * \return int devuelve el id mas alto encontrado, o -1 si no encontro (por no existir archivo) o si hubo error
 *
 */
int parser_FindIdOfLastEmployerFromText(FILE* pFile){
    int id = -1;
    char elem[4][100];
    int cant;

    if (pFile != NULL){
        fscanf(pFile, "%s", elem[0]);//lectura fantasma del encabezado
        do{
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", elem[0],elem[1],elem[2],elem[3]);
            if (cant < 4){
              break;
            }
            if (feof(pFile)){
                id = atoi(elem[0]);
            }
        }while (!feof(pFile));
    }
    return id;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile el puntero al archivo a procesar
 * \param pArrayListEmployee LinkedList* el puntero a la linkedList de empleados a cargar
 * \return int 0 si es exitoso, -1 si falla
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int allRight = -1;
    char elem[4][100];
    int cant;

    if (pFile != NULL && pArrayListEmployee != NULL){
        fscanf(pFile, "%s", elem[0]);//lectura fantasma del encabezado
        printf("\nComprobando IDs duplicados. Aguarde\n");
        do{
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", elem[0],elem[1],elem[2],elem[3]);
            if (cant < 4){
              break;
            }
            Employee * nuevoEmpleado = employee_newParametros(elem[0], elem[1], elem[2], elem[3]);

            if (nuevoEmpleado != NULL){
                //evita que cargue dos veces un mismo empleado. hacerlo en una funcion
                if (parser_IdAlreadyLoaded(pArrayListEmployee, nuevoEmpleado) == 0){
                    ll_add(pArrayListEmployee, nuevoEmpleado);
                }
            }
        }while (!feof(pFile));
        allRight = 0;
    }
    return allRight;
}

/** \brief determina si un elemento employee en base a su valor id ya existe en la lista de linkedlist
 *
 * \param listaEmpleados LinkedList* el puntero a la linkedList de empleados
 * \param empleado Employee* el puntero al elemento empleado cuyo id se contrastara con la lista
 * \return int devuelve 1 si se encontro un id identico, o -1 si no, o si hubo un error
 *
 */
int parser_IdAlreadyLoaded(LinkedList* listaEmpleados, Employee* empleado){
    int esIgual = -1;
    Employee* auxEmp = NULL;
    int idElemLista;
    int idElemArch;

    if (listaEmpleados != NULL && empleado != NULL){
       esIgual = 0;
       for (int x = 0; x < ll_len(listaEmpleados); x++){
            auxEmp = ll_get(listaEmpleados, x);
            employee_getId(auxEmp, &idElemLista);
            employee_getId(empleado, &idElemArch);
            if (idElemLista== idElemArch){
                esIgual = 1;
                break;
            }
        }
    }
    return esIgual;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE* el puntero al archivo a procesar
 * \param pArrayListEmployee LinkedList* el puntero a la linkedList de empleados a cargar
 * \return int devuelve 0 si tuvo exito, -1 si no
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int allRight = -1;
    int cant;

    if (pFile != NULL && pArrayListEmployee != NULL){
        printf("\nComprobando IDs duplicados. Aguarde\n");
        do{
            Employee * nuevoEmpleado = employee_new();
            if (nuevoEmpleado != NULL){
                cant = fread(nuevoEmpleado, sizeof(Employee), 1, pFile);
                if (cant < 1){
                  break;
                }
                if (parser_IdAlreadyLoaded(pArrayListEmployee, nuevoEmpleado) == 0){
                    ll_add(pArrayListEmployee, nuevoEmpleado);
                }
            }
        }while (!feof(pFile));
        allRight = 0;
    }
    return allRight;
}
