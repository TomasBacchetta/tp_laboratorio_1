/*
 ============================================================================
 Name        : tp1.c
 Author      : Tomás Bacchetta
 Version     : 1
 Copyright   : Your copyright notice
 Description : Calculadora
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
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

    setbuf(stdout, NULL);
    do
    {
        switch(menuPrincipal(flagNumeroUno, flagNumeroDos, numeroUno, numeroDos))
        {
        case 1:
            system("cls");
            printf("\nIngrese el primer operando: ");
            scanf("%f", &numeroUno);
            flagNumeroUno = 1;
            break;
        case 2:
            system("cls");
            printf("\nIngrese el segundo operando: ");
            scanf("%f", &numeroDos);
            flagNumeroDos = 1;
            break;
        case 3:
            system("cls");
            if (flagNumeroUno && flagNumeroDos)
            {
                flagOperacion = 1;
                resultadoSuma = suma(numeroUno, numeroDos);
                resultadoResta = resta(numeroUno, numeroDos);
                if (numeroDos != 0)
                {
                    resultadoDiv = division(numeroUno, numeroDos);
                }
                resultadoMul = multiplicacion(numeroUno, numeroDos);
                if (numeroUno >= 0)
                {
                    resultadoFact = factorial(numeroUno);
                }
                printf("\nTodas las operaciones fueron calculadas\n\n");

            }
            else
            {
                if (flagNumeroUno)
                {
                    printf ("\nFalta ingresar el segundo operando!\n");
                }
                else
                {
                    if (flagNumeroDos)
                    {
                        printf("\nFalta ingresar el primer operando!\n");
                    }
                    else
                    {
                        printf("\nFaltan ingresar ambos operandos!\n");
                    }
                }
            }
            system("pause");
            break;
        case 4:
            system("cls");
            if (flagOperacion == 1)
            {
                printf("\nEl resultado de la suma es: %.2f \n", resultadoSuma);
                printf("\nEl resultado de la resta es: %.2f \n", resultadoResta);
                if (numeroDos == 0)
                {
                    printf("\nNo es posible dividir por cero!\n");
                }
                else
                {
                    printf("\nEl resultado de la division es: %.2f \n", resultadoDiv);
                }
                printf("\nEl resultado de la multiplicacion es: %.2f \n", resultadoMul);
                if (numeroUno >= 0 && (numeroUno - (int) numeroUno) == 0)
                {
                    printf("\nEl factorial de a es: %d \n\n", resultadoFact);
                }
                else
                {
                    printf("\nNo se puede sacar factorial de a si este es negativo o no entero, o si el resultado da un numero demasiado grande\n\n");
                }
            }
            else
            {
                printf("\nPara tener los resultados debe hacer los cálculos primero!\n");
            }
            system("pause");
            break;
        case 5:
            salir(&respuesta);
            break;
        default:
            printf("\nOpcion invalida!\n");
            system("pause");

        }


    }
    while (respuesta== 'n');

    return 0;
}



