/*!
   \file Vector3D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vector3D
*/

#include <iostream> // Ficheros de cabecera
#include <cmath>		// Para usar sqrt, acos
#include <cassert>	// Para controlar las pre y post condiciones mediante asertos
#include "Vector3D.hpp"

////////////////////////////////////////////////////////////////
// CONSTRUCTORES

ed::Vector3D::Vector3D(){
	set1(0);
	set2(0);
	set3(0);
	assert((get1()<COTA_ERROR)
					and (get2()<COTA_ERROR)
					and (get3()<COTA_ERROR));

}

ed::Vector3D::Vector3D(double const &x, double const &y, double const &z){
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

////////////////////////////////////////////////////////////////
// OBSERVADORES
// Operaciones de consulta de cada una de las componentes del vector

double  ed::Vector3D::get1()const{
	return x_;
}

double  ed::Vector3D::get2()const{
	return y_;
}

double  ed::Vector3D::get3()const{
	return z_;
}

// Modulo ////////////////////////////////////////////////////////////////////

double ed::Vector3D::modulo()const{

	double modulo = std::sqrt(get1()*get1() + get2()*get2() + get3()*get3());
	assert(std::abs(modulo-sqrt(get1()*get1()
												+ get2()*get2()
												+ get3()*get3()))<COTA_ERROR);

	return modulo;

}

// Angulos ////////////////////////////////////////////////////////////////////

double ed::Vector3D::angulo(ed::Vector3D const &v)const{

	assert(modulo() * v.modulo() > 0);

	double angulo = acos(dotProduct(v)/(modulo())*(v.modulo()));

	if(angulo > 1){
		angulo = 1;
	}
	if(angulo < -1){
		angulo = -1;
	}
	if((angulo > -1)and(angulo < 1)){
		assert(std::abs(angulo - acos(dotProduct(v)/(modulo())*(v.modulo())))<COTA_ERROR);
	}

	return angulo;

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

// Pdto escalar ////////////////////////////////////////////////////////////////

double ed::Vector3D::dotProduct(ed::Vector3D const &v)const{

	double pdtoEscalar = get1()*v.get1() + get2()*v.get2() + get3()*v.get3();

	assert(std::abs(pdtoEscalar-(get1()*v.get1()
								+ get2()*v.get2()
								+ get3()*v.get3()))<COTA_ERROR);

	return pdtoEscalar;

}

// Pdto vectorial //////////////////////////////////////////////////////////////

ed::Vector3D ed::Vector3D::crossProduct(ed::Vector3D const &v)const{

	ed::Vector3D w = Vector3D(0,0,0);

	w.set1(get2()*v.get3()-get3()*v.get2());
	w.set2(-get1()*v.get3()+get3()*v.get1());
	w.set3(get1()*v.get2()-get2()*v.get1());

	assert(dotProduct(w) == 0);
	assert(v.dotProduct(w) == 0);
	assert(std::abs(w.modulo()-modulo()*v.modulo()*std::sin(angulo(v)))<COTA_ERROR);

	return w;

}

// Pdto mixto //////////////////////////////////////////////////////////////////

double ed::Vector3D::productoMixto(Vector3D const &v,Vector3D const &w)const{

	double pdtoMixto = dotProduct(v.crossProduct(w));
	assert(std::abs(pdtoMixto-dotProduct(v.crossProduct(w)))<COTA_ERROR);
	return pdtoMixto;

}

////////////////////////////////////////////////////////////////
// MODIFICADORES
// Operaciones de modificación de cada una de las componentes del vector

void ed::Vector3D::set1(double const &x){
	x_=x;
	assert((std::abs(get1()-x)<COTA_ERROR));
}

void ed::Vector3D::set2(double const &y){
	y_=y;
	assert((std::abs(get2()-y)<COTA_ERROR));
}

void ed::Vector3D::set3(double const &z){
	z_=z;
	assert((std::abs(get3()-z)<COTA_ERROR));
}

////////////////////////////////////////////////////////////////////////////////
// FUNCIONES DE MODIFICACION
// Operaciones de modificación de todas las componentes del vector

void ed::Vector3D::sumConst(double const &k){

	Vector3D old(get1(),get2(),get3());

	 set1(get1()+k);
	 set2(get2()+k);
	 set3(get3()+k);

	 assert((std::abs(get1() - (old.get1() + k)) < COTA_ERROR)
	 			and (std::abs(get2() - (old.get2() + k)) < COTA_ERROR)
 	 			and (std::abs(get3() - (old.get3() + k)) < COTA_ERROR));

}

void ed::Vector3D::sumVect(ed::Vector3D const &v){

	Vector3D old(get1(),get2(),get3());

	set1(get1()+v.get1());
	set2(get2()+v.get2());
	set3(get3()+v.get3());

	assert((std::abs(get1()-(old.get1()+v.get1()))<COTA_ERROR)
				and (std::abs(get1()-(old.get1()+v.get1()))<COTA_ERROR)
				and (std::abs(get1()-(old.get1()+v.get1()))<COTA_ERROR));

}


void ed::Vector3D::multConst(double const &k){

	Vector3D old(get1(),get2(),get3());

	 set1(get1()*k);
	 set2(get2()*k);
	 set3(get3()*k);

	 assert((std::abs(get1() - old.get1() * k) < COTA_ERROR)
				and (std::abs(get2() - old.get2() * k) < COTA_ERROR)
				and (std::abs(get3() - old.get3() * k) < COTA_ERROR));

}


void ed::Vector3D::multVect(ed::Vector3D const &v){

	Vector3D old(get1(),get2(),get3());

	set1(get1()*v.get1());
	set2(get2()*v.get2());
	set3(get3()*v.get3());

	assert((std::abs(get1()-old.get1()*v.get1())<COTA_ERROR)
				and (std::abs(get1()-old.get1()*v.get1())<COTA_ERROR)
				and (std::abs(get1()-old.get1()*v.get1())<COTA_ERROR));

}

////////////////////////////////////////////////////////////////////////////////
// FUNCIONES DE LECTURA Y ESCRITURA

void ed::Vector3D::leerVector3D(){

	double x=0.0,y=0.0,z=0.0;

	std::cout << "\nX → ";
	std::cin >> x;
	set1(x);

	std::cout << "\nY → ";
	std::cin >> y;
	set2(y);

	std::cout << "\nZ → ";
	std::cin >> z;
	set3(z);

}

void ed::Vector3D::escribirVector3D()const{

	std::cout << "(" << this->get1() << ","<< this->get2() << "," << this->get3()<< ")" << std::endl;

}

////////////////////////////////////////////////////////////////////////////////
// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{

// Operador de igualdad == / true == → false !=
bool Vector3D::operator == (ed::Vector3D const &v) const{

	if((std::abs(get1()-v.get1())<COTA_ERROR)
			and (std::abs(get2()-v.get2())<COTA_ERROR)
			and (std::abs(get3()-v.get3())<COTA_ERROR)){

		return true;

	}else{

		return false;

	}
}


// Operador de asignacion = / Asigna B → A
Vector3D & Vector3D::operator=(Vector3D const &v){

	if(this != &v){
		set1(v.get1());
		set2(v.get2());
		set3(v.get3());

		assert(this->get1()==v.get1()
				and this->get2()==v.get2()
				and this->get3()==v.get3());
	}

	return *this;

}

Vector3D Vector3D::operator+(Vector3D const &v)const{

	Vector3D vectorSuma(0,0,0);

	vectorSuma.set1(get1()+v.get1());
	vectorSuma.set2(get2()+v.get2());
	vectorSuma.set3(get3()+v.get3());

	assert((std::abs(vectorSuma.get1()-get1()-v.get1()) < COTA_ERROR)
				and (std::abs(vectorSuma.get2()-get2()-v.get2()) < COTA_ERROR)
				and (std::abs(vectorSuma.get3()-get3()-v.get3()) < COTA_ERROR));

	return vectorSuma;

}

Vector3D Vector3D::operator+()const{

	Vector3D vectorCopia(get1(),get2(),get3());

	assert((std::abs(vectorCopia.get1()-get1()) < COTA_ERROR)
		and (std::abs(vectorCopia.get2()-get2()) < COTA_ERROR)
		and (std::abs(vectorCopia.get3()-get3()) < COTA_ERROR));

		return vectorCopia;

}

Vector3D Vector3D::operator-(Vector3D const &v)const{

	Vector3D vectorSuma(0,0,0);

	vectorSuma.set1(get1()-v.get1());
	vectorSuma.set2(get2()-v.get2());
	vectorSuma.set3(get3()-v.get3());

	assert(((std::abs((vectorSuma.get1()+v.get1())-get1())) < COTA_ERROR)
				and ((std::abs((vectorSuma.get2()+v.get2())-get2())) < COTA_ERROR)
				and ((std::abs((vectorSuma.get3()+v.get3())-get3())) < COTA_ERROR));

	return vectorSuma;

}

Vector3D Vector3D::operator-()const{

	Vector3D vectorCopia(-get1(),-get2(),-get3());

	assert((std::abs(vectorCopia.get1()+get1()) < COTA_ERROR)
		and (std::abs(vectorCopia.get2()+get2()) < COTA_ERROR)
		and (std::abs(vectorCopia.get3()+get3()) < COTA_ERROR));

		return vectorCopia;

}

Vector3D Vector3D::operator*(double const &k)const{

	Vector3D v(get1()*k,get2()*k,get3()*k);

	assert((std::abs(v.get1()-(get1()*k))<COTA_ERROR)
	and (std::abs(v.get1()-(get1()*k))<COTA_ERROR)
	and (std::abs(v.get1()-(get1()*k))<COTA_ERROR));

	return v;

}

double Vector3D::operator*(Vector3D const &v)const{

	double valorDevuelto = (get1()*v.get1()+get2()*v.get2()+get3()*v.get3());
	assert((valorDevuelto-(get1()*v.get1()+get2()*v.get2()+get3()*v.get3()))<COTA_ERROR);
	return valorDevuelto;
}

// Producto vectorial de dos vector.
Vector3D Vector3D::operator ^(Vector3D const &v)const{

	Vector3D w(get2()*v.get3()-get3()*v.get2(),
							-get1()*v.get3()+get3()*v.get1(),
							get1()*v.get2()-get2()*v.get1());

	assert(dotProduct(w) == 0);
	assert(v.dotProduct(w) == 0);
	assert((w.modulo() - (modulo()*v.modulo()*std::sin(angulo(v))))<COTA_ERROR);

	return w;

}


// FUNCIONES EXTERNAS //////////////////////////////////////////////
// Producto "por un" escalar (prefijo): k * v
Vector3D & operator*(double k, Vector3D const & v){

	Vector3D * vectorResultado = new ed::Vector3D();

	vectorResultado->set1(k*v.get1());
	vectorResultado->set2(k*v.get2());
	vectorResultado->set3(k*v.get3());

	return *vectorResultado;
}

// Sobrecarga del operador de salida
// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
ostream &operator<<(ostream &o, Vector3D const &v){

	o << "(" << v.get1() <<","<< v.get2()<< "," <<v.get3()<< ")";

  return o;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &i, Vector3D &v){

	double v1,v2,v3;

	std::cout << "Introduzca los valores para (a,b,c): ";
	i >> v1 >> v2 >> v3;
	i.ignore();

	v.set1(v1);
	v.set2(v2);
	v.set3(v3);

  return i;
}

} // Fin del espacio de nombres ed
