#ifndef _CUBO_H
#define _CUBO_H
#include "objeto3D.h"

class Cubo : public Objeto3D
{
private:

public:
Cubo(float tam);
void createArrayData(float tam);
};
#endif
