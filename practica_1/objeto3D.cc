#ifdef _WIN32
#include <windows.h>
#endif

#include <cstdio>
#include <iostream>
#include "objeto3D.h"

Objeto3D::Objeto3D(){


}


void Objeto3D::dibujar(){
glBegin(GL_TRIANGLES);

	
		glColor3f(0, 1, 0);

	glVertex3f(-50,0,0 );
	glVertex3f(50,0,0);
	glVertex3f(0,50,0);

	

	glEnd();
}
