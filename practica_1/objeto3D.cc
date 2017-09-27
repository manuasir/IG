#ifdef _WIN32
#include <windows.h>
#endif

#include <cstdio>
#include <iostream>
#include "objeto3D.h"

Objeto3D::Objeto3D(){


}


void Objeto3D::dibujar(){
	cout << "el tamaño de vertices es " << vertices.size();
glBegin(GL_TRIANGLES);

	//for (int i= 0; i < triangulos.size(); i++){
		glColor3f(0, 1, 0);
		glEnableClientState(GL_VERTEX_ARRAY);
 		glEnable(GL_CULL_FACE);
		glVertexPointer(3, GL_FLOAT, 0, vertices[0][0] );
		 //glEnableClientState(GL_COLOR_ARRAY);
		// glColorPointer(3, GL_FLOAT, 0, colores );
		glDrawArrays( GL_TRIANGLES, 0, 3 ) ;
		/*
		glVertex3f(vertices[0][0],vertices[0][1],vertices[0][2]);
		glVertex3f(vertices[1][0],vertices[1][1],vertices[1][2]);
		glVertex3f(vertices[2][0],vertices[2][1],vertices[2][2]);
		*/
	//}

	glEnd();
}
