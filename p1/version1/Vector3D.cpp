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


ed::Vector3D::Vector3D(){
	set1(0);
	set2(0);
	set3(0);
	assert((get1()<COTA_ERROR)
					and (get2()<COTA_ERROR)
					and (get3()<COTA_ERROR));

}

ed::Vector3D::Vector3D(double x, double y, double z){
	set1(x);
	set2(y);
	set3(z);
	assert((std::abs((get1()-x)<COTA_ERROR))
					and (std::abs((get2()-y)<COTA_ERROR))
					and (std::abs((get3()-z)<COTA_ERROR)));
}

ed::Vector3D::Vector3D(ed::Vector3D const &v){
	set1(v.get1());
	set2(v.get2());
	set3(v.get3());

	assert((std::abs(get1()-v.get1())<COTA_ERROR)
					and (std::abs(get2()-v.get2())<COTA_ERROR)
					and (std::abs(get3()-v.get3())<COTA_ERROR));

}

// MODIFICADORES

void ed::Vector3D::set1(double x){
	x_=x;
	assert((std::abs(get1()-x)<COTA_ERROR));
}

void ed::Vector3D::set2(double y){
	y_=y;
	assert((std::abs(get2()-y)<COTA_ERROR));
}

void ed::Vector3D::set3(double z){
	z_=z;
	assert((std::abs(get3()-z)<COTA_ERROR));
}

////////////////////////////////////////////////////////////////

// OBSERVADORES

double  ed::Vector3D::get1()const{
	return x_;
}

double  ed::Vector3D::get2()const{
	return y_;
}

double  ed::Vector3D::get3()const{
	return z_;
}

double ed::Vector3D::modulo()const{

	double modulo = sqrt(get1()*get1() + get2()*get2() + get3()*get3());
	assert(std::abs(modulo-sqrt(get1()*get1()
												+ get2()*get2()
												+ get3()*get3()))<COTA_ERROR);

	return modulo;

}

double ed::Vector3D::angulo(ed::Vector3D const &v)const{

	assert(modulo() * v.modulo() > 0);

	double angulo = acos(dotProduct(v)/(modulo())*(v.modulo()));

	assert(std::abs(angulo - acos(dotProduct(v)/(modulo())*(v.modulo())))<COTA_ERROR);

	return angulo;

}

double ed::Vector3D::dotProduct(ed::Vector3D const &v)const{

	double pdtoEscalar = get1()*v.get1() + get2()*v.get2() + get3()*v.get3();

	assert(std::abs(pdtoEscalar-(get1()*v.get1()
								+ get2()*v.get2()
								+ get3()*v.get3()))<COTA_ERROR);

	return pdtoEscalar;

}

double ed::Vector3D::alfa()const{

	assert(modulo()>0);

	double anguloAlfa = angulo(Vector3D(1,0,0));

	assert((anguloAlfa - angulo(Vector3D(1,0,0)))<COTA_ERROR);

	return anguloAlfa;

}

double ed::Vector3D::beta()const{

	assert(modulo()>0);

	double anguloBeta = angulo(Vector3D(0,1,0));

	assert((anguloBeta - angulo(Vector3D(0,1,0)))<COTA_ERROR);

	return anguloBeta;

}

double ed::Vector3D::gamma()const{

	assert(modulo()>0);

	double anguloGamma = angulo(Vector3D(0,0,1));

	assert((anguloGamma - angulo(Vector3D(0,0,1)))<COTA_ERROR);

	return anguloGamma;

}

ed::Vector3D ed::Vector3D::crossProduct(ed::Vector3D const &v)const{

	ed::Vector3D w = Vector3D(0,0,0);

	w.set1(get2()*v.get3()-get3()*v.get2());
	w.set2(-get1()*v.get3()+get3()*v.get1());
	w.set3(get1()*v.get2()-get2()*v.get1());

	assert(dotProduct(w) == 0);
	assert(dotProduct(v) == 0);
	assert(std::abs(w.modulo()-modulo()*v.modulo()*std::sin(angulo(v)))<COTA_ERROR);

	return w;

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
