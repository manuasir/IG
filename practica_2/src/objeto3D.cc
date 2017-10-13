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
	for(int i=0;i<indices.size();i++){
		colores.push_back(0);
		colores.push_back(0);
		colores.push_back(1);
	}
}

void Objeto3D::colorearChess(){
	std::cout << "caras " << indices.size() << endl;
	for(int i=0;i<indices.size();i+=3){
		if(i%2 == 0){
			indicesPares.push_back(indices[i]);
			indicesPares.push_back(indices[i+1]);
			indicesPares.push_back(indices[i+2]);

			coloresPares.push_back(0);
			coloresPares.push_back(0);
			coloresPares.push_back(1);

			coloresPares.push_back(0);
			coloresPares.push_back(0);
			coloresPares.push_back(1);

			coloresPares.push_back(0);
			coloresPares.push_back(0);
			coloresPares.push_back(1);

		}
		else{
			indicesImpares.push_back(indices[i]);
			indicesImpares.push_back(indices[i+1]);
			indicesImpares.push_back(indices[i+2]);

			coloresImpares.push_back(1);
			coloresImpares.push_back(0);
			coloresImpares.push_back(0);

			coloresImpares.push_back(1);
			coloresImpares.push_back(0);
			coloresImpares.push_back(0);

			coloresImpares.push_back(1);
			coloresImpares.push_back(0);
			coloresImpares.push_back(0);
		}
	}	
}

void Objeto3D::dibujar(){
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState( GL_COLOR_ARRAY );
	glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
	glVertexPointer(3, GL_FLOAT, 0, vertices.data() );
			cout << "vertices vale" << vertices.size() << endl;

	glPolygonMode(GL_FRONT_AND_BACK,modePolygon);
	glPointSize(5);

	if(chess){
		glColorPointer( 3, GL_FLOAT, 0, coloresPares.data());
		glDrawElements( mode, indicesPares.size() ,GL_UNSIGNED_BYTE, indicesPares.data() ) ;	
		glColorPointer( 3, GL_FLOAT, 0, coloresImpares.data());
		glDrawElements( mode, indicesImpares.size() ,GL_UNSIGNED_BYTE, indicesImpares.data() ) ;	

	}else{
		glColorPointer( 3, GL_FLOAT, 0, colores.data());
		cout << "indice vale" << indices.size() << endl;
		glDrawElements( GL_TRIANGLES, indices.size()/3 ,GL_UNSIGNED_BYTE, indices.data() ) ;	
	}	
}

