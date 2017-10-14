// Manuel Jiménez Bernal

#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include "../include/objeto3D.h"

Objeto3D::Objeto3D(){

}

void Objeto3D::clear(){
	// vaciar arrays
	colores.clear();
	coloresPares.clear();
	coloresImpares.clear();
	indices.clear();
	indicesPares.clear();
	indicesImpares.clear();
	vertices.clear();
}

void Objeto3D::colorear(){
	for(int i=0;i<vertices.size();i++){
		colores.push_back(_vertex3f(0,0,0));
	}
}

void Objeto3D::colorearChess(){
	for(int i=0;i<indices.size();i++){
		if(i%2 == 0){
			indicesPares.push_back(indices[i]);

		}else{
			indicesImpares.push_back(indices[i]);
		}
	}

	for(int i=0;i<vertices.size();i++){
		coloresPares.push_back(_vertex3f(1,0,0));
		coloresImpares.push_back(_vertex3f(0,0,1));
	}	
}

void Objeto3D::dibujar(){
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState( GL_COLOR_ARRAY );
	glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
	glVertexPointer(3, GL_FLOAT, 0, vertices.data() );
	glPolygonMode(GL_FRONT_AND_BACK,modePolygon);
	glPointSize(5);

	if(chess){
		glColorPointer( 3, GL_FLOAT, 0, coloresPares.data());
		glDrawElements( GL_TRIANGLES, indicesPares.size()*3 ,GL_UNSIGNED_INT, indicesPares.data() ) ;	
		glColorPointer( 3, GL_FLOAT, 0, coloresImpares.data());
		glDrawElements( GL_TRIANGLES, indicesImpares.size()*3 ,GL_UNSIGNED_INT, indicesImpares.data() ) ;	

	}else{
		cout << "Vertices cargados: " << vertices.size() << endl;
		glColorPointer( 3, GL_FLOAT, 0, colores.data());
		glDrawElements( GL_TRIANGLES, indices.size()*3 ,GL_UNSIGNED_INT, indices.data() ) ;	
	}	
}

