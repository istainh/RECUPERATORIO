#include "arrayEmpleados.h"


int main(void)
{	setbuf(stdout, NULL);

	eEmpleados empleado[1];

	empleado[1].sector=1;
	int opsi;
	opsi=empleado[1].sector;

	char descripFinal[TAM];

	descripcionPorInt(&opsi, descripFinal, "Contaduría", "Maestra", "Doctora");
	printf("La descripcion final es %s", descripFinal);

	return EXIT_SUCCESS;
}
