#include "arrayEmpleados.h"


int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	char salir;
	int menu;
	int flagCarga=0;
	int flagId=0;

	eEmpleados datosEmpleado[CANTIDAD_EMPLEADOS];
	inicializarEmpleados(datosEmpleado, CANTIDAD_EMPLEADOS);

	do
	{
		menu=utn_getNumero(&opcion,"MENÚ DE REGISTRO DE EMPLEADOS:\n\n [1] Alta de empleados.\n [2] Modificar datos de empleados.\n [3] Dar de baja empleados\n [4] Informes.\n [5] Salir.\n", "No ingresó una opción válida. Vuelve a intentarlo.\n", 1, 5, 5);

		if(menu)
		{
			switch (opcion)
			{
				case 1: //Alta empleado - PREGUNTAR EN CUÁNTO TIENE QUE INICIAR EL VALOR DEL ID

					if(cargaDatosEmpleado(datosEmpleado, CANTIDAD_EMPLEADOS, &flagId))
					{
						flagCarga=1;
					}
					break;

				case 2: //Modificar datos del empleado
					 if(flagCarga==0)
					 {
						 printf("No se puede modificar datos porque no hay empleados ingresados.\n");
					 }
					 else
					 {
						 modificarDatos(datosEmpleado, CANTIDAD_EMPLEADOS);
					 }
					 break;

				case 3: //Baja empleado
					 if(flagCarga==0)
					 {
						 printf("No se han ingresado ningún empleado.\n");
					 }
					 else
					 {
						 removerEmpleado(datosEmpleado, CANTIDAD_EMPLEADOS);
						 if(revizarIsEmpty(datosEmpleado, CANTIDAD_EMPLEADOS, &flagCarga))
						 {
							 printf("No hay empleados en la base de datos. Seleccione la opción 1 para ingresar un nuevo empleado\n");
						 }
					 }
					 break;

				case 4:
					if(flagCarga==0)
					{
						 printf("No se han ingresado ningún empleado.\n");
					}
					else
					{
						informesEstructura(datosEmpleado, CANTIDAD_EMPLEADOS);
					}
					 break;

				case 5:
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

	}while(salir=='n'||opcion!=5);

	return EXIT_SUCCESS;
}
