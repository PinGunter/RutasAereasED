/**
  * @file ruta.h
  * @brief Fichero cabecera para la clase Ruta
  * @author Abel Ríos Gonzáles
  * @author Salvador Romero Cortés
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
	std::string nombre; ///< Nombre de la ruta
	std::vector<Punto> ruta; ///< Vector de puntos

	/**
	 * @brief metodo para localizar un punto
	 * @param punto el que se busca
	 * @return un iterador apuntando al elemento. End si no lo encuentra
	 */
	std::vector<Punto>::iterator buscarPunto(const Punto & punto);
public:

	/**
	 * @brief constructor por defecto
	 */
	Ruta() = default;
	
	/**
	 * @brief constructor a partir de un nombre
	 * @param nombre_ruta el nombre que tendra la ruta creada
	 */
	Ruta(std::string nombre_ruta);
	
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
	 * @brief metodo para obtener el nombre de una ruta
	 * @return el nombre de la ruta
	 */
	std::string getNombre() const;

	/**
	 * @brief Método modificador del nombre
	 * @param nombre el que se le pone a la ruta
	 */
	void setNombre(std::string nombre);

	/**
	 * @brief metodo para obtener el número de puntos en la ruta
	 * @return entero con el numero de puntos
	 */
	int getNumPuntos() const;

	/**
	 * @brief metodo para insertar puntos en la ruta
	 * @param punto el nuevo punto de la ruta
	 */
	void insertarPunto(Punto punto);

	/**
	 * @brief metodo para eliminar un punto de la ruta
	 * @param punto el que se borra
	 */
	void eliminarPunto(Punto punto);
	
	/**
	 * @brief operador de igualdad entre rutas
	 * @param otra la ruta con la que se compara
	 * @return true si las rutas son iguales
	 * 		   false en caso contrario
	 */
	bool operator==(const Ruta & otra);

	/**
	 * @brief operador de igualdad con respecto a un nombre de ruta
	 * @param nombre_ruta el nombre de ruta con el que se compara
	 * @return true si el nombre de la ruta es igual a nombre_ruta
	 * 		   false en caso contrario
	 */
	bool operator==(const std::string & nombre_ruta);

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
		iterator & operator=(const iterator & otro) = default;

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
		 * @return una copia del objeto
		 */
		iterator operator++();

		/**
		 * @brief operador de incremento (posfijo)
		 * @return una copia del objeto
		 */
		iterator operator++(int);
		
		/**
		 * @brief operador de decremento (prefijo)
		 * @return una referencia al objeto
		 */
		iterator operator--();

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
		const_iterator & operator=(const const_iterator & otro) = default;

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
		 * @return una copia del objeto
		 */
		const_iterator operator++();

		/**
		 * @brief operador de incremento (posfijo)
		 * @return una copia del objeto
		 */
		const_iterator operator++(int);
		
		/**
		 * @brief operador de decremento (prefijo)
		 * @return una referencia al objeto
		 */
		const_iterator operator--();

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
	const_iterator cbegin() const;

	/**
	 * @brief metodo cend
	 * @return un iterador constante que apunta al final de la ruta
	 */
	const_iterator cend() const;

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

