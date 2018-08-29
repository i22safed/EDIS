/*!
   \file Medicion.hpp
   \brief Fichero de la clase Medicion: medición de una estación meteorológica
*/

#ifndef _MEDICION_HPP_
#define _MEDICION_HPP_

// Entrada y salida
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

// Para utilizar el valor absoluto junto con la cota de error
#include <cmath>

// Definición de la clase Fecha
#include "Fecha.hpp"


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Se incluye la clase Medicion dentro del espacio de nombres de la asigantura: ed
namespace ed {

//!  Definición de la clase Medicion
class Medicion
{
  //! \name Atributos privados de la clase Medicion
   private:

		Fecha _fecha;
    double _precipitacion;

   //! \name Funciones o métodos públicos de la clase Medicion
   public:

	//! \name Constructor de la clase Medicion

		Medicion(Fecha fecha=Fecha(1,1,1),double precipitacion=0.0){

      setFecha(fecha);
      setPrecipitacion(precipitacion);

      #ifndef NDEBUG
        assert(getFecha()==fecha);
        assert(std::abs(getPrecipitacion()-precipitacion) < COTA_ERROR);
      #endif

    }

    Medicion(Medicion const &medicion){
      setFecha(medicion.getFecha());
      setPrecipitacion(medicion.getPrecipitacion());

      #ifndef NDEBUG
        assert(getFecha()==medicion.getFecha());
        assert(std::abs(getPrecipitacion()-medicion.getPrecipitacion()) < COTA_ERROR);
      #endif

    }

	//! \name Observadores: funciones de consulta de la clase Medicion

		inline Fecha getFecha()const{
      return _fecha;
    }

    inline double getPrecipitacion()const{
      return _precipitacion;
    }

	//! \name Funciones de modificación de la clase Medicion

    inline void setFecha(Fecha const &fecha){
      _fecha = fecha;
      #ifndef NDEBUG
        assert(getFecha() == fecha);
      #endif
    }

    inline void setPrecipitacion(double const &precipitacion){
      #ifndef NDEBUG
        assert(precipitacion >= 0.0);
      #endif

      _precipitacion = precipitacion;

      #ifndef NDEBUG
        assert(std::abs(getPrecipitacion() - precipitacion) < COTA_ERROR);
      #endif

    }



	//! \name Operadores

    bool operator == (Medicion const &medicion)const;

    Medicion operator = (Medicion const &medicion);

	//! \name Funciones de lectura y escritura de la clase Medicion

		void leerMedicion();

    void escribirMedicion()const;



}; // Fin de la definición de la clase Medicion


   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN



} // \brief Fin de namespace ed.

//  _MEDICION_HPP_
#endif
