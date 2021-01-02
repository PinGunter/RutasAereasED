/**
 * @file punto.cpp
 * @brief definiciones de las funciones declaradas en punto.h
 * @author Abel Ríos González
 * @author Salvador Romero Cortés
 */

#include "punto.h"
#include <iostream>
using namespace std;

std::ostream & operator<<(std::ostream &os, const Punto & p){
    os << "(" << p.getLongitud() << "," << p.getLatitud() << ")";
    return os;
}

std::istream & operator>>(std::istream &is, Punto & p){
    char aux;
    double x_, y_;
    is >> aux;  // abre parentesis
    is >> x_;   // x
    is >> aux;  // coma (,)
    is >> y_;   // y
    is >> aux;  // cierra parentesis
    p.setLongitud(x_); p.setLatitud(y_);
    return is;
}