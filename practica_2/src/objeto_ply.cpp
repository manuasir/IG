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
  if (File_ply.open("/home/anon/FAC/IG/practica_2/src/big_dodge.ply")){
  	vector<_vertex3f> auxvertices;
	vector<_vertex3i> auxindices;

    File_ply.read(auxvertices,auxindices);
    cout << "auxverftices" << auxvertices.size() << endl;
    for(int i=0;i<auxvertices.size();i++){
    	_vertex3f aux;
    	aux.x = auxvertices[i].x*15;
    	aux.y = auxvertices[i].y*15;
    	aux.z = auxvertices[i].z*15;
    	Objeto3D::setVertice(aux);
    }
    for(int i=0;i<auxindices.size();i++){
    	_vertex3i aux;
    	aux.x = auxindices[i].x;
	    cout << "X VALE " << aux.x << endl;

    	aux.y = auxvertices[i].y;
    		    cout << "Y VALE " << aux.y << endl;


    	aux.z = auxvertices[i].z;
    		    cout << "Z VALE " << aux.z << endl;

    	Objeto3D::setIndice(aux);
    }
    std::cout << "File read correctly" << getVertices().size() <<std::endl;
  }
  else std::cout << "File can't be opened" << std::endl;
}


