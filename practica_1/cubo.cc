#ifdef _WIN32
#include <windows.h>
#endif
#include <cubo.h>
#include <vector>
#include <iostream>

using namespace std;
Cubo::Cubo(){	
	this->createArrayData();
}
void Cubo::createArrayData(){

	Objeto3D::setNumTri(36);

	std::cout << "COnstruyendo";
	vertices.push_back(0);
	vertices.push_back(0);
	vertices.push_back(0);

	vertices.push_back(100);
	vertices.push_back(0);
	vertices.push_back(0);

	vertices.push_back(0);
	vertices.push_back(100);
	vertices.push_back(0);

	vertices.push_back(100);
	vertices.push_back(100);
	vertices.push_back(0);

	vertices.push_back(0);
	vertices.push_back(0);
	vertices.push_back(100);

	vertices.push_back(100);
	vertices.push_back(0);
	vertices.push_back(100);

	vertices.push_back(0);
	vertices.push_back(100);
	vertices.push_back(100);

	vertices.push_back(100);
	vertices.push_back(100);
	vertices.push_back(100);


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

}

