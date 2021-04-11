/*
 * bacchetta.h
 *
 *  Created on: 11 abril de 2021
 *      Author: Tomás Bacchetta
 */

#ifndef BACCHETTA_H_INCLUDED
#define BACCHETTA_H_INCLUDED



#endif // BACCHETTA_H_INCLUDED


/** \brief realiza la suma de a y b y la devuelve
 *
 * \param a float recibe el valor del primer operando y lo copia en a
 * \param b float recibe el valor del primer operando y lo copia en b
 * \return float devuelve la suma de a y b
 *
 */
float sumar(float a, float b);

/** \brief realiza la resta de a y b y la devuelve
 *
 * \param a float recibe el valor del primer operando y lo copia en a
 * \param b float recibe el valor del primer operando y lo copia en b
 * \return float devuelve la resta de a y b
 *
 */
float restar(float a, float b);

/** \brief realiza la division de a y b siempre que b no sea 0, y la pasa por referencia a resultado, si pudo realizarla devuelve 1, sino, 0
 *
 * \param a float recibe el valor del primer operando y lo copia en a
 * \param b float recibe el valor del primer operando y lo copia en b
 * \param resultado float* recibe la referencia de la variable de resultado y la copia en el puntero resultado
 * \return int devuelve 1 si pudo realizar la division y 0 si no pudo
 *
 */
int dividir(float a, float b, float* resultado);

/** \brief realiza la multiplicacion de a y b y la devuelve
 *
 * \param a float recibe el valor del primer operando y lo copia en a
 * \param b float recibe el valor del primer operando y lo copia en b
 * \return float devuelve la multiplicacion de a y b
 *
 */
float multiplicar(float a, float b);

/** \brief factoriza a siempre que a siempre y cuando sea un numero natural, pasa el resultado por referencia y devuelve 1 si logra realizar la operacion y 0 si no pudo
 *
 * \param a float
 * \param resultado long*
 * \return int
 *
 */
int factorizar(float a, long* resultado);

/** \brief imprime el menu y de ser ingrados numeros en la opcion 1 y 2, los imprime también
 *
 * \param flagUno int recibe el valor de la bandera de ingreso del primer operando, si es 1 ya lo hizo una vez
 * \param flagDos int recibe el valor de la bandera de ingreso del segundo operando, si es 1 ya lo hizo una vez
 * \param numUno float recibe el valor del primer operando
 * \param numDos float recibe el valor del segundo operando
 * \return int devuelve la opcion elegida
 *
 */
int menuPrincipal(int flagUno, int flagDos, float numUno, float numDos);

/** \brief le pide al usuario el ingreso de un numero por medio de la llamada a obtenerString, caso de no serlo pregunta hasta que se ingrese un dato valido, y retorna 1 fue exitoso y 0 si no
 *
 * \param operando float* recibe la referencia donde se alojara el resultado
 * \return int retorna 1 si al final se pudo realizar la carga con exito y 0 si no se pudo
 *
 */
int ingresarNumero(float* operando);

/** \brief pregunta al usuario si quiere salir (s) o no (n)
 *
 * \param respuesta char recibe el valor de la variable respuesta que por defecto esta en 'n'
 * \return char devuelve el valor de la respuesta escogida
 *
 */
char salir(char respuesta);

/** \brief obtiene el string ingresado por el usuario, lo copia en el string buffer y en caso de que se pueda realizar y de que el valor sea numerico, lo convierte de nuevo a string y lo devuelve por referencia.
 *
 * \param pResultado float* recibe la referencia del valor a ingresar
 * \return int devuelve 1 si logra realizar la operacion y 0 si no lo logro
 *
 */
int obtenerString(float * pResultado);

/** \brief esta funcion cumple el rol del fgets pero elimina el caracter de salto de linea antes del "\0"
 *
 * \param cadena char* recibe la referencia al string buffer de la funcion ingresarNumero
 * \param longitud int recibe el tamaño del string buffer
 * \return int devuelve 0 si pudo realizar la operacion, caso contrario -1
 *
 */
int fixedGets(char * cadena, int longitud);

/** \brief determina si los valores de los caracteres de string corresponden a la sintaxis numérica (por valor, orden y eventual iteración de las mismas)
 *
 * \param cadena char* recibe el string a analizar
 * \return int devuelve 1 si la operacion fue satisfactoria y 0 si no
 *
 */
int esNumericoFloat(char * cadena);

/** \brief imprime los resultados en pantalla, en caso de no poder mostrar la division o multiplicacion especificara por que
 *
 * \param flagOp int recibe el flag que indica si se ya se realizo la operacion
 * \param divOk int recibe el flag que indicca si la division fue exitosa
 * \param factOk int recibe el flag que indica si la factorizacion fue exitosa
 * \param resSuma float recibe el valor del resultado de la suma
 * \param resResta float recibe el valor del resultado de la resta
 * \param resDiv float recibe el valor del resultado de la division
 * \param resMul float recibe el valor del resultado de la multiplicacion
 * \param resFact long int recibe el valor del resultado de la factorizacion
 * \return void
 *
 */
void mostrarResultados(int flagOp, int divOk, int factOk, float resSuma, float resResta, float resDiv, float resMul, long int resFact);

