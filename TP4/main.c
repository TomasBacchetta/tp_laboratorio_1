#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "comida.h"


int main()
{
    //hardcode comidas
    int id = 0;

    char hDescripcion[10][20] = {{"Chorizo"},{"Lechuga"},{"Poroto"},{"Milanesa"},{"Helado"},{"Pionono"},{"Tarta"},{"Albondiga"},{"Pizza"},{"Fideos"}};
    float hPrecio [10] = {100, 20, 5, 50, 20, 30, 25, 15, 40, 35};
    eComida* auxComida = NULL;
    int indice;

    LinkedList* listaComidas = ll_newLinkedList();//TEST NUEVA LINKEDLIST
    LinkedList* listaComidas2 = NULL;
    LinkedList* listaComidas3 = NULL;
    LinkedList* listaComidas4 = NULL;
    LinkedList* listaFiltrada = NULL;


    if (listaComidas == NULL){
        exit(1);
    }

    printf(">>SE CREO UNA NUEVA LINKED LIST<<\n");
    printf("\n\n");
    system("pause");
    system("cls");



    //TEST DE LL_ADD
    for (int x = 0; x < 10; x++){
        id++;
        eComida* comida = comida_newParametros(id, hDescripcion[x], hPrecio[x]);
        if (ll_add(listaComidas, comida) == -1){
            exit(1);
            break;
        }
    }
    listaComidas3 = ll_clone(listaComidas);
    printf(">>SE AGREGARON ELEMENTOS A LA LINKED LIST<<\n");
    printf(">>ESTOS SON LOS ELEMENTOS DE LA LINKEDLIST<<\n");
    //TEST DE LL_GET



    if (comida_mostrarComidas(listaComidas)){
       exit(1);
    }
    printf("\nLargo de la linkedlist: %d\n", ll_len(listaComidas));
    printf("\n\n>>LL_NEWLINKEDLIST FUNCIONO(1/17)<<\n");
    printf(">>LL_ADD FUNCIONO(2/17)<<\n");
    printf(">>LL_LEN FUNCIONO(3/17)<<\n");
    printf(">>LL_GET FUNCIONO(4/17)<<\n");
    printf("\n\n");
    system("pause");
    system("cls");

    //TEST DE LL_CLONE
    listaComidas2 = ll_clone(listaComidas);

    //TEST DE LL_SET
    printf(">>AHORA EN UNA LISTA, SE VA A CAMBIAR EL VALOR DEL SEGUNDO ELEMENTO POR EL DEL PRIMERO<<\n");
    printf("\n\n");
    system("pause");
    system("cls");
    printf(">>ESTA ES LA LISTA CLONADA<<\n");
    auxComida = ll_get(listaComidas2, 0);
    if (ll_set(listaComidas2, 1,auxComida) || comida_mostrarComidas(listaComidas2)){
        exit(1);
    }

    printf("\n>>ESTA ES LA LISTA ORIGINAL<<\n");
    if (comida_mostrarComidas(listaComidas)){
        exit(1);
    }

    printf("\n>>LL_CLONE FUNCIONO(5/17)<<");
    printf("\n>>LL_SET FUNCIONO(6/17)<<");

    printf("\n\n");
    system("pause");
    system("cls");

    printf(">>AHORA SE VA A REMOVER EL QUINTO ELEMENTO DE UNA LISTA<<\n");
    if (comida_mostrarComidas(listaComidas2)){
        exit(1);
    }
    if (ll_remove(listaComidas2, 4)){
        exit(1);
    }
    printf("\n>>ASI QUEDA LA LISTA<<\n");
    if (comida_mostrarComidas(listaComidas2)){
        exit(1);
    }
    printf(">>LL_REMOVE FUNCIONO (7/17)<<\n");
     printf("\n\n");
    system("pause");
    system("cls");

    printf(">>AHORA SE VA A ELIMINAR UNA LISTA<<\n");
    printf("\nLargo de la linkedlist: %d\n", ll_len(listaComidas2));
    ll_deleteLinkedList(listaComidas2);

    printf("\nLargo de la linkedlist luego de borrarla: %d\n", ll_len(listaComidas2));
    listaComidas2 = NULL;// es correcto que la lista borrada apunte a NULL por seguridad
    printf("\nLargo de la linkedlist luego de borrarla y que el puntero apunte a NULL: %d\n", ll_len(listaComidas2));
    printf(">>\nLL_CLEAR FUNCIONO(8/17)<<\n");
    printf(">>LL_DELETELINKEDLIST FUNCIONO(9/17)<<\n");
    printf("\n\n");
    system("pause");
    system("cls");
    printf(">>AHORA SE VA A OBTENER EL INDICE DEL ELEMENTO 'MILANESA' DE UNA LISTA<<");
    printf("\n>>LA DIRECCION DE ESTE ELEMENTO ES: %d\n", (int)(ll_get(listaComidas, 3)));
    indice = ll_indexOf(listaComidas, ll_get(listaComidas,3));
    printf("\n>>PASANDOLE ESTE PUNTERO A LL_INDEXOF ARROJA QUE EL ELEMENTO SE ENCUENTRA EN INDICE: %d, QUE EN LISTA ES POSICION %d\n", indice, indice+1);
    if (comida_mostrarComidas(listaComidas)){
        exit(1);
    }
    printf("\n>>LL_INDEXOF FUNCIONO(10/17)<<");
    printf("\n\n");
    system("pause");
    system("cls");

    printf(">>AHORA SE VA A CLONAR DE NUEVO LA LISTA ORIGINAL, PARA LUEGO COMPROBAR SI TIENE ELEMENTOS O NO\n<<");
    listaComidas2 = ll_clone(listaComidas);
    if (comida_mostrarComidas(listaComidas2)){
        exit(1);
    }
    if(ll_isEmpty(listaComidas2)){
        printf("\nLA LISTA ESTA VACIA\n");
    } else {
        printf("\nLA LISTA NO ESTA VACIA\n");
    }
    ll_clear(listaComidas2);
    printf("\n\n>>AHORA SE BORRARON TODOS LOS ELEMENTOS DE LA LISTA CON LL_CLEAR<<");
    if (comida_mostrarComidas(listaComidas2)){
        exit(1);
    }
    if(ll_isEmpty(listaComidas2)){
        printf("\nLA LISTA ESTA VACIA\n");
    } else {
        printf("\nLA LISTA NO ESTA VACIA\n");
    }
    printf("\n>>LL_ISEMPTY FUNCIONO(11/17)<<");
    printf("\n\n");
    system("pause");
    system("cls");

    printf(">>AHORA SE VA A INSERTAR AL ELEMENTO INDICE 0 EN INDICE 5, CON LL_PUSH, EN UNA LISTA\n<<");
     if (comida_mostrarComidas(listaComidas)){
        exit(1);
    }
    printf("\nLargo de la linkedlist: %d\n", ll_len(listaComidas));
    ll_push(listaComidas, 5, ll_get(listaComidas, 0));
    if (comida_mostrarComidas(listaComidas)){
        exit(1);
    }
    printf("\nLargo de la linkedlist __push(): %d", ll_len(listaComidas));
    printf("\n\n");
    system("pause");
    system("cls");
    printf(">>COMO PUDO APRECIARSE, NO SE REEMPLAZO UN ELEMENTO POR OTRO, SINO QUE SE AGREGO Y EL RESTO SE DESPLAZO AUTOMATICAMENTE<<");
    printf("\n>>LL_PUSH FUNCIONO(12/17)<<");
    printf("\n\n");
    system("pause");
    system("cls");

    printf(">>AHORA SE BORRARA EL ULTIMO ELEMENTO DE UNA LISTA, PERO SE COPIARA EN LA PRIMERA POSICION<");
    printf("\n>>ESTO ES POSIBLE CON LL_POP<\n");
    if (comida_mostrarComidas(listaComidas)){
        exit(1);
    }
    ll_set(listaComidas, 0,ll_pop(listaComidas, 10));
    printf("\n>>ASI QUEDA LA LISTA APLICANDO LL_POP<\n");
    if (comida_mostrarComidas(listaComidas)){
        exit(1);
    }
    printf("\n>>LL_POP FUNCIONO(13/17)<");
    printf("\n");
    system("pause");
    system("cls");

    printf(">>AHORA SE VA A COMPROBAR SI EL PRIMER ELEMENTO DE UNA LISTA ESTA CONTENIDO EN LA LISTA ORIGINAL<\n");
    if (comida_mostrarComidas(listaComidas3)){
        exit(1);
    }
    printf("\n");
    if (comida_mostrarComidas(listaComidas)){
        exit(1);
    }
    if (ll_contains(listaComidas, ll_get(listaComidas3, 0))){
        printf("\nEl elemento se encuentra dentro");
    } else {
        printf("\nEl elemento no esta");
    }
    printf("\n\n");
    system("pause");
    system("cls");

    printf(">>AHORA, SE VA A BORRAR DICHO ELEMENTO EN ESA LISTA, A VER COMO SE COMPORTA LA FUNCION\n");
    ll_remove(listaComidas, 5);
    if (comida_mostrarComidas(listaComidas3)){
        exit(1);
    }
     printf("\n");
    if (comida_mostrarComidas(listaComidas)){
        exit(1);
    }
    if (ll_contains(listaComidas, ll_get(listaComidas3, 0))){
        printf("\nEl elemento se encuentra dentro");
    } else {
        printf("\nEl elemento no esta");
    }
    printf("\n>>LL_CONTAINS FUNCIONO(14/17)<\n");
    printf("\n\n");
    system("pause");
    system("cls");

    printf(">>AHORA SE SE VA A COMPROBAR ESTA LISTA Y SU CLON TIENEN LOS MISMOS ELEMENTOS<\n");
    listaComidas4 = ll_clone(listaComidas3);
    if (comida_mostrarComidas(listaComidas4)){
        exit(1);
    }
     printf("\n");
    if (comida_mostrarComidas(listaComidas3)){
        exit(1);
    }
    if (ll_containsAll(listaComidas4, listaComidas3)){
        printf("\nContienen los mismos elementos\n");
    } else {
        printf("\nNo contienen los mismos elementos\n");
    }
    printf("\n\n");
    system("pause");
    system("cls");

    printf(">>AHORA SE VA A COMPROBAR SI ESTAS DOS LISTAS TIENEN LOS MISMOS ELEMENTOS<\n");
    if (comida_mostrarComidas(listaComidas)){
        exit(1);
    }
     printf("\n");
    if (comida_mostrarComidas(listaComidas3)){
        exit(1);
    }
    if (ll_containsAll(listaComidas, listaComidas3)){
        printf("\nContienen los mismos elementos\n");
    } else {
        printf("\nNo contienen los mismos elementos\n");
    }
    printf("\n>>LL_CONTAINSALL FUNCIONO(15/17)<\n");
    printf("\n\n");
    system("pause");
    system("cls");

    printf(">>AHORA SE VA A CREAR UNA NUEVA LINKEDLIST SOLO CON ELEMENTOS CUYO ID ES PAR<\n");
    listaFiltrada = ll_filter(listaComidas4, comida_filtrarIdPar);

    if (listaFiltrada == NULL){
        exit(1);
    }
    if (comida_mostrarComidas(listaFiltrada)){
        exit(1);
    }
    printf("\n\n>>LL_FILTER FUNCIONO(16/17)<<\n");
    ll_remove(listaComidas, 9);

    if (comida_mostrarComidas(listaComidas)){
        exit(1);
    }
     printf("\n");
    if (comida_mostrarComidas(listaFiltrada)){
        exit(1);
    }


    printf("\n\n");
    system("pause");
    system("cls");

    printf(">>AHORA SE VA A ORDENAR UNA LISTA BAJO DIFERENTES CRITERIOS<\n");
    if (comida_mostrarComidas(listaComidas4)){
        exit(1);
    }
    printf("\n\n");
    system("pause");
    system("cls");

    printf(">>ORDENANDO POR ID<\n");
    printf(">>Orden ascendente<\n");
    ll_sort(listaComidas4, comida_CompararId, 1);
    if (comida_mostrarComidas(listaComidas4)){
        exit(1);
    }
    printf("\n>>Orden descendente<\n");
    ll_sort(listaComidas4, comida_CompararId, 0);
    if (comida_mostrarComidas(listaComidas4)){
        exit(1);
    }
    printf("\n\n");
    system("pause");
    system("cls");

    printf(">>ORDENANDO POR DESCRIPCION<\n");
    printf(">>Orden ascendente<\n");
    ll_sort(listaComidas4, comida_CompararDescripcion, 1);
    if (comida_mostrarComidas(listaComidas4)){
        exit(1);
    }
    printf("\n>>Orden descendente<\n");
    ll_sort(listaComidas4, comida_CompararDescripcion, 0);
    if (comida_mostrarComidas(listaComidas4)){
        exit(1);
    }

    printf("\n\n");
    system("pause");
    system("cls");

    printf(">>ORDENANDO POR PRECIO<\n");
    printf(">>Orden ascendente<\n");
    ll_sort(listaComidas4, comida_CompararPrecio, 1);
    if (comida_mostrarComidas(listaComidas4)){
        exit(1);
    }
    printf("\n>>Orden descendente<\n");
    ll_sort(listaComidas4, comida_CompararPrecio, 0);
    if (comida_mostrarComidas(listaComidas4)){
        exit(1);
    }

    printf("\n\n");
    system("pause");
    system("cls");

    printf(">>LL_SORT FUNCIONO(17/17)<\n");
    return 0;
}





