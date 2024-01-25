#include "Acervo.h"

#include <string>
#include <cstring>
using namespace std;

#include <iostream>

Acervo::Acervo(){
	situacao = 0;  //Item inicializado como livre
}
Acervo::~Acervo(){
}
Acervo::Acervo(string titulo, string editora, string local, int ano, string assunto, string palavChave_1, string palavChave_2, string CDU, int situacao){
	
	setTitulo(titulo);
	setEditora(editora); 
	setLocal(local); 
	setAno(ano);
	setAssunto(assunto);
	setPalavChave_1(palavChave_1); 
	setPalavChave_2(palavChave_2);
	setCDU(CDU);
	setSituacao(situacao);
}

//GET
string Acervo::getCDU(){
	return CDU;
}
string Acervo::getTitulo(){
	return titulo;
}
string Acervo::getEditora(){
	return editora;
}
string Acervo::getLocal(){
	return local;
}
int Acervo::getAno(){
	return ano;
}
string Acervo::getAssunto(){
	return assunto;
}
string Acervo::getPalavChave_1(){
	return palavChave_1;
}
string Acervo::getPalavChave_2(){
	return palavChave_2;
}
int Acervo::getSituacao(){
	return situacao;
}
	
//SET
void Acervo::setCDU(string CDU){
	this->CDU = CDU;
}
void Acervo::setTitulo(string titulo){
	this->titulo = titulo;
}
void Acervo::setEditora(string editora){
	this->editora = editora;
}
void Acervo::setLocal(string local){
	this->local = local;
}
void Acervo::setAno(int ano){  //Validação
	this->ano = (ano >= 0 && ano <= 2022) ? ano:0;  
}
void Acervo::setAssunto(string assunto){
	this->assunto = assunto; 
}
void Acervo::setPalavChave_1(string palavChave_1){
	this->palavChave_1 = palavChave_1;
} 
void Acervo::setPalavChave_2(string palavChave_2){
	this->palavChave_2 = palavChave_2;
}
void Acervo::setSituacao(int situacao){  //Validação
	this->situacao = (situacao == 0 || situacao == 1) ? situacao:0;
}

void Acervo::imprimirFicha(){
	
	cout << endl;
	switch(situacao){  //Situação do item
		
		case 1:
			cout << "|Item emprestado|" << endl;
			break;
		case 0:
			cout << "|Item livre|" << endl;
			break;
	}
	cout << "CDU: " << CDU << endl;  //CDU do item
	cout << titulo << " - " << local << ": " << editora << ", " << ano << ". " << endl;
	cout << "1. " << assunto << ". |. " << palavChave_1 << ". ||. " << palavChave_2 << ". |||. " << titulo << "." << endl;
	
}
