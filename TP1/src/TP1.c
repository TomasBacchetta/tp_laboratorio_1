/*
 ============================================================================
 Name        : TP1.c
 Author      : Tomás Bacchetta
 Version     : 1.0
 Copyright   : Tomás Bacchetta 1G UTNFRA 2021
 Description : Calculadora de dos operandos para sumar, restar, dividir, multiplicar y factorizar
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
    long resultadoFact;
    int divOk = 0;
    int factOk = 0;

    setbuf(stdout, NULL);
    do //do while principal
    {
        system("cls"); //limpia la pantalla
        switch(menuPrincipal(flagNumeroUno, flagNumeroDos, numeroUno, numeroDos))
        {
        case 1:
            if(ingresarNumero(&numeroUno)){
                flagNumeroUno = 1; //flag testigo del exito de la carga del primer operando
            }

            break;
        case 2:
            if(ingresarNumero(&numeroDos)){
                flagNumeroDos = 1;
            }

            break;
        case 3:
            system("cls");
            if (flagNumeroUno && flagNumeroDos) // si se realizaron las dos cargas
            {
                flagOperacion = 1;
                resultadoSuma = sumar(numeroUno, numeroDos);
                resultadoResta = restar(numeroUno, numeroDos);
                resultadoMul = multiplicar(numeroUno, numeroDos); //hasta aqui a las variables de resultado se les asigna el retorno de las funciones de operacion
                divOk = dividir(numeroUno, numeroDos, &resultadoDiv); //desde aqui, a variables de flag se retorna el valor de las funciones (1 ok, 0 error), para estas dos operaciones particulares
                factOk = factorizar(numeroUno, &resultadoFact);
                if (divOk && factOk) // si se pudo factorizar y dividir
                {
                    printf("\nTodas las operaciones fueron calculadas\n\n");
                }
                else //si alguna de esas dos operaciones no se pudo realizar
                {
                    printf("\nNo todas las operaciones pudieron realizarse. Vea la opcion resultados para ver que sucedio.\n");
                }
            }
            else
            {
                if (flagNumeroUno) // si se cargo solo el primer operando
                {
                    printf ("\nFalta ingresar el segundo operando!\n");
                }
                else
                {
                    if (flagNumeroDos)
                    {
                        printf("\nFalta ingresar el primer operando!\n");
                    }
                    else // si no se cargo ninguno de los dos operandos
                    {
                        printf("\nFaltan ingresar ambos operandos!\n");
                    }
                }
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





