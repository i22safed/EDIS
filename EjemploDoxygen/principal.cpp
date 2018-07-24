/*!
 \mainpage Implementación de un vértice de dos  dimensiones
 \brief		P = (x, y)
 \author   Nicolás Luis Fernández García
 \date     2018-2-1
 \version  1.0
*/

/*!

	\file principal.cpp
	\brief Programa principal para mostra el uso de la clase Vertice2D
*/

#include <iostream>

#include "Vertice2D.hpp"


/*! 
	\brief   Función principal
	\return  int
*/
int main()
{
	
	ed::Vertice2D v1(1,2);

	ed::Vertice2D v2(v1);

	std::cout << "Programa de uso de vértices de dos dimensiones " << std::endl;

    std::cout << "Escritura Vértices" << std::endl;
    std::cout << "v1 = ";
	v1.escribirVertice2D();

    std::cout << "v2 = ";
	v2.escribirVertice2D();


    std::cout << "Lectura de vértices" << std::endl;
    std::cout << "Lectura de v1 usando la función de la clase " << std::endl;
	v1.leerVertice2D();

	std::cout << "Lectura de v2 usando el operador de flujo " << std::endl;
	std::cout << "Introduzca dos números separados por un espacio " << std::endl;
	std::cin >> v2;


    std::cout << "Escritura Vértices usando el operador de flujo" << std::endl;
    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;


    std::cout << "Distancia entre los vértices v1 y v2: " << std::endl;
	std::cout << ed::calcularDistanciaEuclidea2D(v1,v2) << std::endl;
    std::cout << std::endl;

    std::cout << "Uso de operadores" << std::endl;
    std::cout << std::endl;

    std::cout << "Operador de igualdad: v1 == v2 " << std::endl;
    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;
	if (v1 == v2)
		std::cout << "son iguales" << std::endl;
	else
		std::cout << "son diferentes" << std::endl;
    std::cout << std::endl;

    std::cout << "Operador de asignación: v1 = v2 " << std::endl;
    std::cout << "Antes" << std::endl;
    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;
	v1 = v2; 
    std::cout << "Después" << std::endl;
    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;
    std::cout << std::endl;

	
	return 0;
}


