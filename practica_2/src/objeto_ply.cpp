// Manuel Jiménez Bernal


#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/objeto_ply.h"
#include <vector>
#include <iostream>

using namespace std;

ObjetoPly::ObjetoPly(){

}

void ObjetoPly::leerFichero(){
  if (File_ply.open("/home/anon/FAC/IG/practica_2/src/beethoven.ply")){
  	vector<_vertex3f> auxvertices;
	vector<_vertex3i> auxindices;

    File_ply.read(Objeto3D::getVertices(),Objeto3D::getIndices());
    cout << "auxverftices" << auxvertices.size() << endl;
    for(int i=0;i<Objeto3D::getVertices().size();i++){
    	//_vertex3f aux;
        Objeto3D::getVertices()[i].x = 15*Objeto3D::getVertices()[i].x;
        Objeto3D::getVertices()[i].y = 15*Objeto3D::getVertices()[i].y;
        Objeto3D::getVertices()[i].z = 15*Objeto3D::getVertices()[i].z;
    	//Objeto3D::setVertice(aux);
    }

    std::cout << "File read correctly" << getVertices().size() << std::endl;
    Objeto3D::colorear();
  }
  else std::cout << "File can't be opened" << std::endl;
}


