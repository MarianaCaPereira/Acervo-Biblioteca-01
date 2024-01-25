#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "Acervo.h"
#include "GeralPaginas.h"
#include "Autores.h"
#include <string>
using namespace std;

#define num_aut 5

class Relatorios : public Acervo, GeralPaginas
{
	private:
	Autores *listaAutores[num_aut];//Autores do item
	string ISBN; //Padrão internacional de numeração de livro : nn-nnnn-nnn-n
	string descricao;  //Descrição do relatório
	int quant_aut; //Quantidade de autores
	
	public:
		Relatorios();
		Relatorios(string titulo, string editora, string local, int ano, string assunto, string palavChave_1, string palavChave_2, string CDU, int situacao, 
		int paginas, float cm, string ISBN, string descricao, int quant_aut);
		//Construtor carregado
		~Relatorios();
		
	//GET
	int getQuant_aut();
	void getListaAutores(Autores *ListaAutores[num_aut]);
	string getISBN();
	string getDescricao();
	
	//SET
	void setQuant_aut(int quant_aut);
	void setListaAutores(Autores *ListaAutores[num_aut]);
	void setISBN(string ISBN);
	void setDescricao(string descricao);
		
	void imprimirFicha();
	
	protected:
};

#endif
