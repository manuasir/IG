// Manuel Jiménez Bernal


#ifndef _REVOLUCION_H_
#define _REVOLUCION_H_
#include <iostream>
#include "vertex.h"
#include "objeto_ply.h"

class ObjetoRevolucionado : public ObjetoPly
{
private:

public:
	ObjetoRevolucionado();
	//void leerFichero();
	_vertex3f revEjeY(_vertex3f vertice, float angulo);
	void revolucionar();
	void close();
	void read(const string & path);
};
#endif
