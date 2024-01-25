#ifndef GERALPAGINAS_H  //Classe base de itens de possuem caracteristicas em comum
#define GERALPAGINAS_H

#include <string>
using namespace std;

class GeralPaginas  //Classe abstrata
{
	private:
		
	protected:
	int paginas;  //Quantidade de paginas
	float cm;  //Tamanho do item
	
	public:
		
		GeralPaginas();
		~GeralPaginas();
		GeralPaginas(int paginas, float cm);  //Construtor carregado
		
	//GET
	int getPaginas();  
	float getCm(); 
	
	//SET
	void setPaginas(int paginas);  
	void setCm(float cm);  
	
	virtual void imprimirFicha_Paginas(); //Método virtual puro
		
	protected:
};

#endif
