/*!
	\file  Provincia.hpp
	\brief Definición de la clase Provincia
	\author
	\date
	\version

*/

#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

// Para comprobar las pre y post condiciones
#include <cassert>

#include <string>


#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"


// DEBES COMPLETAR O MODIFICAR EL CÓDIGO DE LA CLASE Provincia

// DEBES COMPLETAR LOS COMENTARIOS DE DOXYGEN

// IMPORTANTE
// Se incluyen los prototipos de las funciones virtuales que hay que redefinir
// Hay que incluir los prototipos de las demás funciones


/*!
	\namespace ed
	\brief Espacio de nombres para la Provincia Estructuras de Datos

*/
namespace ed{
/*!

  \class Provincia
  \brief Definición de la clase Provincia

*/
class Provincia
{
	//!	\name Métodos públicos de la clase Provincia

	private:
		std::string      _nombre;     //!<  \brief Nombre de la Provincia
		int              _codigo;	  //!<  \brief Código de la Provincia

	  ed::ListaDoblementeEnlazadaOrdenadaMunicipios _listaMunicipios; //!<  \brief Lista de municipios de la Provincia


	/////////////////////////////////////////////////////////////////////

	//!	\name  Métodos públicos de la clase Provincia

  public:

	//!	\name Constructor

	Provincia(std::string nombre, int codigo=0);


	/////////////////////////////////////////////////////////////////////

	//!	\name Observadores → observadores como const

	std::string getNombre()const{
		return _nombre;
	};


	int getCodigo()const{
		return _codigo;
	};

	bool hayMunicipios()const;

	int getNumeroMunicipios()const;

	bool existeMunicipio(std::string nombre)const;

	Municipio getMunicipio(std::string nombre)const;

	/////////////////////////////////////////////////////////////////////

	//!	\name Modificadores

	void setNombre(std::string nombre);

	void setCodigo(int codigo);

	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia



	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros


}; //Fin de la clase  Provincia


} // Fin del espacio de nombres ed

#endif // _PROVINCIA_HPP_
