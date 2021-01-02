/**
  * @file Almacen_Rutas.cpp
  * @brief 
  *
  */

#include "Almacen_Rutas.h"
using namespace std;

vector<Ruta>::iterator Almacen_Rutas::buscarRuta(string nombre_ruta){
	vector<Ruta>::iterator posicion;
	bool encontrado = false;
	for (posicion = almacen.begin(); posicion != almacen.end() && !encontrado ; ++posicion){
        if ((*posicion) == nombre_ruta){
            encontrado = true;
        }
    }

    if (!encontrado){
        posicion = almacen.end();
    }

    return posicion;
}

int Almacen_Rutas::getNumRutas() const{
	return almacen.size();
}

void Almacen_Rutas::insertarRuta(const Ruta & ruta){
	almacen.push_back(ruta);
}

void Almacen_Rutas::eliminarRuta(string nombre_ruta){
	vector<Ruta>::iterator posicion = buscarRuta(nombre_ruta);
	if (posicion != almacen.end()){
		almacen.erase(posicion);
	}
}

Almacen_Rutas::iterator::iterator(const vector<Punto>::iterator & vit){
    it = vit;
}

Almacen_Rutas::iterator::iterator(const Almacen_Rutas::iterator & otro): it(otro.it){}

Almacen_Rutas::iterator & Almacen_Rutas::iterator::operator=(const Almacen_Rutas::iterator & otro){
    it = otro.it;
}

bool Almacen_Rutas::iterator::operator!=(const Almacen_Rutas::iterator & otro){
    return it != otro.it;
}

Punto & Almacen_Rutas::iterator::operator*(){
    return (*it);
}

Almacen_Rutas::iterator  Almacen_Rutas::iterator::operator++(){
    return ++it;
}

Almacen_Rutas::iterator Almacen_Rutas::iterator::operator++(int){
    return it++;
}

Almacen_Rutas::iterator  Almacen_Rutas::iterator::operator--(){
    return --it;
}

Almacen_Rutas::iterator Almacen_Rutas::iterator::operator--(int){
    return it--;
}

Almacen_Rutas::const_iterator::const_iterator(const vector<Punto>::const_iterator & vit){
    it = vit;
}

Almacen_Rutas::const_iterator::const_iterator(const Almacen_Rutas::const_iterator & otro): it(otro.it){}

Almacen_Rutas::const_iterator & Almacen_Rutas::const_iterator::operator=(const Almacen_Rutas::const_iterator & otro){
    it = otro.it;
}

bool Almacen_Rutas::const_iterator::operator!=(const Almacen_Rutas::const_iterator & otro){
    return it != otro.it;
}

Ruta Almacen_Rutas::const_iterator::operator*(){
    return (*it);
}

Almacen_Rutas::const_iterator  Almacen_Rutas::const_iterator::operator++(){
    return ++it;
}

Almacen_Rutas::const_iterator Almacen_Rutas::const_iterator::operator++(int){
    return it++;
}

Almacen_Rutas::const_iterator  Almacen_Rutas::const_iterator::operator--(){
    return --it;
}

Almacen_Rutas::const_iterator Almacen_Rutas::const_iterator::operator--(int){
    return it--;
}

Almacen_Rutas::iterator Almacen_Rutas::begin(){
    return iterator(almacen.begin());
}

Almacen_Rutas::iterator Almacen_Rutas::end(){
    return iterator(almacen.end());
}

Almacen_Rutas::const_iterator Almacen_Rutas::cbegin() const{
    return const_iterator(almacen.cbegin());
}

Almacen_Rutas::const_iterator Almacen_Rutas::cend() const{
    return const_iterator(almacen.cend());
}

istream & operator>>(istream & is, Almacen_Rutas & a){
	Ruta aux;
	std::string password;
	is >> password;
	if (password != "#Rutas"){
		// Mensajes de error y finalizar?
	}

	while (!is.eof()){ // Devuelve true si ha alcanzado el final del archivo
		is >> aux;
		a.insertarRuta(aux); 
	}

	return is;
}

ostream & operator<<(ostream & os, const Almacen_Rutas & a){
    // Usar operator << de la clase Ruta
    os << "#Rutas";
    for(auto it = a.cbegin(); it != a.cend(); ++it){
    	os << (*it);
    }
    return os;
}





