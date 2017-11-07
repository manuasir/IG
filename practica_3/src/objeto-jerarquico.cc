#include "../include/objeto-jerarquico.h"
using namespace std;

ObjetoJerarquico::ObjetoJerarquico(){
	//objeto=cubo;
};

void ObjetoJerarquico::dibujaBase(){
	/*
	glPushMatrix();
	glTranslatef(0,25,0);
	glScalef(0.5,0.05,0.5);
	objeto.dibujar();
	glPopMatrix();
	*/
}

void ObjetoJerarquico::dibujaTapa(){
	/*
	glPushMatrix();
	glTranslatef(25,38,0);
	glScalef(0.05,0.3,0.5);
	objeto.dibujar();
	glPopMatrix();
	*/
}
void ObjetoJerarquico::dibujaObjeto(float angulo, int horizontal, int vertical){
	/*
	glPushMatrix();
	glRotatef(angulo,0.0,1.0,0.0);
	glTranslatef(horizontal,0,vertical);
	dibujaBase();
	dibujaTapa();
	glPopMatrix();
	*/
};

/*
void ObjetoJerarquico::setTipo(Objeto3D::DrawMode tip){
		tipo = tip;
	};
	*/