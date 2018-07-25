/*!
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones en su versión de tres variables (x,y,z)
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

//!  Definición de la clase Vector3D:  \f$ \vec{v} = (x_, y_, z_) = x_ \vec{i} + y_ \vec{j} + z_ \vec{k} \f$
class Vector3D{

//! \name Atributos privados de la clase Vector3D
   private:

	   double x_,y_,z_;

//! \name Funciones o métodos públicos de la clase Vector3D
   public:

//! \name Constructores de la clase Vector3D

/*!
    \fn        Vector3D();
    \brief     Constructor sin argumentos, inicializa cada una de las variables a cero
    \post      Comprueba que se ha asignado un cero a cada una de las componentes\n
               del vector con el siguiente código:
               assert((get1()<COTA_ERROR)\n
             					and (get2()<COTA_ERROR)\n
             					and (get3()<COTA_ERROR));

    \note      En la Postcondición se compara con la cota de error (COTA_ERROR - 1.0e-6)\n
               para aumentar la precisión del resultado. Será mas relevante en funciones\n
               posteriores
    \pre       -

*/
     Vector3D();


 /*!
     \fn        Vector3D(double const &x, double const &y, double const &z);
     \brief     Constructor parametrizado, inicializa cada una de las variables a \n
                las pasadas como parametro
     \param     double const &x → Referencia constante de tipo double (Real) que\n
                almacena el valor x del vector.
     \param     double const &y → Referencia constante de tipo double (Real) que\n
                almacena el valor y del vector.
     \param     double const &z → Referencia constante de tipo double (Real) que\n
                almacena el valor z del vector.
     \post      Comprueba que se ha asignado un correctamente las variables pasadas\n
                como parametro
                assert((std::abs((get1()-x)<COTA_ERROR))\n
              					and (std::abs((get2()-y)<COTA_ERROR))\n
              					and (std::abs((get3()-z)<COTA_ERROR)));

     \note      Para aumentar la precisión de la postcondición se resta el valor\n
                de la variable asignada con el valor pasado como parametro (el \n
                resultado de dicha resta sería en valor absoluto), y si este es \n
                menor que la cota de error (1.0e-6) se toma como correcta la \n
                postcondición.
     \pre       -

 */
     Vector3D(double const &x, double const &y, double const &z);


 /*!
    \fn        Vector3D(ed::Vector3D const &v);
    \brief     Constructor parametrizado, inicializa cada una de las variables a \n
                a cada una de las respectivas variables del vector pasado como \n
                argumento.
    \param     ed::Vector3D const &v → Referencia constante de tipo Vector3D\n
                que posee el valor de cada una de las componentes del vector
    \note      El tipo Vector3D pertenece al espacio de nombre "ed"
    \post      Comprueba que se ha asignado un correctamente las variables pasadas\n
                como parametro
                assert((std::abs(get1()-v.get1())<COTA_ERROR)
              					and (std::abs(get2()-v.get2())<COTA_ERROR)
              					and (std::abs(get3()-v.get3())<COTA_ERROR));
    \note      Para aumentar la precisión de la postcondición se resta el valor\n
               de la variable asignada con el valor pasado como parametro (el \n
               resultado de dicha resta sería en valor absoluto), y si este es \n
               menor que la cota de error (1.0e-6) se toma como correcta la \n
               postcondición.
     \pre       -

 */
     Vector3D(ed::Vector3D const &v);


//! \name Observadores: funciones de consulta de Vector3D


/*!
    \fn        double  get1()const;
    \brief     Observador de la componente x del vector
    \note      Al ser observador se declara como const
    \pre       -
    \return   retorna le valor de la componente x del vector, de tipo double (Real)

*/
     double  get1()const;
     double  get2()const;
     double  get3()const;

     double modulo()const;
     double angulo(ed::Vector3D const &v)const;

     double alfa()const;
     double beta()const;
     double gamma()const;

     double dotProduct(Vector3D const &v)const;
     Vector3D crossProduct(Vector3D const &v)const;
     double productoMixto(Vector3D const &v,Vector3D const &w)const;

  //! \name Modificadores: funciones de modificación de Vector3D

     void set1(double const &x);
     void set2(double const &y);
     void set3(double const &z);

  // Operaciones de modificación para todas las componentes del vector

     void sumConst(double const &k);
     void sumVect(ed::Vector3D const &v);
     void multConst(double const &k);
     void multVect(ed::Vector3D const &v);

  //! \name Funciones lectura y escritura de la clase Vector3D

     void leerVector3D();
     void escribirVector3D()const;

  //! \name Operadores de la clase

     bool operator == (Vector3D const &v)const;
     Vector3D & operator=(Vector3D const &v);
     Vector3D operator+(Vector3D const &v)const;
     Vector3D operator+()const;
     Vector3D operator-(Vector3D const &v)const;
     Vector3D operator-()const;
     Vector3D operator*(double const &k)const;
     double operator*(Vector3D const &v)const;
     Vector3D operator^(Vector3D const &v)const;

}; // Fin de la definición de la clase Vector3D

//////////////////////////////////////////////////////////////////////////////////////

//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D


   Vector3D & operator* (double k, Vector3D const & objeto);
   istream &operator>>(istream &stream, Vector3D &objeto);
	 ostream &operator<<(ostream &stream, Vector3D const &objeto);


} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif
