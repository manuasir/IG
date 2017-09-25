#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdio>
#include <iostream>
#include "objeto3D.h"

Objeto3D::Objeto3D(){
    axisSize = 50;
	//createArrayData();
}

void Objeto3D::changeAxisSize(float newSize) {
	axisSize = newSize;
}

void Objeto3D::draw(float * vertexArray, float * colorArray, int n){
	drawArray(vertexArray,colorArray,n);
}


void Objeto3D::drawArray(float * vertexArray, float * colorArray, int n){
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertexArray );
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(n, GL_FLOAT, 0, colorArray );
	glDrawArrays( GL_LINE_LOOP, 0, n ) ;
}
