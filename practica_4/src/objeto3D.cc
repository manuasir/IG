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

void Objeto3D::generarNormales() {
	generarNormalesCaras();
	generarNormalesVertices();
}

void Objeto3D::generarNormalesCaras() {

	// Calculamos las normales de las caras
	vector<_vertex3f> normales_caras;

	for(int i = 0; i < indices.size(); i++)	{

		_vertex3f A, B, C;
		A = vertices[indices[i]._0];
		B = vertices[indices[i]._1];
		C = vertices[indices[i]._2];

		_vertex3f ab, bc, normal;

		ab.x = B.x - A.x;
		ab.y = B.y - A.y;
		ab.z = B.z - A.z;

		bc.x = C.x - B.x;
		bc.y = C.y - B.y;
		bc.z = C.z - B.z;

		// Calculamos el producto vectorial (https://es.wikipedia.org/wiki/Producto_vectorial)
		normal.x = ab.y * bc.z - ab.z * bc.y;
		normal.y = ab.z * bc.x - ab.x * bc.z;
		normal.z = ab.x * bc.y - ab.y * bc.x;

		// Antonio para normalizar
		float modulo=sqrt(normal.x*normal.x+normal.y*normal.y+normal.z*normal.z);
		normal.x=normal.x/modulo;
		normal.y=normal.y/modulo;
		normal.z=normal.z/modulo;
		// Fin Antonio

		normales_caras.push_back(normal);

	}
	normalesCaras = normales_caras;
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

void Objeto3D::generarNormalesVertices()
{

    // Generamos las normales de los vertices

    vector<_vertex3f> normales_vertices;


    // Recorremos los vertices
    for(int i = 0; i < vertices.size(); i++)
    {

        _vertex3f verticeactual = vertices[i];
        _vertex3f normal(0,0,0);

        // Recorremos las caras
        for(int h = 0; h < indices.size(); h++)
        {
            // Comprobamos si el vertice esta en otra cara (por la posicion)
            if (indices[h]._0 == i || indices[h]._1 == i || indices[h]._2 == i)
            {
                normal = _vertex3f(normal.x + normalesCaras[h].x,
                                    normal.y + normalesCaras[h].y,
                                    normal.z + normalesCaras[h].z);
            }

        }

        // Antonio para normalizar
        float modulo=sqrt(normal.x*normal.x+normal.y*normal.y+normal.z*normal.z);
        normal.x=normal.x/modulo;
        normal.y=normal.y/modulo;
        normal.z=normal.z/modulo;
        // Fin Antonio

        // La agregago al vector
        normales_vertices.push_back(normal);
    }

    normalesVertices=normales_vertices;

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

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState( GL_COLOR_ARRAY);
	glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
	glVertexPointer(3, GL_FLOAT, 0, vertices.data());
	glPolygonMode(GL_FRONT_AND_BACK,modePolygon);
	glPointSize(5);

	if(chess){
		colorearChess();
		glColorPointer( 3, GL_FLOAT, 0, coloresPares.data());
		glDrawElements( GL_TRIANGLES, indicesPares.size()*3 ,GL_UNSIGNED_INT, indicesPares.data() ) ;
		glColorPointer( 3, GL_FLOAT, 0, coloresImpares.data());
		glDrawElements( GL_TRIANGLES, indicesImpares.size()*3 ,GL_UNSIGNED_INT, indicesImpares.data() ) ;

	} else{
		colorear();
		glColorPointer( 3, GL_FLOAT, 0, colores.data());
		glDrawElements( GL_TRIANGLES, indices.size()*3 ,GL_UNSIGNED_INT, indices.data() ) ;
	}
}

void Objeto3D::dibujar(){
	glPushMatrix();
	glTranslatef(translateX,translateY,translateZ);
	glRotatef(grados,rotateX,rotateY,rotateZ);
	glScalef(scaleX,scaleY,scaleZ);
	dibujaObjeto();
	if (children.size()>0)
	for (int i=0;i<children.size();++i){
		glPushMatrix();
		if (getChess()){
			children[i].setChess(true);
		}
		children[i].setGlEnumPolygon(modePolygon);
		children[i].dibujar();
		children[i].setChess(chess);
		glPopMatrix();
	}
	glPopMatrix();
}
