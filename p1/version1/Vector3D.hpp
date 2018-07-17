/*!
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones
*/

#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_

// Entrada y salida
#include <iostream>

// Para usar abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

// COMPLETAR, SI ES PRECISO


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales


// Se incluye la clase Vector3D dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$
class Vector3D
{
  //! \name Atributos privados de la clase Vector3D
   private:

	    double x_,y_,z_;

   //! \name Funciones o métodos públicos de la clase Vector3D
   public:

	//! \name Constructores de la clase Vector3D

  // Constructor sin argumentos
	 Vector3D();
   // Constructor parametrizado
   Vector3D(double x, double y, double z);
   // Constructor de copia
   Vector3D(ed::Vector3D const &v);

   //! \name Modificadores: funciones de modificación de Vector3D

   void set1(double x);
   void set2(double y);
   void set3(double z);

	//! \name Observadores: funciones de consulta de Vector3D

  // Observadores de las componentes del Vector3D
  double  get1()const;
  double  get2()const;
  double  get3()const;

  // Observador del modulo
  double modulo()const;

  // Observador del angulo
  double angulo(ed::Vector3D const &v)const;

  // Observadores de los angulos alfa, beta y gamma
  double alfa()const;
  double beta()const;
  double gamma()const;

  // Producto escalar
  double dotProduct(Vector3D const &v)const;

  // Producto vectorial
  Vector3D crossProduct(Vector3D const &v)const;

  // Producto mixto
  double productoMixto(Vector3D const &v,Vector3D const &w)const;

  // Suma de una constante a un vector (x+k,y+k,z+k)
  void sumConst(double k);

  // Suma de un vector a otro (x1+x2,y1+y2,z1+z2)
  void sumVect(ed::Vector3D const &v);

  // Multiplicacion de vector por constante k (x*k,y*k,z*k)
  void mulConst(double k);

  // Multiplicacion de un vector por otro (x1*x2,y1*y2,z1*z2)
  void mulVect(ed::Vector3D const &v);


    //! \name Operadores de la clase

  // Operador de igualdad ==
  bool operator == (Vector3D const &v) const;

	// Operador de asignación =
	Vector3D & operator=(Vector3D const &v);

	// Operador + binario
  Vector3D operator+(Vector3D const &v);

  // Operador + unario
  Vector3D operator+();

  // Operador - binario
  Vector3D operator-(Vector3D const &v);

  // Operador - unario
  Vector3D operator-();

	//! \name Funciones lectura y escritura de la clase Vector3D

  void leerVector3D();

  void escribirVector3D();




}; // Fin de la definición de la clase Vector3D


//////////////////////////////////////////////////////////////////////////////////////

//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

	// COMPLETAR COMENTARIOS DE DOXYGEN
    Vector3D & operator* (double k, Vector3D const & objeto);


	// COMPLETAR COMENTARIOS DE DOXYGEN
    istream &operator>>(istream &stream, Vector3D &objeto);

	// COMPLETAR COMENTARIOS DE DOXYGEN
	ostream &operator<<(ostream &stream, Vector3D const &objeto);


} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif
