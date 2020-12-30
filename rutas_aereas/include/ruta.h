/**
  * @file ruta.h
  * @brief Fichero cabecera para la clase Ruta
  */

#ifndef _PUNTO_H_
#define _PUNTO_H_

class Ruta{

private:

	Punto * ruta;
	//int tam;
	//int util;
	
	void allocate(int n);
	void deallocate();
	void copy(const Ruta &r);

public:

	Ruta();
	
	~Ruta();
	
	Ruta(const Ruta& r);
	
	Ruta & operator=(const Ruta& r);
	
	Punto & getPunto(int i);

};
