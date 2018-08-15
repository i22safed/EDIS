/*!
	\file  Provincia.hpp
	\brief Definición de la clase Provincia
	\author David Sánchez
	\date 09/04/2018
	\version v1.0

*/

#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

// Para comprobar las pre y post condiciones

#include <cassert>
#include <string>
#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"


// IMPORTANTE
// Se incluyen los prototipos de las funciones virtuales que hay que redefinir
// Hay que incluir los prototipos de las demás funciones


/*!
	\namespace ed
	\brief Espacio de nombres para la Provincia Estructuras de Datos

*/
namespace ed{
/*!

  \class Provincia
  \brief Definición de la clase Provincia

*/
class Provincia{

	//!	\name Métodos públicos de la clase Provincia

	private:
		std::string      _nombre;     //!<  \brief Nombre de la Provincia
		int              _codigo;	  //!<  \brief Código de la Provincia

	  	ed::ListaDoblementeEnlazadaOrdenadaMunicipios _listaMunicipios; //!<  \brief Lista de municipios de la Provincia


	//!	\name  Métodos públicos de la clase Provincia

  public:

	//!	\name Constructor

	/*!
		\fn        Provincia(string,int)
		\brief     Constructor una provincia inicializando el nombre a
					\n cadena vacia y el codigo a 0
		\param     string: nombre de la provincia
		\param     int: codigo de la provincia
		\pre       N/A
		\post     assert(getNombre()==_nombre);
		\post	assert(getCodigo()==_codigo);
		\post	assert(hayMunicipios()==false);
	*/

	Provincia(std::string nombre="",int codigo=0){
		setNombre(nombre);
		setCodigo(codigo);

		assert(getNombre()==_nombre);
		assert(getCodigo()==_codigo);
		assert(hayMunicipios()==false);

	};


	//!	\name Observadores

	/*!
		\fn 		 inline std::string getNombre() const;
		\brief     Observador del atributo _nombre
		\note      Función inline
		\param     N/A
		\pre       N/A
		\post      N/A

	*/

	inline std::string getNombre() const {return _nombre;};

	/*!
		\fn 		 std::string getNombre() const{}
		\brief     Observador del atributo _codigo
		\note      Función inline
		\param     N/A
		\pre       N/A
		\post      N/A

	*/
	inline int getCodigo() const {return _codigo;};


	/*!
		\fn 		 inline int getCodigo() const{}
		\brief     Observador que devuelve true si hay municipios en la
				\n prinvincia y false en caso contrario
		\note      Función inline
		\param     N/A
		\pre       N/A
		\post      N/A

	*/
	inline bool hayMunicipios() const {return not _listaMunicipios.isEmpty();};


	/*!
		\fn 		 inline int getNumeroMunicipios() const{}
		\brief     Observador que devuelve el numero de municipios de la
				\n provincia
		\note      Función inline
		\param     N/A
		\pre       N/A
		\post      N/A

	*/
	inline int getNumeroMunicipios() const {return _listaMunicipios.nItems();};

	/*!
		\fn 		 bool existeMunicipio(std::string const &nombre);
		\brief     Observador que comprueba existe un municipio dentro de la
				\n provincia
		\note      Función inline
		\param     string: nombre del municipio a buscar
		\pre       N/A
		\post      N/A

	*/
	bool existeMunicipio(std::string const &nombre);


	/*!
		\fn 		 ed::Municipio const & getMunicipio(std::string const &nombre)
		\brief     Observador que devuelve una referencia constante objeto
				\n de tipo municipio en caso de exista dentro de la provincia
		\param     string: nombre del municipio
		\pre       assert(existeMunicipio(nombre)==true);
		\post      N/A

	*/
	ed::Municipio const & getMunicipio(std::string const &nombre);


	/*!
		\fn int getTotalHombres();
		\brief     Observador que devuelve el numero total de hombres
				\n de la provincia
		\pre       N/A
		\post      N/A

	*/
	int getTotalHombres();

	/*!
		\fn int getTotalMujeres();
		\brief     Observador que devuelve el numero total de mujeres
				\n de la provincia
		\pre       N/A
		\post      N/A

	*/
	int getTotalMujeres();


	/*!
		\fn        int getTotalHabitantes()
		\brief     Observador que devuelve el numero total de habitantes
				\n de la provincia
		\pre       N/A
		\post      N/A

	*/
	int getTotalHabitantes();


	//!	\name Modificadores


	/*!
		\fn        void setNombre(std::string nombre);
		\brief     Modificador del atributo _nombre de la clase
		\param     string: nombre de la provincia
		\pre       N/A
		\post     assert(getNombre() == nombre);

	*/
	void setNombre(std::string nombre);


	/*!
		\fn        void setCodigo(int codigo);
		\brief     Modificador del atributo _codigo de la clase
		\param     int: codigo de la provincia
		\pre       N/A
		\post     assert(getCodigo() == codigo);

	*/
	void setCodigo(int codigo);

	/*!
		\fn        void insertarMunicipio(ed::Municipio const & m);
		\brief     Inserta un municipio en la lista de municipios
				\n _listaMunicipios()
		\param     int: codigo de la provincia
		\pre       assert(existeMunicipio(m.getNombre())==false);
		\post      assert(existeMunicipio(m.getNombre())==false);
	     \post 	 assert(getNumeroMunicipios() == (old + 1));

	*/
	void insertarMunicipio(ed::Municipio const & m);

	void borrarMunicipio(std::string const & nombre);

	void borrarTodosLosMunicipios();



	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia

	void escribirMunicipios();


	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros

	bool cargarFichero(std::string const & nombre);

	bool grabarFichero(std::string const & nombre);



}; //Fin de la clase  Provincia


} // Fin del espacio de nombres ed

#endif // _PROVINCIA_HPP_
