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
   _vertex3f auxvert;
    auxvert.x = cos(angulo) * vertice.x + sin(angulo) * vertice.z;
    auxvert.y = vertice.y;
    auxvert.z = -sin(angulo) * vertice.x + cos(angulo) * vertice.z;
    return auxvert;
}

/**
* Lee un fichero PLY y carga la información en los vectores de Objeto3D
*/
void ObjetoRevolucionado::leerFichero(){
  if (File_ply.open("/home/anon/FAC/IG/practica_2/ply/revolucion.ply")){
  	vector<_vertex3f> auxvertices;
	  vector<_vertex3i> auxindices;

    File_ply.read(Objeto3D::getVertices(),Objeto3D::getIndices());
    cout << "auxverftices" << auxvertices.size() << endl;
    for(int i=0;i<Objeto3D::getVertices().size();i++){
        Objeto3D::getVertices()[i].x = 15*Objeto3D::getVertices()[i].x;
        Objeto3D::getVertices()[i].y = 15*Objeto3D::getVertices()[i].y;
        Objeto3D::getVertices()[i].z = 15*Objeto3D::getVertices()[i].z;
    }
    std::cout << "File read correctly" << getVertices().size() << std::endl;
    Objeto3D::colorear();
  }
  else std::cout << "File can't be opened" << std::endl;
}