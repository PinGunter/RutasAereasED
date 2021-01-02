/**
  * @file Almacen_Rutas.h
  * @brief Fichero cabecera para la clase Almacen_Rutas
  */

#ifndef _Almacen_Rutas_H_
#define _Almacen_Rutas_H_
#include "ruta.h"
#include <vector>
#include <iostream>

class Almacen_Rutas{

private:
	
	std::vector<Ruta> almacen;
	std::vector<Ruta>::iterator buscarRuta(std::string nombre_ruta);

public:

	Almacen_Rutas() = default;
	
	~Almacen_Rutas() = default;

	Almacen_Rutas(const Almacen_Rutas & a) = default;

	Almacen_Rutas & operator=(const Almacen_Rutas & a) = default;

	int getNumRutas() const;

	void insertarRuta(const Ruta & ruta);

	void eliminarRuta(std::string nombre_ruta);

	/**
	 * @brief clase iteradora para la clase Almacen_Rutas
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
		Ruta & operator*();

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

		friend class Almacen_Rutas;
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
		Ruta operator*();

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

		friend class Almacen_Rutas;
	};

	/**
	 * @brief metodo begin
	 * @return un interador que apunta al comienzo del almacen de Rutas
	 */
	iterator begin();

	/**
	 * @brief metodo end
	 * @return un iterador que apunta al final del almacen de Rutas
	 */
	iterator end();
	
	/**
	 * @brief metodo cbegin
	 * @return un interador constante que apunta al comienzo del almacen de Rutas
	 **/
	const_iterator cbegin() const;

	/**
	 * @brief metodo cend
	 * @return un iterador constante que apunta al final del almacen de Rutas
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

#endif /* Almacen_Rutas_H_ */ 
