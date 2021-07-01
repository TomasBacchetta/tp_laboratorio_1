#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comida.h"

//setters
int comida_setId(eComida* this,int id){
    int allRight = -1;

        if (this != NULL){
            this->id = id;
            allRight = 0;
        }
    return allRight;
}

int comida_setDescripcion(eComida* this,char* descripcion){
    int allRight = -1;

    if (this != NULL && descripcion != NULL){
        strcpy(this->descripcion, descripcion);
        allRight = 0;
    }
    return allRight;
}

int comida_setPrecio(eComida* this, float precio){
    int allRight = -1;

    if (this != NULL){
        this->precio = precio;
        allRight = 0;
    }
    return allRight;
}

//getters
int comida_getId(eComida* this, int* id){
    int allRight = -1;

    if(this!= NULL && id != NULL){
        *id = this->id;
        allRight = 0;
    }
    return allRight;
}

int comida_getDescripcion(eComida* this,char* descripcion){
    int allRight = -1;

    if(this!= NULL && descripcion != NULL){
        strcpy(descripcion, this->descripcion);
        allRight = 0;
    }
    return allRight;
}

int comida_getPrecio(eComida* this,float* precio){
    int allRight = -1;

    if(this!= NULL && precio != NULL){
        *precio = this->precio;
        allRight = 0;
    }
    return allRight;
}

//constructores
eComida* comida_new(){
     eComida* nuevaComida = (eComida*) malloc (sizeof(eComida));

     if (nuevaComida == NULL){
        return NULL;
     }
     return nuevaComida;
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
eComida* comida_newParametros(int id, char* descripcion, float precio){
    eComida* comida = comida_new();

    if (comida_setId(comida, id) < 0 ||
        comida_setDescripcion(comida, descripcion) < 0 ||
        comida_setPrecio(comida, precio) < 0
        ){
            comida_delete(comida);
            comida = NULL;
        }
    return comida;
}

void comida_delete(eComida* this){
    if (this != NULL){
        free(this);
    }
}

int comida_mostrarComida(eComida* comida){
    int allRight = -1;
    int id;
    char descripcion[20];
    float precio;
    if (comida != NULL){
        if (!comida_getId(comida, &id) && !comida_getDescripcion(comida, descripcion) && !comida_getPrecio(comida, &precio)){
                  printf("%2d  %10s       %5f\n", id, descripcion, precio);
        }
        allRight = 0;
    }
    return allRight;
}

int comida_mostrarComidas(LinkedList* lista){
    int allRight = -1;
    eComida * comida = NULL;
    int tam;

    if (lista != NULL){
        if (!ll_isEmpty(lista)){
            tam = ll_len(lista);
            printf("ID || Descripcion || Precio\n");
            for (int x = 0; x < tam; x++){
                comida = (eComida*)ll_get(lista, x);
                comida_mostrarComida(comida);
            }
        } else {
            printf("\nNo hay elementos que mostrar!\n");
        }
        allRight = 0;
    }
    return allRight;
}


int comida_filtrarIdPar(void* comida){
    int es = 0;
    int id;
    eComida* auxComida = NULL;
        if (comida != NULL){
              auxComida = (eComida*) comida;
            if (!comida_getId(auxComida, &id)){
                if (id % 2 == 0){
                    es = 1;
                }
            }
        }
    return es;
}

int comida_CompararId(void* pComidaA, void* pComidaB){
    if (((eComida*)pComidaA)->id > ((eComida*)pComidaB)->id){
        return 1;
    }
    if (((eComida*)pComidaA)->id < ((eComida*)pComidaB)->id){
        return -1;
    }
    return 0;

}

int comida_CompararDescripcion(void* pComidaA, void* pComidaB){
    if (strcmp(((eComida*)pComidaA)->descripcion,((eComida*)pComidaB)->descripcion) == 1){
        return 1;
    }
    if (strcmp(((eComida*)pComidaA)->descripcion,((eComida*)pComidaB)->descripcion) == -1){
        return -1;
    }
    return 0;

}

int comida_CompararPrecio(void* pComidaA, void* pComidaB){
    if (((eComida*)pComidaA)->precio > ((eComida*)pComidaB)->precio){
        return 1;
    }
    if (((eComida*)pComidaA)->precio < ((eComida*)pComidaB)->precio){
        return -1;
    }
    return 0;

}

