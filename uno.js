// Una software factory registra la siguiente informacion de sus empleados:
// Nombre,
// edad (validar),
// sexo (masculino - femenino - no binario),
// puesto (programador - analista - Qa),
// sueldo (entre 15000 y 70000).
// La empresa desea saber: se debe informar de existir, o informar que no existe , en el caso que corresponda.
// a) promedio de sueldos para cada puesto
// b) el sexo del que percibe el mayor sueldo
// c) el nombre del empleado femenino con mas sueldo
// d) cantidad de programadores no binarios que cobran sueldos entre 20000 y 55000


function mostrar()
{
	var nombre;
	var edad;
	var sexo;
	var puesto;
	var sueldo;
	var continuar;

	var acuSueldoP=0;
	var acuSueldoA=0;
	var acuSueldoQ=0;
	var contaSueldoP=0;
	var contaSueldoA=0;
	var contaSueldoQ=0;
	var promeA;
	var promeP;
	var promeQ;

	var sexoSueldo;
	var mayorSueldo;
	var flagSueldo=false;

	var nombreFeme;
	var sueldoFeme;
	var flagFeme=false;

	var contaNoBinarios=0;

	//PEDIDO DE DATOS

	do 
	{
		nombre=prompt("Ingrese el nombre del empleado.");

		while (isNaN(nombre)==false||nombre==" ")
		{
			nombre=prompt("Nombre invalido. Ingrese el nombre del empleado.");
		}
	
		edad=prompt("Ingrese la edad del empleado.");
		edad=parseInt(edad);

		while(edad<18||edad>70)
		{
			edad=prompt("Error, reingrese una edad valida.");
			edad=parseInt(edad);
		}
	
		puesto=prompt("Ingrese el puesto del empleado. (programador - analista - Qa)");

		while (puesto!="programador"&&puesto!="analista"&&puesto!="qa")
		{
			puesto=prompt("Puesto invalido. Ingrese el puesto del empleado.");
		}
		
		sexo=prompt("Ingrese el sexo del empleado. (masculino - femenino - no binario)");

		while (sexo!="femenino"&&sexo!="masculino"&&sexo!="no binario")
		{
			sexo=prompt("Sexo invalido. Ingrese el sexo.");
		}
	
		sueldo=prompt("Ingrese el sueldo del empleado. Entre 15.000 y 70.000 pesos.");
		sueldo=parseInt(sueldo);

		while(sueldo<15000||sueldo>70000)
		{
			sueldo=prompt("Error, reingrese un sueldo valida.");
			sueldo=parseInt(sueldo);
		}
	
		//A
	
		switch (puesto) {
			case "analista":
				acuSueldoA=acuSueldoA+sueldo;
				contaSueldoA=contaSueldoA+1;
				break;
		
			case "programador":
				acuSueldoP=acuSueldoP+sueldo;
				contaSueldoP=contaSueldoP+1;
				break;

			case "qa":
				acuSueldoQ=acuSueldoQ+sueldo;
				contaSueldoQ=contaSueldoQ+1;
				break;		
		}
	
		//B

		if (flagSueldo==false||mayorSueldo<sueldo)
		{
			var mayorSueldo=sueldo;
			var sexoSueldo=sexo;
			var flagSueldo=true;
		}
	
		//C

		if (sexo=="femenino")
		{
			if (flagFeme==false||sueldoFeme<sueldo)
			{
				nombreFeme=nombre;
				sueldoFeme=sueldo;
				flagFeme=true;
			}
		}
	
		//D

		if (puesto=="programador"&&sexo=="no binario")
		{
			if (sueldo>22000||sueldo<55000)
			{
				contaNoBinarios=contaNoBinarios+1;
			}
		}

		continuar=confirm("Desea añadir a otro empleado?");
	
	}while (continuar==true)

	//CALCULAR Y MOSTRAR DATOS

	//A

	if (contaSueldoA>0)
	{
		promeA=acuSueldoA/contaSueldoA;
		alert("El promedio de sueldo para los analistas es "+promeA+" pesos.");
	}

	if (contaSueldoP>0)
	{
		promeP=acuSueldoP/contaSueldoP;
		alert("El promedio de sueldo para los programadores es "+promeP+" pesos.");
	}

	if (contaSueldoQ>0)
	{
		promeQ=acuSueldoQ/contaSueldoQ;
		alert("El promedio de sueldo para los Qa es "+promeQ+" pesos.");
	}

	//B

	alert("El sexo con mayor sueldo es "+sexoSueldo+" con un ingreso de "+mayorSueldo+" pesos.");

	//C

	if (flagFeme==true)
	{
		alert("El nombre de la empleada con mayor sueldo es "+nombreFeme);
	}

	//D

	if (contaNoBinarios>0)
	{
		alert("La cantidad de programadores no binarios con salario que comprende entre 22.000 y 55.000 pesos son "+contaNoBinarios);
	}
}
