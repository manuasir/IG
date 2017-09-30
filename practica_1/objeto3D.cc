#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include "objeto3D.h"

Objeto3D::Objeto3D(){
}


void Objeto3D::dibujar(){
	std::cout << "Pintando " << vertices.size() << " " << vertices[0] << endl;
	glPolygonMode(GL_FRONT,GL_LINE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState( GL_COLOR_ARRAY );
	glColorPointer( 3, GL_FLOAT, 0, colores.data());
	glVertexPointer(3, GL_FLOAT, 0, vertices.data() );
	glDrawElements( GL_TRIANGLES, num_tri ,GL_UNSIGNED_BYTE, indices.data() ) ;	
}
