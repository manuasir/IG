// Manuel Jiménez Bernal


#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h> // pulls in declaration of malloc, free
#include <vector>

using namespace std;

class Objeto3D {

public:

	vector<float> vertices;
	vector<float> colores;
	vector<float> coloresPares;
	vector<float> coloresImpares;
	vector<GLubyte> indices;
	vector<GLubyte> indicesPares;
	vector<GLubyte> indicesImpares;

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
};

#endif
