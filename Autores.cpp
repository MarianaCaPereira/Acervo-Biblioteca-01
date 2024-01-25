#include "Autores.h"
#include <string>
#include <cstring>
using namespace std;

#include <iostream>

Autores::Autores(){
}
Autores::Autores(string nome){
	setNome(nome);
}
Autores::~Autores(){
}

//GET
string Autores::getNome(){
	return nome;
}
	
//SET
void Autores::setNome(string nome){
	this->nome = nome;
}
