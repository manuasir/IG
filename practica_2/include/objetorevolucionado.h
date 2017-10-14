// Manuel Jiménez Bernal


#ifndef _REVOLUCION_H_
#define _REVOLUCION_H_
#include "objeto3D.h"
#include <iostream>
#include "vertex.h"
#include "objeto_ply.h"

class ObjetoRevolucionado : public Objeto3D
{
private:
	vector<_vertex3f> auxvertices;
  	vector<_vertex3i> auxindices;

public:
	ObjetoRevolucionado();
	void leerFichero();
};
#endif
