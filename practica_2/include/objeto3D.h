// Manuel Jiménez Bernal


#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h> // pulls in declaration of malloc, free
#include <vector>
#include "vertex.h"

using namespace std;

class Objeto3D {

public:

	vector<_vertex3f> vertices;
	vector<float> colores;
	vector<float> coloresPares;
	vector<float> coloresImpares;
	vector<_vertex3i> indices;
	vector<_vertex3i> indicesPares;
	vector<_vertex3i> indicesImpares;

	int num_tri;
	GLenum mode;
	GLenum modePolygon;
	bool chess;

public:
	Objeto3D();
	void dibujar();
	void setNumTri(int num){ num_tri=num; }
	void setGlEnum(GLenum elem){ mode=elem; }
	void setGlEnumPolygon(GLenum elem){ modePolygon=elem; }
	void colorear();
	void colorearChess();
	void setChess(bool val){ chess=val; }
	void clear();
	vector<_vertex3i> & getIndices(){ cout << "devolviendo indices..."; return indices; }
	vector<_vertex3f> & getVertices(){ return vertices; }
	void setVertices(vector<_vertex3f> vec){ vertices = vec; }
	void setIndices(vector<_vertex3i> vec){ indices = vec; }
	void setVertice(_vertex3f element){ vertices.push_back(element); }
	void setIndice(_vertex3i element){ indices.push_back(element); }

};

#endif
