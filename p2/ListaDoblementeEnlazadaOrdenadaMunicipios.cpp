/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author David Sanchez Fernandez
	\date 09/04/2018
	\version 1.0
*/


#include <cassert> // Para comprobar las pre y post-condiciones

#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "NodoMunicipioInterfaz.hpp"
#include "Municipio.hpp"




int ed::ListaDoblementeEnlazadaOrdenadaMunicipios::nItems() const {

	int numeroItem=0;
     if(isEmpty()==false){

		NodoDoblementeEnlazadoMunicipio *puntero;
	   	puntero=getHead();

	   	while (puntero!=NULL){ //tiene que estar llena
	   			puntero=puntero->getNext();
	   			numeroItem++;
	   	}
   	}

   	return numeroItem;
}


bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::find(ed::Municipio  const & m){

	// Si la lista está vacía, no lo encuentra
	if(isEmpty()==true){
	return false;
	}

	gotoHead(); //llevo el puntero a la cabeza

	while(isLastItem()==false){
		if(m ==getCurrentItem()){

			#ifndef NDEBUG
			assert( getCurrentItem()==m);
			#endif

			return true;


		}else{

			gotoNext();

		}
	}

	if(m ==getCurrentItem()){

		#ifndef NDEBUG
		assert( getCurrentItem()==m);
		#endif

		return true;

	}else{

		return false;
	}
}


bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::isFirstItem() const{

		#ifndef NDEBUG
    		assert(isEmpty()==false);
    	#endif

     if(getCurrent() == getHead()){
       return true;
     }else{
       return false;
     }


}

bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::isLastItem() const{

			#ifndef NDEBUG
    		assert(isEmpty()==false);
    	#endif

     if(getCurrent()->getNext()==NULL){
       return true;
 		}else{
 		  return false;
     }

}

ed::Municipio const & ed::ListaDoblementeEnlazadaOrdenadaMunicipios:: getCurrentItem() const{

	#ifndef NDEBUG
    		assert( isEmpty()==false);
    	#endif

 	return getCurrent()->getItem();

}

ed::Municipio const & ed::ListaDoblementeEnlazadaOrdenadaMunicipios:: getPreviousItem() const{

	#ifndef NDEBUG
	    	assert( isEmpty()==false);
	    	assert( isFirstItem()==false);
    	#endif

 	return getCurrent()->getPrevious()->getItem();

}


ed::Municipio const & ed::ListaDoblementeEnlazadaOrdenadaMunicipios:: getNextItem() const{

	#ifndef NDEBUG
     assert(isEmpty()==false);
     assert(isLastItem()==false);
	#endif

     NodoDoblementeEnlazadoMunicipio *aux;
     aux-> getNext();
     return aux->getItem();


}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoHead(){

	#ifndef NDEBUG
   		assert(isEmpty()==false);
   	#endif

	  setCurrent(getHead());

   	#ifndef NDEBUG
   		assert( isFirstItem()==true);
   	#endif

}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoLast(){

	#ifndef NDEBUG
   		assert( isEmpty()==false);
   	#endif

	while (isLastItem()==false){
		gotoNext();
	}

   	#ifndef NDEBUG
   		assert( isLastItem()==true);
   	#endif


}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoPrevious(){

	#ifndef NDEBUG
	   	assert( isEmpty()==false);
	#endif

	setCurrent (getCurrent()->getPrevious());

}


void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoNext(){

	#ifndef NDEBUG
	   	assert( isEmpty()==false);
	   	assert( isLastItem()==false);
   	#endif

	setCurrent(getCurrent()->getNext());

}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::insert(ed::Municipio const &m){

	NodoDoblementeEnlazadoMunicipio *aux = new NodoDoblementeEnlazadoMunicipio (m, NULL, NULL);

    #ifndef NDEBUG
    assert(find(m)==false);
    int n = nItems();
    #endif

	//la lista esta vacia
	//Insertar como cabeza
	if(isEmpty()==true){

		setHead(aux);//Es la cabeza
		setCurrent(getHead());

	}else{//no esta vacia

     gotoHead();

	while(isLastItem()==false){
			  if(m<getCurrentItem()){
				  break; //Me salgo del bucle
			  }

        gotoNext();
   	}

	    if(nItems()==1){

			if(m < getCurrentItem()){ //va a ser la cabeza

	   			aux->setPrevious(NULL);//va a ser la cabeza
	   			aux->setNext(getCurrent());
	   			getCurrent()->setPrevious(aux);
	   			gotoPrevious(); //apunta al nuevo nodo
	   			setHead(getCurrent());//es la cabeza

	   		}else{  //insertarlo despues de la cabeza

				aux->setNext(NULL);
				aux->setPrevious(getCurrent());
				getCurrent()->setNext(aux);
				gotoNext();//apunta al nuevo nodo
	   		}
	   		return;
	   	}

	   	if(isFirstItem()==true){ //si hay que insertar el primero

			  aux->setPrevious(NULL);
			  aux->setNext(getCurrent());
			  getCurrent()->setPrevious(aux);
			  gotoPrevious();
			  setHead(getCurrent());

		  }else if(isLastItem()==true){//insertar el ultimo

			if(getCurrentItem()<m){

				  aux->setNext(NULL);
				  aux->setPrevious(getCurrent());
				  getCurrent()->setNext(aux);
				  gotoNext();

			}else{ //insertar penultimo

				  aux->setPrevious(getCurrent()->getPrevious());
				  aux->setNext(getCurrent());
				  getCurrent()->setPrevious(aux);
				  gotoPrevious();
				  getCurrent()->getPrevious()->setNext(getCurrent());
			}
				return;
			//entre medias
			}else{
				aux->setPrevious(getCurrent()->getPrevious());
				aux->setNext(getCurrent());
				getCurrent()->setPrevious(aux);
				gotoPrevious();
				getCurrent()->getPrevious()->setNext(getCurrent());
			}
	}

   #ifndef NDEBUG
   assert(getCurrentItem()==m);
   assert(nItems()== n +1);
   #endif

}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::remove(){

	//precondicion  La lista no está vacía
	   	#ifndef NDEBUG
	   		assert( isEmpty()==false);
	   	#endif

		if(nItems()==1){ //SOLO HAY 1 NODO

			setHead(NULL);
			setCurrent(NULL);

		}else if(isFirstItem()==true){ //BORRAR EL PRIMERO

			setHead(getCurrent()->getNext()); //cabeza es la siguiente
			getHead()->setPrevious(NULL); //null antes de cabeza
			getCurrent()->setNext(NULL); //elimina totalmente el nodo
			setCurrent(getHead());//apunta a la nueva cabeza

		}else if(isLastItem()==true){//BORRAR EL ULTIMO

			gotoPrevious();
			getCurrent()->getNext()->setPrevious(NULL); //el nodo que se quiere eliminar ya no apunta a nada
			getCurrent()->setNext(NULL);//convierte el penultimo nodo en el ultimo

		}else{ //BORRAR ENTRE MEDIAS

			NodoDoblementeEnlazadoMunicipio * puntero=getCurrent();
			puntero->getPrevious()->setNext(puntero->getNext());
			puntero->getNext()->setPrevious(puntero->getPrevious());
			setCurrent(puntero->getNext());
			puntero->setNext(NULL); //elimino puntero
			puntero->setPrevious(NULL);//elimino puntero

		}

		//postcondicion
	   	#ifndef NDEBUG
	   		assert(nItems()==nItems()-1);
	   	#endif

	}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::removeAll(){

	NodoDoblementeEnlazadoMunicipio *aux;

     gotoHead();

     while(getCurrent()->getNext() != NULL)
     {
       gotoNext();
       aux=getCurrent();
       gotoPrevious();
       remove();
       setCurrent(aux);
     }
   			remove();

         #ifndef NDEBUG
         assert(isEmpty() == true);
         #endif
}
