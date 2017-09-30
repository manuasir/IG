#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include "../include/objeto3D.h"

Objeto3D::Objeto3D(){

}

void Objeto3D::colorear(){
	colores.clear();
	for(int i=0;i<vertices.size();i+=3){
		std::cout << "color";
		colores.push_back(1);
		colores.push_back(0);
		colores.push_back(0);
	}
}

void Objeto3D::colorearAjedrez(){
	std::cout << "colorear ajedrez " << endl;
	colores.clear();
	bool pair=true;
	for(int i=0;i<vertices.size();i+=9){
		std::cout << "color";
		if(pair){
			colores.push_back(0);
			colores.push_back(1);
			colores.push_back(0);
			colores.push_back(0);
			colores.push_back(1);
			colores.push_back(0);
			colores.push_back(0);
			colores.push_back(1);
			colores.push_back(0);
			pair=false;
		}else{
			colores.push_back(0);
			colores.push_back(0);
			colores.push_back(1);
			colores.push_back(0);
			colores.push_back(0);
			colores.push_back(1);
			colores.push_back(0);
			colores.push_back(0);
			colores.push_back(1);
			pair=true;
		}
	}
}

void Objeto3D::dibujar(){
	std::cout << "Pintando " << vertices.size() << " " << vertices[0] << endl;
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState( GL_COLOR_ARRAY );
	glPolygonMode(GL_FRONT,GL_POINT);
	glColorPointer( 3, GL_FLOAT, 0, colores.data());
	glVertexPointer(3, GL_FLOAT, 0, vertices.data() );
	glPolygonMode(GL_FRONT_AND_BACK,modePolygon);
	glPointSize(5);
	glDrawElements( mode, num_tri ,GL_UNSIGNED_BYTE, indices.data() ) ;	
	//glDrawElements( mode, num_tri ,GL_UNSIGNED_BYTE, indices.data() ) ;	
}
