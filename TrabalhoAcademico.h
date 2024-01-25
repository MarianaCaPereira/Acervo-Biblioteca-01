#ifndef TRABALHOACADEMICO_H  //monografias, dissertações e teses
#define TRABALHOACADEMICO_H


#include "Acervo.h"
#include "GeralPaginas.h"
#include "Autores.h"
#include <string>
using namespace std;

#define num_aut 5

class TrabalhoAcademico : public Acervo, GeralPaginas
{
	private:
	Autores *listaAutores[num_aut];//Autores do item
	string tipo;  //monografia, dissertação ou tese
	string ISBN; //Padrão internacional de numeração de livro : nn-nnnn-nnn-n
	string descricao;  //Descrição do trabalho
	string curso;  //Curso que está vinculado o trabalho
	string orientador;  //Orientador do trabalho
	int quant_aut; //Quantidade de autores
	
	public:
		TrabalhoAcademico();
		TrabalhoAcademico(string titulo, string editora, string local, int ano, string assunto, string palavChave_1, string palavChave_2, string CDU, int situacao, 
		int paginas, float cm, string tipo, string ISBN, string descricao, string curso, string orientador, int quant_aut);
		//Construtor carregado;
		~TrabalhoAcademico();
		
	//GET
	int getQuant_aut();
	void getListaAutores(Autores *ListaAutores[num_aut]);
	string getISBN(); 
	string getTipo();  
	string getDescricao();
	string getCurso();
	string getOrientador();
	
	//SET
	void setQuant_aut(int quant_aut);
	void setListaAutores(Autores *ListaAutores[num_aut]);
	void setISBN(string ISBN);
	void setTipo(string tipo);  
	void setDescricao(string descricao);
	void setCurso(string curso);
	void setOrientador(string orientador);
		
	void imprimirFicha();
	
	protected:
};

#endif
