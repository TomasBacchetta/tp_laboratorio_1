#ifndef BACCHETTA_H_INCLUDED
#define BACCHETTA_H_INCLUDED



#endif // BACCHETTA_H_INCLUDED




float sumar(float a, float b);

float restar(float a, float b);

int dividir(float a, float b, float* resultado);

float multiplicar(float a, float b);

int factorizar(float a, long* resultado);

int menuPrincipal(int flagUno, int flagDos, float numUno, float numDos);

void ingresarNumero(float* operando);

void salir(char* respuesta);

void activarFlag(int * bandera);

void resetearFlag(int * bandera);

/** \brief esta funcion cumple el rol del fgets pero elimina el caracter de salto de linea antes del "\0"
 *
 * \param cadena char* recibe la referencia al string buffer de la funcion ingresarNumero
 * \param longitud int recibe el tamaño del string buffer
 * \return int devuelve 0 si pudo realizar la operacion, caso contrario -1
 *
 */
int fixedGets(char * cadena, int longitud);

int obtenerString(float * pResultado);

int esNumericoFloat(char * cadena);


