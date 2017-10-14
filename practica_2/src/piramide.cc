// Manuel Jiménez Bernal

#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/piramide.h"
#include <vector>
#include <iostream>

using namespace std;

/**
* Constructor
*/
Piramide::Piramide(){
	tam=50;
	this->createArrayData();
}

/**
* Constructor por parametro
*/
Piramide::Piramide(float val){
	tam=val;	
	this->createArrayData();
}

/**
* Crea las estructuras de datos para contener la información que dibuja una pirámide
*/
void Piramide::createArrayData(){
	Objeto3D::setNumTri(15);
	//vertices
	vertices.push_back(_vertex3f(-tam/2,0,0));
	vertices.push_back(_vertex3f(tam/2,0,0));
	vertices.push_back(_vertex3f(-tam/2,0,tam));
	vertices.push_back(_vertex3f(tam/2,0,tam));
	vertices.push_back(_vertex3f(0,tam,tam/2));
	// triangulos
	indices.push_back(_vertex3i(1,2,0));
	indices.push_back(_vertex3i(3,2,1));
	indices.push_back(_vertex3i(1,4,0));
	indices.push_back(_vertex3i(3,4,1));
	indices.push_back(_vertex3i(2,4,3));
	indices.push_back(_vertex3i(0,4,2));
	Objeto3D::colorear();
}

