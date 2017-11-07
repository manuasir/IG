#ifndef _OBJETO_JERARQUICO_
#define _OBJETO_JERARQUICO_

#include "objeto3D.h"
#include <GL/glut.h>

class ObjetoJerarquico: public Objeto3D{
private:
	//Objeto3D::DrawMode tipo = Objeto3D::CHESS;
public:
	//Objeto3D objeto;
	//Cubo cubo;
	ObjetoJerarquico();
	void dibujaBase();
	void dibujaTapa();
	void dibujaObjeto(float angulo,int horizontal, int vertical);
	//void setTipo(Objeto3D::DrawMode tip);
};

#endif