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
  int size = Objeto3D::getVertices().size();
  float circunferenciaRadianes = 360 * M_PI / 180.0;
  vector<_vertex3f> vertRev(Objeto3D::getVertices());
  vector<_vertex3i> indicesRev;
  for(unsigned int paso = 0; paso < 20; paso++){
    float angulo = circunferenciaRadianes / paso;
    cout << angulo;
    vector<_vertex3f> sig_perfil(size);
    for(int i = 0; i < size ; i++)
      sig_perfil[i] = revEjeY(Objeto3D::getVertice(i),angulo);
    vertRev.insert(vertRev.end(),sig_perfil.begin(),sig_perfil.end());
    //Generamos las caras con los nuevos vértices
    unsigned int perfilInicio, perfilFinal;
    perfilInicio = paso * size;
    perfilFinal = perfilInicio + size;
    
    for (unsigned int i = perfilInicio+1, k = perfilFinal+1; i < perfilFinal; i++, k++){
      indicesRev.push_back(_vertex3i(i-1, k-1, k));
      indicesRev.push_back(_vertex3i(i-1, k,   i));
    }

    Objeto3D::setVertices(sig_perfil);
    Objeto3D::setIndices(indicesRev);
   // Objeto3D::colorear();
    
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