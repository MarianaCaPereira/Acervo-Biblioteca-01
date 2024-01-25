#ifndef FOLHETO_H  //cartazes e mapas
#define FOLHETO_H

#include "Acervo.h"
#include "Autores.h"
#include <string>
using namespace std;

#define num_aut 5

class Folheto : public Acervo
{
	private:
	
	Autores *listaAutores[num_aut];//Autores do item
	string tipo;  //cartaz ou mapa
	string descricao;  //Descrição do folheto
	string medidas;  //Tamanho do folheto
	int quant_aut; //Quantidade de autores
		
	public:
		Folheto();
		~Folheto();
		Folheto(string titulo, string editora, string local, int ano, string assunto, 
		string palavChave_1, string palavChave_2, string CDU, int situacao, string tipo, string descricao, string medidas, int quant_aut);
		//Construtor carregado
		
	//GET
	int getQuant_aut();
	void getListaAutores(Autores *ListaAutores[num_aut]);
	string getTipo();  
	string getDescricao(); 
	string getMedidas(); 
	
	//SET
	void setQuant_aut(int quant_aut);
	void setListaAutores(Autores *ListaAutores[num_aut]);
	void setTipo(string tipo);  
	void setDescricao(string descricao); 
	void setMedidas(string medidas); 
	
	void imprimirFicha(); 
	
	protected:
};

#endif
