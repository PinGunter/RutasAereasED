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

	double latitud;	///< Coordenada x del punto
	double longitud;	///< Coordenada y del punto
	std::string comentario; ///< String con comentario
	
public:

	/**
	 * @brief Constructor
	 */
	Punto(): latitud(0), longitud(0){}

	/**
	 * @brief Constructor con parametros
	 * @param i Coordenada x del punto
	 * @param j Coordenada y del punto
	 * @param c Comentario del punto
	 */
	Punto(double i, double j, std::string c="") : latitud(i), longitud(j), comentario(c){}

	/**
	 * @brief Consultor de la coordenada x del Punto
	 */
	inline double getLongitud() const {return longitud;};
	
	/**
	 * @brief Consultor de la coordenada y del Punto
	 */
	inline double getLatitud() const {return latitud;};

	/**
	 * @brief metodo para establecer la longitud
	 * @param i la nueva longitud
	 */
	inline void setLongitud(double i) { latitud = i; }

	/**
	 * @brief metodo para establecer la latitud
	 * @param j la nueva latitud
	 */
	inline void setLatitud(double j) { longitud = j; }

	/**
	 * @brief operador de igualdad
	 * @param otro con el que se compara
	 * @return true si son iguales, false en caso contrario
	 */
	bool operator==(const Punto & otro) const { return latitud == otro.latitud && longitud == otro.longitud; };
	
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
