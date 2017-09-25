#ifdef _WIN32
#include <windows.h>
#endif
#include <cubo.h>

Cubo::Cubo(){	
	createArrayData();
}
void Cubo::createArrayData(){
	colorArray[0] = 1; colorArray[1] = 1; colorArray[2] = 0;

	vertexArray[0] = 0; vertexArray[1] = 0; vertexArray[2] = 0;
	vertexArray[3] = 0; vertexArray[4] = 100; vertexArray[5] = 100;
	vertexArray[6] = 100; vertexArray[7] = 100; vertexArray[8] = 100;
	vertexArray[9] = 100; vertexArray[10] = 0; vertexArray[11] = 100;
	vertexArray[12] = 100; vertexArray[13] = 100; vertexArray[14] = 0;
	vertexArray[15] = 0; vertexArray[16] = 100; vertexArray[17] = 0;
	vertexArray[18] = 0; vertexArray[19] = 0; vertexArray[20] = 100;
	vertexArray[21] = 100; vertexArray[22] = 0; vertexArray[23] = 0;
}

void Cubo::draw(){
	Objeto3D::draw(vertexArray,colorArray,8);
}