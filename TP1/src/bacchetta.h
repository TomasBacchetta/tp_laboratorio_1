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

/** \brief imprime la opcion uno que le pide al usuario el ingreso del primer operando
  *
  * \param operandoUno int* recibe la direccion de memoria del primer numero a ingresar
  * \param flagUno int* recibe la direccion de memoria de la bandera de la primera opcion
  * \return void
  *
  */
void opcionUno(float* operandoUno, float* flagUno);

/** \brief imprime la opcion dos que le pide al usuario el ingreso del segundo operando
 *
 * \param operandoDos int* recibe la direccion de memoria del segundo numero a ingresar
 * \param flagDos int* recibe la direccion de memoria de la bandera de la segunda opcion
 * \return void
 *
 */
void opcionDos(float* operandoDos, float* flagDos);

/** \brief realiza todas las operaciones
 *
 * \param flagUno int* recibe la direccion del flag del ingreso del primer operando
 * \param flagDos int* recibe la direccion del flag del ingreso del segundo operando
 * \param numUno float* recibe la direccion del operando uno
 * \param numDos float* recibe la direccion del operando dos
 * \param flagOp int* recibe la direccion del flag de las operaciones
 * \param resSuma float* recibe la direccion del resultado de la suma
 * \param resResta float* recibe la direccion del resultado de la resta
 * \param resDiv float* recibe la direccion del resultado de la division
 * \param resMulti float* recibe la direccion del resultado de la multiplicacion
 * \param resFact long* recibe la direccion del resultado del factorial del primer numero ingresado
 * \return void
 *
 */
void opcionTres(int* flagUno, int* flagDos, float* numUno, float* numDos, int* flagOp, float* resSuma, float* resResta, float* resDiv, float* resMulti, long* resFact);

/** \brief imprime todos los resultados
*
* \param flagOp int* recibe la direccion de la bandera de operacion
* \param numUno float* recibe la direccion del primer operando
* \param numDos float* recibe la direccion del segundo operando
* \param resSuma float* recibe la direccion del resultado de la suma
* \param resResta float* recibe la direccion del resultado de la resta
* \param resDiv float* recibe la direccion del resultado de la division
* \param resMul float* recibe la direccion del resultado de la multiplicacion
* \param resFact long* recibe la direccion del resultado del factorial
* \return void
*
*/
void opcionCuatro(int* flagOp, float* numUno, float* numDos, float* resSuma, float* resResta, float* resDiv, float* resMul, long* resFact);

/** \brief funcion para salir del programa
 *
 * \return char devuelve el caracter de respuesta
 *
 */
void salir(char* respuesta);
