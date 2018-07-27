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

//!  Definición de la clase Vector3D 
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
                almacena el valor X del vector.

     \param     double const &y → Referencia constante de tipo double (Real) que\n
                almacena el valor Y del vector.

     \param     double const &z → Referencia constante de tipo double (Real) que\n
                almacena el valor Z del vector.

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

    \brief     Observador de la componente X del vector

    \note      Observador declarado como const

    \pre       -

    \return    Devuelve el valor de la componente X del vector, de tipo double (Real)

*/
     double  get1()const;

/*!

     \fn        double  get2()const;

     \brief     Observador de la componente Y del vector

     \note      Observador declarado como const

     \pre       -

     \return    Devuelve el valor de la componente Y del vector, de tipo double (Real)

*/
     double  get2()const;

/*!
     \fn        double  get3()const;

     \brief     Observador de la componente Z del vector

     \note      Observador declarado como const

     \pre       -

     \return    Devuelve el valor de la componente Z del vector, de tipo double (Real)

*/
     double  get3()const;


/*!
     \fn        double modulo()const;

     \brief     Observador del modulo del vector, que posee la siguiente formula:\n
                sqrt(v1*v1+v2*v2+v3*v3).

     \note      Observador declarado como const.

     \pre       -

     \return    Devuelve el valor del módulo del vector en cuestión.

*/
     double modulo()const;



/*!
     \fn        double angulo(ed::Vector3D const &v)const;

     \brief     Observador del angulo del vector, que posee la siguiente formula:\n
                sqrt(v1*v1+v2*v2+v3*v3)

     \note      Observador declarado como const

     \param     ed::Vector3D const &v → Referencia constante de tipo Vector3D\n
                que posee el valor de cada una de las componentes del vector.\n
                perteneciente al espacio de nombres ed

     \pre       *

     \note      *Se podría definir como complemento a la postcondición la\n
                la estructura de control if(angulo < -1) && if(angulo > 1) ya que\n
                el valor del angulo debe de estar entre [-1,1]. En caso de que supere\n
                por alguno de los dos extremos, se asigna el extremo.

     \post      Se realiza la diferencia entre valorDevuelto (angulo) y la \n
                operación acos(dotProduct(v)/(modulo())*(v.modulo())). Si el\n
                resultado en valor absoluto es menor que la COTA_ERROR, se tomará\n
                como verdadero la condición del aserto.

     \return    Devuelve el angulo que forma el vector en cuestión con el que se\n
                le ha pasado por Referencia. De tipo double (Real).

*/
     double angulo(ed::Vector3D const &v)const;


/*!
     \fn        double alfa()const;

     \brief     Observador del angulo que forma el vector en cuestión y el vector\n
                alfa, el cual solamente tiene componentes en X → (1,0,0) Siendo\n
                la operación angulo(Vector3D(1,0,0))

     \note      Observador declarado como const

     \pre       El módulo debe de ser mayor que 0: assert(modulo()>0);

     \post      La diferencia entre valorDevuelto y angulo(Vector3D(1,0,0))) en\n
                valor absoluto debe de ser menor que la COTA_ERROR para que la\n
                condición del aserto sea cierta

     \return    Devuelve el angulo que forma el vector en cuestión con el vector\n
                alfa (1,0,0). De tipo double (Real).

*/
     double alfa()const;


/*!
     \fn        double beta()const;

     \brief     Observador del angulo que forma el vector en cuestión y el vector\n
                beta, el cual solamente tiene componentes en Y → (0,1,0) Siendo\n
                la operación angulo(Vector3D(0,1,0))

     \note      Observador declarado como const

     \pre       El módulo debe de ser mayor que 0: assert(modulo()>0);

     \post      La diferencia entre valorDevuelto y angulo(Vector3D(0,1,0))) en\n
                valor absoluto debe de ser menor que la COTA_ERROR para que la\n
                condición del aserto sea cierta

     \return    Devuelve el angulo que forma el vector en cuestión con el vector\n
                beta (0,1,0). De tipo double (Real).

*/
     double beta()const;

/*!
     \fn        double gamma()const;

     \brief     Observador del angulo que forma el vector en cuestión y el vector\n
                gamma, el cual solamente tiene componentes en Z → (0,0,1). Siendo\n
                la operación angulo(Vector3D(0,0,1))

     \note      Observador declarado como const

     \pre       El módulo debe de ser mayor que 0: assert(modulo()>0);

     \post      La diferencia entre valorDevuelto y angulo(Vector3D(0,0,1))) en\n
                valor absoluto debe de ser menor que la COTA_ERROR para que la\n
                condición del aserto sea cierta

     \return    Devuelve el angulo que forma el vector en cuestión con el vector\n
                gamma (0,0,1). De tipo double (Real).

*/
     double gamma()const;



/*!
     \fn        double dotProduct(Vector3D const &v)const;

     \brief     Observador del producto escalar del vector actual y el vector\n
                pasado como parametro (v). La operación es (get1()*v.get1()+ \n
                get2()*v.get2() + get3()*v.get3())

     \note      Observador declarado como const

     \param     ed::Vector3D const &v → Referencia constante de tipo Vector3D\n
                que posee el valor de cada una de las componentes del vector.\n
                perteneciente al espacio de nombres ed

     \post      La diferencia entre el valor devuelto (pdtoEscalar) y la \n
                operación get1()*v.get1()+get2()*v.get2()+get3()*v.get3() debe \n
                debe ser menor que la COTA_ERROR, para que la condición del aserto\n

     \return    Devuelve el angulo que forma el vector en cuestión con el que se\n
                le ha pasado por Referencia. De tipo double (Real).

*/
     double dotProduct(Vector3D const &v)const;



/*!
     \fn        Vector3D crossProduct(Vector3D const &v)const;

     \brief     Observador del producto vectorial del vector actual y el vector\n
                pasado como parametro (v). La operación es\n
                     w.set1(get2()*v.get3()-get3()*v.get2());\n
                	   w.set2(-get1()*v.get3()+get3()*v.get1());\n
                	   w.set3(get1()*v.get2()-get2()*v.get1());

     \note      Observador declarado como const

     \param     ed::Vector3D const &v → Referencia constante de tipo Vector3D\n
                que posee el valor de cada una de las componentes del vector.\n
                perteneciente al espacio de nombres ed

     \post      El producto escalar del vector actual con el vector W (valorDevuelto) \n
                debe de ser 0 (o menor que la COTA_ERROR).

     \post      El producto escalar del vector v (pasado por parámetro) con el vector\n
                W (valorDevuelto) debe ser igual a 0 (o menor que la COTA_ERROR).

     \note      La primera y segunda postcondición se comprueba que W es perpendicular\n
                a los vectores U y V

   	 \post      La diferencia entre valorDevuelto.modulo() y el producto de modulo(),\n
                v.modulo() y sin(angulo(v)) debe de ser menor que la COTA_ERROR.

     \return    Devuelve un vector de tipo Vector3D que es el resultado del producto\n
                vectorial de dos vectores.


*/
     Vector3D crossProduct(Vector3D const &v)const;


/*!
     \fn        double productoMixto(Vector3D const &v,Vector3D const &w)const;

     \brief     Observador del producto escalar del vector actual con el vector\n
                obtenido al calcular el producto vectorial de otros dos vectores\n
                con la siguiente formula → (u*(v^w))

     \note      Observador declarado como const

     \param     ed::Vector3D const &v → Referencia constante de tipo Vector3D\n
                que posee el valor de cada una de las componentes del vector.\n
                perteneciente al espacio de nombres ed

    \param      ed::Vector3D const &w → Referencia constante de tipo Vector3D\n
                que posee el valor de cada una de las componentes del vector.\n
                perteneciente al espacio de nombres ed

     \post      Comprueba que el valor de pdtoMixto menos el producto vectorial\n
                de V con W sea menor que la COTA_ERROR. Condición que dará como \n
                cierta la condición del aserto. Con el siguiente fragmento \n
                de código → pdtoMixto-dotProduct(v.crossProduct(w)

     \return    Devuelve el resultado de calcular el producto escalar del vector\n
                actual con el vector obtenido al calcular el producto vectorial\n
                de otros dos vectores.


*/
     double productoMixto(Vector3D const &v,Vector3D const &w)const;

//! \name Modificadores: funciones de modificación de Vector3D

/*!
      \fn        void set1(double const &x);

      \brief     Modificador de la componente X del vector → X_ = x

      \param     double const &x → Referencia constante de la componente X del vector.

      \post      Se comprueba que el valor asignado a X_ es el mismo que el valor\n
                 pasado como parámetro. El valor absoluto de la diferencia entre\n
                 el valor retornado por el observador y el pasado por parámetro\n
                 debe de ser menor que la COTA_ERROR para cumplir la condición del \n
                 aserto.

      \return    void


*/
     void set1(double const &x);

/*!
     \fn        void set2(double const &y);

     \brief     Modificador de la componente Y del vector → Y_ = y

     \param     double const &y → Referencia constante de la componente Y del vector.

     \post      Se comprueba que el valor asignado a Y_ es el mismo que el valor\n
                pasado como parámetro. El valor absoluto de la diferencia entre\n
                el valor retornado por el observador y el pasado por parámetro\n
                debe de ser menor que la COTA_ERROR para cumplir la condición del \n
                aserto.

     \return    void


*/
     void set2(double const &y);



/*!
     \fn        void set3(double const &z);

     \brief     Modificador de la componente Z del vector → Z_ = z

     \param     double const &z → Referencia constante de la componente Z del vector.

     \post      Se comprueba que el valor asignado a Z_ es el mismo que el valor\n
                pasado como parámetro. El valor absoluto de la diferencia entre\n
                el valor retornado por el observador y el pasado por parámetro\n
                debe de ser menor que la COTA_ERROR para cumplir la condición del \n
                aserto.

     \return    void


*/
     void set3(double const &z);

  // Operaciones de modificación para todas las componentes del vector


/*!
      \fn        void sumConst(double const &k);

      \brief     Modifica el vector sumando una constante a cada componente

      \param     double const &k → Referencia constante de una constante K

      \post      Comprueba el valor actual del vector con el anterior mas \n
                 el de la constante K. En este caso se resta el valor anterior\n
                 mas la constante K, al valor actual quedando un valor que ha de\n
                 ser menor que la COTA_ERROR.

      \return    void


*/
     void sumConst(double const &k);


/*!
     \fn        void sumVect(ed::Vector3D const &v);

     \brief     Modifica el vector sumando un vector componente a componente

     \param     ed::Vector3D const &v → Referencia constante de un vector V de tipo\n
                Vector3D

     \post      Comprueba el valor actual del vector con el anterior mas \n
                el de la vector V. En este caso se resta el valor anterior\n
                mas el del vector V, al valor actual quedando un valor que ha de\n
                ser menor que la COTA_ERROR.

     \return    void


*/
     void sumVect(ed::Vector3D const &v);



/*!
     \fn        void multConst(double const &k);

     \brief     Modifica el vector multiplicando una constante a cada componente

     \param     double const &k → Referencia constante de una constante K

     \post      Comprueba el valor actual del vector con el anterior mas \n
                el de la constante K. En este caso se resta el valor anterior\n
                mas la constante K, al valor actual quedando un valor que ha de\n
                ser menor que la COTA_ERROR.

     \return    void


*/
     void multConst(double const &k);



/*!
     \fn        void multVect(ed::Vector3D const &v);

     \brief     Modifica el vector sumando un vector componente a componente

     \param     ed::Vector3D const &v → Referencia constante de un vector V de tipo\n
                Vector3D

     \post      Comprueba el valor actual del vector con el anterior mas \n
                el de la vector v. En este caso se resta el valor anterior\n
                mas el del vector V, al valor actual quedando un valor que ha de\n
                ser menor que la COTA_ERROR.

     \return    void


*/
     void multVect(ed::Vector3D const &v);

  //! \name Funciones lectura y escritura de la clase Vector3D


/*!
      \fn        void leerVector3D();
      \brief     Lee desde teclado las componentes del vector
      \return    void


*/
     void leerVector3D();



/*!
       \fn        void escribirVector3D()const;
       \note      Método declarado const
       \brief     Muestra por pantalla las componentes del vector con el formato\n
                  (x,y,z)
       \return    void

*/
     void escribirVector3D()const;

//! \name Operadores de la clase


/*!
    \fn        bool operator == (Vector3D const &v)const;
    \brief     Comprueba si el vector actual y el vector V son iguales
    \param     Vector3D const &v → Referencia constante de tipo Vector3D
    \post      Se comprueba que las componentes sean iguales una a una
    \return    TRUE en caso de que sean iguales FALSE en caso contrario

*/
     bool operator == (Vector3D const &v)const;


/*!
     \fn        Vector3D & operator=(Vector3D const &v);
     \brief     Asigna el vector V al vector actual
     \param     Vector3D const &v → Referencia constante de tipo Vector3D
     \post      Se comprueba que el valor actual coincide con el del vector pasado \n
                como parametro
     \return    Puntero al vector actual (*this)

*/
     Vector3D & operator=(Vector3D const &v);



/*!
     \fn        Vector3D operator+(Vector3D const &v)const;
     \brief     Suma el vector V al vector actual
     \param     Vector3D const &v → Referencia constante de tipo Vector3D
     \note      Método declarado como const
     \post      Se comprueba que el valor actual de la componente es igual a la\n
                suma de la componente anterior mas la componente del vector\n
                pasado como parámetro.
     \return    Vector resultante de la suma del vector actual y el pasado \n
                como parametro

*/
     Vector3D operator+(Vector3D const &v)const;



/*!
     \fn        Vector3D operator+()const;
     \brief     Devuelve otro vector que es una copia del vector actual
     \note      Método declarado como const
     \post      Se comprueba que coincidan el valor del get() con el valor de las\n
                componentes del vectorCopia. Esta acción se realiza con la resta\n
                de ambas componentes y comprobando que sea menor que COTA_ERROR.
     \return    Devuelve otro vector que es una copia del vector actual

*/
     Vector3D operator+()const;

/*!
     \fn        Vector3D operator-(Vector3D const &v)const;
     \brief     Resta el vector V al vector actual
     \param     Vector3D const &v → Referencia constante de tipo Vector3D
     \note      Método declarado como const
     \post      Se comprueba que el valor actual de la componente es igual a la\n
                resta de la componente anterior mas la componente del vector\n
                pasado como parámetro.
     \return    Vector resultante de la resta del vector actual y el pasado \n
                como parametro

 */
     Vector3D operator-(Vector3D const &v)const;

 /*!
     \fn        Vector3D operator-()const;
     \brief     Devuelve otro vector que es una copia del vector actual pero con\n
                signo negativo
     \note      Método declarado como const
     \post      Se comprueba que coincidan el valor del get() con el valor de las\n
                componentes del vectorCopia. Esta acción se realiza con la suma\n
                de ambas componentes y comprobando que sea menor que COTA_ERROR.
     \return    Devuelve otro vector multiplicadas por -1 cada una de las componentes.

 */
     Vector3D operator-()const;

/*!
     \fn        Vector3D operator*(double const &k)const;
     \brief     Se multiplican las componentes del vector por una constante K
     \note      Método declarado como const
     \param     double const &k → Referencia constante de una constante K
     \post      Se comprueba que el valor actual menos el valor anterior multiplicado\n
                por K sea menor que COTA_ERROR
     \return    Devuelve otro vector multiplicadas por K cada una de las componentes.

 */
     Vector3D operator*(double const &k)const;


 /*!
     \fn        Vector3D operator*(Vector3D const &v)const;
     \brief     Prodcuto escalar del vector actual y el pasado como parámetro
     \note      Método declarado como const
     \param     Vector3D const &v → Referencia constante de tipo Vector3D
     \post      Se comprueba que el valor actual menos el producto escalar\n
                es menor que COTA_ERROR
     \return    Devuelve otro vector multiplicadas por K cada una de las componentes.

 */
     double operator*(Vector3D const &v)const;


 /*!
     \fn        Vector3D operator^(Vector3D const &v)const;
     \brief     Se realiza el producto vectorial del vector actual y el vector \n
                pasado por parametro.
     \note      Método declarado como const
     \param     Vector3D const &v → Referencia constante de tipo Vector3D
     \post      El producto escalar del vector actual con el vector W (valorDevuelto) \n
                debe de ser 0 (o menor que la COTA_ERROR).
     \post      El producto escalar del vector v (pasado por parámetro) con el vector\n
                W (valorDevuelto) debe ser igual a 0 (o menor que la COTA_ERROR).
     \note      La primera y segunda postcondición se comprueba que W es perpendicular\n
                a los vectores U y V
   	 \post      La diferencia entre valorDevuelto.modulo() y el producto de modulo(),\n
                v.modulo() y sin(angulo(v)) debe de ser menor que la COTA_ERROR.
     \return    Devuelve un vector de tipo Vector3D que es el resultado del \n
                producto vectorial de dos vectores

 */
     Vector3D operator^(Vector3D const &v)const;

}; // Fin de la definición de la clase Vector3D

//////////////////////////////////////////////////////////////////////////////////////

//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

/*!
    \fn        Vector3D & operator* (double k, Vector3D const &v);
    \brief     Multiplica las componentes del vector V por la constante K
               pasado por parametro.
    \note      Método declarado como const
    \param     double k → Constante K, de tipo double (Real)
    \param     Vector3D const &v → Referencia constante de tipo Vector3D
    \post      Se comprueba que el valor actual menos el producto del anterior \n
               por la constante K debe ser menor que COTA_ERROR
    \return    Devuelve otro vector cuyas componentes se obtienen multiplicando\n
               por K las componentes del vector V pasado como parámetro

*/
   Vector3D & operator* (double k, Vector3D const & objeto);


 /*!
     \fn        istream &operator>>(istream &stream, Vector3D &objeto);
     \brief     Lee desde el flujo de entrada las componentes del vector “v” separadas por espacios
     \param     istream &stream → Flujo de entrada, de tipo istram
     \param     Vector3D &objeto → Vector, de tipo Vector3D
     \return    Flujo de entrada

 */
   istream &operator>>(istream &stream, Vector3D &objeto);


 /*!
     \fn        ostream &operator<<(ostream &stream, Vector3D const &objeto);
     \brief     Escribe en el flujo de salida las componentes del vector “v” \n
                con el formato (x,y,z)
     \param     ostream &stream → Flujo de salida, de tipo ostream
     \param     Vector3D const &objeto → Vector, de tipo Vector3D
     \return    Flujo de entrada

 */
	 ostream &operator<<(ostream &stream, Vector3D const &objeto);


} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif
