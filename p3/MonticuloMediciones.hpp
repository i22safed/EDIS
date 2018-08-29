/*!
	\file MonticuloMediciones.hpp
	\brief Se define el TAD MonticuloMediciones.
	\author
	\date
*/

#ifndef _MONTICULO_MEDICIONES_HPP
#define _MONTICULO_MEDICIONES_HPP

#include <vector>

#include <cassert>

#include "Medicion.hpp"

#include "MonticuloMedicionesInterfaz.hpp"


// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

namespace ed
{

// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

class MonticuloMediciones : public MonticuloMedicionesInterfaz{

	private:

		//! \name Atributos privados de la clase MonticuloMediciones

		std::vector <ed::Medicion> _monticulo;

		//! \name Métodos privados de la clase MonticuloMediciones

		inline Medicion getElement(int const &i) const {
			#ifndef NDEBUG
				assert((i >= 0)/*and(i < size())*/);
			#endif

			return _monticulo[i];

		}


		inline void setElement(int const &i, Medicion medicion){

			#ifndef NDEBUG
				assert((i >= 0)/*and(i < size())*/);
			#endif

			_monticulo[i] = medicion;

			#ifndef NDEBUG
				assert(getElement(i)==medicion);
			#endif

			return ;

		}

		int getLeftChild(int const &i) const ;

		int getRightChild(int const &i) const ;

		int getParent(int const &i) const ;

		void shiftUp(int const &i) const ;

		void shiftDown(int const &i) const ;

		bool has(Medicion medicion) const ; 

	  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Métodos públicos de la clase MonticuloMediciones
	public:

		//! \name Constructor

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN


		//! \name Observadores

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

		////////////////////////////////////////////////////////////

		//! \name Operaciones de modificación

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN


		//! \name Operadores

		// COMPLETAR


		////////////////////////////////////////////////////////////////////

		//! \name Función de escritura

		// COMPLETAR

	}; // Clase MonticuloMediciones

} // Espacio de nombres ed


#endif // _MONTICULO_MEDICIONES_HPP
