#include "TrabalhoAcademico.h"

#include "Acervo.h"
#include "GeralPaginas.h"
#include "Autores.h"
#include <string>
using namespace std;
#include <iostream>

#define num_aut 5


TrabalhoAcademico::TrabalhoAcademico(){
	for(int i = 0; i < num_aut; i++){
	listaAutores[i] = NULL;
	}
}
TrabalhoAcademico::TrabalhoAcademico(string titulo, string editora, string local, int ano, string assunto, string palavChave_1, string palavChave_2, string CDU, int situacao, 
int paginas, float cm, string tipo, string ISBN, string descricao, string curso, string orientador, int quant_aut): Acervo(titulo, editora, local, ano, assunto, palavChave_1, palavChave_2, CDU, situacao), GeralPaginas(paginas, cm){
	
	setISBN(ISBN);
	setTipo(tipo);  
	setDescricao(descricao);
	setCurso(curso);
	setOrientador(orientador);
	setQuant_aut(quant_aut);
}
TrabalhoAcademico::~TrabalhoAcademico(){
	for(int i = 0; i < num_aut; i++){
	delete(listaAutores[i]);
	listaAutores[i] = NULL;
	}
}

//GET
int TrabalhoAcademico::getQuant_aut(){
	return quant_aut;
}
void TrabalhoAcademico::getListaAutores(Autores *listaAutores[num_aut]){
	for(int i = 0; i < num_aut; i++){
	listaAutores[i] = NULL;
	}
	for(int i = 0; i < num_aut; i++){
	listaAutores[i] = this->listaAutores[i];
	}
}
string TrabalhoAcademico::getTipo(){
	return tipo;
} 
string TrabalhoAcademico::getISBN(){
	return ISBN;
}
string TrabalhoAcademico::getDescricao(){
	return descricao;
}	
string TrabalhoAcademico::getCurso(){
	return curso;
}
string TrabalhoAcademico::getOrientador(){
	return orientador;
}
	
//SET
void TrabalhoAcademico::setQuant_aut(int quant_aut){
	this->quant_aut = quant_aut;
}
void TrabalhoAcademico::setListaAutores(Autores *listaAutores[num_aut]){
	for(int i = 0; i < num_aut; i++){
	this->listaAutores[i] = NULL;
	}
	for(int i = 0; i < num_aut; i++){
	this->listaAutores[i] = listaAutores[i];
	}
}
void TrabalhoAcademico::setTipo(string tipo){
	this->tipo = tipo;
} 
void TrabalhoAcademico::setISBN(string ISBN){
	this->ISBN = ISBN;
}
void TrabalhoAcademico::setDescricao(string descricao){
	this->descricao = descricao;
}
void TrabalhoAcademico::setCurso(string curso){
	this->curso = curso;
}
void TrabalhoAcademico::setOrientador(string orientador){
	this->orientador = orientador;
}
	
void TrabalhoAcademico::imprimirFicha(){
cout << endl;
cout << "---------------------------------------------------------" << endl;

	cout << "Item: " << tipo << endl;

	Acervo::imprimirFicha();
	cout << "Autor(es): ";
	for(int i = 0; i < quant_aut; i++){  //Autores do item
		
		if(listaAutores[i] != NULL){
			
		cout << listaAutores[i]->getNome() << ". ";	
		}
	}
	cout << endl << "Curso: " << curso << ". " << "Orientador: " << orientador << ". ";
	GeralPaginas::imprimirFicha_Paginas();
	cout << descricao << endl;
	cout << "ISBN: " << ISBN << endl;
	
cout << "---------------------------------------------------------" << endl;
}
