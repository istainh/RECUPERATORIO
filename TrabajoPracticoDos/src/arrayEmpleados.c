#include "arrayEmpleados.h"

//FUNCION INIT

int inicializarEmpleados(eEmpleados arrayStruct[], int tamanio)
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

int agregarEmpleado(eEmpleados arrayStruct[], int posicion, char nombre[], char apellido[], float salario, int sector, int iD)
{
	int retorno=0;

	if(arrayStruct!=NULL&&nombre!=NULL&&apellido!=NULL)
	{
		strcpy(arrayStruct[posicion].nombre, nombre);
		strcpy(arrayStruct[posicion].apellido, apellido);
		arrayStruct[posicion].salario=salario;
		arrayStruct[posicion].sector=sector;
		arrayStruct[posicion].id=iD;
		arrayStruct[posicion].isEmpty=0;

		imprimirEmpleados(arrayStruct, posicion);
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
			}
		}
	}
	return retorno;
}

int cargaDatosEmpleado(eEmpleados arrayStruct[], int tamanio, int* flagId)
{
	int retorno=0;
	int posicion;
	char nombre[TAM];
	char apellido[TAM];
	float salario;
	int sector;
	int iD;
	int flagAux=*flagId;

	if(buscarIsEmpty(arrayStruct, tamanio, &posicion))
	{
		if(utn_getString("Ingrese el nombre del empleado: \n\n","Error al ingresar el nombre del empleado. Intentelo de nuevo:\n\n", nombre, 5)&&
		   utn_getString("Ingrese el apellido del empleado:\n\n", "Error al ingresar el apellido del empleado. Intentelo de nuevo:\n\n", apellido, 5)&&
		   utn_getFloat(&salario, "Ingrese el salario neto del empleado:\n\n", "Error al ingresar el salario neto del empleado. Intente de nuevo:\n\n", 99.99, 59999.99, 5)&&
		   utn_getNumero(&sector, "Ingrese el sector donde trabaja el empleado:\n [1] Comercial\n [2] Legal\n [3] Reclutamiento\n\n", "No ingresó una opción valida, intete de nuevo:\n\n", 1, 3, 5)&&
		   obtenerId(&flagAux, 1000, &iD))
		{
			if(agregarEmpleado(arrayStruct, posicion, nombre, apellido, salario, sector, iD))
			{
				printf("Se cargó exitosamente al empleado #%d\n\n", iD);
				*flagId=flagAux;
				retorno=1;
			}
		}
		else
		{
			printf("Hubo algún error en el ingreso de alguno de los datos.\n\n");
			retorno=0;
		}
	}
	else
	{
		printf("Intente dar de baja algún empleado para poder cargar.\n\n");
		retorno=0;
	}

	return retorno;
}

//Mostrar
void mostrarListado(eEmpleados arrayStruct[], int tamanio)
{
	int i;

	printf("ID           APELLIDO           NOMBRE        SALARIO                SECTOR\n");

	for(i=0;i<tamanio;i++)
	{
		if(arrayStruct[i].isEmpty==0)
		{
			imprimirEmpleados(arrayStruct, i);
		}
	}
}

int buscarEmpleadoConId (eEmpleados arrayStruct[], int tamanio, int iD, int* posicion)
{
	int retorno=0;
	int i;

	for(i=0;i<tamanio;i++)
		{
			if(arrayStruct[i].isEmpty==0)
			{
				if(arrayStruct[i].id==iD)
				{
					*posicion=i;
					retorno=1;
				}
				else
				{
					printf("No existe el ID ingresado. \n");
				}
			}
		}
	return retorno;
}

//MODIFICAR

void modificarDatos(eEmpleados arrayStruct[], int tamanio)
{
	int opcion;
	char salir;
	int menu;
	char modificar;
	int posicion;
	char nombre[TAM];
	char apellido[TAM];
	float salario;
	int sector;
	int id;

	if(arrayStruct!=NULL&&tamanio>0)
	{
		utn_getNumero(&id, "Ingrese el ID del empleado que desee modificar\n", "Error al ingresar el ID. Intentelo de nuevo:\n", 1001, 1999, 5);

		if(buscarEmpleadoConId(arrayStruct, tamanio, id, &posicion))
		{
			printf("ID            APELLIDO           NOMBRE       SALARIO    SECTOR\n");

			imprimirEmpleados(arrayStruct, posicion);

			printf("¿Desea modificar este ID? [s]-si [n]-no\n\n");
			fflush(stdin);
			scanf("%c", &modificar);

			if(modificar=='s')
			{
				do
				{
					menu=utn_getNumero(&opcion,"MENÚ MODIFICARDOR DE DATOS\n\n Seleccione una opción:\n [1] Nombre del empleado\n [2] Apellido del empleado.\n [3] Salario del empleado.\n [4] Sector del empleado.\n [5] Salir.\n\n", "No ingresó una opción válida, vuelva a intentarlo.\n\n", 1, 5, 5);
					if(menu)
					{
						switch (opcion)
						{
							case 1:
								if(utn_getString("Ingrese el nuevo nombre del empleado:\n","Error al ingresar el nombre del empleado, intentelo de nuevo:\n", nombre, 5))
								{
									strncpy(arrayStruct[posicion].nombre,nombre,TAM);
									printf("Se cambió el nombre del empleado a %s exitosamente.\n\n", arrayStruct[posicion].nombre);
								}
								else
								{
									printf("No se pudo modificar el nombre del empleado.\n\n");
								}
								break;

							case 2:
								if(utn_getString("Ingrese el apellido del empleado:\n","Error al ingresar el apellido del empleado, intentelo de nuevo.\n", apellido, 5))
								{
									strncpy(arrayStruct[posicion].apellido,apellido,TAM);
								}
								else
								{
									printf("No se pudo modificar el apellido del empleado.\n");
								}
								break;

							case 3:
								if(utn_getFloat(&salario, "Ingrese el nuevo salario del empleado:\n", "Error al ingresar el nuevo salario del empleado, intente de nuevo.\n", 1000.99, 5999.99, 5))
								{
									arrayStruct[posicion].salario=salario;
								}
								else
								{
									printf("No se pudo modificar el salario del empleado.\n");
								}
								break;

							case 4:
								if(utn_getNumero(&sector, "Ingrese el nuevo sector donde trabaja el empleado:\n [1] Comercial\n [2] Legal\n [3] Reclutamiento\n", "No ingresó una opción valida, intete de nuevo: \n", 1, 3, 5))
								{
									arrayStruct[posicion].sector=sector;
								}
								else
								{
									printf("No se pudo modificar el sector del empleado.\n");
								}
								break;

							case 5:
								printf("¿Desea salir? s-si o n-no:\n");
								fflush(stdin);
								scanf("%c", &salir);
								if (salir=='s')
								{
									printf("Salió del modificador de datos del empleado.\n");
								}
								break;
							}
					}
					else
					{
						printf("Error al seleccionar en el menu. Intente más tarde.\n");
						salir='s';
					}

				}while(salir=='n'||opcion!=5);
			}
		}
	}
}



void imprimirEmpleados(eEmpleados* arrayStruct, int tamanio)
{
	printf("%d       %s        %s        %.2f        %d \n\n", arrayStruct[tamanio].id, arrayStruct[tamanio].apellido, arrayStruct[tamanio].nombre, arrayStruct[tamanio].salario, arrayStruct[tamanio].sector);
}



int removerEmpleado(eEmpleados arrayStruct[], int tamanio)
{
	int retorno=0;
	int id;
	int posicion;
	char darBaja;

	utn_getNumero(&id, "Ingrese en ID del empleado que desee dar de baja:\n", "Error al ingresar el ID, intentelo de nuevo.\n", 1001, 1999, 5);

	if(buscarEmpleadoConId(arrayStruct, tamanio, id, &posicion))
	{
		printf("ID            APELLIDO          NOMBRE      SALARIO    SECTOR\n");

		imprimirEmpleados(arrayStruct, posicion);

		printf("¿Desea dar de baja este empleado? s-si n-no \n");
		fflush(stdin);
		scanf("%c", &darBaja);
		if(darBaja=='s')
		{
			arrayStruct[posicion].isEmpty=1;
			printf("Se dio de baja al ID %d.\n", id);
			retorno=1;
		}
		else
		{
			printf("No dio de baja al ID %d \n", id);
		}
	}

	return retorno;
}


int revizarIsEmpty(eEmpleados arrayStruct[], int tamanio, int* flag)
{
	int retorno=0;
	int i;
	int contaIsEmpty=0;

	for(i=0;i<tamanio;i++)
	{
		if(arrayStruct[i].isEmpty==1)
		{
			contaIsEmpty++;
		}
	}

	if(contaIsEmpty==tamanio)
	{
		*flag=0;
		retorno=1;
	}

	return retorno;
}


int ordenarEmpleados(eEmpleados arrayStruct[], int tamanio, int orden)
{
	int retorno=0;
	int i;
	int j;
	eEmpleados aux;

	if(arrayStruct!=NULL&&tamanio>0)
	{
		switch (orden)
		{
			case 1:
				for(i=0;i<tamanio-1;i++)
				{
					for(j=i+1;j<tamanio;j++)
					{
						if(arrayStruct[i].isEmpty==0&&arrayStruct[j].isEmpty==0)
						{
							if(arrayStruct[i].sector>arrayStruct[j].sector)
							{
								aux=arrayStruct[i];
								arrayStruct[j]=arrayStruct[i];
								arrayStruct[j]=aux;
							}
							else
							{
								if(stricmp(arrayStruct[i].apellido, arrayStruct[j].apellido)>0)
								{
									aux=arrayStruct[i];
									arrayStruct[j]=arrayStruct[i];
									arrayStruct[j]=aux;
								}
							}
						}
					}
				}
				retorno=1;
				break;

			case 0:
				for(i=0;i<tamanio-1;i++)
				{
					for(j=i+1;j<tamanio;j++)
					{
						if(arrayStruct[i].isEmpty==0&&arrayStruct[j].isEmpty==0)
						{
							if(arrayStruct[i].sector<arrayStruct[j].sector)
							{
								aux=arrayStruct[i];
								arrayStruct[i]=arrayStruct[j];
								arrayStruct[j]=aux;
							}
							else
							{
								if(stricmp(arrayStruct[j].apellido, arrayStruct[i].apellido)>0)
								{
									aux=arrayStruct[i];
									arrayStruct[i]=arrayStruct[j];
									arrayStruct[j]=aux;
								}
							}
						}
					}
				}
				retorno=1;
				break;
		}
	}
	return retorno;
}


int calcularSalarios(eEmpleados estructura[], int tamanio)
{
	int retorno=0;
	float sumaSalarios=0;
	float promedioSalarios;
	int contaEmpleados=0;
	int maxSalario;
	int i;

	if(estructura!=NULL&&tamanio>0)
	{
		for(i=0;i<tamanio;i++)
		{
			if(estructura[i].isEmpty==0)
			{
				contaEmpleados++;
				sumaSalarios=sumaSalarios+estructura[i].salario;
			}
		}

		promedioSalarios=sumaSalarios/contaEmpleados;

		for(i=0;i<tamanio;i++)
		{
			if(estructura[i].salario>promedioSalarios)
			{
				maxSalario++;
			}
		}

		mostrarListadoSalarios(sumaSalarios, promedioSalarios, maxSalario);

		retorno=1;
	}
	return retorno;
}


int informesEstructura(eEmpleados estructura[], int tamanio)
{
	int retorno=0;
	int opcion;
	int opcionOrden;
	char salir;
	int menu;

	do
	{
		menu=utn_getNumero(&opcion,"MENÚ INFORMES DE EMPLEADOS:\n\n [1] Lista de empleados ordenados alfabéticamente.\n [2] Total y promedio de los salarios.\n [3] Salir\n", "No ingresó una opción válida. Vuelve a intentarlo.\n", 1, 3, 5);

		if(menu)
		{
			switch (opcion)
			{
				case 1:
					utn_getNumero(&opcionOrden, "[1] En orden ascendente\n [0] En orden descendente\n", "No ingresó una opción válida. Vuelve a intentarlo.\n", 0, 1, 5);
					ordenarEmpleados(estructura, tamanio, opcionOrden);
					mostrarListado(estructura, tamanio);
					break;

				case 2:
					calcularSalarios(estructura, tamanio);
					 break;

				case 3:
					printf("¿Desea salir? s-si o n-no:\n");
					fflush(stdin);
					scanf("%c", &salir);
					if (salir=='s')
					{
						printf("Terminó el programa.\n");
					}
					break;
			}
		}
		else
		{
			printf("Error al seleccionar en el menu. Intente más tarde.\n");
			salir='s';
		}

	}while(salir=='n'||opcion!=3);

	return retorno;
}

void mostrarListadoSalarios(int suma, float promedio, int max)
{
	printf("TOTAL    PROMEDIO    SUPERAN EL PROMEDIO\n");
	printf("%d         %.2f        %10d       \n\n", suma, promedio, max);
}




















