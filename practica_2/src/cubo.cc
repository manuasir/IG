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

	vertices.push_back(_vertex3f(0,0,0));				//0
	vertices.push_back(_vertex3f(tam,0,0));				//1
	vertices.push_back(_vertex3f(0,tam,0));				//2
	vertices.push_back(_vertex3f(tam,tam,0));				//3
	vertices.push_back(_vertex3f(0,0,tam));			//4
	vertices.push_back(_vertex3f(tam,0,tam));			//5
	vertices.push_back(_vertex3f(0,tam,tam));			//6
	vertices.push_back(_vertex3f(tam,tam,tam));			//7

	indices.push_back(_vertex3i(0,1,2));			//Primera cara
	indices.push_back(_vertex3i(1,3,2));			//Primera cara
	indices.push_back(_vertex3i(2,3,7));			//Segunda cara
	indices.push_back(_vertex3i(2,7,6));			//Segunda cara
	indices.push_back(_vertex3i(1,7,3));			//Tercera cara
	indices.push_back(_vertex3i(1,5,7));			//Tercera cara
	indices.push_back(_vertex3i(6,7,4));			//Cuarta cara
	indices.push_back(_vertex3i(7,5,4));			//Cuarta cara
	indices.push_back(_vertex3i(0,4,1));			//Quinta cara
	indices.push_back(_vertex3i(1,4,5));			//Quinta cara
	indices.push_back(_vertex3i(2,6,4));			//Sexta cara
	indices.push_back(_vertex3i(0,2,4));			//Sexta cara

	Objeto3D::colorear();
}

