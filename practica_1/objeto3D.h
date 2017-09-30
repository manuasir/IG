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

public:
	Objeto3D();
	void dibujar();
	void createArray();
	vector<float> getVertices() { return vertices; };
	void setVertices(vector<float> verts) { vertices=verts; };
	vector<GLubyte> getIndices() { return indices; };
	void setIndices(vector<GLubyte> index) { indices=index; };
};

#endif
