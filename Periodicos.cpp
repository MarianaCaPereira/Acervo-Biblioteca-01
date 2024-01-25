#include "Periodicos.h"

#include "Acervo.h"
#include "GeralPaginas.h"
#include "Autores.h"
#include <string>
using namespace std;
#include <iostream>

Periodicos::Periodicos(){
	
}
Periodicos::Periodicos(string titulo, string editora, string local, int ano, string assunto, string palavChave_1, string palavChave_2, string CDU, int situacao, 
int paginas, float cm, string tipo, string ISSN, string periodo, int volume, int edicao): Acervo( titulo, editora, local, ano, assunto, palavChave_1, palavChave_2, CDU, situacao), GeralPaginas(paginas, cm){
	
	setISSN(ISSN);
	setTipo(tipo);    
	setPeriodo(periodo);  
	setVolume(volume);  
	setEdicao(edicao);
			
}
Periodicos::~Periodicos(){
	
}

//GET
string Periodicos::getTipo(){
	return tipo;
} 
string Periodicos::getISSN(){
	return ISSN;
}
string Periodicos::getPeriodo(){
	return periodo;
}  
int Periodicos::getVolume(){
	return volume;
}  
int Periodicos::getEdicao(){
	return edicao;
}
	
//SET
void Periodicos::setTipo(string tipo){
	this->tipo = tipo;
}  
void Periodicos::setISSN(string ISSN){
	this->ISSN = ISSN;
}
void Periodicos::setPeriodo(string periodo){
	this->periodo  = periodo;
}  
void Periodicos::setVolume(int volume){
	this->volume = volume;
}  
void Periodicos::setEdicao(int edicao){
	this->edicao = edicao;
}

void Periodicos::Periodicos::imprimirFicha(){
cout << endl;
cout << "---------------------------------------------------------" << endl;

	cout << "Item: " << tipo << endl;
	
	Acervo::imprimirFicha();
	GeralPaginas::imprimirFicha_Paginas();
	cout << edicao << " Edição. " << volume << " Volume. " << "Período: " << periodo << ". " << endl;
	cout << "ISSN: " << ISSN << endl;
	
cout << "---------------------------------------------------------" << endl;
}
