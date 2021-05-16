#include "utn.h"

#ifndef ARRAYEMPLEADOS_H_
#define ARRAYEMPLEADOS_H_

#define CANTIDAD_EMPLEADOS 1000

typedef struct
{
 int id;
 char nombre[TAM];
 char apellido[TAM];
 float salario;
 int sector;
 int isEmpty;
}eEmpleados;

//FUNCIONES QUE PIDEN EN EL PDF

int inicializarEmpleados(eEmpleados arrayStruct[], int tamanio);
int agregarEmpleado(eEmpleados arrayStruct[], int posicion, char nombre[], char apellido[], float salario, int sector, int iD);
int buscarEmpleadoConId (eEmpleados arrayStruct[], int tamanio, int iD, int* posicion);
int removerEmpleado(eEmpleados arrayStruct[], int tamanio);
int ordenarEmpleados(eEmpleados arrayStruct[], int tamanio, int orden);




//ABM
//Alta
int buscarIsEmpty(eEmpleados arrayStruct[], int tamanio, int* auxTamanio);
int cargaDatosEmpleado(eEmpleados arrayStruct[], int tamanio, int* flagId);

//Mostrar
void mostrarListado(eEmpleados arrayStruct[], int tamanio);
void imprimirEmpleados(eEmpleados* arrayStruct, int tamanio);

int calcularSalarios(eEmpleados estructura[], int tamanio);


//Modificar

void modificarDatos(eEmpleados arrayStruct[], int tamanio);


int revizarIsEmpty(eEmpleados arrayStruct[], int tamanio, int* flag);

int informesEstructura(eEmpleados estructura[], int tamanio);
void mostrarListadoSalarios(int suma, float promedio, int max);



#endif /* ARRAYEMPLEADOS_H_ */
