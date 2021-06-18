#ifndef BACCHETTAINPUT_H_INCLUDED
#define BACCHETTAINPUT_H_INCLUDED



#endif // BACCHETTAINPUT_H_INCLUDED
/** \brief determina si el valor ingresado es compatible con un nombre (sin numeros ni espacios de mas)
 *
 * \param cadena char*
 * \return int
 *
 */
int esNombre(char * cadena);

/** \brief llama a fgets y arregla el problema de que toma el salto de linea como caracter
 *
 * \param cadena char*
 * \param longitud int
 * \return int
 *
 */
int fixedGets(char * cadena, int longitud);

/** \brief determina si un valor ingresado corresponde con un numero entero
 *
 * \param cadena char*
 * \return int
 *
 */
int esEntero(char * cadena);

/** \brief confiere mayusculas a nombres de ser necesario
 *
 * \param cadena char*
 * \return int
 *
 */
int formatearNombre(char * cadena);

/** \brief permite ingresar un nombre como input
 *
 * \param cadenaTexto char*
 * \return int
 *
 */
int obtenerNombre(char * cadenaTexto);
int obtenerMayorDeEdad(int * edad);
int obtenerPorcentaje(int * porcentaje);
int obtenerSueldo(float * sueldo);
int esTelefono(char * cadena);

/** \brief determina si el valor ingresado corresponde a un numero de tipo punto flotante
 *
 * \param cadena char*
 * \return int
 *
 */
int esFloat(char * cadena);

/** \brief permite ingresar una fecha como input
 *
 * \param dia int*
 * \param mes int*
 * \param anio int*
 * \return int
 *
 */
int obtenerFecha(int * dia, int * mes, int * anio);

/** \brief determina si el valor ingresado corresponde a una fecha
 *
 * \param
 * \param
 * \return
 *
 */
int esFecha (char * fecha, int * pDia, int * pMes, int * pAnio);

/** \brief permite ingresar sexo como input
 *
 * \param sexo char*
 * \return int
 *
 */
int obtenerSexo(char * sexo);

/** \brief determina si el valor ingresado corresponde a un sexo
 *
 * \param sexo char*
 * \return int
 *
 */
int esSexo(char * sexo);

/** \brief determina que cantidad maxima de dias le corresponde a un mes especifico
 *
 * \param mes int
 * \return int
 *
 */
int diasDelMes(int mes);
/** \brief pregunta al usuario si quiere salir
 *
 * \return char
 *
 */
char salir();

/** \brief pregunta al usuario si quiere confirmar una accion
 *
 * \return char
 *
 */
char confirmar();

/** \brief permite ingresar un monto de dinero como input
 *
 * \param monto float*
 * \return int
 *
 */
int obtenerMonto(float * monto);

/** \brief permite ingresar un telefono como input
 *
 * \param
 * \param
 * \return
 *
 */
int obtenerTelefono (char * telefono);
