#ifndef ACERVO_H  //Classe base, com informações gerais de todos os itens da biblioteca
#define ACERVO_H
#include <string>
#include <cstring>
using namespace std;

class Acervo { //Classe abstrata
	private:

	protected:
		
		string titulo; //Titulo do item
		string editora;  //Empresa/unidade responsável pela divulgação do item
		string local;  //Local onde foi divulgado o item
		int ano;  //Ano de divulgação do item
		string assunto;  //Assunto do qual se trata o item
		string palavChave_1;  //Palavra chave 1 referente ao item
		string palavChave_2; //Palavra chave 2 referente ao item
		string CDU;  //sistemas de classificação do acervo, Exemplo de CDU: nnn.nn:nnn.nn
		int situacao; //Situação do item: Emprestado ou livre

	public:

		Acervo();
		~Acervo();
		Acervo(string titulo, string editora, string local, int ano, string assunto,
		       string palavChave_1, string palavChave_2, string CDU, int situacao);
		//Construtor carregado

		//GET
		string getCDU();
		string getTitulo();
		string getEditora();
		string getLocal();
		int getAno();
		string getAssunto();
		string getPalavChave_1();
		string getPalavChave_2();
		int getSituacao();

		//SET
		void setCDU(string CDU);
		void setTitulo(string titulo);
		void setEditora(string editora);
		void setLocal(string local);
		void setAno(int ano);
		void setAssunto(string assunto);
		void setPalavChave_1(string palavChave_1);
		void setPalavChave_2(string palavChave_2);
		void setSituacao(int situacao);


		virtual void imprimirFicha(); //Método virtual puro

};

#endif
