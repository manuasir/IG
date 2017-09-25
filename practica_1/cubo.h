#ifndef _CUBO_H
#define _CUBO_H
#include "objeto3D.h"

class Cubo : public Objeto3D
{
private:
	float vertexArray[24];
	float colorArray[3];

public:
Cubo();
void createArrayData();
void draw();

};
#endif
