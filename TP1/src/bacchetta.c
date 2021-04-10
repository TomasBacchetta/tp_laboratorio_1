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

    if (a >= 0 && a < 17 && (a - (int) a) == 0 && resultado!= NULL)
    {
        long calculoFactorial = a;
        for (int x = a; x > 1; x--)
        {
            calculoFactorial = (long) calculoFactorial * (x-1);

        }
        if (a == 0)
        {
            *resultado = 1;
        }
        else
        {
            *resultado = calculoFactorial;
        }

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


void ingresarNumero(float* operando)
{
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
                *operando = num; //al ser exitoso, ingresar
            }

        }
        while (verif);
    }
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

void activarFlag(int * bandera)
{
    *bandera = 1;
}

void resetearFlag(int * bandera)
{
    *bandera = 0;
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

int esNumericoFloat(char * cadena)
{
    int allRight = 1;
    int contadorPunto = 0;

    if (cadena != NULL && strlen(cadena) > 0){
        for (int x = 0; x < strlen(cadena); x++)
        {
            if (cadena[x] < '0' || cadena[x] > '9') //si el caracter no es numerico
            {
                if (cadena[x] == '.') // si el caracter es un punto
                {
                    contadorPunto++;
                    if (contadorPunto > 1 || x == 0 || x == strlen(cadena)-1 || (x == 1 && cadena[0] == '-')) //si hay mas de un punto, o si este esta al final o al principio, o si prosigue a un signo negativo
                    {
                        allRight = 0;
                        break;
                    }

                }
                else // si no es un punto
                {
                    if (cadena[x] == '-') // si el caracter es un signo negativo
                    {
                        if (x != 0) //si el signo negativo no se encuentra al principio
                        {
                            allRight = 0;
                            break;
                        }
                        else //si el signo negativo se encuentra al principio
                        {
                            if (strlen(cadena) == 1) //si la cadena solo tiene un elemento
                            {
                                allRight = 0;
                                break;
                            }
                        }
                    }
                    else //si el caracter tampoco es un signo negativo
                    {
                        allRight = 0;
                        break;
                    }
                }
            }
        }
    }
    return allRight;
}





