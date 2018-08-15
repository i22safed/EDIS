/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 2
  \author
  \date
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Provincia.hpp"

namespace ed
{

  int menu();

	///////////////////////////////////////////////////////////////////


	void comprobarProvinciaVacia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////


	void cargarProvincia(ed::Provincia & provincia);


	void grabarProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////


	void consultarDatosDeProvincia(ed::Provincia & provincia);


	void mostrarMunicipiosDeProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////


	void modificarDatosDeProvincia(ed::Provincia & provincia);


	void borrarTodosLosMunicipiosDeProvincia(ed::Provincia & provincia);


	///////////////////////////////////////////////////////////////////


	void consultarMunicipioDeProvincia(ed::Provincia & provincia);


	void insertarMunicipioEnProvincia(ed::Provincia & provincia);


	void borrarMunicipioDeProvincia(ed::Provincia & provincia);


} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif
