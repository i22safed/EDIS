/*!
   \file Vector3D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vector3D
*/

// Ficheros de cabecera
#include <iostream>
// Para usar sqrt, acos
#include <cmath>
// Para controlar las pre y post condiciones mediante asertos
#include <cassert>
#include "Vector3D.hpp"

// Constructores

	// Por defecto
	ed::Vector3D::Vector3D(){

		set1(0);
		set2(0);
		set3(0);

		assert((get1() < COTA_ERROR)
					and(get2() < COTA_ERROR)
					and(get3() < COTA_ERROR));
	}

	ed::Vector3D::Vector3D(double v1, double v2, double v3){
		set1(v1);
		set2(v2);
		set3(v3);

		assert((std::abs(get1()-v1)<COTA_ERROR)
					and (std::abs(get2()-v2)<COTA_ERROR)
					and (std::abs(get3()-v3)<COTA_ERROR));

	}

	ed::Vector3D::Vector3D(ed::Vector3D const &v){

		set1(v.get1());
		set2(v.get2());
		set3(v.get3());

		assert((std::abs(get1()-v.get1())<COTA_ERROR)
					and (std::abs(get2()-v.get2())<COTA_ERROR)
					and (std::abs(get3()-v.get3())<COTA_ERROR));

	}


// OBSERVADORES

double ed::Vector3D::modulo(){

	double valorDevuelto = sqrt(get1()*get1()+get2()*get2()+get3()*get3());

	assert(std::abs(valorDevuelto - sqrt(get1()*get1()
									+get2()*get2()+get3()*get3())) < COTA_ERROR);

	return valorDevuelto;

}

double ed::Vector3D::angulo(Vector3D v){

	assert((modulo()*v.modulo())>0);

	double angulo = acos(dotProduct(v)/(modulo()*v.modulo()));

	assert(std::abs(angulo-acos(dotProduct(v)/(modulo()*v.modulo())))<COTA_ERROR);

	return angulo;

}

double ed::Vector3D::dotProduct(Vector3D const &v){

	double valorDevuelto = get1()*v.get1() + get2()*v.get2() + get3()*v.get3();

	assert(std::abs(valorDevuelto-(get1()*v.get1()+get2()*v.get2()+get3()*v.get3()))<COTA_ERROR);

	return valorDevuelto;

}


double ed::Vector3D::alfa(){

	ed::Vector3D alfa(1,0,0);
	assert(alfa.modulo()>0);

	double valorDevuelto = angulo(alfa);

	assert(std::abs(valorDevuelto - angulo(alfa))<COTA_ERROR);

	return valorDevuelto;

}

double ed::Vector3D::beta(){

	ed::Vector3D beta(0,1,0);
	assert(beta.modulo()>0);

	double valorDevuelto = angulo(beta);

	assert(std::abs(valorDevuelto - angulo(beta))<COTA_ERROR);

	return valorDevuelto;


}

double ed::Vector3D::gamma(){

	ed::Vector3D gamma(0,0,1);
	assert(gamma.modulo()>0);

	double valorDevuelto=angulo(gamma);

	assert(std::abs(valorDevuelto-angulo(gamma))<COTA_ERROR);

	return valorDevuelto;

}


////////////////////////////////////////////////////////////////

// MODIFICADORES


	void ed::Vector3D::set1(double v1){
		vector_[0] = v1;
		assert(((get1()-v1)<COTA_ERROR));
	}
  void ed::Vector3D::set2(double v2){
		vector_[1] = v2;
		assert(((get2()-v2)<COTA_ERROR));
	}

	void ed::Vector3D::set3(double v3){
		vector_[2] = v3;
		assert(((get3()-v3)<COTA_ERROR));
	}



////////////////////////////////////////////////////////////////////////////////

// OPERADORES

// COMPLETAR



////////////////////////////////////////////////////////////////////////////////

// FUNCIONES DE LECTURA Y ESCRITURA

// COMPLETAR


////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{


// Producto "por un" escalar (prefijo): k * v
ed::Vector3D & operator* (double k, ed::Vector3D const & objeto)
{
	ed::Vector3D *vectorResultado = new ed::Vector3D();

	// COMPLETAR

	return *vectorResultado;
}


// Sobrecarga del operador de salida
// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
ostream &operator<<(ostream &stream, ed::Vector3D const &objeto)
{
	// COMPLETAR

  return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Vector3D &objeto)
{
  // COMPLETAR

  return stream;
}

} // Fin del espacio de nombres ed
