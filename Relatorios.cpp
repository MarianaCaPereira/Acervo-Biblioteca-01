#include "Relatorios.h"

#include "Acervo.h"
#include "GeralPaginas.h"
#include "Autores.h"
#include <string>
using namespace std;
#include <iostream>

#define num_aut 5


Relatorios::Relatorios(){
	for(int i = 0; i < num_aut; i++){
	listaAutores[i] = NULL;
	}
}
Relatorios::Relatorios(string titulo, string editora, string local, int ano, string assunto, string palavChave_1, string palavChave_2, string CDU, int situacao, 
int paginas, float cm, string ISBN, string descricao, int quant_aut): Acervo(titulo, editora, local, ano, assunto, palavChave_1, palavChave_2, CDU, situacao), GeralPaginas(paginas, cm){
			
		setISBN(ISBN);
		setDescricao(descricao);
		setQuant_aut(quant_aut);
}
Relatorios::~Relatorios(){
	for(int i = 0; i < num_aut; i++){
	delete(listaAutores[i]);
	listaAutores[i] = NULL;
	}
}

//GET
int Relatorios::getQuant_aut(){
	return quant_aut;
}
void Relatorios::getListaAutores(Autores *listaAutores[num_aut]){
	for(int i = 0; i < num_aut; i++){
	listaAutores[i] = NULL;
	}
	for(int i = 0; i < num_aut; i++){
	listaAutores[i] = this->listaAutores[i];
	}
}
string Relatorios::getISBN(){
	return ISBN;
}
string Relatorios::getDescricao(){
	return descricao;
}
	
//SET
void Relatorios::setQuant_aut(int quant_aut){
	this->quant_aut = quant_aut;
}
void Relatorios::setListaAutores(Autores *listaAutores[num_aut]){
	for(int i = 0; i < num_aut; i++){
	this->listaAutores[i] = NULL;
	}
	for(int i = 0; i < num_aut; i++){
	this->listaAutores[i] = listaAutores[i];
	}
}
void Relatorios::setISBN(string ISBN){
	
	this->ISBN = ISBN;
}
void Relatorios::setDescricao(string descricao){
	this->descricao = descricao;
}
	
void Relatorios::imprimirFicha(){
cout << endl;
cout << "---------------------------------------------------------" << endl;

	cout << "Item : Relatório" << endl;
	
	Acervo::imprimirFicha();
	cout << "Autor(es): ";
	for(int i = 0; i < quant_aut; i++){  //Autores do item
		
		if(listaAutores[i] != NULL){
			
		cout << listaAutores[i]->getNome() << ". ";	
		}
	}
	GeralPaginas::imprimirFicha_Paginas();
	cout << descricao << endl;
	cout << "ISBN: " << ISBN << endl;
	
cout << "---------------------------------------------------------" << endl;
}

