#ifndef _OBJETO_JERARQUICO_
#define _OBJETO_JERARQUICO_

#include "cubo.h"
#include <GL/glut.h>

class ObjetoJerarquico: public Objeto3D{
private:
	//Objeto3D::DrawMode tipo = Objeto3D::CHESS;
	Cubo cubo;
public:
	//Objeto3D objeto;
	
	ObjetoJerarquico();
	void dibujaBase();
	void dibujaTapa();
	void dibujaObjeto();
	//void setTipo(Objeto3D::DrawMode tip);
};

#endif