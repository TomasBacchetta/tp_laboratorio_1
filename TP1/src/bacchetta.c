/*
 * bacchetta.c
 *
 *  Created on: 11 abril 2021
 *      Author: Tomás Bacchetta
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bacchetta.h"



float sumar(float a, float b)
{
    return a+b;

}


float restar(float a, float b)
{
    return a-b;
}


int dividir(float a, float b, float* resultado)
{
    int allRight = 0;
    if (b != 0 && resultado != NULL)
    {
        *resultado = a / b;
        allRight = 1;
    }

    return allRight;
}


float multiplicar(float a, float b)
{
    return a*b;
}

int factorizar(float a, long* resultado)
{
    int allRight = 0;

    if (a >= 0 && a < 17 && (a - (int) a) == 0 && resultado!= NULL) // si es natural menor a 17 y entero y el puntero resultado no apunta al vacio
    {
        long calculoFactorial = a;
        if (a == 0){
            *resultado = 1; //si el operando es 0 la factorizacion es siempre 1
        } else {
            for (int x = a; x > 1; x--)
            {
            calculoFactorial = (long) calculoFactorial * (x-1);
            }
        }
        *resultado = calculoFactorial;
        allRight = 1;
    }
    return allRight;
}

int menuPrincipal(int flagUno, int flagDos, float numUno, float numDos)
{
    int opcion;
    fflush(stdin);
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

int ingresarNumero(float* operando)
{
    int allRight = 0;
    float num; //de esta variable se tomará su dirección al enviarla como parámetro a obtenerString
    int verif = 0;

    system("cls");
    if (operando != NULL)
    {

        do
        {
            fflush(stdin); //limpia el buffer
            printf("\nIngrese el operando: ");
            if (obtenerString(&num) != 0)
            {
                printf("Error!");
                verif = 1;
            }
            else
            {
                verif = 0;
                *operando = num;
            }

        }
        while (verif);
        allRight = 1;
    } else {
        printf("\nHubo un problema al cargar el numero");
    }
    return allRight;
}

char salir(char respuesta)
{
    do
    {
        fflush(stdin); //evita que aparezcan multiples preguntas al ingresar mas de un caracter
        printf("\n\nSeguro que quiere salir? (s/n)");
        scanf(" %c", &respuesta);
    }
    while (respuesta != 's' && respuesta != 'n');


    return respuesta;
}

int obtenerString(float * pResultado)
{
    int allRight = -1;
    char buffer[64];
    if (pResultado != NULL)
    {
        if (fixedGets(buffer, sizeof(buffer)) == 0 && esNumericoFloat(buffer))
        {
            *pResultado = atof(buffer);
            allRight = 0;
        }

    }
    return allRight;
}

int fixedGets(char * cadena, int longitud)
{
    int allRight = -1;
    if (cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin)== cadena  && cadena[0] != '\n')
    {
        fflush(stdin);
        if (cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        allRight = 0;
    }
    return allRight;
}

int esNumericoFloat(char * cadena)
{
    int allRight = 1; //inicia en verdadero, y de no cumplir algun requisito la funcion le asignara el 0
    int contadorPunto = 0;
    int stop = 0;

    if (cadena != NULL && strlen(cadena) > 0){ //si el puntero cadena no apunta al vacio y su largo es mayor a 0
        for (int x = 0; x < strlen(cadena) && !stop ; x++)
        {
            if (cadena[x] < '0' || cadena[x] > '9') //si el caracter no es numerico
            {
                switch(cadena[x]){
                    case '.':
                        if (contadorPunto > 1 || x == 0 || x == strlen(cadena)-1 || (x == 1 && cadena[0] == '-')) //si hay mas de un punto, o si este esta al final o al principio, o si prosigue a un signo negativo
                    {
                        allRight = 0;
                        stop = 1; //finaliza la iteracion (utilizar break entraria en conflicto con el switch)
                    }
                    break;
                    case '-':
                        if (x != 0 || strlen(cadena) == 1) //si el signo negativo no se encuentra al principio o si la cadena tiene solo 1 elemento
                        {
                            allRight = 0;
                            stop = 1;
                        }
                    break;
                    default:
                    allRight = 0;
                    stop = 1;
                }
            }
        }
    }
    return allRight;
}

void mostrarResultados(int flagOp, int divOk, int factOk, float resSuma, float resResta, float resDiv, float resMul, long int resFact){
    system("cls");
            if (flagOp == 1)
            {
                printf("El resultado de la suma es %.2f\n", resSuma);
                printf("\nEl resultado de la resta es: %.2f\n", resResta);
                if (divOk)
                {
                    printf("\nEl resultado de la division es: %.2f\n", resDiv + 0.00); //sumar 0.00 evita un eventual cero negativo
                }
                else
                {
                    printf("\nNo es posible dividir por cero!\n");
                }
                printf("\nEl resultado de la multiplicacion es: %.2f\n", resMul + 0.00);
                if (factOk)
                {
                    printf("\nEl factorial de a es: %li\n\n", resFact);
                }
                else
                {
                    printf("\nNo se puede sacar factorial de A si este es negativo o no entero, o si el resultado da un numero demasiado grande\n\n");
                }
            }
            else
            {
                printf("\nPara tener los resultados debe hacer los calculos primero!\n");
            }
            system("pause");

}





