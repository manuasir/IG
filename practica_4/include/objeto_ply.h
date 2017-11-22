// Manuel Jiménez Bernal

#ifndef _OBJETO_PLY_H_
#define _OBJETO_PLY_H_
#include "objeto3D.h"
#include <iostream>
#include "file_ply_stl.h"
#include "vertex.h"

/**
* Clase que gestiona el manejo de ficheros con format PLY y lo asigna a un Objeto3D
*/
class ObjetoPly : public Objeto3D
{
private:
	_file_ply File_ply;
public:
	ObjetoPly();
	void leerFichero(const string &File_name);
	void closeFile();
};
#endif
