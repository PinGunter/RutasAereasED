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
    } else{
        --posicion; //porque se incrementa tras encontrar el elemento
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

bool Almacen_Rutas::operator==(const Almacen_Rutas & otra){
    bool iguales = getNumRutas() == otra.getNumRutas();
    for (int i=0; i < getNumRutas() && iguales; i++){
        if (!(almacen[i] == otra.almacen[i])){
            iguales = false;
        }
    }
    return iguales;
} 

Almacen_Rutas::iterator::iterator(const vector<Ruta>::iterator & vit){
    it = vit;
}

Almacen_Rutas::iterator::iterator(const Almacen_Rutas::iterator & otro): it(otro.it){}


bool Almacen_Rutas::iterator::operator!=(const Almacen_Rutas::iterator & otro){
    return it != otro.it;
}

Ruta & Almacen_Rutas::iterator::operator*(){
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

Almacen_Rutas::const_iterator::const_iterator(const vector<Ruta>::const_iterator & vit){
    it = vit;
}

Almacen_Rutas::const_iterator::const_iterator(const Almacen_Rutas::const_iterator & otro): it(otro.it){}

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

istream & operator>>(istream & is, Almacen_Rutas & almacen){
	Ruta aux;
	std::string password;
	is >> password;
	if (password != "#Rutas"){
		cerr << "Error: archivo no válido" << endl;
        exit(1); 
	}
	while (is){
		is >> aux;
        if (is){
            almacen.insertarRuta(aux);
        }
	}

	return is;
}

ostream & operator<<(ostream & os, const Almacen_Rutas & almacen){
    os << "#Rutas" << endl;
    for(auto it = almacen.cbegin(); it != almacen.cend(); ++it){
    	os << (*it) << endl;
    }
    return os;
}





