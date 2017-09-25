#ifdef _WIN32
#include <windows.h>
#endif
#include <cubo.h>

Cubo::Cubo(){
	createArrayData();
}
void Cubo::createArrayData(){
		colorArray[0] = 1; colorArray[1] = 1; colorArray[2] = 0;
		colorArray[3] = 0; colorArray[4] = 1; colorArray[5] = 1;
		colorArray[6] = 1; colorArray[7] = 0; colorArray[8] = 1;
		//colorArray[9] = 0; colorArray[10] = 0; colorArray[11] = 1;
		

		vertexArray[0] = -200/2; vertexArray[1] = 0; vertexArray[2] = 0;
		vertexArray[3] = 200/2; vertexArray[4] = 0; vertexArray[5] = 0;
		vertexArray[6] = 0; vertexArray[7] = -200/2; vertexArray[8] = 0;
		//vertexArray[9] = 0; vertexArray[10] = -axisSize; vertexArray[11] = 0;
}

void Cubo::draw(){
	Objeto3D::draw(vertexArray,colorArray,3);
}