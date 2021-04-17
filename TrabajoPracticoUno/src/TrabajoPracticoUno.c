/*
 ============================================================================
 Name        : TrabajoPracticoUno.c
 Author      : Ainhoa Osorio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesGenerales.h"
#include "calculos.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int menu;
	char salir;
	int numeroUno;
	int flagUno=0;
	int numeroDos;
	int flagDos=0;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	int resultadoFactorialA;
	int resultadoFactorialB;
	int flagOperaciones=0;
	int divicionPorCero;

	do
	{
		if (flagUno==1&&flagDos==1)
		{
			printf("A= %d B= %d\n\n", numeroUno, numeroDos);
		}

		menu=utn_getNumero(&opcion,"MENU CALCULADORA \n\nSeleccione una opci�n:\n 1-Ingresar 1er n�mero.\n 2-Ingresar 2do n�mero.\n 3-Calcular las operaciones.\n 4-Ver resultados.\n 5-Salir.\n", "No ingres� una opci�n v�lida, vuelva a intentarlo.\n\n", 1, 5, 1000);
		if(menu==0)
		{
			switch (opcion)
			{
				case 1:
					if (flagUno!=0)
					{
						printf("Ya ingresaste el primer operando.\n\n");
					}
					else
					{
						utn_getNumero(&numeroUno,"Ingrese el 1er operando (A):\n\n","Error en el ingreso del operando. Vuelve a intertarlo\n\n", -32000, 32000, 1000);
						flagUno=1;
					}
					break;

				case 2:
					if (flagDos!=0)
					{
						printf("Ya ingresaste el segundo operando.\n\n");
					}
					else
					{
						utn_getNumero(&numeroDos,"Ingrese el 2do operando (B):\n\n","Error en el ingreso del operando. Vuelve a intertarlo\n\n", -32000, 32000, 1000);
						flagDos=1;
					}

					break;

				case 3:
					if (flagUno==0||flagDos==0)
					{
						printf("Falta ingresar alg�n operando.\n\n");
					}
					else
					{
						sumar(&resultadoSuma, numeroUno, numeroDos);
						restar(&resultadoResta, numeroUno, numeroDos);
						multiplicar(&resultadoMultiplicacion, numeroUno, numeroDos);
						factorizar(&resultadoFactorialA, &resultadoFactorialB, numeroUno, numeroDos);
						divicionPorCero=dividir(&resultadoDivision, numeroUno, numeroDos);

						printf("Seleccione la opci�n 4 del men� si desea ver los resultados.\n\n");

						flagOperaciones=1;
					}
					break;

				case 4:
					if (flagOperaciones==0)
					{
						printf("Todav�a no hay resultados para mostrar.\n\n");
					}
					else
					{
						printf("Resultados: \n\n");
						printf("SUMA: %d\n", resultadoSuma);
						printf("RESTA: %d\n", resultadoResta);
						printf("MULTIPLICACI�N: %d\n", resultadoMultiplicacion);
						printf("FACTORIZACI�N: A) %d B) %d\n", resultadoFactorialA, resultadoFactorialB);
						if(divicionPorCero==1)
						{
							printf("DIVISI�N: No es posible dividir entre 0. \n");
						}
						else
						{
							printf("DIVISI�N: %.2f\n", resultadoDivision);
						}

						flagUno=0;
						flagDos=0;
						flagOperaciones=0;

						printf("Para seguir usando la calculadora podes volver a ingresar dos operandos.\n\n");

					}
					break;

				case 5:
					printf("�Desea salir? s-si o n-no:\n");
					fflush(stdin);
					scanf("%c", &salir);
					if (salir=='s')
					{
						printf("Termin� el programa CALCULADORA.\n");
					}
					break;
			}
		}
		else
		{
			printf("Error al seleccionar en el menu. Intente m�s tarde.\n");
			salir='s';
		}

	}while(salir=='n'||opcion!=5);

	return EXIT_SUCCESS;
}
