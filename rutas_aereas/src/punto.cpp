/**
  * @file punto.cpp
  * @brief 
  *
  */

#include <iostream>
#include "Punto.h"

using namespace std;

Punto::Punto(double x, double y) : x(x), y(y){}

double Punto::getX() const{
	return x;
}

double Punto::getY() const{
	return y;
}

double Punto::distancia(const POint &p) const{
	int distancia = y-x;
	return distancia;
}

Punto::~Punto(){}


