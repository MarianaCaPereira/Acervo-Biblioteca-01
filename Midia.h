#ifndef MIDIA_H  //fitas VHS, CDs e DVDs
#define MIDIA_H

#include "Acervo.h"
#include "Autores.h"
#include <string>
using namespace std;

#define num_aut 5

class Midia : public Acervo
{
	private:
	Autores *listaAutores[num_aut];//Autores do item
	string tipo;  //Fita VHS, CD ou DVD
	string descricao;  //Descrição da mídia
	float capacidade;  //Capacidade de armazenamento
	int quant_aut; //Quantidade de autores
		
	public:
		
		Midia();
		Midia(string titulo, string editora, string local, int ano, string assunto, string palavChave_1, string palavChave_2, string CDU, int situacao, 
		string tipo, string descricao, float capacidade, int quant_aut);  
		//Construtor carregado
		~Midia();
		
	//GET
	int getQuant_aut();
	void getListaAutores(Autores *ListaAutores[num_aut]);
	string getTipo();  
	string getDescricao(); 
	float getCapacidade();  
	
	//SET
	void setQuant_aut(int quant_aut);
	void setListaAutores(Autores *ListaAutores[num_aut]);
	void setTipo(string tipo);  
	void setDescricao(string descricao); 
	void setCapacidade(float capacidade);
	
	void imprimirFicha();
	
	protected:
};

#endif
