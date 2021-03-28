#include <stdio.h>
#include <stdlib.h>
#include "bacchetta.h"

float suma(float a, float b)
{

    return a + b;
}

float resta(float a, float b)
{

    return a - b;
}

float division(float a, float b)
{
    return a / b;
}

float multiplicacion(float a, float b)
{
    return a * b;
}

long factorial(float a)
{
    long calculoFactorial = a;
    for (int x = a; x > 1; x--)
    {
        calculoFactorial = (long) calculoFactorial * (x-1);
    }
    return calculoFactorial;
}

int menuPrincipal(int flagUno, int flagDos, float numUno, float numDos)
{
    int opcion;

    system("cls");
    printf("\n\t<<<MENU DE OPCIONES>>>\n");
    printf("\n1.Ingresar primer operando");
    if (flagUno)
    {
        printf(" (A = %.2f)", numUno);
    }
    printf("\n2.Ingresar segundo operando");
    if (flagDos)
    {
        printf(" (B = %.2f)", numDos);
    }
    printf("\n3.Calcular todas las operaciones");
    printf("\n4.Informar resultados\n");
    printf("\n5.Salir\n");
    printf("\n\nIngrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


void opcionUno(float* operandoUno, float* flagUno)
{
    system("cls");
    printf("\nIngrese el primer operando: ");
    scanf("%f", operandoUno);
    *flagUno = 1;
}

void opcionDos(float* operandoDos, float* flagDos)
{
    system("cls");
    printf("\nIngrese el segundo operando: ");
    scanf("%f", operandoDos);
    *flagDos = 1;
}

void opcionTres(int* flagUno, int* flagDos, float* numUno, float* numDos, int* flagOp, float* resSuma, float* resResta, float* resDiv, float* resMulti, long* resFact)
{
    system("cls");
    if (*flagUno && *flagDos)
    {
        *flagOp = 1;
        *resSuma = suma(*numUno, *numDos);
        *resResta = resta(*numUno, *numDos);
        if (*numDos != 0)
        {
            *resDiv = division(*numUno, *numDos);
        }
        *resMulti = multiplicacion((*numUno), (*numDos));
        if (*numUno >= 0)
        {
            *resFact = factorial(*numUno);
        }
        printf("\nTodas las operaciones fueron calculadas\n\n");
    }
    else
    {
        if (*flagUno)
        {
            printf ("\nFalta ingresar el segundo operando!\n");
        }
        else
        {
            if (*flagDos)
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

}

void opcionCuatro(int* flagOp, float* numUno, float* numDos, float* resSuma, float* resResta, float* resDiv, float* resMul, long* resFact)
{
    system("cls");
    if (*flagOp == 1)
    {
        printf("\nEl resultado de la suma es: %.2f \n", *resSuma);
        printf("\nEl resultado de la resta es: %.2f \n", *resResta);
        if (*numDos == 0)
        {
            printf("\nNo es posible dividir por cero!\n");
        }
        else
        {
            printf("\nEl resultado de la division es: %.2f \n", *resDiv + 0.00);
        }
        printf("\nEl resultado de la multiplicacion es: %.2f \n", *resMul + 0.00);
        if (*numUno >= 0 && *numUno < 17 && (*numUno - (int) *numUno) == 0)
        {
            printf("\nEl factorial de a es: %li \n\n", *resFact);
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
}

void salir(char* respuesta)
{
    do
    {
        printf("\n\nSeguro que quiere salir? (s/n)");
        scanf(" %c", respuesta);
    }
    while (*respuesta != 's' && *respuesta != 'n');



}
