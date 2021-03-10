/*
3)Nos ingresan una cantidad indeterminada de estadías de  vacaciones, 
validando los datos ingresados. 
sexo del titular ,lugar ( “bariloche”, “cataratas” o “salta”),
temporada(“otoño”,”invierno, “verano,”primavera”),
cantidad de personas que viajan.
informar:
a)el lugar más elegido
b)el sexo de titular que lleva más pasajeros.
c)el promedio de personas por viaje,  que viajan en invierno
*/
function mostrar()
{
		
	var respuesta;
	var sexoTitular;
	var lugarIngresado;
	var temporadaIngresada;
	var cantidadPasajeros;

	var contadorBariloche;
	var contadorSalta;
	var contadorCataratas;
	var lugarMasElegido;
	var banderaMaximosPasajeros;
	var mayorCantidadPasajeros;
	var sexoMasPasajeros;
	var contadorViajesInvierno;
	var acumuladorPersonasInvierno;
	var promedioPersonasInvierno;

	respuesta="si";
	banderaMaximosPasajeros=0;
	contadorCataratas=0;
	contadorSalta=0;
	contadorBariloche=0;
	contadorViajesInvierno=0;
	acumuladorPersonasInvierno=0;


	while(respuesta=="si")
	{
		sexoTitular=prompt("Ingrese el sexo del titular 'f' para femenino, 'm' para masculino.");
		while(isNaN(sexoTitular)==false || sexoTitular!="f" && sexoTitular!="m")
		{
			sexoTitular=prompt("ERROR, ingrese un sexo valido");
		}

		lugarIngresado=prompt("Ingrese el lugar, sea 'cataratas', 'bariloche' o 'salta' ");
		while(isNaN(lugarIngresado)==false || lugarIngresado!="cataratas" && lugarIngresado!="bariloche" && lugarIngresado!="salta")
		{
			lugarIngresado=prompt("ERROR, ingrese el lugar correcto");
		}

		temporadaIngresada=prompt("Ingrese la temporada del año (estacion)");
		while(isNaN(temporadaIngresada)==false || temporadaIngresada!="otoño" && temporadaIngresada!="primavera" && temporadaIngresada!="verano" && temporadaIngresada!="invierno")
		{
			temporadaIngresada=prompt("ERROR, ingrese una estacion del año");
		}

		cantidadPasajeros=prompt("Ingrese la cantidad de pasajeros");
		cantidadPasajeros=parseInt(cantidadPasajeros);
		while(isNaN(cantidadPasajeros)==true || cantidadPasajeros<0)
		{
			cantidadPasajeros=prompt("ERROR, ingrese una cantidad correcta de pasajeros");
			cantidadPasajeros=parseInt(cantidadPasajeros);
		}


		//contadores de destinos
		switch(lugarIngresado)
		{
			case "bariloche":
				contadorBariloche++;
				break;
			case "salta":
				contadorSalta++;
				break;
			case "cataratas":
				contadorCataratas++;
				break;
		}


		//sexo del titular con mayor cantidad de pasajeros
		if(banderaMaximosPasajeros==0)
		{
			sexoMasPasajeros=sexoTitular;
			mayorCantidadPasajeros=cantidadPasajeros;

			banderaMaximosPasajeros++;
		}
		else
		{
			if(mayorCantidadPasajeros<cantidadPasajeros)
			{
				sexoMasPasajeros=sexoTitular;
				mayorCantidadPasajeros=cantidadPasajeros;
			}
		}

		//promedio de personas por viaje en invierno
		switch(temporadaIngresada)
		{
			case "invierno":
				contadorViajesInvierno++;
				acumuladorPersonasInvierno=acumuladorPersonasInvierno+cantidadPasajeros;
		}



		respuesta=prompt("Ingrese 'si' si desea ingresar otra estadia");
	}//fin del while principal


	//comparo contadores de destinos
	if(contadorCataratas>contadorSalta && contadorCataratas>contadorBariloche)
	{
		lugarMasElegido="Cataratas";
	}
	else
	{
		if(contadorSalta>contadorBariloche)
		{
			lugarMasElegido="Salta";
		}
		else
		{
			lugarMasElegido="Bariloche";
		}
	}

	document.write("El destino mas elegido es: "+lugarMasElegido+"<br>");
	document.write("El sexo del titular que lleva mas pasajeros es: "+sexoMasPasajeros+"<br>");


	//promedio de personas por viaje en invierno
	promedioPersonasInvierno=acumuladorPersonasInvierno / contadorViajesInvierno ;

	if(contadorViajesInvierno>0)
	{
		document.write("El promedio de personas por viaje en invierno es de: "+promedioPersonasInvierno+"<br>");
	}

}
