/*!
	\file MonticuloMedicionesInterfaz.hpp
	\brief Se define la interfaz del TAD MonticuloMediciones.
	\author
	\date
*/

#ifndef _MONTICULO_MEDICIONES_INTERFAZ_HPP
#define _MONTICULO_MEDICIONES_INTERFAZ_HPP

#include "Medicion.hpp"

// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

namespace ed
{

	// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN
	class MonticuloMedicionesInterfaz
	{
		public:

			virtual int size() const = 0;

			virtual Medicion top() const = 0;

			virtual void insert(ed::Medicion medicion) const = 0;

			virtual void remove() const = 0;

	}; // Clase MonticuloMedicionesInterfaz

} // Espacio de nombres ed

#endif //  _MONTICULO_MEDICIONES_INTERFAZ_HPP
