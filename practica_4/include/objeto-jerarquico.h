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
	float ejeX,ejeY,ejeZ,ejeXcuerda;
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
	void avanzarPlataforma(){ if(ejeX <= 200) ejeX++; }
	void retrocederPlataforma(){ if(ejeX >= -200) ejeX--; }
	void subir(){ if(ejeY >= 0) ejeY-=0.05; }
	void bajar(){ if(ejeY <= 10) ejeY+=0.05; }
	void avanzarCuerda(){ if(ejeXcuerda < 48) ejeXcuerda++; }
	void retrocederCuerda(){ if(ejeXcuerda >= 17.5) ejeXcuerda--; }
	virtual void dibujar(){ construir(); }
	int move(unsigned char Tecla1);
};

#endif