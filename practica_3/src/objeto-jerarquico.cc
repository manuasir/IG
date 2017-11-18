#include "../include/objeto-jerarquico.h"
using namespace std;

ObjetoJerarquico::ObjetoJerarquico(){
	anguloArriba=0;
	ejeX=0;
	ejeXcuerda=50;
	ejeY=1.0;
	chess=false;
	dibujaBase();
	dibujaCuerpo();
	dibujaPlataforma();
	dibujaCuerda();
}

int ObjetoJerarquico::move(unsigned char Tecla1){
	if (Tecla1=='Z') { 
			girarPlataformaIzq();
			return 0;
	}
	else if (Tecla1=='z') { 
			girarPlataformaDer();
			return 0;
	}
	else if (Tecla1=='X') { 
			avanzarPlataforma();
			return 0;
	}
	else if (Tecla1=='x') { 
			retrocederPlataforma();
			return 0;
	}
	else if (Tecla1=='C') { 
			subir();
			return 0;
	}
	else if (Tecla1=='c') { 
			bajar();
			return 0;
	} 
	else if (Tecla1=='V') { 
			ejeXcuerda++;
			return 0;
	}
	else if (Tecla1=='v') { 
			ejeXcuerda--;
			return 0;
	} else return 0;
}

void ObjetoJerarquico::dibujaBase(){
	base.trasladar(-10,0,0);
	base.escalar(0.5,0.1,0.5);
}

void ObjetoJerarquico::dibujaCuerpo(){
	cuerpo.trasladar(25,50,25);
	cuerpo.escalar(0.5,10,0.5);
	base.setHijo(cuerpo);
}

void ObjetoJerarquico::dibujaPlataforma(){
	plataforma.trasladar(37.5,550,37.5);
	plataforma.rotar(90.0, 1.0, 0.0, 0.0);
	plataforma.escalar(2,1,0.5);
}

void ObjetoJerarquico::dibujaCuerda(){
	cout << "pintando cuerda " << endl;
	cuerda.trasladar(25,0,25);
	cuerda.rotar(180.0, 1.0, 0.0, 0.0);
	cuerda.escalar(0.05,1,0.05);
	plataforma.setHijo(cuerda);
	base.setHijo(plataforma);
}

void ObjetoJerarquico::construir(){
	base.setGlEnumPolygon(Objeto3D::getGlEnumPolygon()); 
	base.rotar(30,0.0,1.0,0.0);
	base.trasladar(ejeX,0.0,0.0);
	base.getHijo(1).rotar(anguloArriba,0,1,0);
	base.getHijo(1).getHijo(0).trasladar(ejeXcuerda,0,25);
	base.getHijo(1).getHijo(0).escalar(0.01,ejeY,0.1);
	if(!Objeto3D::getChess()){
		base.setChess(false);
		base.dibujar();
	} else{
		base.setChess(true);
		base.dibujar();
	}
}