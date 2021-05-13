#include "arrayEmpleados.h"

//FUNCION INIT

int initEmpleados(eEmpleados* arrayStruct, int tamanio)
{
	int retorno=-1;
	int i;

	if(arrayStruct!=NULL)
	{
		for(i=0;i<tamanio;i++)
		{
			arrayStruct[i].isEmpty=1;
			retorno=0;
		}
	}
	return retorno;
}

//FUNCION ADD

int addEmpleado(eEmpleados* arrayStruct, int tamanio, char nombre[], char apellido[], float salario, int sector, int iD)
{
	int retorno=0;

	if(arrayStruct!=NULL&&nombre!=NULL&&apellido!=NULL&&tamanio>0)
	{
		strcpy(arrayStruct[tamanio].nombre, nombre);
		strcpy(arrayStruct[tamanio].apellido, apellido);
		arrayStruct[tamanio].salario=salario;
		arrayStruct[tamanio].sector=sector;
		arrayStruct[tamanio].id=iD;
		arrayStruct[tamanio].isEmpty=0;

		retorno=1;
	}
	return retorno;
}

//ABM
//Alta

int buscarIsEmpty(eEmpleados arrayStruct[], int tamanio, int* auxTamanio)
{
	int i;
	int retorno=0;
	if(arrayStruct!=NULL&&tamanio>0)
	{
		for(i=0;i<tamanio;i++)
		{
			if(arrayStruct[i].isEmpty==1)
			{
				*auxTamanio=i;
				retorno=1;
				break;
			}
			else
			{
				printf("No hay más espacio para cargar. \n");
			}
		}
	}
	return retorno;
}

void cargaDatosEmpleado(eEmpleados* arrayStruct, int tamanio, int* flagCarga, int* flagId)
{
	int posicion;
	char nombre[TAM];
	char apellido[TAM];
	float salario;
	int sector;
	int iD;
	int flagIdDos=flagId;
	eEmpleados auxStruct;

	if(buscarIsEmpty(arrayStruct, tamanio, &posicion))
	{
		if(utn_getString("Ingrese el nombre del empleado: \n","Error al ingresar el nombre del empleado. Intentelo de nuevo: \n", nombre, 2)&&
		   utn_getString("Ingrese el apellido del empleado: \n", "Error al ingresar el apellido del empleado. Intentelo de nuevo: \n", apellido, 2)&&
		   utn_getFloat(&salario, "Ingrese el salario neto del empleado: \n", "Error al ingresar el salario neto del empleado. Intente de nuevo: \n", 1000.99, 5999.99, 2)&&
		   utn_getNumero(&sector, "Ingrese el sector donde trabaja el empleado:\n 1-Comercial\n 2-Legal\n 3-Reclutamiento\n", "No ingresó una opción valida, intete de nuevo: \n", 1, 3, 2)&&
		   obtenerId(&flagIdDos, 1000, &iD))
		{
			if(addEmpleado(&auxStruct, posicion, nombre, apellido, salario, sector, iD))
			{
				arrayStruct=auxStruct;
				printf("Se cargó exitosamente al empleado # %d\n", iD);
				break;
			}
		}
		else
		{
			printf("Hubo algún error en el ingreso de alguno de los datos.\n");
			break;
		}
	}
	else
	{
		printf("Intente dar de baja algún empleado para poder cargar.\n");
		break;
	}
}

//Mostrar
void mostrarListado(eEmpleados arrayStruct[], int tamanio)
{
	int i;

	for(i=0;i<tamanio;i++)
	{
		if(arrayStruct[i].isEmpty==0)
		{
			printf("LEGAJO    SEXO    EDAD    NOTA 1    NOTA 2    PROMEDIO    APELLIDO\n");
			mostrarDatosStruct(arrayStruct, i);
		}
	}
}

int buscarEmpleadoConId (eEmpleados arrayStruct, int tamanio, int iD)
{
	int retorno=0;
	int i;

	for(i=0;i<tamanio;i++)
		{
			if(arrayStruct[i].isEmpty==0)
			{
				if(arrayStruct[i].id==iD)
				{
					retorno=i;
				}
				else
				{
					printf("No existe el ID ingresado. \n");
				}
			}
		}
	return retorno;
}

void darBaja(alumnos arrayStruct[], int tamanio)
{
	int legajo;
	int i;
	char darBaja;

	printf("Ingrese el legajo que desee dar de baja: \n");
	scanf("%d", &legajo);

	for(i=0;i<tamanio;i++)
	{
		if(arrayStruct[i].isEmpty==0)
		{
			if(arrayStruct[i].legajo==legajo)
			{
				printf("LEGAJO    SEXO    EDAD    NOTA 1    NOTA 2    PROMEDIO    APELLIDO\n");
				mostrarDatosStruct(arrayStruct, i);

				printf("¿Desea dar de baja este legajo? s-si n-no \n");
				fflush(stdin);
				scanf("%c", &darBaja);
				if(darBaja=='s')
				{
					arrayStruct[i].isEmpty=1;
					printf("Se dio de baja al legajo.\n");
				}
				else
				{
					printf("No dio de baja al legajo numero %d \n", legajo);
				}
			}
			else
			{
				printf("No existe el legajo ingresado. \n");
			}
		}
	}
}







