#include "../include/objeto-jerarquico.h"
using namespace std;

ObjetoJerarquico::ObjetoJerarquico(){
	anguloArriba=0;
	ejeX=0;
	ejeY=1.0;
	chess=false;
	dibujaBase();
	dibujaPrimerCuerpo();
	//dibujaSegundoCuerpo();
	//dibujaTercerCuerpo();
	dibujaPlataforma();
	//dibujaCuerda();
}

int ObjetoJerarquico::move(unsigned char Tecla1){
	if (toupper(Tecla1)=='Z') { 
			girarPlataformaIzq();
			return 0;
	}
	else if (toupper(Tecla1)=='X') { 
			girarPlataformaDer();
			return 0;
	}
	else if (toupper(Tecla1)=='C') { 
			avanzarPlataforma();
			return 0;
	}
	else if (toupper(Tecla1)=='V') { 
			retrocederPlataforma();
			return 0;
	}
	else if (toupper(Tecla1)=='B') { 
			subir();
			return 0;
	}
	else if (toupper(Tecla1)=='N') { 
			bajar();
			return 0;
	} else return 0;
}
void ObjetoJerarquico::dibujaBase(){
	//glPushMatrix();
		base.trasladar(-10,0,0);
		base.escalar(0.5,0.1,0.5);
		//base.dibujar();
	//glPopMatrix();
}

void ObjetoJerarquico::dibujaPrimerCuerpo(){
	//glPushMatrix();
		//cout << "cuerpo " << endl;
		Cubo cuerpo;
		cuerpo.trasladar(25,50,25);
		cuerpo.escalar(0.5,10,0.5);
		//cuerpo.rotar(90,1,0,1);
		base.setHijo(cuerpo);
	//glPopMatrix();
}


void ObjetoJerarquico::dibujaPlataforma(){
	//glPushMatrix();
		Cubo plataforma;
		plataforma.trasladar(25,500,15);
		plataforma.rotar(90.0, 1.0, 0.0, 0.0);
		plataforma.escalar(2,1,1);
		base.setHijo(plataforma);
		//base.dibujar();
	//glPopMatrix();
}

void ObjetoJerarquico::dibujaCuerda(){
	//glPushMatrix();
			//cout << "cuerpo cuerda" << endl;

		Tetraedro tetra;
		tetra.trasladar(0,90,50);
		tetra.rotar(180.0, 1.0, 0.0, 0.0);
		tetra.escalar(0.05,1,0.05);
		base.setHijo(tetra);
		//base.dibujar();
	//glPopMatrix();
}

void ObjetoJerarquico::construir(){
	//glPushMatrix();
		base.rotar(30,0.0,1.0,0.0);
		base.trasladar(ejeX,0.0,0.0);
		base.getHijo(1).rotar(anguloArriba,1,0,1);
		if(!Objeto3D::getChess()){
			base.dibujar();
		} else{
			base.dibujar();
			base.setChess(true);
			//base.colorearChess();
			base.setGlEnumPolygon(GL_FILL); 
		}
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