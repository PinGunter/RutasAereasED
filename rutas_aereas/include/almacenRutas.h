/**
  * @file almacenRutas.h
  * @brief Fichero cabecera para la clase almacenRutas
  */

#ifndef _ALMACENRUTAS_H_
#define _ALMACENRUTAS_H_
#include "ruta.h"

class AlmacenRutas{

private:
	
	std::vector<Ruta> almacen;

public:

	AlmacenRutas() = default;
	
	~AlmacenRutas() = default;
	AlmacenRutas(const AlmacenRutas & a) = default;

	AlmacenRutas & operator=(const AlmacenRutas & a);

	Ruta & getRuta(int i);


	
	

};

#endif /* ALMACENRUTAS_H_ */ 
