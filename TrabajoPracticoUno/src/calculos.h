/*
 * calculos.h
 *
 *  Created on: 15 abr. 2021
 *      Author: 54112
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/**
 * \brief Recibe dos numeros enteros, los suma y devuelve un resultado por medio de la dirección de memoria de una de las variables.
 * \param numero1 es la primera variable que recibe el valor de otra variable del main.
 * \param numero2 es la segunda variable que recibe el valor de otra variable del main.
 * \return Retorna 1 si hubo error y 0 si no lo hubo.
 */
int sumar (int* resultado, int numero1, int numero2);


/**
 * \brief Recibe dos numeros enteros, los resta y devuelve un resultado por medio de la dirección de memoria de una de las variables.
 * \param numero1 es la primera variable que recibe el valor de otra variable del main.
 * \param numero2 es la segunda variable que recibe el valor de otra variable del main.
 * \return Retorna 1 si hubo error y 0 si no lo hubo.
 */
int restar (int* resultado, int numero1, int numero2);


/**
 * \brief Recibe dos numeros enteros, los divide (se castea una de las variables en el proceso)y devuelve un resultado por medio de la dirección de memoria de una de las variables.
 * \param numero1 es la primera variable que recibe el valor de otra variable del main.
 * \param numero2 es la segunda variable que recibe el valor de otra variable del main.
 * \return Retorna 1 si hubo error y 0 si no lo hubo.
 */
int dividir (float* resultado, int numero1, int numero2);


/**
 * \brief Recibe dos numeros enteros, los multiplica y devuelve un resultado por medio de la dirección de memoria de una de las variables.
 * \param numero1 es la primera variable que recibe el valor de otra variable del main.
 * \param numero2 es la segunda variable que recibe el valor de otra variable del main.
 * \return Retorna 1 si hubo error y 0 si no lo hubo.
 */
int multiplicar (int* resultado, int numero1, int numero2);


/**
 * \brief Recibe dos numeros enteros, realiza la factorización de cada uno y devuelve dos resultados por medio de la dirección de memoria de una de las variables.
 * \param numero1 es la primera variable que recibe el valor de otra variable del main.
 * \param numero2 es la segunda variable que recibe el valor de otra variable del main.
 * \return Retorna 1 si hubo error y 0 si no lo hubo.
 */
int factorizar (int* resultado1, int* resultado2, int numero1, int numero2);


#endif /* CALCULOS_H_ */
