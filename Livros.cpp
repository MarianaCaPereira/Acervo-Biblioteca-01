#include "Livros.h"

#include "Acervo.h"
#include "GeralPaginas.h"
#include "Autores.h"
using namespace std;
#include <iostream>

#define num_aut 5

Livros::Livros(){
	for(int i = 0; i < num_aut; i++){
	listaAutores[i] = NULL;
	}
}
Livros::Livros(string titulo, string editora, string local, int ano, string assunto, string palavChave_1, string palavChave_2, string CDU, int situacao, 
int paginas, float cm, string ISBN, int edicao, int quant_aut) : Acervo(titulo, editora, local, ano, assunto, palavChave_1, palavChave_2, CDU, situacao), GeralPaginas(paginas, cm){
	
	setISBN(ISBN);
	setEdicao(edicao);
	setQuant_aut(quant_aut);
}
Livros::~Livros(){
	for(int i = 0; i < num_aut; i++){
	delete(listaAutores[i]);
	listaAutores[i] = NULL;
	}
}

//GET
int Livros::getQuant_aut(){
	return quant_aut;
}
void Livros::getListaAutores(Autores *listaAutores[num_aut]){
	for(int i = 0; i < num_aut; i++){
	listaAutores[i] = NULL;
	}
	for(int i = 0; i < num_aut; i++){
	listaAutores[i] = this->listaAutores[i];
	}
}	
string Livros::getISBN(){
	return ISBN;
}
int Livros::getEdicao(){
	return edicao;
}
	
//SET
void Livros::setQuant_aut(int quant_aut){
	this->quant_aut = quant_aut;
}
void Livros::setListaAutores(Autores *listaAutores[num_aut]){
	for(int i = 0; i < num_aut; i++){
	this->listaAutores[i] = NULL;
	}
	for(int i = 0; i < num_aut; i++){
	this->listaAutores[i] = listaAutores[i];
	}
}	
void Livros::setISBN(string ISBN){
	
	this->ISBN = ISBN;
}
void Livros::setEdicao(int edicao){
	this->edicao = edicao;
}

void Livros::imprimirFicha(){
cout << endl;
cout << "---------------------------------------------------------" << endl;

	cout << "Item: Livro" << endl;
	
	Acervo::imprimirFicha();
	cout << "Autor(es): ";
	for(int i = 0; i < quant_aut; i++){  //Autores do item
		
		if(listaAutores[i] != NULL){
			
		cout << listaAutores[i]->getNome() << ". ";	
		}
	}
	GeralPaginas::imprimirFicha_Paginas();
	cout << edicao << " Edição. " << endl;
	cout << "ISBN: " << ISBN << endl;
	
cout << "---------------------------------------------------------" << endl;
}
