/**
  * @file ruta.h
  * @brief Fichero cabecera para la clase Ruta
  */

#ifndef _RUTA_H_
#define _RUTA_H_
#include "punto.h"
#include <vector>
#include <iostream>

/**
 * @brief Clase Ruta que representa una ruta que es una sucesión de puntos
 */
class Ruta{

private:

	std::vector<Punto> ruta;

public:

	/**
	 * @brief constructor por defecto
	 */
	Ruta() = default;
	
	/**
	 * @brief destructor
	 */
	~Ruta() = default;
	
	/**
	 * @brief constructor de copia
	 * @param r el que se copia
	 */
	Ruta(const Ruta & r) = default;
	
	/**
	 * @brief operador de asignación
	 * @param r el objeto que se asigna a @e this
	 * @return referencia al objeto
	 */
	Ruta & operator=(const Ruta & r) = default;

	/**
	 * @brief clase iteradora para la clase Ruta
	 **/
	class iterator{	
	private:
		std::vector<Punto>::iterator it;
		/**
		 * @brief constructor de iterador de ruta a partir de un iterador de vector
		 * @param vit iterador de vector
		 */
		iterator(const std::vector<Punto>::iterator & vit);
	public:
		/**
		 * @brief constructor por defecto de iterador
		 */
		iterator() = default;

		/**
		 * @brief constructor de copìa de iterador
		 * @param otro el que se copia
		 */
		iterator(const iterator & otro);

		/**
		 * @brief operador de asignación 
		 * @param otro el que se asigna
		 * @return una referencia del iterador actual
		 */
		iterator & operator=(const iterator & otro);

		/**
		 * @brief operador de desigualdad
		 * @param otro con el que se compara
		 * @return true si @e this y @e otro son distintos
		 * 		   false si @e this y @e otro son iguales
		 */
		bool operator!=(const iterator & otro);

		/**
		 * @brief operador * 
		 * @return el Punto donde apunta el iterador
		 */
		Punto & operator*();

		/**
		 * @brief operador de incremento (prefijo)
		 * @return una referencia al objeto
		 */
		iterator & operator++();

		/**
		 * @brief operador de incremento (posfijo)
		 * @return una copia del objeto
		 */
		iterator operator++(int);
		
		/**
		 * @brief operador de decremento (prefijo)
		 * @return una referencia al objeto
		 */
		iterator & operator--();

		/**
		 * @brief operador de decremento (posfijo)
		 * @return una copia del objeto
		 */
		iterator operator--(int);

		friend class Ruta;
	};
	
	/**
	 * @brief clase iteradora constante para la clase Ruta
	 **/
	class const_iterator{	
	private:
		std::vector<Punto>::const_iterator it;
		/**
		 * @brief constructor de iterador de ruta a partir de un iterador de vector
		 * @param vit iterador de vector
		 */
		const_iterator(const std::vector<Punto>::const_iterator & vit);
	public:
		/**
		 * @brief constructor por defecto de iterador
		 */
		const_iterator() = default;

		/**
		 * @brief constructor de copìa de iterador
		 * @param otro el que se copia
		 */
		const_iterator(const const_iterator & otro);

		/**
		 * @brief operador de asignación 
		 * @param otro el que se asigna
		 * @return una referencia del iterador actual
		 */
		const_iterator & operator=(const const_iterator & otro);

		/**
		 * @brief operador de desigualdad
		 * @param otro con el que se compara
		 * @return true si @e this y @e otro son distintos
		 * 		   false si @e this y @e otro son iguales
		 */
		bool operator!=(const const_iterator & otro);

		/**
		 * @brief operador * 
		 * @return el Punto donde apunta el iterador
		 */
		Punto operator*();

		/**
		 * @brief operador de incremento (prefijo)
		 * @return una referencia al objeto
		 */
		const_iterator & operator++();

		/**
		 * @brief operador de incremento (posfijo)
		 * @return una copia del objeto
		 */
		const_iterator operator++(int);
		
		/**
		 * @brief operador de decremento (prefijo)
		 * @return una referencia al objeto
		 */
		const_iterator & operator--();

		/**
		 * @brief operador de decremento (posfijo)
		 * @return una copia del objeto
		 */
		const_iterator operator--(int);

		friend class Ruta;
	};

	/**
	 * @brief metodo begin
	 * @return un interador que apunta al comienzo de la ruta
	 */
	iterator begin();

	/**
	 * @brief metodo end
	 * @return un iterador que apunta al final de la ruta
	 */
	iterator end();
	
	/**
	 * @brief metodo cbegin
	 * @return un interador constante que apunta al comienzo de la ruta
	 */
	const_iterator cbegin();

	/**
	 * @brief metodo cend
	 * @return un iterador constante que apunta al final de la ruta
	 */
	const_iterator cend();

	friend std::istream & operator>>(std::istream & is, Ruta & r);
	friend std::ostream & operator<<(std::ostream & os, const Ruta & r);
};

/**
 * @brief operador de entrada de datos
 * @param is el flujo de donde se leen los datos
 * @param r el objeto ruta que guarda los datos leidos
 * @return referencia a istream
 */
std::istream & operator>>(std::istream & is, Ruta & r);
/**
 * @brief operador de salida de datos
 * @param os el flujo hacia donde se transfieren los datos
 * @param r el objeto ruta que se saca por el flujo
 * @return referencia a ostream
 */
std::ostream & operator<<(std::ostream & os, const Ruta & r);

#endif /* RUTA_H_ */ 

