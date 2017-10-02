// Manuel Jiménez Bernal


#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/cubo.h"
#include <vector>
#include <iostream>

using namespace std;

Cubo::Cubo(){
	tam=50;
	this->createArrayData();
}


Cubo::Cubo(float val){
	tam=val;
	this->createArrayData();
}
void Cubo::createArrayData(){

	Objeto3D::setNumTri(36);
	Objeto3D::mode=GL_POINTS;
	Objeto3D::modePolygon=GL_POINT;
	
	std::cout << "Construyendo";
	vertices.push_back(0);
	vertices.push_back(0);
	vertices.push_back(0);

	vertices.push_back(tam);
	vertices.push_back(0);
	vertices.push_back(0);

	vertices.push_back(0);
	vertices.push_back(tam);
	vertices.push_back(0);

	vertices.push_back(tam);
	vertices.push_back(tam);
	vertices.push_back(0);

	vertices.push_back(0);
	vertices.push_back(0);
	vertices.push_back(tam);

	vertices.push_back(tam);
	vertices.push_back(0);
	vertices.push_back(tam);

	vertices.push_back(0);
	vertices.push_back(tam);
	vertices.push_back(tam);

	vertices.push_back(tam);
	vertices.push_back(tam);
	vertices.push_back(tam);


	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	indices.push_back(1);
	indices.push_back(3);
	indices.push_back(2);

	indices.push_back(2);
	indices.push_back(3);
	indices.push_back(7);

	indices.push_back(2);
	indices.push_back(7);
	indices.push_back(6);

	indices.push_back(1);
	indices.push_back(7);
	indices.push_back(3);

	indices.push_back(1);
	indices.push_back(5);
	indices.push_back(7);

	indices.push_back(6);
	indices.push_back(7);
	indices.push_back(4);

	indices.push_back(7);
	indices.push_back(5);
	indices.push_back(4);

	indices.push_back(0);
	indices.push_back(4);
	indices.push_back(1);

	indices.push_back(1);
	indices.push_back(4);
	indices.push_back(5);

	indices.push_back(2);
	indices.push_back(6);
	indices.push_back(4);

	indices.push_back(0);
	indices.push_back(2);
	indices.push_back(4);

	Objeto3D::colorear();


}

