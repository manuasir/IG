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

    File_ply.read(auxvertices,auxindices);
    cout << "auxverftices" << auxvertices.size() << endl;
    for(int i=0;i<auxvertices.size();i++){
    	//cout << "vertice: " << 15*auxvertices[i].x << endl;
    	//cout << "vertice: " << 15*auxvertices[i].y << endl;
    	//cout << "vertice: " << 15*auxvertices[i].z << endl;
    	_vertex3f aux;
    	aux.x = auxvertices[i].x;
    	aux.y = auxvertices[i].y;
    	aux.z = auxvertices[i].z;
    	Objeto3D::setVertice(aux);
    }
    for(int i=0;i<auxindices.size();i++){

    	//cout << "indice: " << auxindices[i]._0 << endl;
    	//cout << "indice: " << auxindices[i]._1 << endl;
    	//cout << "indice: " << auxindices[i]._2 << endl;
    	_vertex3i aux;
    	aux._0 = auxindices[i]._0;
    	aux._1 = auxvertices[i]._1;
    	aux._2 = auxvertices[i]._2;

    	Objeto3D::setIndice(aux);
    }
    std::cout << "File read correctly" << getVertices().size() <<std::endl;
  }
  else std::cout << "File can't be opened" << std::endl;
}


