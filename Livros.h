#ifndef LIVROS_H  //Livros
#define LIVROS_H
#include "Acervo.h"
#include "GeralPaginas.h"
#include "Autores.h"
#include <string>
using namespace std;

#define num_aut 5

class Livros : public Acervo, GeralPaginas
{
	private:
	Autores *listaAutores[num_aut];//Autores do item
	string ISBN; //Padrão internacional de numeração de livro : nn-nnnn-nnn-n
	int edicao;  //Edição que está sendo publicada
	int quant_aut; //Quantidade de autores
	
	public:
		
		Livros();
		Livros(string titulo, string editora, string local, int ano, string assunto, string palavChave_1, string palavChave_2, string CDU, int situacao, 
		int paginas, float cm, string ISBN, int edicao, int quant_aut);
		//Construtor carregado
		~Livros();
	
	//GET
	int getQuant_aut();
	void getListaAutores(Autores *ListaAutores[num_aut]);	
	string getISBN();
	int getEdicao();
	
	//SET	
	void setQuant_aut(int quant_aut);
	void setListaAutores(Autores *ListaAutores[num_aut]);
	void setISBN(string ISBN);
	void setEdicao(int edicao);
	
	void imprimirFicha();
		
	protected:
};
#endif
