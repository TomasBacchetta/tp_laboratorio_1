#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED
#include "LinkedList.h"

struct{
    int id;
    char descripcion[20];
    float precio;
} typedef eComida;

int comida_setId(eComida* this,int id);
int comida_setDescripcion(eComida* this,char* descripcion);
int comida_setPrecio(eComida* this, float precio);
int comida_getId(eComida* this, int* id);
int comida_getDescripcion(eComida* this,char* descripcion);
int comida_getPrecio(eComida* this,float* precio);
eComida* comida_new();
eComida* comida_newParametros(int id, char* descripcion, float precio);
void comida_delete(eComida* this);
int comida_mostrarComida(eComida* comida);
int comida_mostrarComidas(LinkedList* lista);
int comida_filtrarIdPar(void* comida);
int comida_CompararId(void* pComidaA, void* pComidaB);
int comida_CompararDescripcion(void* pComidaA, void* pComidaB);
int comida_CompararPrecio(void* pComidaA, void* pComidaB);


#endif // COMIDA_H_INCLUDED
