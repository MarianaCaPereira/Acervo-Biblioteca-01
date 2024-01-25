#ifndef PERIODICOS_H  //Revista e jornal
#define PERIODICOS_H

#include "Acervo.h"
#include "GeralPaginas.h"
#include "Autores.h"
#include <string>
using namespace std;

class Periodicos : public Acervo, GeralPaginas
{
	private:
	string tipo;  //Revista ou jornal
	string ISSN;  //N�mero Internacional Normalizado para Publica��es Seriadas: nnnn-nnnn
	string periodo;  //Per�odo do qual � publicado a revista/jornal
	int volume;  //Volume da publica��o
	int edicao;  //Edi��o que est� sendo publicada
	
	public:
		Periodicos();
		Periodicos(string titulo, string editora, string local, int ano, string assunto, string palavChave_1, string palavChave_2, string CDU, int situacao, 
		int paginas, float cm, string tipo, string ISSN, string periodo, int volume, int edicao);
		//Construtor carregado
		~Periodicos();
		
	//GET
	int getQuant_aut();
	string getTipo();  
	string getISSN();
	string getPeriodo();  
	int getVolume();  
	int getEdicao();
	
	//SET
	void setTipo(string tipo);  
	void setISSN(string ISSN);  
	void setPeriodo(string periodo);  
	void setVolume(int volume);  
	void setEdicao(int edicao);
	
	void imprimirFicha();
	
	protected:
};

#endif
