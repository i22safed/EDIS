/*!
	\file MonticuloMediciones.cpp
	\brief Fichero que contiene el código de las funciones de la clase MonticuloMediciones.
	\author
	\date
*/

//#include <vector>

#include <cassert>

#include "Medicion.hpp"

#include "MonticuloMediciones.hpp"

////////////////////////////////////////////////////////////////////

// Métodos privados de la clase MonticuloMediciones
		int ed::Medicion::getLeftChild(int const &i)const{

      #ifndef NDEBUG
        assert( i >= 0);
      #endif

      int valorDevuelto = 2 * i + 1;

      #ifndef NDEBUG
        assert(valorDevuelto == 2 * i + 1);
      #endif

      return valorDevuelto;

    }

    int ed::Medicion::getRightChild(int const &i) const {

      #ifndef NDEBUG
        assert( i >= 0);
      #endif

      int valorDevuelto = 2 * i + 2;

      #ifndef NDEBUG
        assert(valorDevuelto == 2 * i + 2);
      #endif

      return valorDevuelto;

    }

    int ed::Medicion::getParent(int const &i) const{

      #ifndef NDEBUG
        assert( i >= 1);
      #endif

      int valorDevuelto = ((i-1)/2);

      #ifndef NDEBUG
        assert(valorDevuelto == (i-1)/2);
      #endif

      return valorDevuelto;

    }


/*
  El elemento indicado por el indice es subido en el monticulo hasta
  que se verifica la ordenación de máximos

  Condiciones de para los asertos

    · Si no es la cima, el elemento actual es menor o igual que su
    padre
    · Si tiene hijo izquierdo, el elemento actual es mayor o igual
    que él y, además, si tiene hijo derecho, es mayor o igual que
    él.
*/


    void ed::Medicion::shiftUp(int const &i) const {

      #ifndef NDEBUG
        assert((i >= 0 ) and (i < size()));
      #endif

      ed::Medicion aux;
      int aux1 = 1;

      if(getElement(getParent(i)).getPrecipitaciones() <
      getElement(i).getPrecipitaciones()){

        aux1=getParent(i);
        aux=getElement(aux1);
        setElement(aux1,getElement(i));
        setElement(i,aux);

        if(aux1!=0){
          shiftUp(aux1);
        }
      }


      #ifndef
      if(aux1!=0){
      	assert(getElement(aux1).getPrecipitaciones() <=
                getElement(getParent(aux1)).getPrecipitaciones());
      }

      if(getLeftChild(aux1) < size()){
      	assert(getElement(aux1).getPrecipitaciones() >=
                getElement(getLeftChild(aux1)).getPrecipitaciones());
      }

      if(getRightChild(aux1) < size()){
      	assert(getElement(aux1).getPrecipitaciones() >=
                getElement(getRightChild(aux1)).getPrecipitaciones());
      }

      #endif


    }

/*
  El elemento indicado por el índice es bajado en el montículo hasta que se
  verifica la ordenación de máximos.

  Condiciones de para los asertos

    · Si no es la cima, el elemento actual es menor o igual que su
    padre
    · Si tiene hijo izquierdo, el elemento actual es mayor o igual
    que él y, además, si tiene hijo derecho, es mayor o igual que
    él.
*/

void shiftDown(int const &i) const {
    #ifndef NDEBUG
      assert((i >= 0)and(i < size()));
    #endif

    ed::Medicion aux;

    int aux1=i;
    int HI=getLeftChild(i);
    int HD=getRightChild(i);

    if((unsigned int)HI < _monticulo.size()){
      if(getElement(HI).getPrecipitaciones()
          > getElement(i).getPrecipitaciones()){
              aux1=HI;
      }
    }

    if((unsigned int)HD < _monticulo.size()){
        if(getElement(HD).getPrecipitaciones()
          > getElement(aux1).getPrecipitaciones()){
            aux1=HD;
        }
      }

      if(i!=aux1){

        aux=getElement(i);
        setElement(i, getElement(aux1));
        setElement(aux1,aux);

        #ifndef NDEBUG
          if(i!=0){
            assert(aux.getPrecipitaciones()<=
                  getElement(getParent(i)).getPrecipitaciones());
          }

          if(getLeftChild(i)<=size()){
            assert(getElement(i).getPrecipitaciones() >=
                    getElement(getLeftChild(i)).getPrecipitaciones());
          }

          if(getRightChild(i)<=size()){
            assert(getElement(i).getPrecipitaciones() >=
                    getElement(getRightChild(i)).getPrecipitaciones());
          }

        #endif

        shiftDown(aux1);

      }
}

bool has(Medicion medicion) const {

  for(int i = 0; i < size(); i++){
    if(_monticulo[i] == medicion){
      return true;
    }else{
      return false;
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////7

// Métodos públicos de la clase MonticuloMediciones

		// COMPLETAR
