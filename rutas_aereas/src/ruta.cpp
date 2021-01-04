/**
 * @file ruta.cpp
 * @brief definiciones de los metodos y funciones declarados en ruta.h
 * @author Salvador Romero Cortés
 * @author Abel Ríos González
 */

#include <ruta.h>
using namespace std;

Ruta::Ruta(string nombre_ruta):nombre(nombre_ruta){}

vector<Punto>::iterator Ruta::buscarPunto(const Punto & punto){
    vector<Punto>::iterator posicion;
    bool encontrado = false;
    for (posicion = ruta.begin(); posicion != ruta.end() && !encontrado ; ++posicion){
        if ((*posicion) == punto){
            encontrado = true;
        }
    }
    if (!encontrado){
        posicion = ruta.end();
    }

    return posicion;
}

string Ruta::getNombre() const {
    return nombre;
}

void Ruta::setNombre(string nombre){
    this->nombre = nombre;
}
    
int Ruta::getNumPuntos() const{
    return ruta.size();
}


void Ruta::insertarPunto(Punto punto){
    ruta.push_back(punto);
}

void Ruta::eliminarPunto(Punto punto){
    vector<Punto>::iterator posicion = buscarPunto(punto);
    if (posicion != ruta.end()){
        ruta.erase(posicion);
    }
}
bool Ruta::operator==(const Ruta & otra){
    bool iguales = this->nombre == otra.nombre && getNumPuntos() == otra.getNumPuntos();
    for (auto it = begin(); it != end() && iguales; ++it){
        auto it_otra = it;
        if (!((*it) == (*it_otra)))
            iguales = false;
    }    
    return iguales;
}

bool Ruta::operator==(const std::string & nombre_ruta){
    return this->nombre == nombre_ruta;
}

void Ruta::vaciar(){
    ruta.clear();
    nombre = "";
}

Ruta::iterator::iterator(const vector<Punto>::iterator & vit){
    it = vit;
}

Ruta::iterator::iterator(const Ruta::iterator & otro): it(otro.it){}


bool Ruta::iterator::operator!=(const Ruta::iterator & otro){
    return it != otro.it;
}

Punto & Ruta::iterator::operator*(){
    return (*it);
}

Ruta::iterator  Ruta::iterator::operator++(){
    return ++it;
}

Ruta::iterator Ruta::iterator::operator++(int){
    return it++;
}

Ruta::iterator  Ruta::iterator::operator--(){
    return --it;
}

Ruta::iterator Ruta::iterator::operator--(int){
    return it--;
}

Ruta::const_iterator::const_iterator(const vector<Punto>::const_iterator & vit){
    it = vit;
}

Ruta::const_iterator::const_iterator(const Ruta::const_iterator & otro): it(otro.it){}


bool Ruta::const_iterator::operator!=(const Ruta::const_iterator & otro){
    return it != otro.it;
}

Punto Ruta::const_iterator::operator*(){
    return (*it);
}

Ruta::const_iterator  Ruta::const_iterator::operator++(){
    return ++it;
}

Ruta::const_iterator Ruta::const_iterator::operator++(int){
    return it++;
}

Ruta::const_iterator  Ruta::const_iterator::operator--(){
    return --it;
}

Ruta::const_iterator Ruta::const_iterator::operator--(int){
    return it--;
}

Ruta::iterator Ruta::begin(){
    return iterator(ruta.begin());
}

Ruta::iterator Ruta::end(){
    return iterator(ruta.end());
}

Ruta::const_iterator Ruta::cbegin() const{
    return const_iterator(ruta.cbegin());
}

Ruta::const_iterator Ruta::cend() const{
    return const_iterator(ruta.cend());
}

istream & operator>>(istream & is, Ruta & r){
    // Ejemplo de ruta
    // R1 5 (34.520418555522845,69.20082090000005) (52.50786264022465,13.426141949999987) (7.406652727545182,12.344585699999925) (-0.18659558628491132,-78.4305382) (40.40051528912146	,-3.5916460749999635)
    // nombre, numero de puntos, puntos entre parentesis separados por espacios
    string nombre_aux;
    int numero;
    Punto punto;
    if (is){   
        is >> nombre_aux;
        if (is){
            is >> numero;
            for (int i=0; i < numero && is; i++){
                is >> punto;
                r.insertarPunto(punto);
            }
            r.nombre = nombre_aux;

            }
    }
    return is;
}
ostream & operator<<(ostream & os, const Ruta & r){
    os << r.nombre << " " << r.getNumPuntos() << " ";
    for (auto it = r.cbegin(); it != r.cend(); ++it){
        os << (*it) << " ";
    }

    return os;
}