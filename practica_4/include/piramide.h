// Manuel Jiménez Bernal


#ifndef _PIRAMIDE_H
#define _PIRAMIDE_H
#include "objeto3D.h"

class Piramide : public Objeto3D{

private:
	float tam;
public:
	Piramide();
	Piramide(float val);
	void createArrayData();
	void setTam(float data){ tam = data; };
};
#endif
