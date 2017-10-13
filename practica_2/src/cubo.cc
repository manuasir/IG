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

	vertices.push_back(_vertex3f(50.0f,50.0f,50.0f));				//0
	vertices.push_back(_vertex3f(50.0f,50.0f,-50.0f));				//1
	vertices.push_back(_vertex3f(50.0f,-50.0f,50.0f));				//2
	vertices.push_back(_vertex3f(-50.0f,50.0f,50.0f));				//3
	vertices.push_back(_vertex3f(50.0f,-50.0f,-50.0f));			//4
	vertices.push_back(_vertex3f(-50.0f,50.0f,-50.0f));			//5
	vertices.push_back(_vertex3f(-50.0f,-50.0f,50.0f));			//6
	vertices.push_back(_vertex3f(-50.0f,-50.0f,-50.0f));			//7

	indices.push_back(_vertex3i(0,3,6));			//Primera cara
	indices.push_back(_vertex3i(0,6,2));			//Primera cara
	indices.push_back(_vertex3i(0,1,4));			//Segunda cara
	indices.push_back(_vertex3i(0,2,4));			//Segunda cara
	indices.push_back(_vertex3i(0,3,1));			//Tercera cara
	indices.push_back(_vertex3i(1,5,3));			//Tercera cara
	indices.push_back(_vertex3i(1,5,7));			//Cuarta cara
	indices.push_back(_vertex3i(1,7,4));			//Cuarta cara
	indices.push_back(_vertex3i(3,7,5));			//Quinta cara
	indices.push_back(_vertex3i(3,6,7));			//Quinta cara
	indices.push_back(_vertex3i(2,7,6));			//Sexta cara
	indices.push_back(_vertex3i(2,4,7));			//Sexta cara

	Objeto3D::colorear();
}

