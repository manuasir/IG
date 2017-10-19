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
  int size = Objeto3D::getTamVertices();
  float circunferenciaRadianes = 360 * M_PI / 180.0;
  float angulo = circunferenciaRadianes / 20;

  for(unsigned int paso = 0; paso < 20; paso++){
    vector<_vertex3f> sig_perfil;
    unsigned int perfilInicio, perfilFinal;

    perfilInicio = paso * size;
    perfilFinal = perfilInicio + size;
    for(int i = perfilInicio; i < perfilFinal; i++)
      sig_perfil.push_back(revEjeY(Objeto3D::getVertice(i),angulo));
    Objeto3D::getVertices().insert(Objeto3D::getVertices().end(),sig_perfil.begin(),sig_perfil.end());
    sig_perfil.clear();
    // Pintar los triangulos mapeando en el array las posiciones
    for (unsigned int i = perfilInicio+1, k = perfilFinal+1; i < perfilFinal; i++, k++){
      Objeto3D::setIndice(_vertex3i(i-1,k-1,k));
      Objeto3D::setIndice(_vertex3i(i-1,k,i));
    }
  }
  // Colocar la tapa de abajo:
  // - acceder al eje Y del primer vértice para ajustar la altura más baja de la figura
  // - acceder a los primeros vértices de cada perfil para conectar con el central
  Objeto3D::setVertice(_vertex3f(0.0,Objeto3D::getVertices().front().y,0.0));
    for(unsigned int paso = 0; paso < 20; paso++){
      unsigned int perfilInicio = paso * size;
      unsigned int perfilFinal = perfilInicio + size;
      Objeto3D::setIndice(_vertex3i(Objeto3D::getTamVertices()-1,perfilFinal,perfilInicio));
    }
    
  // tapa de abajo
  //Objeto3D::setVertice()
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