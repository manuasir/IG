// Manuel Jiménez Bernal

#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include "../include/objeto3D.h"

/**
* Constructores
*/
Objeto3D::Objeto3D(){
	chess=false;
	rotateX=0;
	rotateY=0;
	rotateZ=0;
	scaleX=1;
	scaleY=1;
	scaleZ=1;
	translateX=0;
	translateY=0;
	translateZ=0;
	grados=0;
}


/**
* Limpia todos los vectores
*/
void Objeto3D::clear(){
	colores.clear();
	coloresPares.clear();
	coloresImpares.clear();
	indices.clear();
	indicesPares.clear();
	indicesImpares.clear();
	vertices.clear();
	children.clear();
}

/**
* Rellena el vector de colores
*/
void Objeto3D::colorear(){
	for(int i=0;i<vertices.size();i++){
		colores.push_back(_vertex3f(0,0,0));
	}
}

/**
* Rellena el vector de colores en modo ajedrez
*/
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

/**
* Esta función se llama 30 veces por segundo (30 FPS)
*/
void Objeto3D::dibujaObjeto(){
			cout << "dentro de dibujaobjeto... " << endl;

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
		cout << "glDrawElements... " << endl;

		glColorPointer( 3, GL_FLOAT, 0, colores.data());
		glDrawElements( GL_TRIANGLES, indices.size()*3 ,GL_UNSIGNED_INT, indices.data() ) ;	
	}	
}

void Objeto3D::dibujar(){
	//cout << "dibujando objeto3d..." << endl;
	glPushMatrix();
		cout << "push en dibujar Objeto3D" << endl;
		glTranslatef(translateX,translateY,translateZ);
		glRotatef(grados,rotateX,rotateY,rotateZ);
		glScalef(scaleX,scaleY,scaleZ);
		cout << "dibujaobjeto..." << endl;

		dibujaObjeto();
		if(children.size()>0)
			for(int i=0;i<children.size();++i){
				//glPushMatrix();
					cout << "dibujando hijo " << i << endl;
					children[i].dibujar();
				//glPopMatrix();
			}
		cout << "pop en dibujar Objeto3D" << endl;
	glPopMatrix();
}