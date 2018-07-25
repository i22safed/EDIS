
### Comandos Doxygen

//// Comentario de bloque ////

/*!
  \param
  \file
  \...
*/

//// Comentario de linea ////

//! \name Funciones o métodos públicos de la clase Vector3D

//// Comandos para los comentarios de bloque ////

 \brief     → Breve definición
 \date      → Fecha
 \def       → Indica que un bloque de comentario contiene información de un #define
 \file      → Nombre del fichero
 \fn        → Nombre de la función (function declaration)
 \note      → Notas
 \param     → Parametro que admite la función
 \post      → Postcondición
 \pre       → Precondición
 \return    → Tipo de retorno y que retorna
 \sa        → Referencias
 \see       → Similar a \sa
 \short     → Descripción corta
 \warning   → Precaución

 ===============================================================================

 \code      → Comienzo de bloque de código
 \endcode   → Final de bloque de código

 ===============================================================================

 \f$        → Comienzo/final de una formula
 \\         → Caracter de escape

================================================================================


// Ejemplo de comandos

/*!
 *  \brief     Pretty nice class.
 *  \details   This class is used to demonstrate a number of section commands.
 *  \author    John Doe
 *  \author    Jan Doe
 *  \version   4.1a
 *  \date      1990-2011
 *  \pre       First initialize the system.
 *  \bug       Not all memory is freed when deleting an object of this class.
 *  \warning   Improper use can crash your application
 *  \copyright GNU Public License.
 */
class SomeNiceClass {};
