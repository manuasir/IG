// Manuel Jiménez Bernal

#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/tetraedro.h"
#include <vector>
#include <iostream>

using namespace std;

Tetraedro::Tetraedro(){
	tam=50;
	this->createArrayData();
}


Tetraedro::Tetraedro(float val){
	tam=val;	
	this->createArrayData();
}

void Tetraedro::createArrayData(){
	Objeto3D::setNumTri(12);
	Objeto3D::modePolygon=GL_POINT;
	vertices.push_back(_vertex3f(-tam/2,0,0));
	vertices.push_back(_vertex3f(tam/2,0,0));
	vertices.push_back(_vertex3f(0,0,tam));
	vertices.push_back(_vertex3f(0,tam,tam/2));

	indices.push_back(_vertex3i(0,1,3));
	indices.push_back(_vertex3i(2,3,1));
	indices.push_back(_vertex3i(0,3,2));
	indices.push_back(_vertex3i(1,2,0));

	Objeto3D::colorear();
}

