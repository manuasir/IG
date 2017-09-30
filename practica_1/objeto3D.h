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
	vector<GLubyte> indices;
	int num_tri;
	GLenum mode;

public:
	Objeto3D();
	void dibujar();
	void createArray();
	void setNumTri(int num){ num_tri=num; }
	void setGlEnum(GLenum elem){ mode=elem; }
};

#endif
