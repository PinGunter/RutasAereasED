/**
  * @file ruta.h
  * @brief Fichero cabecera para la clase Ruta
  */

#ifndef _RUTA_H_
#define _RUTA_H_
#include "punto.h"
#include <vector>

class Ruta{

private:

	std::vector<Punto> ruta;

public:

	Ruta() = default;
	
	~Ruta() = default;
	
	Ruta(const Ruta & r) = default;
	
	//Ruta & operator=(const Ruta & r){
	//	ruta = r.ruta;
	//	return *this;
	//}

	Ruta & operator=(const Ruta & r) = default;

	class iretator{

	private:

	


	public:

	};
	<< >>
	iterator::operator!=
	iterator::operator*
	iterator::operator++
	begin end 	
};

#endif /* RUTA_H_ */ 
