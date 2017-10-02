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
	Objeto3D::mode=GL_POINTS;
	Objeto3D::modePolygon=GL_POINT;

	vertices.push_back(-tam/2);
	vertices.push_back(0);
	vertices.push_back(0);

	vertices.push_back(tam/2);
	vertices.push_back(0);
	vertices.push_back(0);

	vertices.push_back(0);
	vertices.push_back(0);
	vertices.push_back(tam);

	vertices.push_back(0);
	vertices.push_back(tam);
	vertices.push_back(tam/2);




	Objeto3D::colorear();


	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);

	indices.push_back(2);
	indices.push_back(0);
	indices.push_back(3);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(3);

}

