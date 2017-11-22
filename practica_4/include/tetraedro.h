// Manuel Jiménez Bernal


#ifndef _TETRAEDRO_H
#define _TETRAEDRO_H
#include "objeto3D.h"

class Tetraedro : public Objeto3D{

private:
	float tam;
public:
	Tetraedro();
	Tetraedro(float val);
	void createArrayData();
	void setTam(float data){ tam = data; };
};
#endif
