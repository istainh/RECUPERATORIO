/*
2)De una compra debes ingresar una cantidad indeterminada de productos,
 validando los siguientes datos:
marca, precio, peso en kilogramos, tipo(sólido o líquido)
a)informar el peso total de la compra.
b)la marca del más caro de los líquidos
c)la marca del más barato de los sólidos
*/function mostrar()
{
	var marca;
	var peso;
	var precio;
	var tipo;
	var respuesta;
	var acumuladorPeso;
	var marcaLiquidoCaro;
	var precioLiquidoIngresaso;
	var banderaPrimerLiquido;
	var banderaSolidoMasBarato;
	var marcaMasBaratoSolido;
	var precioMasBaratoSolido;

	banderaSolidoMasBarato=0;
	banderaPrimerLiquido=0;
	acumuladorPeso=0;
	

	respuesta="si";

	while(respuesta=="si")
	{
		marca=prompt("Ingrese por favor la marca");//puede ser numero
		while(marca==" ")
		{
			tipo=prompt("Error, ingrese una marca valida");
		}

		tipo=prompt("Ingrese por favor el tipo");
		while(!isNaN(tipo)||tipo!="solido"&&tipo!="liquido")
		{
			tipo=prompt("Error, ingrese un tipo valido");
		}

		peso=prompt("Ingrese el peso en kilogramos");
		peso=parseInt(peso);
		while(isNaN(peso)||peso<1)
		{
			
			peso=prompt("Error, Ingrese el peso en kilogramos");
			peso=parseInt(peso);
		}

		precio=prompt("Ingrese el precio por favor");
		precio=parseInt(precio);
		while(isNaN(precio)||precio<1)
		{
			precio=prompt("Ingrese el precio por favor");
			precio=parseInt(precio);

		}

		acumuladorPeso=acumuladorPeso+peso;		
  		

		switch(tipo)
		{
			case "liquido":
				if(banderaPrimerLiquido==0)
				{
					marcaLiquidoCaro=marca;
					precioLiquidoIngresaso=precio;
					banderaPrimerLiquido=1;
				}
				else
				{
					if(precio>precioLiquidoIngresaso)
					{
						marcaLiquidoCaro=marca;
						precioLiquidoIngresaso=precio;
					}
				}
				break;
			case "solido":
				if(banderaSolidoMasBarato==0)
				{
					marcaMasBaratoSolido=marca;
					precioMasBaratoSolido=precio;
					banderaSolidoMasBarato=1;
				}
				else
				{
					if(precio<precioMasBaratoSolido)
					{
						marcaMasBaratoSolido=marca;
						precioMasBaratoSolido=precio;
					}
				}
				break;
					
		}//cierre switch

		
		respuesta=prompt("Desea seguir?")
	} //cierre while



 console.log("El peso total de la compra es: "+acumuladorPeso); 					
 console.log("La marca del más caro de los liquidos es: "+marcaLiquidoCaro);
 console.log("La marca del más barato de los solidos es: "+marcaMasBaratoSolido);

}
