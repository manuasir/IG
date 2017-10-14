// Manuel Jiménez Bernal


#ifndef _REVOLUCION_H_
#define _REVOLUCION_H_
#include "objeto3D.h"
#include <iostream>
#include "vertex.h"

class ObjetoPly : public Objeto3D
{
private:
	_file_ply File_ply;
public:
	ObjetoPly();
	void leerFichero();
};
#endif
