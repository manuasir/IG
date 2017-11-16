#include "../include/objeto-jerarquico.h"
using namespace std;

ObjetoJerarquico::ObjetoJerarquico(){
	anguloArriba=0;
	ejeX=0;
	ejeY=1.0;
};

void ObjetoJerarquico::dibujaBase(){
	//glPushMatrix();
		base.trasladar(-10,0,0);
		base.escalar(0.5,0.1,0.5);
		//base.dibujar();
	//glPopMatrix();
}

void ObjetoJerarquico::dibujaPrimerCuerpo(){
	//glPushMatrix();
		tetra.trasladar(0,5,0);
		tetra.escalar(0.2,1,0.1);
		base.setHijo(tetra);
	//glPopMatrix();
}

void ObjetoJerarquico::dibujaSegundoCuerpo(){
	//glPushMatrix();
		tetra.trasladar(0,55,0);
		tetra.escalar(0.2,0.5,0.1);
		base.setHijo(tetra);
		//tetra.dibujar();
	//glPopMatrix();
}

void ObjetoJerarquico::dibujaTercerCuerpo(){
	//glPushMatrix();
		tetra.trasladar(0,80,0);
		tetra.escalar(0.1,0.5,0.1);
		base.setHijo(tetra);
		//tetra.dibujar();
	//glPopMatrix();
}

void ObjetoJerarquico::dibujaPlataforma(){
	//glPushMatrix();
		tetra.trasladar(-7,95,0);
		tetra.rotar(90.0, 1.0, 0.0, 0.0);
		tetra.escalar(0.3,1,0.1);
		base.setHijo(tetra);
		//base.dibujar();
	//glPopMatrix();
}

void ObjetoJerarquico::dibujaCuerda(){
	//glPushMatrix();
		tetra.trasladar(0,90,50);
		tetra.rotar(180.0, 1.0, 0.0, 0.0);
		tetra.escalar(0.05,1,0.05);
		base.setHijo(tetra);
		//base.dibujar();
	//glPopMatrix();
}

void ObjetoJerarquico::dibujaObjeto(){
	//glPushMatrix();
		base.rotar(30,0.0,1.0,0.0);
		base.trasladar(ejeX,0.0,0.0);
		base.dibujar();
		//dibujaBase();
		//dibujaPrimerCuerpo();
		//glPushMatrix();
			//glRotatef(180,1.0,0.0,0.0);
			//dibujaSegundoCuerpo();
			//dibujaTercerCuerpo();
			//glPushMatrix();
			//	glRotatef(anguloArriba,0.0,1.0,0.0);
			//	dibujaPlataforma();
			//	glPushMatrix();
			//		glScalef(1,ejeY,1);
			//		dibujaCuerda();

			//	glPopMatrix();
			//glPopMatrix();
		//glPopMatrix();
	//glPopMatrix();
};

/*
void ObjetoJerarquico::setTipo(Objeto3D::DrawMode tip){
		tipo = tip;
	};
*/