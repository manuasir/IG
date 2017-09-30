#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include "objeto3D.h"

Objeto3D::Objeto3D(){
	//vertices.push_back(0,100,0,0,0,100,100,0,-50,-100,0,-50);
	this->createArray();
}

void Objeto3D::createArray(){
	

	
}

void Objeto3D::dibujar(){
	std::cout << "Pintando " << vertices.size() << " " << vertices[0] << endl;

	//createArray();
	//glColor3f(1, 1, 0);
	glEnableClientState(GL_VERTEX_ARRAY);
 	//glEnable(GL_CULL_FACE);
	glVertexPointer(3, GL_FLOAT, 0, vertices.data() );
	glDrawElements( GL_TRIANGLES, 3,GL_UNSIGNED_BYTE, indices.data() ) ;	
}
