#ifndef BACCHETTA_H_INCLUDED
#define BACCHETTA_H_INCLUDED



#endif // BACCHETTA_H_INCLUDED

/** \brief devuelve la suma de a y b
 *
 * \param a float primer operando
 * \param b float segundo operando
 * \return float el resultado de la suma
 *
 */

float suma(float a, float b);

/** \brief devuelve la resta de a y b
 *
 * \param a float primer operando ingresado
 * \param b float segundo operando ingresado
 * \return float el resultado de la resta
 *
 */
float resta(float a, float b);

/** \brief devuelve la division entre a y b
 *
 * \param a float devuelve
 * \param b float
 * \return float el resultado de la division
 *
 */
float division(float a, float b);

/** \brief devuelve la multiplicacion de a y b
 *
 * \param a float
 * \param b float
 * \return float el resultado de la multiplicacion
 *
 */
float multiplicacion(float a, float b);

/** \brief devuelve el factorial de a
 *
 * \param a float
 * \return long el factorial de a
 *
 */
long factorial(float a);

/** \brief imprime el menu principal del programa en pantalla
 *
 * \param flagUno int* recibe bandera del primer operando
 * \param flagDos int* recibe bandera del segundo operando
 * \param numUno float* recibe numero uno
 * \param numDos float* recibe numero dos
 * \return int devuelve la opcion ingresada
 *
 */
int menuPrincipal(int flagUno, int flagDos, float numUno, float numDos);

/** \brief funcion para salir del programa
 *
 * \return char devuelve el caracter de respuesta
 *
 */
void salir(char* respuesta);
