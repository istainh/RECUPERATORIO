/*
 ============================================================================
 Name        : FUNCIONES.c
 Author      : Ainhoa Osorio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
A- Hacer el menú de un programa con las siguientes opciones: 1. Loguearse, 2. Comprar, 3. Ver mis compras, 4. Vender, 5. Salir
B- Al menú anterior chequear que no pueda ingresar a ninguna opción si no se logueó
C- Al menú anterior chequear que no pueda ver sus compras, si no ingresó primero a comprar al menos una vez
D- Cuando se ingresa a la opción vender del menú, debe abrirse otro menú que contenga: 1. Vender 2. Hacer factura 3. Volver atrás
E- A lo anterior sumarle que haya compras para poder vender. (Si compré una vez y vendí una vez no puedo ingresar a vender).
F- Pasar las acciones de menú a funciones y llevarlas a una biblioteca
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int menu;
	char salir;
	int flagLogueo=0;
	int acuCompras=0; //puedo realizar un puntero en la función de compra que me modifique este flag a verdadero.
	int menuDos;
	int acuVentas=0;
	char continuar;

	do
	{
		printf("MENÚ \n\n");
		printf("1) Logearse.\n);");
		printf("2) Comprar.\n");
		printf("3) Ver mis compras.\n");
		printf("4) Vender.\n");
		printf("5) Salir.\n");
		fflush(stdin);
		scanf("%d", &menu);

		switch (menu)
		{
			case 1:
				if(flagLogueo!=0)
				{
					printf("\nYa estás logueado");
				}
				else
				{
					printf("\nLogueo exitoso.");
					flagLogueo=1;
				}
			break;

			case 2:
				if(flagLogueo!=0)
				{
					acuCompras++;
					printf("\nCompra realizada.");
				}
				else
				{
					printf("\nNecesitas loguearte para poder comprar.");
				}
			break;

			case 3:
				if(acuCompras!=0)
				{
					printf("\nEl total de compras que ya realizó es %d", acuCompras);

				}
				else
				{
					printf("\nNo ha realizado ninguna compra.");
				}
			break;

			case 4:
				if(acuCompras!=0)
				{
					do
					{
						printf("MENÚ \n\n");
						printf("1) Vender.\n);");
						printf("2) Hacer factura.\n");
						printf("3) Volver atrás.\n");
						fflush(stdin);
						scanf("%d", &menuDos);

						switch (menuDos)
						{
							case 1:
								if(acuCompras!=0)
								{
									acuCompras--;
									acuVentas++;
									printf("\nVenta realizada.");
								}
								else
								{
									printf("\nNo tenes nada que vender.");
								}
								break;

							case 2:
								if(acuVentas!=0)
								{
									printf("\nFactura de sus ventas realizada.");
								}
								else
								{
									printf("\nNo tenes nada que facturar.");
								}
								break;

							case 3:
								printf("\n¿Desea volver atrás? s-si o n-no:");
								fflush(stdin);
								scanf("%c", &continuar);
								break;

							default:
								printf("\nIngrese un número válido del menú.");
								break;
						}
					}while(continuar=='n');
				}
			break;

			case 5:
				printf("\n¿Desea salir? s-si o n-no:");
				fflush(stdin);
				scanf("%c", &salir);
		}
	}while(salir=='n');

//
//	}while(salir!=5);
//
//	printf("Bienvenido. Debes loguearte para poder comprar.");
//	printf("\n Ingrese su dirección de email: ");
//	scanf("%s", &email);
//
//	while(email==' ')
//	{
//		printf("\n Error no ingresaste una dirección de email. Debes loguearte para poder comprar.");
//		scanf("%c", &email);
//	}
//
//	printf("\n Ahora elige una de las siguientes opciones:");
//	scanf("%d", &comprar);
//
//	swhich (menu)
//	{
//		case 1:
//		{
//			compraTotal=comprar(); //funcion no creada
//		}
//		case 2:
//		{
//			verCompras=verCompras();
//		}
//		case 3:
//
//	}




