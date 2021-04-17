#include <stdio.h>
#include <stdlib.h>


int utn_getNumero(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=1;
	int numero;

	if (pNumero!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numero);

		do
		{
			if (numero>=minimo && numero<=maximo)
			{
				*pNumero=numero;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos>=0);
	}
	return retorno;
}



