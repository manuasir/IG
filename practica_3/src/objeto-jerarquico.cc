#include "../include/objeto-jerarquico.h"
using namespace std;

ObjetoJerarquico::ObjetoJerarquico(){
	//objeto=cubo;
};

void ObjetoJerarquico::dibujaBase(){
	glPushMatrix();
	glTranslatef(0,0,0);
	glScalef(0.5,0.1,0.5);
	cubo.dibujar();
	glPopMatrix();
}

void ObjetoJerarquico::dibujaPrimerCuerpo(){
	glPushMatrix();
	glTranslatef(0,5,0);
	glScalef(0.5,1,0.5);
	tetra.dibujar();
	glPopMatrix();
}

/*
void ObjetoJerarquico::dibujaObjeto(float angulo, int horizontal, int vertical){
	
	glPushMatrix();
	glRotatef(angulo,0.0,1.0,0.0);
	glTranslatef(horizontal,0,vertical);
	dibujaBase();
	dibujaTapa();
	glPopMatrix();
	
};
*/
void ObjetoJerarquico::dibujaObjeto(){
	
	glPushMatrix();
	glRotatef(30,0.0,1.0,0.0);

	dibujaBase();
	dibujaPrimerCuerpo();

	glPopMatrix();
	
};

/*
void ObjetoJerarquico::setTipo(Objeto3D::DrawMode tip){
		tipo = tip;
	};
	*/