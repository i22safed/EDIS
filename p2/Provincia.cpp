/*!

	\file  Provincia.cpp
	\brief Definición de la clase Provincia
	\author
	\date
	\version 1.0

*/
//Para los flujos de entrada/salida en ficheros.
#include <fstream>
#include <iostream>

// Para comprobar las pre y post condiciones
#include <cassert>

#include "Provincia.hpp"


// DEBES CODIFICAR LAS FUNCIONES DE LA CLASE Provincia

///////////////////////////////////////////////////////////////////////////////

// CONSTRUCTOR

ed::Provincia::Provincia(std::string nombre, int codigo=0){
    setNombre(nombre);
    setCodigo(codigo);

    assert(getNombre() == nombre);
    assert(getCodigo() == codigo);
    assert(hayMunicipios() == false);
}



///////////////////////////////////////////////////////////////////////////////

// OSBSERVADORES

  bool ed::Provincia::hayMunicipios()const{

    return not(_listaMunicipios.isEmpty());

  }

  int ed::Provincia::getNumeroMunicipios()const{

    return _listaMunicipios.nItems();

  }

  bool ed::Provincia::existeMunicipio(std::string nombre)const{ // Se podría cambiar

    // Comprobamos que la lista no está vacía

    if(_listaMunicipios.isEmpty()==false){

      // Dejamos el puntero en la cabeza

       this->_listaMunicipios.gotoHead();

       // Mientras que no coincida nombre ni estemos en el último elemento
       // incrementamos el cursor

       while((this->_listaMunicipios.getCurrentItem().getNombre() != nombre)
       and (this->_listaMunicipios.isLastItem() == false)){

          this->_listaMunicipios.gotoNext();

       }

       // Se ha recorrido toda la lista y no ha coincidido el nombre

       if((this->_listaMunicipios.isLastItem() == true)
       and (this->_listaMunicipios.getCurrentItem().getNombre() != nombre)){

         return false;

       }

       // El elemento actual coincide con el nombre que se le ha pasado

       if(this->_listaMunicipios.getCurrentItem().getNombre() == nombre){
         return true;
       }

    }

    // Para ninguno de los casos anteriores, se retorna false

    return false;

  }

ed::Municipio ed::Provincia::getMunicipio(std::string nombre)const{

    assert(existeMunicipio(nombre) == true);

    this->_listaMunicipios.gotoHead();

    while((this->_listaMunicipios.getCurrentItem().getNombre() != nombre)
    and(this-> _listaMunicipios.isLastItem() == false)){

      this->_listaMunicipios.gotoNext();

    }

    if(this->_listaMunicipios.getCurrentItem().getNombre() == nombre){

      return getCurrentItem();

    }

}

/////////////////////////////////////////////////////////////////////////////////////////

// MODIFICADORES

void ed::Provincia::setNombre(std::string const & nombre){
  nombre_=nombre;
  assert(getNombre() == nombre);
}


void ed::Provincia::setCodigo(int const & codigo){
  codigo_=codigo;
  assert(getCodigo() == codigo);
}


///////////////////////////////////////////////////////////////////////////////////

// FUNCIÓN DE ESCRITURA



/////////////////////////////////////////////////////////////////////////////////////////

// OPERACIONES CON FICHEROS
