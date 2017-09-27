#ifdef _WIN32
#include <windows.h>
#endif
#include <cubo.h>
#include <vector>

Cubo::Cubo(){	
	createArrayData();
}
void Cubo::createArrayData(){

	// Vertices
	triangulos[] = {0,1,2} 
	vector <GLfloat> aux;
	aux.push_back(200);
	aux.push_back(0);
	aux.push_back(0);
	vector <GLfloat> aux1;
	aux1.push_back(0);
	aux1.push_back(200);
	aux1.push_back(0);
	vector <GLfloat> aux2;
	aux2.push_back(0);
	aux2.push_back(0);
	aux2.push_back(200);
	vertices.push_back(aux);
	vertices.push_back(aux1);
	vertices.push_back(aux2);
	/*puntos.push_back(_vertex3f(-tam,	-tam, 	tam));
	puntos.push_back(_vertex3f(tam,	-tam, 	tam));
	puntos.push_back(_vertex3f(tam, 	tam, 	tam));
	puntos.push_back(_vertex3f(-tam, 	tam, 	tam));
    puntos.push_back(_vertex3f(-tam,	-tam,	 -tam));
    puntos.push_back(_vertex3f(tam,	-tam,	 -tam));
    puntos.push_back(_vertex3f(tam,	 tam,	 -tam));
    puntos.push_back(_vertex3f(-tam,	 tam,	 -tam));*/
}

