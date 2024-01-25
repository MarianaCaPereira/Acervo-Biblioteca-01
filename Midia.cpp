#include "Midia.h"

#include "Acervo.h"
#include "Autores.h"
#include <string>
using namespace std;
#include <iostream>

#define num_aut 5

Midia::Midia(){
	for(int i = 0; i < num_aut; i++){
	listaAutores[i] = NULL;
	}
}
Midia::Midia(string titulo, string editora, string local, int ano, string assunto, string palavChave_1, string palavChave_2, string CDU, int situacao, 
string tipo, string descricao, float capacidade, int quant_aut) : Acervo(titulo, editora, local, ano, assunto, palavChave_1, palavChave_2, CDU, situacao){
	
	setTipo(tipo);
	setDescricao(descricao);
	setCapacidade(capacidade);
	setQuant_aut(quant_aut);
}	
Midia::~Midia(){
	for(int i = 0; i < num_aut; i++){
	delete(listaAutores[i]);
	listaAutores[i] = NULL;
	}
}

//GET
int Midia::getQuant_aut(){
	return quant_aut;
}
void Midia::getListaAutores(Autores *listaAutores[num_aut]){
	for(int i = 0; i < num_aut; i++){
	listaAutores[i] = NULL;
	}
	for(int i = 0; i < num_aut; i++){
	listaAutores[i] = this->listaAutores[i];
	}
}
string Midia::getTipo(){
	return tipo;
}
string Midia::getDescricao(){
	return descricao;
}
float Midia::getCapacidade(){
	return capacidade;
}
	
//SET
void Midia::setQuant_aut(int quant_aut){
	this->quant_aut = quant_aut;
}
void Midia::setListaAutores(Autores *listaAutores[num_aut]){
	for(int i = 0; i < num_aut; i++){
	this->listaAutores[i] = NULL;
	}
	for(int i = 0; i < num_aut; i++){
	this->listaAutores[i] = listaAutores[i];
	}
}
void Midia::setTipo(string tipo){
	this->tipo = tipo;
} 
void Midia::setDescricao(string descricao){
	this->descricao = descricao;
}
void Midia::setCapacidade(float capacidade){
	this->capacidade = capacidade;
}
	
void Midia::imprimirFicha(){
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
	cout << endl << descricao << endl;
	cout << "Capacidade: " << capacidade << endl;
	
cout << "---------------------------------------------------------" << endl;
}
