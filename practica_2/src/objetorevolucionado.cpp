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
  float angulo = circunferenciaRadianes / 20;

  for(unsigned int paso = 0; paso < 20; paso++){
    cout << angulo;
    vector<_vertex3f> sig_perfil;
    cout << "TAMAÑO " << sig_perfil.size() << endl;
    unsigned int perfilInicio, perfilFinal;

    perfilInicio = paso * size;
    perfilFinal = perfilInicio + size;
    for(int i = perfilInicio; i < perfilFinal; i++)
      sig_perfil.push_back(revEjeY(Objeto3D::getVertice(i),angulo));
    Objeto3D::getVertices().insert(Objeto3D::getVertices().end(),sig_perfil.begin(),sig_perfil.end());
    sig_perfil.clear();
    cout << "tamaño debe ser incremental " << Objeto3D::getVertices().size() << endl;
    //Generamos las caras con los nuevos vértices    
    for (unsigned int i = perfilInicio+1, k = perfilFinal+1; i < perfilFinal; i++, k++){
      Objeto3D::setIndice(_vertex3i(i-1,k-1,k));
      Objeto3D::setIndice(_vertex3i(i-1,k,i));
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