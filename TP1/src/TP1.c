/*
 ============================================================================
 Name        : TP1.c
 Author      : Tomás Bacchetta
 Version     : 1.0
 Copyright   : Tomás Bacchetta 1G UTNFRA 2021
 Description : Calculadora de dos operandos para sumar, restar, dividir, multiplicar y factorizar
 ============================================================================
 */

/*Bacchetta, Tomás - TP1*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int resultadoFact;
    int divOk = 0;
    int factOk = 0;

    setbuf(stdout, NULL);
    do //do while principal
    {
        system("cls"); //limpia la pantalla
        switch(menuPrincipal(flagNumeroUno, flagNumeroDos, numeroUno, numeroDos)) //switch de opciones retornadas por la funcion que imprime el menu
        {
        case 1:
            if(ingresarNumero(&numeroUno))
            {
                flagNumeroUno = 1; //flag testigo del exito de la carga del primer operando
            }
            break;
        case 2:
            if(ingresarNumero(&numeroDos))
            {
                flagNumeroDos = 1;
            }
            break;
        case 3:
            system("cls");
            if (validarCargas (flagNumeroUno, flagNumeroDos, &flagOperacion)) // si se realizaron las dos cargas
            {
                resultadoSuma = sumar(numeroUno, numeroDos);
                resultadoResta = restar(numeroUno, numeroDos);
                resultadoMul = multiplicar(numeroUno, numeroDos); //hasta aqui a las variables de resultado se les asigna el retorno de las funciones de operacion
                alertaFactDiv(dividir(numeroUno, numeroDos, &resultadoDiv), factorizar(numeroUno, &resultadoFact), &divOk, &factOk);
            }
            system("pause");
            break;
        case 4:
            mostrarResultados(flagOperacion, divOk, factOk, resultadoSuma, resultadoResta, resultadoDiv, resultadoMul, resultadoFact);
            break;
        case 5:
            respuesta = salir(respuesta);
            break;
        default:
            printf("\nOpcion invalida!\n");
            system("pause");
        }
    }
    while (respuesta== 'n');

    return 0;
}

