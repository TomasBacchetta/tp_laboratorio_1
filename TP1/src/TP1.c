/*
 ============================================================================
 Name        : TP1.c
 Author      : Tomás Bacchetta
 Version     : 1.0
 Copyright   : Tomás Bacchetta UTNFRA 1G
 Description : Calculadora de dos operandos
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
    do
    {
        system("cls"); //limpia la pantalla
        switch(menuPrincipal(flagNumeroUno, flagNumeroDos, numeroUno, numeroDos))
        {
        case 1:
            ingresarNumero(&numeroUno);
            flagNumeroUno = 1; //flag testigo del exito de la carga de datos
            break;
        case 2:
            ingresarNumero(&numeroDos);
            flagNumeroDos = 1;
            break;
        case 3:
            system("cls");
            if (flagNumeroUno && flagNumeroDos)
            {
                activarFlag(&flagOperacion);
                resultadoSuma = sumar(numeroUno, numeroDos);
                resultadoResta = restar(numeroUno, numeroDos);
                resultadoMul = multiplicar(numeroUno, numeroDos); //hasta aqui a las variables de resultado se les asigna el retorno de las funciones de operacion
                divOk = dividir(numeroUno, numeroDos, &resultadoDiv); //desde aqui, a variables de flag se retorna el valor de las funciones (1 ok, 0 error)
                factOk = factorizar(numeroUno, &resultadoFact);
                if (divOk && factOk)
                {
                    printf("\nTodas las operaciones fueron calculadas\n\n");
                }
                else
                {
                    printf("\nNo todas las operaciones pudieron realizarse. Vea la opcion resultados para ver que sucedio.\n");
                }
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
                printf("El resultado de la suma es %.2f\n", resultadoSuma);
                printf("\nEl resultado de la resta es: %.2f\n", resultadoResta);
                if (divOk)
                {
                    printf("\nEl resultado de la division es: %.2f\n", resultadoDiv + 0.00); //sumar 0.00 evita un eventual cero negativo
                }
                else
                {
                    printf("\nNo es posible dividir por cero!\n");
                }
                printf("\nEl resultado de la multiplicacion es: %.2f\n", resultadoMul + 0.00);
                if (factOk)
                {
                    printf("\nEl factorial de a es: %li\n\n", resultadoFact);
                }
                else
                {
                    printf("\nNo se puede sacar factorial de A si este es negativo o no entero, o si el resultado da un numero demasiado grande\n\n");
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



