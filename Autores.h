#ifndef AUTORES_H
#define AUTORES_H

#include <string>
#include <cstring>
using namespace std;

class Autores
{
	private:
	string nome;
	
	public:
		Autores();
		Autores(string nome);  //Construtor carregado;
		~Autores();
		
	//GET
	string getNome();
	
	//SET
	void setNome(string nome);
	
	protected:
};
