#ifndef _OBJETO_JERARQUICO_
#define _OBJETO_JERARQUICO_

#include <GL/glut.h>

#include "cubo.h"
#include "tetraedro.h"

class ObjetoJerarquico: public Objeto3D{
private:
	Cubo base;
	Cubo plataforma;
	Cubo cuerpo;
	Cubo cuerda;
	float ejeX,ejeY,ejeZ,ejeXcuerda,ejeZcuerda;
	float anguloArriba;
public:

	ObjetoJerarquico();
	void dibujaBase();
	void dibujaCuerpo();
	void construir();
	void dibujaPlataforma();
	void dibujaCuerda();
	void girarPlataformaIzq(){ anguloArriba++; }
	void girarPlataformaDer(){ anguloArriba--; }
	void avanzarPlataforma(){ ejeX++; }
	void retrocederPlataforma(){ ejeX--; }
	void subir(){ ejeY-=0.05; }
	void bajar(){ ejeY+=0.05; }
	virtual void dibujar(){ construir(); }
	int move(unsigned char Tecla1);
};

#endif