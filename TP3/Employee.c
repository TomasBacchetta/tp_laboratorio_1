#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "BacchettaInput.h"

static int isValidNombre(char * nombre);
static int isValidHorasTrabajadas(int horasTra);
static int isValidSueldo(int sueldo);


/** \brief valida el ingreso de un nombre a un elemento employee
 *
 * \param nombre char* el nombre a validar
 * \return int 0 si tiene exito -1 si no
 *
 */
static int isValidNombre(char * nombre){
    int allRight = 0;
    if (nombre != NULL){
        allRight = 1;
        for (int x = 0; x < nombre[x] && nombre[x] != '\0'; x++)
            {
                if (((nombre[x] < 65 || nombre[x] > 122) && nombre[x] != ' ' && nombre[x] != '\n' && nombre[x] != '-') ||
                    nombre[0] == ' ' ||
                    nombre[strlen(nombre)-2] == ' ' ||
                    nombre[0] == '-') //si no es texto incluyendo espacio y salto de linea, mientras que el espacio no este adelante o al final de la cadena
                {
                    allRight = 0;
                    break;
                }
                if (x > 0)  //evita leer fuera del rango de cadena
                {
                    if (nombre[x - 1] == ' ' && nombre[x] == ' ')  //si hay por lo menos dos espacios consecutivos
                    {
                        allRight = 0;
                        break;
                    }
                }
            }
    }
    return allRight;
}

/** \brief valida el ingreso de horas ingresadas a un elemento employee
 *
 * \param horasTra int
 * \return int 0 si tiene exito -1 si no
 *
 */
static int isValidHorasTrabajadas(int horasTra){
    int allRight = 1;

    if (horasTra < 20 || horasTra > 500){
        allRight = 0;
    }
    return allRight;
}

/** \brief valida el ingreso de sueldo a un elemento employee
 *
 * \param sueldo int
 * \return int 0 si tiene exito -1 si no
 *
 */
static int isValidSueldo(int sueldo){
    int allRight = 1;

    if (sueldo < 5000 || sueldo > 300000){
        allRight = 0;
    }
    return allRight;
}

//setters
int employee_setId(Employee* this,int id){
    int allRight = -1;

        if (this != NULL){
            this->id = id;
            allRight = 0;
        }
    return allRight;
}

int employee_setNombre(Employee* this,char* nombre){
    int allRight = -1;

    if (this != NULL && nombre != NULL && isValidNombre(nombre)){
        formatearNombre(nombre);
        strcpy(this->nombre, nombre);
        allRight = 0;
    }
    return allRight;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas){
    int allRight = -1;

    if (this != NULL && isValidHorasTrabajadas(horasTrabajadas)){
        this->horasTrabajadas = horasTrabajadas;
        allRight = 0;
    }
    return allRight;
}

int employee_setSueldo(Employee* this,int sueldo){
    int allRight = -1;

    if (this != NULL && isValidSueldo(sueldo)){
        this->sueldo = sueldo;
        allRight = 0;
    }
    return allRight;
}

//getters

int employee_getId(Employee* this, int* id){
    int allRight = -1;

    if(this!= NULL && id != NULL){
        *id = this->id;
        allRight = 0;
    }
    return allRight;
}

int employee_getNombre(Employee* this,char* nombre){
    int allRight = -1;

    if(this!= NULL && nombre != NULL){
        strcpy(nombre, this->nombre);
        allRight = 0;
    }
    return allRight;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    int allRight = -1;

    if(this!= NULL && horasTrabajadas != NULL){
        *horasTrabajadas = this->horasTrabajadas;
        allRight = 0;
    }
    return allRight;
}

int employee_getSueldo(Employee* this,int* sueldo){
    int allRight = -1;

    if(this!= NULL && sueldo != NULL){
        *sueldo = this->sueldo;
        allRight = 0;
    }
    return allRight;
}

/** \brief constructor de elemento empleado
 *
 * \return Employee* devuelve el indice al elemento de tipo empleado creado en memoria dinamica
 *
 */
Employee* employee_new(){
     Employee* nuevoEmpleado = (Employee*) malloc (sizeof(Employee));

     if (nuevoEmpleado == NULL){
        return NULL;
     }
     return nuevoEmpleado;
}

/** \brief constructor de elemento empleado en base a parametros en string
 *
 * \param idStr char* recibe el id como string
 * \param nombreStr char* recibe el nombre
 * \param horasTrabajadasStr char* recibe las horas trabajadas como string
 * \param sueldoStr char* recibe el sueldo como string
 * \return Employee* devuelve el puntero al elemento empleado creado en memoria dinamica
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
    Employee* empleado = employee_new();
    int id = atoi(idStr);
    int horasTrabajadas = atoi(horasTrabajadasStr);
    int sueldo = atoi(sueldoStr);

    if (employee_setId(empleado, id) < 0 ||
        employee_setNombre(empleado, nombreStr) < 0 ||
        employee_setHorasTrabajadas(empleado, horasTrabajadas) < 0 ||
        employee_setSueldo(empleado, sueldo) < 0 || idStr == NULL ||
        nombreStr == NULL ||
        horasTrabajadasStr == NULL ||
        sueldoStr == NULL
        ){
            employee_delete(empleado);
            empleado = NULL;
        }
    return empleado;
}

/** \brief libera el espacio de memoria de un elemento empleado
 *
 * \param this Employee* recibe la direccion en memoria del elemento empleado a liberar
 * \return void
 *
 */
void employee_delete(Employee* this){
    if (this != NULL){
        free(this);
    }
}

/** \brief libera el espacio de memoria de una linkedlist de empleados
 *
 * \param listaEmpleados LinkedList* recibe la linkedList
 * \return int retorna 0 si borro todo o -1 si encontro un error
 *
 */
int employee_deleteAll(LinkedList* listaEmpleados){
    Employee* empParaEliminar = NULL;
    int allRight = -1;

    if (listaEmpleados != NULL){
        for (int x = 0; x < ll_len(listaEmpleados); x++){
            empParaEliminar = ll_get(listaEmpleados, x);
            employee_delete(empParaEliminar);
        }
        allRight = 0;
    }
    return allRight;
}

/** \brief determina entre dos elementos cual tiene mayor id (tal como especifica ll_sort())
 *
 * \param empleadoA void* el puntero a un elemento de la lista
 * \param empleadoB void* el elemento al elemento siguiente de la lista
 * \return int 0 si son iguales, 1 si empleadoA es mayor, -1 si empleadoB es mayor
 *
 */
int employee_CompareId(void * empleadoA, void* empleadoB){
    int comp = 0;//si son iguales

    if (((Employee*)empleadoA)->id > ((Employee*)empleadoB)->id){
        comp = 1;//si A es mayor
    } else {
         if (((Employee*)empleadoA)->id < ((Employee*)empleadoB)->id){
            comp = -1;//si B es mayor
        }
    }
    return comp;
}

/** \brief determina entre dos elementos cual tiene mayor nombre alfabeticamente (utilizado por ll_sort)
 *
 * \param empleadoA void* el puntero a un elemento de la lista
 * \param empleadoB void* el elemento al elemento siguiente de la lista
 * \return int 0 si son iguales, 1 si empleadoA es mayor, -1 si empleadoB es mayor
 *
 */
int employee_CompareNombre(void * empleadoA, void* empleadoB){
    int comp = 0;//si son iguales

    if (strcmp(((Employee*)empleadoA)->nombre, ((Employee*)empleadoB)->nombre) == 1){
        comp = 1;//si A es mayor
    } else {
        if (strcmp(((Employee*)empleadoA)->nombre, ((Employee*)empleadoB)->nombre) == -1){
            comp = -1;//si B es mayor
        }
    }
    return comp;//si son iguales
}

/** \brief determina entre dos elementos cual tiene mayor valor de horas trabajadas (utilizado por ll_sort)
 *
 * \param empleadoA void* el puntero a un elemento de la lista
 * \param empleadoB void* el elemento al elemento siguiente de la lista
 * \return int 0 si son iguales, 1 si empleadoA es mayor, -1 si empleadoB es mayor
 *
 */
int employee_CompareHorasTra(void * empleadoA, void* empleadoB){
    int comp = 0;//si son iguales

    if (((Employee*)empleadoA)->horasTrabajadas > ((Employee*)empleadoB)->horasTrabajadas){
        comp = 1;//si A es mayor
    } else {
        if (((Employee*)empleadoA)->horasTrabajadas < ((Employee*)empleadoB)->horasTrabajadas){
            comp = -1;//si B es mayor
        }
    }
    return comp;
}

/** \brief determina entre dos elementos cual tiene mayor sueldo (utilizado por ll_sort)
 *
 * \param empleadoA void* el puntero a un elemento de la lista
 * \param empleadoB void* el elemento al elemento siguiente de la lista
 * \return int 0 si son iguales, 1 si empleadoA es mayor, -1 si empleadoB es mayor
 *
 */
int employee_CompareSueldo(void * empleadoA, void* empleadoB){
    int comp = 0;//si son iguales

    if (((Employee*)empleadoA)->sueldo > ((Employee*)empleadoB)->sueldo){
        comp = 1;//si A es mayor
    } else {
        if (((Employee*)empleadoA)->sueldo < ((Employee*)empleadoB)->sueldo){
            comp = -1;//si B es mayor
        }
    }
    return comp;
}

/** \brief busca el mayor id de la linkedList de empleados
 *
 * \param listaEmpleados LinkedList*
 * \return int retorna el maximo id encontrado, o -1 si no hay ids porque no hay elementos cargados, o si surgio un error
 *
 */
int employee_SearchHighestId(LinkedList* listaEmpleados){
    int mayorId = -1;
    Employee* auxEmp = NULL;

    if (listaEmpleados != NULL && ll_len(listaEmpleados) > 0){
        for (int x = 0; x < ll_len(listaEmpleados); x++){
            auxEmp = (Employee*) ll_get(listaEmpleados, x);
            if (auxEmp->id > mayorId){
                mayorId = auxEmp->id;
            }
        }
    }
    return mayorId;
}

/** \brief devuelve la posicion en memoria de un elemento en linkedList en base a su id
 *
 * \param listaEmpleados LinkedList*
 * \param id int
 * \return Employee* devuelve el puntero al empleado o NULL si no lo encontro o surgio un error
 *
 */

Employee* employee_findEmployeeById(LinkedList* listaEmpleados, int id){
    int flagEncontroId = 0;
    Employee* auxEmp = NULL;

    if (listaEmpleados != NULL){
        for (int x = 0; x < ll_len(listaEmpleados); x++){
            auxEmp = (Employee *) ll_get(listaEmpleados, x);
            if (id == auxEmp->id){
                flagEncontroId = 1;
                break;
            }
        }
        if (!flagEncontroId){
            auxEmp = NULL;
        }
    }
    return auxEmp;
}
