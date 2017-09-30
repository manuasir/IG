#ifdef _WIN32
#include <windows.h>
#endif
#include <cubo.h>
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

	for(int i=0;i<vertices.size();i+=3){
		std::cout << "color";
		if(i%2 == 0 ){
			colores.push_back(0);
			colores.push_back(1);
			colores.push_back(0);
		}else{
			colores.push_back(1);
			colores.push_back(0);
			colores.push_back(1);
		}
		colores.push_back(1);
	}


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

