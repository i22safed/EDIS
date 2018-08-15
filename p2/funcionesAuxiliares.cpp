/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal de la provincia
  \author
  \date
*/

#include <iostream>
#include <string>

// Para usar atoi
#include <stdlib.h>

#include "Provincia.hpp"
#include "Municipio.hpp"
#include "funcionesAuxiliares.hpp"
#include "macros.hpp"

int ed::menu()
{
	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Comprobar si la provincia tiene municipios";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Cargar la provincia desde un fichero";

	PLACE(posicion++,10);
	std::cout << "[3] Grabar la provincia en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[4] Consultar datos de la provincia";

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar municipios de la provincia";

	PLACE(posicion++,10);
	std::cout << "[6] Modificar datos de la provincia: código o nombre";

	PLACE(posicion++,10);
	std::cout << "[7] Borrar todos los municipios de una provincia";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[8] Consultar un municipio";

	PLACE(posicion++,10);
	std::cout << "[9] Insertar un municipio";

	PLACE(posicion++,10);
	std::cout << "[10] Borrar un municipio";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}


//////////////////////////////////////////////////////////////////////////////

void ed::comprobarProvinciaVacia(ed::Provincia &provincia){

	std::cout << "La provincia de nombre < " << provincia.getNombre() << " > ";

	if (provincia.hayMunicipios() == true)
		std::cout <<BGREEN<< "Está vacía"<<RESET<<std::endl;
	else
		std::cout <<BGREEN<< "No está vacía"<<RESET<<std::endl;
	return;
}

//////////////////////////////////////////////////////////////////////////////

void ed::cargarProvincia(ed::Provincia &provincia){

	if(provincia.hayMunicipios() == true){
	 std::cout<<"Ya hay una provincia, borre la que hay si quiere cargar una"<< std::endl;

	}else{
	std::string nombreFichero;
	std::cout <<BGREEN<<"Nombre del fichero"<< RESET<< std::endl;
	std::cin >>nombreFichero;

	if(provincia.cargarFichero(nombreFichero)==true){
	 std::cout <<BCYAN<< "Provincia cargada "<<RESET<<std::endl;
	}else{
		std::cout << BRED<<"Provincia no cargada, no existe el fichero "<<RESET<<std::endl;
	}
	getchar();
	}

	return;
}

void ed::grabarProvincia(ed::Provincia  &provincia){

	if(provincia.hayMunicipios() == false){
			std::cout<<BRED<<"Error, provincia vacia"<<RESET<< std::endl;

		}else{
		std::string nombreFichero;
		std::cout <<BGREEN<<"Nombre del fichero"<<RESET<< std::endl;
		std::cin >> nombreFichero;
		if(provincia.grabarFichero(nombreFichero)==true){
			std::cout << "Provincia grabada "<<std::endl;
		}
		else{
			std::cout<<BRED<<"No se encontro fichero"<<RESET<<std::endl;
			std::cout <<BRED<< "Provincia no grabada "<<RESET<<std::endl;

		}
	  	getchar();

		}
	return;

}

//////////////////////////////////////////////////////////////////////

void ed::consultarDatosDeProvincia(ed::Provincia &provincia){

	if(provincia.hayMunicipios() == false){
			std::cout<<BRED<<"Error, provincia vacia"<<RESET<< std::endl;

		}else{
		std::string nombreFichero;
		std::cout <<BGREEN<<"Nombre del fichero"<<RESET<< std::endl;
		std::cin >> nombreFichero;
		if(provincia.grabarFichero(nombreFichero)==true){
			std::cout << "Provincia grabada "<<std::endl;
		}
		else{
			std::cout<<BRED<<"No se encontro fichero"<<RESET<<std::endl;
			std::cout <<BRED<< "Provincia no grabada "<<RESET<<std::endl;

		}
	  	getchar();

		}
	return;
}


//
void ed::mostrarMunicipiosDeProvincia(ed::Provincia & provincia){

	ed::Municipio municipio;

		if(provincia.hayMunicipios() == false){
			std::cout<<BRED<<"Provincia vacia, por tanto no puede consultar nada"<< RESET<< std::endl;

		}
		else{
		std::cout <<BYELLOW<< "Nombre de la provincia: " <<RESET<<provincia.getNombre() << std::endl;
		std::cout <<BYELLOW<< "Codigo de la provincia:  " <<RESET<<provincia.getCodigo() << std::endl;
		std::cout << BIPURPLE<< "Lista: " <<RESET<< std::endl;

		provincia.escribirMunicipios();
		}
	return;
}


////////////////////////////////////////////////////////////////////////
void ed::modificarDatosDeProvincia(ed::Provincia &provincia)
{

std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;

	int opcion, codigo;
	std::string nombre;

	do{
		std::cout << BIYELLOW  << "Nombre de la provincia: "  << RESET
				  << provincia.getNombre() << std::endl;
		std::cout << BIYELLOW << "Código de la provincia: " << RESET
				  << provincia.getCodigo() << std::endl  << std::endl;

		std::cout << "Indique qué dato desea modificar: " << std::endl;
		std::cout << BIBLUE << "(1) Nombre " << std::endl;
		std::cout << BIBLUE << "(2) Código" << std::endl  << std::endl;
		std::cout << BIRED << "(0) Salir" << std::endl << std::endl  << std::endl;
		std::cout << BIGREEN;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
	    std::cin.ignore();

		std::cout << std::endl;

		switch(opcion)
		{
			case 0:
					// Fin de las modificaciones
					break;
			case 1:
					std::cout << BIGREEN;
					std::cout << "Nuevo nombre de la provincia: ";
					std::cout << RESET;
					std::getline(std::cin,nombre);
					provincia.setNombre(nombre);
					break;

			case 2:
					std::cout << BIGREEN;
					std::cout << "Nuevo código de la provincia: ";
					std::cout << RESET;
					std::cin >> codigo;
					provincia.setCodigo(codigo);
					break;
			default:
					std::cout << BIRED << "Opción incorrecta:" << RESET
							  << opcion << std::endl;
		}
	}while (opcion != 0);
	return;
}


void ed::borrarTodosLosMunicipiosDeProvincia(ed::Provincia &provincia){

	if(provincia.hayMunicipios() == false)
		{
			std::cout<<BRED<<"Provincia vacia, por tanto no puede borrar nada"<< RESET<< std::endl;
		}
		else{
			provincia.borrarTodosLosMunicipios();
			std::cout <<BCYAN<< "Los municipios han sido borrados correctamente" <<RESET<< std::endl;
		}
	return;
}


void ed::consultarMunicipioDeProvincia(ed::Provincia &provincia){

	std::string nombre;
	if(provincia.hayMunicipios()==false)
	{
		std::cout<<BRED<<"Provincia vacia, no hay nada para consultar "<<RESET<<std::endl;

	}else
	{
	std::cout <<BYELLOW<< "Nombre del municipio que quiere consultar " <<RESET<< std::endl;
	getline(std::cin,nombre);

		if(provincia.existeMunicipio(nombre)==false){
			std::cout<<BRED<<"No existe "<<RESET<<std::endl;

		}else{
		ed::Municipio m;
		m=provincia.getMunicipio(nombre);
		std::cout<<BCYAN<<"El Municipio que busca:  "<<RESET<<std::endl;

		m.escribirMunicipio();
		}
	}
	return;
}

void ed::insertarMunicipioEnProvincia(ed::Provincia &provincia){

	ed::Municipio municipio;
	std::cout<<BGREEN;
	municipio.leerMunicipio();
	std::cout <<RESET;

	provincia.insertarMunicipio(municipio);

	std::cout<<BCYAN<<"Municipio insertado "<<RESET<<std::endl;
	return;
}




void ed::borrarMunicipioDeProvincia(ed::Provincia &provincia){

	bool control;
	std::string nombre;
	ed::Municipio municipio;


	std::cout <<BYELLOW<< "Nombre: "<<RESET;
	std::getline(std::cin,nombre);

	control = provincia.existeMunicipio(nombre);

	if (control == true){
		provincia.borrarMunicipio(nombre);

		control = provincia.existeMunicipio(nombre);

		if (control == true)
			std::cout <<BRED<< "El municipio no ha podido ser borrado" <<RESET<< std::endl;
		else
			std::cout <<BCYAN<< "El municipio ha sido borrado correctamente" <<RESET<< std::endl;
	}
	else{
		std::cout << "El municipio  "<< nombre ;
		std::cout << BRED<<"no pertenece a la provincia"<<RESET<<std::endl;
	}

	return;
}
