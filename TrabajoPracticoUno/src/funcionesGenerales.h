/*
 * funcionesGenerales.h
 *
 *  Created on: 16 abr. 2021
 *      Author: 54112
 */

#ifndef FUNCIONESGENERALES_H_
#define FUNCIONESGENERALES_H_
/**
 * \brief Pide un número al usuario y lo valida.
 * \param pNumero es un puntero que modifica la dirección de memoria de una variable que se encuentra en otro scope.
 * \param mensaje es un puntero con el mensaje que se desea imprimir al usuario.
 * \param mensajeError imprime un mensaje al usuario notificando un error en el datto ingresado después de validarlo.
 * \param minimo es el numero menor permitido ingresar por el usuario.
 * \param maximo es el numero mayor permitido ingresar por el usuario.
 * \param reintentos es la cantidad de veces permitidas que el usuario podra ingresar un numero si anteriormente el numero ingresado es invalido.
 * \return Retorna 1 si hubo un error y 0 si salio ok.
 */
int utn_getNumero(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

#endif /* FUNCIONESGENERALES_H_ */
