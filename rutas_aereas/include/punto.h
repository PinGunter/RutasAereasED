/**
  * @file punto.h
  * @brief Fichero cabecera para la clase Punto
  * @author Abel Ríos González
  * @author Salvador Romero Cortés
  */

#ifndef _PUNTO_H_
#define _PUNTO_H_

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
	 * @param x Coordenada x del punto
	 * @param y Coordenada y del punto
	 */
	Punto(double x, double y) : x(x), y(y){}

	/**
	 * @brief Consultor de la coordenada x del Punto
	 */
	inline double getLongitud() const {return x;};
	
	/**
	 * @brief Consultor de la coordenada y del Punto
	 */
	inline double getLatitud() const {return y;};

};

#endif /* PUNTO_H_ */ 
