// Manuel Jiménez Bernal

#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/objetorevolucionado.h"
#include <vector>
#include <iostream>
#include <cmath>        // std::abs

using namespace std;

/**
* Constructor
*/
ObjetoRevolucionado::ObjetoRevolucionado(){
  
}

void ObjetoRevolucionado::normalizar(vector<_vertex3f> & vertex){
  for(int i=0;i<vertex.size();i++)
    if(vertex[i].x < 0){
        vertex[i].x=abs(vertex[i].x);
      }
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
* Calcular los perfiles que se generan por revolución
*/
void ObjetoRevolucionado::revolucionar(){
  // Tamaño del vector de vértices al inicio de la revolución (será el mismo para cada perfil)
  int size = Objeto3D::getTamVertices();
  // La fórmula del seno y coseno funciona con radianes
  float circunferenciaRadianes = 360 * M_PI / 180.0;
  // 20 por poner algo, mientras más pasos menores serán los ángulos
  float angulo = circunferenciaRadianes / 20;

  normalizar(Objeto3D::getVertices());

  // Generar los perfqiles
  for(unsigned int paso = 0; paso < 20; paso++){
    vector<_vertex3f> sig_perfil;
    // Esto controla dónde empieza y dónde acaba cada perfil, al estar todos en el mismo vector
    unsigned int perfilInicio, perfilFinal;
    perfilInicio = paso * size;
    perfilFinal = perfilInicio + size;
    // Para cada perfil, calcular __ el siguiente por revolución__ y añadir al vector de vértices general 
    for(int i = perfilInicio; i < perfilFinal; i++)
      sig_perfil.push_back(revEjeY(Objeto3D::getVertice(i),angulo));
    Objeto3D::getVertices().insert(Objeto3D::getVertices().end(),sig_perfil.begin(),sig_perfil.end());
    // Limpiar el perfil auxiliar
    sig_perfil.clear();
    // Pintar los triangulos mapeando en el array las posiciones
    // | v0 | v'0 |
    // | v1 | v'1 |
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
      unsigned int primerVertice = paso * size;
      unsigned int segundoVertice = primerVertice + size;
      Objeto3D::setIndice(_vertex3i(Objeto3D::getTamVertices()-1,segundoVertice,primerVertice));
    }
  // Colocar la tapa de arriba:
  // - acceder al eje Y del último vertice para ajustar la altura más alta de la figura
  // - acceder a los últimos vértices de cada perfil para conectar con el central
  Objeto3D::setVertice(_vertex3f(0.0,Objeto3D::getVertice(Objeto3D::getVertices().size()-2).y,0.0));
    for(unsigned int paso = 0; paso < 20; paso++){
      unsigned int primerVertice = (paso+1)*size-1;
      unsigned int segundoVertice = primerVertice + size;
      Objeto3D::setIndice(_vertex3i(Objeto3D::getVertices().size()-1,primerVertice,segundoVertice));
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