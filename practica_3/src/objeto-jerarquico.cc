#include "../include/objeto-jerarquico.h"
using namespace std;

ObjetoJerarquico::ObjetoJerarquico(){
	anguloArriba=0;
	ejeX=0;
	ejeY=1.0;
};

void ObjetoJerarquico::dibujaBase(){
	glPushMatrix();
		glTranslatef(-10,0,0);
		glScalef(0.5,0.1,0.5);
		cubo.dibujar();
	glPopMatrix();
}

void ObjetoJerarquico::dibujaPrimerCuerpo(){
	glPushMatrix();
		glTranslatef(0,5,0);
		glScalef(0.2,1,0.1);
		tetra.dibujar();
	glPopMatrix();
}

void ObjetoJerarquico::dibujaSegundoCuerpo(){
	glPushMatrix();
		glTranslatef(0,55,0);
		glScalef(0.2,0.5,0.1);
		tetra.dibujar();
	glPopMatrix();
}

void ObjetoJerarquico::dibujaTercerCuerpo(){
	glPushMatrix();
		glTranslatef(0,80,0);
		glScalef(0.1,0.5,0.1);
		tetra.dibujar();
	glPopMatrix();
}

void ObjetoJerarquico::dibujaPlataforma(){
	glPushMatrix();
		glTranslatef(-7,95,0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(0.3,1,0.1);
		cubo.dibujar();
	glPopMatrix();
}

void ObjetoJerarquico::dibujaCuerda(){
	glPushMatrix();
		glTranslatef(0,90,50);
		glRotatef(180.0, 1.0, 0.0, 0.0);
		glScalef(0.05,1,0.05);
		cubo.dibujar();
	glPopMatrix();
}

void ObjetoJerarquico::dibujaObjeto(){
	glPushMatrix();
		glRotatef(30,0.0,1.0,0.0);
		glTranslatef(ejeX,0.0,0.0);
		dibujaBase();
		dibujaPrimerCuerpo();
		glPushMatrix();
			//glRotatef(180,1.0,0.0,0.0);
			dibujaSegundoCuerpo();
			dibujaTercerCuerpo();
			glPushMatrix();
				glRotatef(anguloArriba,0.0,1.0,0.0);
				dibujaPlataforma();
				glPushMatrix();
					glScalef(1,ejeY,1);
					dibujaCuerda();

				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
};

/*
void ObjetoJerarquico::setTipo(Objeto3D::DrawMode tip){
		tipo = tip;
	};
*/