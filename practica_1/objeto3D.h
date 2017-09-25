#ifndef _OBJETO3D_H
#define _OBJETO3D_H

class Objeto3D {

private:
	float axisSize;

public:
	Objeto3D();
	void changeAxisSize(float newSize);
	void draw(float * vertexArray, float * colorArray, int n);

private:
	void drawArray(float * vertexArray, float * colorArray, int n);
};
#endif
