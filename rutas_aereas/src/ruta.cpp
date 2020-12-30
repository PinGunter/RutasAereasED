/**
  * @file ruta.cpp
  * @brief 
  *
  */
  
#include <iostream>
#include "Ruta.h"

using namespace std;

void allocate(int n){
}

void deallocate(){
	if(ruta != nullptr){
		delete []ruta;
	}
}

void resize(int n){
	
}

void copy(const Ruta &r){

}

Ruta::Ruta(){
	ruta = nullptr;
}

Ruta::~Ruta(){
	deallocate();
}


