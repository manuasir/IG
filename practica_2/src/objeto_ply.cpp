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
	_file_ply File_ply;

  vector<_vertex3f> Vertices;
  vector<_vertex3i> Triangles;

  if (File_ply.open("/home/anon/FAC/IG/practica_2/src/beethoven.ply")){
    File_ply.read(Vertices,Triangles);
    std::cout << "File read correctly" << std::endl;
  }
  else std::cout << "File can't be opened" << std::endl;
}


