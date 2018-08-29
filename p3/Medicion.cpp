/*!
   \file  Medicion.cpp
   \brief Fichero que contiene el código de las funciones de la clase Medicion
*/


// Ficheros de cabecera
#include <iostream>

// atoi, atof
#include <stdlib.h>

#include "Medicion.hpp"


// COMPLETAR


////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{

bool ed::Medicion::operator == (Medicion const &medicion) const{

  bool valorDevuelto = false;

  if(getFecha() == medicion.getFecha()){
    valorDevuelto = true;
  }else{
    valorDevuelto = false;
  }

  #ifndef NDEBUG
    assert(valorDevuelto == (getFecha() == medicion.getFecha()));
  #endif

  return valorDevuelto;

}

ed::Medicion ed::Medicion::operator = (Medicion const &medicion){

    ed::Medicion m;

    m.setFecha(medicion.getFecha());
    m.setPrecipitacion(medicion.getPrecipitacion());

    #ifndef NDEBUG
      assert(m.getFecha() == medicion.getFecha());
      assert(std::abs(m.getPrecipitacion() - medicion.getPrecipitacion()) < COTA_ERROR);
    #endif

    return m;

}

void ed::Medicion::leerMedicion(){

  double p;
  Fecha fecha;
  fecha.leerFecha();

  std::cout << "Precipitacion → ";
  std::cin >> p;

  setFecha(fecha);
  setPrecipitacion(p);
}

void ed::Medicion::escribirMedicion()const{

  std::cout << getFecha() << " "
            << getPrecipitacion() << std::endl;

}



// Sobrecarga del operador de salida
ostream &operator<<(ostream &o, ed::Medicion const &medicion){

  o << medicion.getFecha();
  o << " ";
  o << medicion.getPrecipitacion();
  o << "\n";

  return o;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &i, ed::Medicion &medicion){

  std::string cadena;
  Fecha f;

  std::getline(i,cadena,'-');
  f.setDia(atoi(cadena.c_str()));
  std::getline(i,cadena,'-');
  f.setMes(atoi(cadena.c_str()));
  std::getline(i,cadena,'-');
  f.setAgno(atoi(cadena.c_str()));

  medicion.setFecha(f);

  std::getline(i,cadena,'\n');

  medicion.setPrecipitacion(atof(cadena.c_str())); // Cast a dato tipo real

  return i;
}

} // Fin del espacio de nombres ed
