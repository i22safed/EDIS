/*!
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones
*/

#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_

#include <iostream> // Entrada y salida
#include <cmath>    // Para usar abs
#include <cassert>  // Para controlar las pre y post condiciones mediante asertos

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales


// Se incluye la clase Vector3D dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$
class Vector3D{

  //! \name Atributos privados de la clase Vector3D
   private:

	    double vector_[3];

   //! \name Funciones o métodos públicos de la clase Vector3D
   public:

	//! \name Constructores de la clase Vector3D

	   Vector3D();
     Vector3D(double v1,double v2, double v3);
     Vector3D(ed::Vector3D const &v);

	//! \name Observadores: funciones de consulta de Vector3D

  	 double get1()const{return vector_[0];};
     double get2()const{return vector_[1];};
     double get3()const{return vector_[2];};

     double modulo()const;
     double angulo(ed::Vector3D const &v)const;

     double alfa()const;
     double beta()const;
     double gamma()const;
     double dotProduct(ed::Vector3D const &v)const;
     Vector3D crossProduct(ed::Vector3D const &v)const;
     double productoMixto(ed::Vector3D const &v, ed::Vector3D const &w)const;

 //! \name Modificadores: funciones de modificación de Vector3D

     void set1(double v1);
     void set2(double v2);
     void set3(double v3);

     void sumConst(double k);
     void sumVect(ed::Vector3D const &v);
     void multConst(double k);
     void multVect(ed::Vector3D const &v);

    //! \name Operadores de la clase

     bool operator == (Vector3D const &v)const;
     Vector3D & operator=(Vector3D const &v);
     Vector3D operator+(Vector3D const &v)const;
     Vector3D operator+()const;
     Vector3D operator-(Vector3D const &v)const;
     Vector3D operator-()const;
     Vector3D operator*(double k)const;
     double operator*(Vector3D const &v)const;
     Vector3D operator^(Vector3D const &v)const;

  //! \name Funciones lectura y escritura de la clase Vector3D

     void leerVector3D();
     void escribirVector3D()const;

}; // Fin de la definición de la clase Vector3D

//////////////////////////////////////////////////////////////////////////////////////

//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

	// COMPLETAR COMENTARIOS DE DOXYGEN
     Vector3D & operator* (double k, Vector3D const & v);
     istream &operator>>(istream &i, Vector3D &v);
	   ostream &operator<<(ostream &o, Vector3D const &v);


} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif
