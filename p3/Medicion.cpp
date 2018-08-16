/*!
   \file  Medicion.cpp
   \brief Fichero que contiene el código de las funciones de la clase Medicion
*/


// Ficheros de cabecera
#include <iostream>
// atoi, atof
#include <stdlib.h>
#include "Medicion.hpp"


////////////////////////////////////////////////////////////////////////////////

void ed::Medicion::leerMedicion(){

  ed::Fecha fecha(0,0,0);
  int dia = 0, mes = 0, agno = 0;
  double precipitacion = 0.0;

  std::cout << "Dia: ";
  std::cin >> dia;
  std::cout << "Mes: ";
  std::cin >> mes;
  std::cout << "Año: ";
  std::cin >> agno;
  std::cout << "Precipitacion: ";
  std::cin >> precipitacion;


  fecha.setDia(dia);
  fecha.setMes(mes);
  fecha.setAgno(agno);
  setPrecipitacion(precipitacion);

  return;

}

void ed::Medicion::escribirMedicion(){

  std::cout << "\n" << getFecha() << " " << getPrecipitacion() << std::endl;

  return;

}

ostream & ed::Medicion::operator << (ostream &o, ed::Medicion const & m){

  o << m.getFecha();
  o << " ";
  o << m.getPrecipitacion();
  o << "\n";

  return o;
}

ostream & ed::Medicion::operator << (ostream &o, ed::Medicion const & m);




// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{

// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, ed::Medicion const &medicion)
{
  // COMPLETAR

  return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Medicion &medicion)
{
 // COMPLETAR

  return stream;
}

} // Fin del espacio de nombres ed
