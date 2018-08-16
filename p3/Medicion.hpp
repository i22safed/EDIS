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

// Definición de la clase Fecha
#include "Fecha.hpp"


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Se incluye la clase Medicion dentro del espacio de nombres de la asigantura: ed
namespace ed {

//!  Definición de la clase Medicion
class Medicion{

  //! \name Atributos privados de la clase Medicion
   private:

		   Fecha _fecha;
       double _precipitacion;

   //! \name Funciones o métodos públicos de la clase Medicion
   public:

	//! \name Constructor de la clase Medicion

    Medicion(Fecha fecha = Fecha(1,1,1), double precipitacion = 0.0){
      assert((getFecha()==fecha) and (getPrecipitacion()==precipitacion));
    }

    inline Medicion(Medicion &m){
      setFecha(m.getFecha());
      setPrecipitacion(m.getPrecipitacion());
    }

	//! \name Observadores: funciones de consulta de la clase Medicion

    inline Fecha getFecha() const {
      return _fecha;
    }

    inline double getPrecipitacion() const {
      return _precipitacion;
    }

	//! \name Funciones de modificación de la clase Medicion

		inline void setFecha(Fecha fecha){
      _fecha = fecha;
      assert(getFecha() == fecha);
    }

    inline void setPrecipitacion(double precipitacion){
      assert(precipitacion >= 0.0);
      _precipitacion = precipitacion;
      assert(getPrecipitacion() == precipitacion);
    }



	//! \name Operadores

  		inline bool operator == (ed::Medicion const & m)const{

          bool valorDevuelto = false;

          if(getFecha() == m.getFecha()){
            valorDevuelto = true;
            assert(valorDevuelto == (getFecha() == m.getFecha()));
          }

          return valorDevuelto;

      }

      inline ed::Medicion operator = (ed::Medicion const & m)const{

        ed::Medicion med;

        med.setFecha(m.getFecha());
        med.setPrecipitacion(m.getPrecipitacion());

        assert(med.getFecha() == m.getFecha());
        assert(med.getPrecipitacion() == m.getPrecipitacion());

        return med;
      }

	//! \name Funciones de lectura y escritura de la clase Medicion

      void leerMedicion();

      void escribirMedicion();

      ostream & operator << (ostream &o, ed::Medicion const & m);

      istream & operator >> (istream &i, ed::Medicion const & m);


}; // Fin de la definición de la clase Medicion


   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN



} // \brief Fin de namespace ed.

//  _MEDICION_HPP_
#endif
