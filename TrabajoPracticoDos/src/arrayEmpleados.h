#include "Biblioteca.h"


#ifndef ARRAYEMPLEADOS_H_
#define ARRAYEMPLEADOS_H_

typedef struct
{
 int id;
 char nombre[TAM];
 char apellido[TAM];
 float salario;
 int sector;
 int isEmpty;
}eEmpleados;

//FUNCION INIT

int initEmpleados(eEmpleados* arrayStruct, int tamanio);

//FUNCION ADD

int addEmpleado(eEmpleados* arrayStruct, int tamanio, char nombre[], char apellido[], float salario, int sector, int iD);

//ABM
//Alta
int buscarIsEmpty(eEmpleados arrayStruct[], int tamanio, int* auxTamanio);
void cargaDatosEmpleado(eEmpleados* arrayStruct, int tamanio, int* flagCarga, int* flagId);

//Mostrar
void mostrarListado(eEmpleados arrayStruct[], int tamanio);

//Buscar
int buscarEmpleadoConId (eEmpleados arrayStruct, int tamanio, int iD);



#endif /* ARRAYEMPLEADOS_H_ */
