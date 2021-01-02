/**
  * @file punto.h
  * @brief Fichero cabecera para la clase Punto
  * @author Abel Ríos González
  * @author Salvador Romero Cortés
  */

#ifndef _PUNTO_H_
#define _PUNTO_H_
#include <iostream>

/**
 * @brief clase Punto, representa una coordenada en 2 dimensiones
 */
class Punto{

private:

	double x;	///< Coordenada x del punto
	double y;	///< Coordenada y del punto
	
public:

	/**
	 * @brief Constructor
	 */
	Punto(): x(0), y(0){}

	/**
	 * @brief Constructor con parametros
	 * @param i Coordenada x del punto
	 * @param j Coordenada y del punto
	 */
	Punto(double i, double j) : x(i), y(j){}

	/**
	 * @brief Consultor de la coordenada x del Punto
	 */
	inline double getLongitud() const {return x;};
	
	/**
	 * @brief Consultor de la coordenada y del Punto
	 */
	inline double getLatitud() const {return y;};

	/**
	 * @brief metodo para establecer la longitud
	 * @param i la nueva longitud
	 */
	inline void setLongitud(double i) { x = i; }

	/**
	 * @brief metodo para establecer la latitud
	 * @param j la nueva latitud
	 */
	inline void setLatitud(double j) { y = j; }

	/**
	 * @brief operador de igualdad
	 * @param otro con el que se compara
	 * @return true si son iguales, false en caso contrario
	 */
	bool operator==(const Punto & otro) const { return x == otro.x && y == otro.y; };
	
	friend std::ostream & operator<<(std::ostream &os, const Punto &p);
	friend std::istream & operator>>(std::istream &is, Punto & p);
};

/**
 * @brief operador de entrada de datos
 * @param is el flujo de donde se leen los datos
 * @param p el objeto punto que guarda los datos leidos
 * @return referencia a istream
 */
std::istream & operator>>(std::istream & is, Punto & p );
/**
 * @brief operador de salida de datos
 * @param os el flujo hacia donde se transfieren los datos
 * @param p el objeto punto que se saca por el flujo
 * @return referencia a ostream
 */
std::ostream & operator<<(std::ostream & os, const Punto & p);
#endif /* PUNTO_H_ */ 
