#include "Folheto.h"

#include "Acervo.h"
#include "Autores.h"
#include <string>
using namespace std;
#include <iostream>

#define num_aut 5

Folheto::Folheto(){
	for(int i = 0; i < num_aut; i++){
	listaAutores[i] = NULL;
	}
}
Folheto::~Folheto(){
	for(int i = 0; i < num_aut; i++){
	delete(listaAutores[i]);
	listaAutores[i] = NULL;
	}
}
Folheto::Folheto(string titulo, string editora, string local, int ano, string assunto, string palavChave_1, string palavChave_2, string CDU, int situacao,
 string tipo, string descricao, string medidas, int quant_aut) : Acervo(titulo, editora, local, ano, assunto, palavChave_1, palavChave_2, CDU, situacao){
	setTipo(tipo);  
	setDescricao(descricao); 
	setMedidas(medidas);
	setQuant_aut(quant_aut);
}

//GET
int Folheto::getQuant_aut(){
	return quant_aut;
}
void Folheto::getListaAutores(Autores *listaAutores[num_aut]){
	for(int i = 0; i < num_aut; i++){
	listaAutores[i] = NULL;
	}
	for(int i = 0; i < num_aut; i++){
	listaAutores[i] = this->listaAutores[i];
	}
}
string Folheto::getTipo(){
	return tipo;
} 
string Folheto::getDescricao(){
	return descricao;
}
string Folheto::getMedidas(){
	return medidas;
}
	
//SET
void Folheto::setQuant_aut(int quant_aut){
	this->quant_aut = quant_aut;
}
void Folheto::setListaAutores(Autores *listaAutores[num_aut]){
	for(int i = 0; i < num_aut; i++){
	this->listaAutores[i] = NULL;
	}
	for(int i = 0; i < num_aut; i++){
	this->listaAutores[i] = listaAutores[i];
	}
}
void Folheto::setTipo(string tipo){
	this->tipo = tipo;
} 
void Folheto::setDescricao(string descricao){
	this->descricao = descricao;
}
void Folheto::setMedidas(string medidas){
	this->medidas = medidas;
}

void Folheto::imprimirFicha(){
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
	cout << endl;
	cout << "Medidas: " << medidas << endl;
	cout << descricao << endl;
	
cout << "---------------------------------------------------------" << endl;
}
