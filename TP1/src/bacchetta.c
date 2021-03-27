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
        printf(" (a = %.2f)", numUno);
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

void salir(char* respuesta)
{
    do
    {
        printf("\n\nSeguro que quiere salir? (s/n)");
        scanf(" %c", respuesta);
    }
    while (*respuesta != 's' && *respuesta != 'n');



}
