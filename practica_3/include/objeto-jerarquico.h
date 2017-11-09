#ifndef _OBJETO_JERARQUICO_
#define _OBJETO_JERARQUICO_

#include <GL/glut.h>

#include "cubo.h"
#include "tetraedro.h"

class ObjetoJerarquico: public Objeto3D{
private:
	//Objeto3D::DrawMode tipo = Objeto3D::CHESS;
	Cubo cubo;
	Tetraedro tetra;
	float anguloArriba;
public:
	//Objeto3D objeto;
	
	ObjetoJerarquico();
	void dibujaBase();
	void dibujaPrimerCuerpo();
	void dibujaSegundoCuerpo();
	void dibujaTercerCuerpo();
	void dibujaObjeto();
	void dibujaPlataforma();
	void dibujaCuerda();
	void girarPlataformaIzq(){ anguloArriba++; }
	void girarPlataformaDer(){ anguloArriba--; }
	//void setTipo(Objeto3D::DrawMode tip);
};

#endif