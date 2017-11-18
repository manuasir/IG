// Manuel Jiménez Bernal

#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h> // pulls in declaration of malloc, free
#include <vector>
#include "vertex.h"

using namespace std;

/**
* Clase principal que contiene las estructuras de datos para modelar cosas
*/
class Objeto3D {

public:

	vector<_vertex3f> vertices;
	vector<_vertex3f> colores;
	vector<_vertex3f> coloresPares;
	vector<_vertex3f> coloresImpares;
	vector<_vertex3i> indices;
	vector<_vertex3i> indicesPares;
	vector<_vertex3i> indicesImpares;
	vector<Objeto3D> children;

	int num_tri;
	float rotateX,rotateY,rotateZ,scaleX,scaleY,scaleZ,translateX,translateY,translateZ,grados;
	GLenum modePolygon = GL_LINE;
	bool chess;

public:
	Objeto3D();
	void dibujar();
	void setNumTri(int num){ num_tri=num; }
	void setGlEnumPolygon(GLenum elem){ modePolygon=elem; }
	const GLenum getGlEnumPolygon() const { return modePolygon; }
	void colorear();
	void colorearChess();
	void setChess(bool val){ chess=val; }
	bool getChess(){ return chess; }
	void clear();
	vector<_vertex3i> & getIndices(){ return indices; }
	vector<_vertex3f> & getVertices(){ return vertices; }
	void setVertices(vector<_vertex3f> vec){ vertices = vec; }
	void setIndices(vector<_vertex3i> vec){ indices = vec; }
	void setVertice(_vertex3f vec){ vertices.push_back(vec); }
	void setIndice(_vertex3i vec){ indices.push_back(vec); }
	_vertex3f getVertice(int i){ return vertices[i]; }
	_vertex3i getIndice(int i){ return indices[i]; }
	int getTamVertices(){ return vertices.size(); }
	int getTamIndices(){ return indices.size(); }
	void dibujaObjeto();
	void rotar(float angulo,float x,float y,float z){ grados=angulo, rotateX=x; rotateY=y; rotateZ=z; };
	void escalar(float x,float y,float z){ scaleX=x; scaleY=y; scaleZ=z; };
	void trasladar(float x,float y,float z){ translateX=x; translateY=y; translateZ=z; };
	void setHijo(Objeto3D obj){ children.push_back(obj); };
	Objeto3D & getHijo(int i){ return children[i]; };
};
#endif
