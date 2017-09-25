#ifndef _CUBO_H
#define _CUBO_H
#include "objeto3D.h"

class Cubo : public Objeto3D
{
private:

	float vertexArray[12];
	float colorArray[12];

public:
Cubo();
void createArrayData();
void draw();

};
#endif
