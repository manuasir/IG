#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h> // pulls in declaration of malloc, free
#include <vector>
#include <map>

using namespace std;



class Objeto3D {

protected:
	
	vector< vector<GLfloat> > vertices;
	//vector<GLuint[3]> lados;
	//map<int,vector<GLfloat[3]> > triangulos;
	GLubyte triangulos;

public:

	Objeto3D();
	void dibujar();

private:
};

#endif
