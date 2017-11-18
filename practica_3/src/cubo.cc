// Manuel Jiménez Bernal

#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/cubo.h"
#include <vector>
#include <iostream>

using namespace std;

/**
* Constructor
*/
Cubo::Cubo(){
	tam=50;
	this->createArrayData();
}

/**
* Constructor por parametro
*/
Cubo::Cubo(float val){
	tam=val;
	this->createArrayData();
}

/**
* Crea las estructuras de datos para contener la información que dibuja un cubo
*/
void Cubo::createArrayData(){

	Objeto3D::setNumTri(36);
	// vertices
	vertices.push_back(_vertex3f(0,0,0));
	vertices.push_back(_vertex3f(tam,0,0));
	vertices.push_back(_vertex3f(0,tam,0));
	vertices.push_back(_vertex3f(tam,tam,0));
	vertices.push_back(_vertex3f(0,0,tam));			
	vertices.push_back(_vertex3f(tam,0,tam));			
	vertices.push_back(_vertex3f(0,tam,tam));			
	vertices.push_back(_vertex3f(tam,tam,tam));			
	// orden de los triangulos
	indices.push_back(_vertex3i(0,1,2));
	indices.push_back(_vertex3i(1,3,2));
	indices.push_back(_vertex3i(2,3,7));
	indices.push_back(_vertex3i(2,7,6));
	indices.push_back(_vertex3i(1,7,3));
	indices.push_back(_vertex3i(1,5,7));
	indices.push_back(_vertex3i(6,7,4));
	indices.push_back(_vertex3i(7,5,4));
	indices.push_back(_vertex3i(0,4,1));
	indices.push_back(_vertex3i(1,4,5));
	indices.push_back(_vertex3i(2,6,4));
	indices.push_back(_vertex3i(0,2,4));
}

