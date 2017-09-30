#ifndef _TETREADRO_H
#define _TETREADRO_H
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
