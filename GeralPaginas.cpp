#include "GeralPaginas.h"

#include <string>
using namespace std;
#include <iostream>

GeralPaginas::GeralPaginas(){
}
GeralPaginas::~GeralPaginas(){
}
GeralPaginas::GeralPaginas(int paginas, float cm){
	
	setPaginas(paginas);  
	setCm(cm);
}

//GET
int GeralPaginas::getPaginas(){
	return paginas;
}
float GeralPaginas::getCm(){
	return cm;
}
	
//SET
void GeralPaginas::setPaginas(int paginas){
	this->paginas = (paginas > 0) ? paginas:0;
}
void GeralPaginas::setCm(float cm){
	this->cm = (cm > 0) ? cm:0;
}

void GeralPaginas::imprimirFicha_Paginas(){
	
	cout << endl << paginas << " pág.:" << cm << " cm. " << endl;
	
}
