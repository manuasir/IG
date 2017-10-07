// Manuel Jiménez Bernal

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
	coloresPares.clear();
	coloresImpares.clear();
	for(int i=0;i<indices.size();i++){
		std::cout << "color";
		colores.push_back(0);
		colores.push_back(0);
		colores.push_back(1);
	}
}

void Objeto3D::colorearChess(){
	colores.clear();
	coloresPares.clear();
	coloresImpares.clear();

	for(int i=0;i<indices.size();i+=3){
		if(i%2 == 0){
			std::cout << "color par";
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
			std::cout << "color impar";
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
	std::cout << "Pintando " << vertices.size() << " " << vertices[0] << endl;
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState( GL_COLOR_ARRAY );
	glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
	glVertexPointer(3, GL_FLOAT, 0, vertices.data() );
	glPolygonMode(GL_FRONT_AND_BACK,modePolygon);
	glPointSize(5);
	glCullFace(GL_FRONT_AND_BACK);
	glEnable(1);


	if(chess){
		glColorPointer( 3, GL_FLOAT, 0, coloresPares.data());
		glDrawElements( mode, num_tri ,GL_UNSIGNED_BYTE, indicesPares.data() ) ;	
		glColorPointer( 3, GL_FLOAT, 0, coloresImpares.data());
		glDrawElements( mode, num_tri ,GL_UNSIGNED_BYTE, indicesImpares.data() ) ;	

	}else{
		glColorPointer( 3, GL_FLOAT, 0, colores.data());
		glDrawElements( mode, num_tri ,GL_UNSIGNED_BYTE, indices.data() ) ;	
	}	
}

