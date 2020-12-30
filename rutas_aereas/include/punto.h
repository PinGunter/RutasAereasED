/**
  * @file punto.h
  * @brief Fichero cabecera para la clase Punto
  */

#ifndef _PUNTO_H_
#define _PUNTO_H_

class Punto{

private:

	double x;
	double y;
	
public:

	Point();
	
	virtual ~Punto();
	
	Point(const double x, const double y);

	double getX();
	
	double getY();
	
	double distancia(const Point &p) const;	

};

#endif /* PUNTO_H_ */ 
