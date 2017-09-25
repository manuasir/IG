#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdio>
#include <iostream>
#include "objeto3D.h"

Objeto3D::Objeto3D(){
    axisSize = 200;
	createArrayData();

}

void Objeto3D::changeAxisSize(float newSize) {
	axisSize = newSize;
}

void Objeto3D::draw(){
	std::cout << "ENTRO EN DRAW\n";
	drawArray();
}

void Objeto3D::createArrayData(){
	colorArray[0] = 1; colorArray[1] = 1; colorArray[2] = 0;
	colorArray[3] = 0; colorArray[4] = 1; colorArray[5] = 1;
	colorArray[6] = 1; colorArray[7] = 0; colorArray[8] = 1;
	//colorArray[9] = 0; colorArray[10] = 0; colorArray[11] = 1;
	

	vertexArray[0] = -axisSize/2; vertexArray[1] = 0; vertexArray[2] = 0;
	vertexArray[3] = axisSize/2; vertexArray[4] = 0; vertexArray[5] = 0;
	vertexArray[6] = 0; vertexArray[7] = -axisSize/2; vertexArray[8] = 0;
	//vertexArray[9] = 0; vertexArray[10] = -axisSize; vertexArray[11] = 0;
	
}

void Objeto3D::drawArray(){
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertexArray );
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, colorArray );
	glDrawArrays( GL_LINES, 0, 3 ) ;
}
