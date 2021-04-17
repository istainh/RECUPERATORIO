/*
 * calculos.c
 *
 *  Created on: 16 abr. 2021
 *      Author: 54112
 */

#include <stdio.h>
#include <stdlib.h>

int sumar (int* resultado, int numero1, int numero2)
{
	int retorno=1;

	if (resultado!=NULL)
	{
		*resultado=numero1+numero2;
		retorno=0;
	}
	else
	{
		printf("Hubo un error.");
	}

	return retorno;
}


int restar (int* resultado, int numero1, int numero2)
{
	int retorno=1;

	if (resultado!=NULL)
	{
		*resultado=numero1-numero2;
		retorno=0;
	}
	else
	{
		printf("Hubo un error.");
	}

	return retorno;
}


int dividir (float* resultado, int numero1, int numero2)
{
	int retorno=1;

	if (resultado!=NULL)
	{
		if (numero2!=0)
		{
			*resultado=(float)numero1/numero2;
			retorno=0;
		}
		else
		{
			printf("No es posible dividir entre 0.");
		}
	}
	return retorno;
}


int multiplicar (int* resultado, int numero1, int numero2)
{
	int retorno=1;

	if (resultado!=NULL)
	{
		if (numero1==0||numero2==0)
		{
			*resultado=0;
			retorno=0;
		}
		else
		{
			*resultado=numero1*numero2;
			retorno=0;
		}
	}
	else
	{
		printf("Hubo un error.");
	}

	return retorno;
}


int factorizar (int* resultado1, int* resultado2, int numero1, int numero2)
{
	int retorno=1;
	int factorial=1;
	int factorial2=1;

	if (resultado1!=NULL)
	{
		if (numero1!=0)
		{
			for (int i=1 ; i<=numero1 ; i++)
			{
				factorial=factorial*i;
			}
			*resultado1=factorial;
			retorno=0;
		}
		else
		{
			*resultado1=1;
			retorno=0;
		}
	}

	if (resultado2!=NULL)
	{
		if (numero2!=0)
		{
			for (int i=1 ; i<=numero2 ; i++)
			{
				factorial2=factorial2*i;
			}
			*resultado2=factorial2;
			retorno=0;
		}
		else
		{
			*resultado2=1;
			retorno=0;
		}
	}
	return retorno;
}



