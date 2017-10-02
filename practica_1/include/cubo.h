// Manuel Jiménez Bernal


#ifndef _CUBO_H
#define _CUBO_H
#include "objeto3D.h"

class Cubo : public Objeto3D
{
private:
float tam;
public:
Cubo();
Cubo(float val);
void createArrayData();
void setTam(float data){ tam = data; };
};
#endif
