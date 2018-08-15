/*!

	\file  Provincia.cpp
	\brief Definición de la clase Provincia
	\author David Sanchez Fernandez
	\date 09/04/2018
	\version 1.0

*/
//Para los flujos de entrada/salida en ficheros.
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>


// Para comprobar las pre y post condiciones
#include <cassert>
#include "Provincia.hpp"
#include "macros.hpp"

// OSBSERVADORES

bool ed::Provincia::existeMunicipio(std::string const &nombre){

     if(_listaMunicipios.isEmpty()==false){

     		this->_listaMunicipios.gotoHead();
     		while((this->_listaMunicipios.getCurrentItem().getNombre() != nombre) and (this->_listaMunicipios.isLastItem() == false)){
     			this->_listaMunicipios.gotoNext();
     		}

               if((this->_listaMunicipios.isLastItem() == true) and (this->_listaMunicipios.getCurrentItem().getNombre() != nombre)){
     			return false;
     		}

               if(this->_listaMunicipios.getCurrentItem().getNombre() == nombre){
     			return true;
     		}
     }

     return false;

}

ed::Municipio const & ed::Provincia::getMunicipio(std::string const &nombre){

     #ifndef NDEBUG
          assert(existeMunicipio(nombre)==true);
     #endif

     this->existeMunicipio(nombre);
     return this->_listaMunicipios.getCurrentItem();
}

int ed::Provincia::getTotalHombres(){

     int valorDevuelto = 0;

     this->_listaMunicipios.gotoHead();

     while(not _listaMunicipios.isLastItem()){

          valorDevuelto+=(this->_listaMunicipios.getCurrentItem().getHombres());
		this->_listaMunicipios.gotoNext();

     }

     return valorDevuelto;

}

int ed::Provincia::getTotalMujeres(){

     int valorDevuelto = 0;

     this->_listaMunicipios.gotoHead();

     while(not _listaMunicipios.isLastItem()){

          valorDevuelto+=(this->_listaMunicipios.getCurrentItem().getMujeres());
		this->_listaMunicipios.gotoNext();

     }

     return valorDevuelto;

}

int ed::Provincia::getTotalHabitantes(){

     int valorDevuelto = getTotalHombres() + getTotalMujeres();
     assert(valorDevuelto == getTotalHombres()+getTotalMujeres());
     return valorDevuelto;

}



/////////////////////////////////////////////////////////////////////////////////////////

// MODIFICADORES

void ed::Provincia::setNombre(std::string nombre){
     _nombre = nombre;
     assert(getNombre() == nombre);
};

void ed::Provincia::setCodigo(int codigo){
     _codigo = codigo;
     assert(getCodigo() == codigo);
};

void ed::Provincia::insertarMunicipio(ed::Municipio const & m){

     #ifndef NDEBUG
	    assert(existeMunicipio(m.getNombre()) == false);
	#endif

	int old=this->_listaMunicipios.nItems();
	this->_listaMunicipios.insert(m);

	#ifndef NDEBUG
	    assert(existeMunicipio(m.getNombre()) == true);
	    assert(getNumeroMunicipios() == (old+1));
	#endif

};


void ed::Provincia::borrarMunicipio(std::string const & nombre){

     #ifndef NDEBUG
	    assert(existeMunicipio(nombre) == true);
	#endif

	int old=this->_listaMunicipios.nItems();
	this->_listaMunicipios.remove();

	#ifndef NDEBUG
	    assert(existeMunicipio(nombre) == false);
	    assert(getNumeroMunicipios() == (old-1));
	#endif

}

void ed::Provincia::borrarTodosLosMunicipios(){

     this->_listaMunicipios.removeAll();

     #ifndef NDEBUG
	    assert(hayMunicipios() == false);
	#endif

}




///////////////////////////////////////////////////////////////////////////////////

// FUNCIÓN DE ESCRITURA

void ed::Provincia::escribirMunicipios(){

     std::cout << this->getNombre() << "\t\t" << this->getCodigo() << "\t" << std::endl;

		if(_listaMunicipios.isEmpty()==false){
               this->_listaMunicipios.gotoHead();

               while(this->_listaMunicipios.isLastItem() != true){

                    this->_listaMunicipios.getCurrentItem().escribirMunicipio();
                    this->_listaMunicipios.gotoNext();

          }
	}

}

/////////////////////////////////////////////////////////////////////////////////////////

// OPERACIONES CON FICHEROS

bool ed::Provincia::cargarFichero(std::string const & nombre){

     ed::Municipio aux;
	std::string linea;
	std::ifstream fich;
	fich.open(nombre.c_str());
	if(fich.fail())
	{
		std::cout << "Imposible abrir fichero de entrada" << std::endl;
		return false;
	}
	else
	{
		getline(fich, linea, ' ');
		this->setCodigo(atoi(linea.c_str()));
		getline(fich, linea, '\n');
		this->setNombre(linea);

		while(getline(fich, linea, ' '))
		{
			aux.setCodigoPostal(atoi(linea.c_str()));
			getline(fich, linea, ';');
			aux.setNombre(linea);
			getline(fich, linea, ';');
			aux.setHombres(atoi(linea.c_str()));
			getline(fich, linea, ';');
			aux.setMujeres(atoi(linea.c_str()));

			this->_listaMunicipios.insert(aux);
		}
		fich.close();
		return true;
	}

}


bool ed::Provincia::grabarFichero(std::string const & nombre){

     Municipio m;
     std::ofstream fichero (nombre.c_str());

     if(fichero.is_open()){
          fichero << getCodigo() << " " << getNombre() << std::endl;

          _listaMunicipios.gotoHead();

          while(_listaMunicipios.isLastItem()!=true){

               fichero << _listaMunicipios.getCurrentItem() << std::endl;
               std::cout << BIYELLOW << "Municipio grabado" << RESET << _listaMunicipios.getCurrentItem() << std::endl;
               _listaMunicipios.gotoNext();
          }

          std::cout << BIYELLOW << "Municipio grabado" << RESET << _listaMunicipios.getCurrentItem() << std::endl;
          fichero << _listaMunicipios.getCurrentItem() << std::endl;

     }else{

          std::cout << "Error al abrir fichero" << std::endl;
          return false;

     }

     fichero.close();
     return true;

}
