// Manuel Jiménez Bernal

#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/objetorevolucionado.h"
#include <vector>
#include <iostream>

using namespace std;

/**
* Constructor
*/
ObjetoRevolucionado::ObjetoRevolucionado(){
  
}

/**
 * Pasado un vertice _vertex3f devuelve otro que le corresponde en un barrido por revolución en el eje Y
**/
_vertex3f ObjetoRevolucionado::revEjeY(_vertex3f vertice, float angulo){
    //cout << vertice.x << endl;

  
    _vertex3f auxvert;
    auxvert.x = cos(angulo) * vertice.x + sin(angulo) * vertice.z;
    auxvert.y = vertice.y;
    auxvert.z = -sin(angulo) * vertice.x + cos(angulo) * vertice.z;
    //cout << auxvert.x;
    return auxvert;
    
}

/**
* Lee un fichero PLY y carga la información en los vectores de Objeto3D
*/
void ObjetoRevolucionado::revolucionar(){
  float circunferenciaRadianes = 360 * M_PI / 180.0;
  vector<_vertex3f> auxVector;
  for(unsigned int paso = 0; paso < 20; paso++){
    float angulo = circunferenciaRadianes / paso;
    cout << angulo;
    for(int i = 0; i < Objeto3D::getVertices().size() ; i++){
      cout << Objeto3D::getVertices().size() << endl;

      _vertex3f aux = revEjeY(Objeto3D::getVertice(i),angulo);
      Objeto3D::setVertice(aux);
      //cout << Objeto3D::getVertice(i).x << endl;
    }
  }
}

/**
* Leer fichero para revolucionar
*/
void ObjetoRevolucionado::read(const string & path){
  ObjetoPly::leerFichero(path);
}

/**
* Destructor
*/
void ObjetoRevolucionado::close(){
  ObjetoPly::closeFile();
}