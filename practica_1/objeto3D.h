#ifndef _OBJETO3D_H
#define _OBJETO3D_H

class Objeto3D {

private:
	float axisSize;
	float vertexArray[12];
	float colorArray[12];

public:
	Objeto3D();
	void changeAxisSize(float newSize);
	void draw();

private:
	void createArrayData();
	void drawArray();
};
#endif
