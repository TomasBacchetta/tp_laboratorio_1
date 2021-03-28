/*
 ============================================================================
 Name        : tp1.c
 Author      : Tomás Bacchetta
 Version     : 1
 Copyright   : Your copyright notice
 Description : Calculadora
 ============================================================================
 */

/*Bacchetta, Tomás - TP1*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bacchetta.h"


int main()
{
    char respuesta = 'n';
    float numeroUno;
    float numeroDos;
    int flagNumeroUno = 0;
    int flagNumeroDos = 0;
    int flagOperacion = 0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDiv;
    float resultadoMul;
    long resultadoFact;

    do
    {
    	setbuf(stdout, NULL);
        switch(menuPrincipal(flagNumeroUno, flagNumeroDos, numeroUno, numeroDos))
        {
        case 1:
            opcionUno(&numeroUno, &flagNumeroUno);
            break;
        case 2:
            opcionDos(&numeroDos, &flagNumeroDos);
            break;
        case 3:
            opcionTres(&flagNumeroUno, &flagNumeroDos, &numeroUno, &numeroDos, &flagOperacion, &resultadoSuma, &resultadoResta, &resultadoDiv, &resultadoMul, &resultadoFact);
            break;
        case 4:
            opcionCuatro(&flagOperacion, &numeroUno, &numeroDos, &resultadoSuma, &resultadoResta, &resultadoDiv, &resultadoMul, &resultadoFact);
            break;
        case 5:
            salir(&respuesta);
            break;
        default:
            printf("\nOpcion invalida!\n");
            system("pause");
        }
    } while (respuesta== 'n');

    return 0;
}



