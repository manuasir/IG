// Manuel Jiménez Bernal


#ifndef _OBJETO_PLY_H_
#define _OBJETO_PLY_H_
#include "objeto3D.h"
#include <iostream>
#include "file_ply_stl.h"
#include "vertex.h"

class ObjetoPly : public Objeto3D
{

_file_ply File_ply;
public:
ObjetoPly();
void leerFichero();
};
#endif
