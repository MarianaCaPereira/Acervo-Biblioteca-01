#include <locale>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <ctype.h>

#include "Acervo.h"
#include "GeralPaginas.h"
#include "Livros.h"
#include "TrabalhoAcademico.h"
#include "Relatorios.h"
#include "Periodicos.h"
#include "Folheto.h"
#include "Midia.h"

#define num_aut 5
#define num_issn 10
#define num_isbn 14
#define num_cdu 14

using std::string;

int validar_CDU(char CDU[num_cdu]){  //Validar o ISBN
int resul;
	for(int i = 0; i < num_cdu; i++){
		if(i == 3 || i == 10){  //Verificar '.'
			
			if(CDU[i] == '.'){
			resul = resul + 0;	
			}else{
			resul = resul + 1;	
			}
		}
		else if(i == 6){  //Verificar ':'
		
			if(CDU[i] == ':'){
			resul = resul + 0;	
			}else{
			resul = resul + 1;	
			}
		}else{  //Verificar n�meros
			if(isdigit(CDU[i]) == 1){
			resul = resul + 0;
			}else{
			resul = resul + 1;
			}
		}
	}
	return resul;  //O resultado deve ser 0 para ser v�lido
}
int validar_ISBN(char ISBN[num_isbn]){  //Validar o ISBN
int resul;
	for(int i = 0; i < num_isbn; i++){
		if(i == 2 || i == 7 || i == 11){  //Verificar '-'
			
			if(ISBN[i] == '-'){
			resul = resul + 0;	
			}else{
			resul = resul + 1;	
			}
		}else{  //Verificar n�meros
			if(isdigit(ISBN[i]) == 1){
			resul = resul + 0;
			}else{
			resul = resul + 1;
			}
		}
	}
	return resul;  //O resultado deve ser 0 para ser v�lido
}
int validar_ISSN(char ISSN[num_issn]){  //Validar o ISSN
int resul;
	for(int i = 0; i < num_issn; i++){
		
		if(i == 4){  //Verificar '-'
			
			if(ISSN[i] == '-'){
			resul = resul + 0;	
			}else{
			resul = resul + 1;	
			}
		}else{  //Verificar n�meros
			if(isdigit(ISSN[i]) == 1){
			resul = resul + 0;
			}else{
			resul = resul + 1;
			}
		}
	}
	return resul;  //O resultado deve ser 0 para ser v�lido
}
Autores* cadastrar_Autores(Autores* autor, int n){
autor = NULL;
string nome;
	
	cout << endl << "Entre com autor " << n+1 << ": ";
	getline(cin, nome);
	cin.clear();
	fflush(stdin);
	cout << endl;
	
	autor = new Autores(nome);
	
	return autor;
}

Livros* cadastra_Livro(Livros *livro){
	livro = NULL;
	
	string titulo; 
	string editora;  
	string local;  
	int ano;  
	string assunto;  
	string palavChave_1; 
	string palavChave_2; 
	string CDU; 
	int situacao;  //Inicializado como livre
	
	string ISBN;
	int edicao;
	int paginas;
	float cm;
	
	
	cout << endl << "|CADASTRO DE LIVRO|" << endl;
	
	cout << endl << "Entre com o t�tulo do livro: ";
	getline(cin, titulo);
	cin.clear();
	fflush(stdin);
	
	int quant_aut = -1;	
	
		while(quant_aut <= 0 || quant_aut > 5){
			
			cout << endl << "Entre com a quantidade de autores do livro: ";
			cin >> quant_aut;
			cin.clear();
			fflush(stdin);
			
			if(quant_aut <= 0 || quant_aut > 5){  //Caso a quantidade seja seja inv�lida
			cout << endl << "|Quantidade inv�lida!| ";	
			}
		}
		
		Autores *listaAutores[num_aut];  //Cadastrar os autores
		for(int i = 0; i < quant_aut; i++){
		string nome;
	
		cout << endl << "Entre com autor " << i+1 << ": ";
		getline(cin, nome);
		cin.clear();
		fflush(stdin);
		cout << endl;
		listaAutores[i] = new Autores(nome);
		}
		
	cout << "Entre com a editora do livro: ";
	getline(cin, editora);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o local de publica��o: ";
	getline(cin, local);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o ano de publica��o: ";
	cin >> ano;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a edi��o do livro: ";
	cin >> edicao;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a quantidade de p�ginas do livro: ";
	cin >> paginas;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o tamanho (em cm) do do livro: ";
	cin >> cm;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o assunto do livro: ";
	getline(cin, assunto);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a palavra chave 1 do livro: ";
	getline(cin, palavChave_1);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a palavra chave 2 do livro: ";
	getline(cin, palavChave_2);
	cin.clear();
	fflush(stdin);
	
	int resul = 0;
	
		while(resul != 1){  //Repetir at� o CDU estar v�lido
		cout << endl << "Entre com o CDU do livro: ";
		getline(cin, CDU);
		cin.clear();
		fflush(stdin);	
		
		int n = CDU.length();  //Transformar o CDU em Array para conferir 
		char cdu_array[n + 1];
		strcpy(cdu_array, CDU.c_str());
		
		resul = validar_CDU(cdu_array);
		
			if(resul != 1){  //Caso o CDU seja inv�lido
			cout << endl << "|CDU inv�lido!| " << endl;	
			}
		}
		
	resul = 0;	
	
		while(resul != 1){  //Repetir at� o ISBN estar v�lido
		cout << endl << "Entre com o ISBN do livro: ";
		getline(cin, ISBN);
		cin.clear();
		fflush(stdin);	
		
		int n = ISBN.length();  //Transformar o ISBN em Array para conferir 
		char isbn_array[n + 1];
		strcpy(isbn_array, ISBN.c_str());
		
		resul = validar_ISBN(isbn_array);
		
			if(resul != 1){  //Caso o ISBN seja inv�lido
			cout << endl << "|ISBN inv�lido!| " << endl;	
			}
		}
	livro = new Livros(titulo, editora, local, ano, assunto, palavChave_1, palavChave_2, CDU, situacao, paginas, cm, ISBN, edicao, quant_aut);
	livro->setListaAutores(listaAutores);
	
	return livro;
}
TrabalhoAcademico* cadastra_Trabalho(TrabalhoAcademico * trabalho){
trabalho = NULL;

	string titulo; 
	string editora;  
	string local;  
	int ano;  
	string assunto;  
	string palavChave_1; 
	string palavChave_2; 
	string CDU; 
	int situacao;  //Inicializado como livre
	
	int paginas;
	float cm;
	
	string tipo;  //monografia, disserta��o ou tese
	string ISBN; 
	string descricao;  
	string curso;  
	string orientador;  
	
	cout << endl << "|CADASTRO DE TRABALHO ACAD�MICO|" << endl;
	
	int opcao = 0;
		while(opcao < 1 || opcao > 3){
			cout << endl << "1- monografia 2-disserta��o 3-tese";
			cout << endl << "Entre com o tipo do trabalho: ";
			cin >> opcao;
			cin.clear();
			fflush(stdin);
			
			if(opcao < 1 || opcao > 3){  //Caso a op��o seja seja inv�lida
			cout << endl << "|Op��o inv�lida!| ";	
			}
		}
		
		if(opcao == 1){
		tipo = "Monografia";
		}
		else if(opcao == 2){
		tipo = "Disserta��o";
		}
		else if(opcao == 3){
		tipo = "Tese";	
		}
	
	cout << endl << "Entre com o t�tulo do trabalho: ";
	getline(cin, titulo);
	cin.clear();
	fflush(stdin);
	
	int quant_aut = -1;	
	
		while(quant_aut <= 0 || quant_aut > 5){
			
			cout << endl << "Entre com a quantidade de autores do trabalho: ";
			cin >> quant_aut;
			cin.clear();
			fflush(stdin);
			
			if(quant_aut <= 0 || quant_aut > 5){  //Caso a quantidade seja seja inv�lida
			cout << endl << "|Quantidade inv�lida!| ";	
			}
		}
		
		Autores *listaAutores[num_aut];  //Cadastrar os autores
		for(int i = 0; i < quant_aut; i++){
		string nome;
	
		cout << endl << "Entre com autor " << i+1 << ": ";
		getline(cin, nome);
		cin.clear();
		fflush(stdin);
		cout << endl;
		listaAutores[i] = new Autores(nome);
		}
		
	cout << endl << "Entre com orientador do trabalho: ";
	getline(cin, orientador);
	cin.clear();
	fflush(stdin);
		
	cout << endl << "Entre com o curso vinculado ao trabalho: ";
	getline(cin, curso);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a institui��o vinculada ao trabalho: ";
	getline(cin, editora);
	cin.clear();
	fflush(stdin);
		
	cout << endl << "Entre com a descri��o trabalho: ";
	getline(cin, descricao);
	cin.clear();
	fflush(stdin);
		
	cout << endl << "Entre com o local de publica��o: ";
	getline(cin, local);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o ano de publica��o: ";
	cin >> ano;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a quantidade de p�ginas do trabalho: ";
	cin >> paginas;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o tamanho (em cm) do do trabalho: ";
	cin >> cm;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o assunto do trabalho: ";
	getline(cin, assunto);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a palavra chave 1 do trabalho: ";
	getline(cin, palavChave_1);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a palavra chave 2 do trabalho: ";
	getline(cin, palavChave_2);
	cin.clear();
	fflush(stdin);
	
	int resul = 0;
	
		while(resul != 1){  //Repetir at� o CDU estar v�lido
		cout << endl << "Entre com o CDU do trabalho: ";
		getline(cin, CDU);
		cin.clear();
		fflush(stdin);	
		
		int n = CDU.length();  //Transformar o CDU em Array para conferir 
		char cdu_array[n + 1];
		strcpy(cdu_array, CDU.c_str());
		
		resul = validar_CDU(cdu_array);
		
			if(resul != 1){  //Caso o CDU seja inv�lido
			cout << endl << "|CDU inv�lido!| " << endl;	
			}
		}
		
	resul = 0;	
	
		while(resul != 1){  //Repetir at� o ISBN estar v�lido
		cout << endl << "Entre com o ISBN do trabalho: ";
		getline(cin, ISBN);
		cin.clear();
		fflush(stdin);	
		
		int n = ISBN.length();  //Transformar o ISBN em Array para conferir 
		char isbn_array[n + 1];
		strcpy(isbn_array, ISBN.c_str());
		
		resul = validar_ISBN(isbn_array);
		
			if(resul != 1){  //Caso o ISBN seja inv�lido
			cout << endl << "|ISBN inv�lido!| " << endl;	
			}
		}
		
	trabalho = new TrabalhoAcademico(titulo, editora, local, ano, assunto, palavChave_1, palavChave_2, CDU, situacao, paginas, cm, tipo, ISBN, descricao, curso, orientador, quant_aut);	
	trabalho->setListaAutores(listaAutores);
	return trabalho;
}
Relatorios* cadastra_Relatorio(Relatorios* relatorio){
relatorio = NULL;

	string titulo; 
	string editora;  
	string local;  
	int ano;  
	string assunto;  
	string palavChave_1; 
	string palavChave_2; 
	string CDU; 
	int situacao;  //Inicializado como livre
	
	int paginas;
	float cm;
	
	string ISBN; 
	string descricao; 
	
	cout << endl << "|CADASTRO DE RELAT�RIO|" << endl;
	
	cout << endl << "Entre com o t�tulo do relat�rio: ";
	getline(cin, titulo);
	cin.clear();
	fflush(stdin);
	
	int quant_aut = -1;	
	
		while(quant_aut <= 0 || quant_aut > 5){
			
			cout << endl << "Entre com a quantidade de autores do relat�rio: ";
			cin >> quant_aut;
			cin.clear();
			fflush(stdin);
			
			if(quant_aut <= 0 || quant_aut > 5){  //Caso a quantidade seja seja inv�lida
			cout << endl << "|Quantidade inv�lida!| ";	
			}
		}
		
		Autores *listaAutores[num_aut];  //Cadastrar os autores
		for(int i = 0; i < quant_aut; i++){
		string nome;
	
		cout << endl << "Entre com autor " << i+1 << ": ";
		getline(cin, nome);
		cin.clear();
		fflush(stdin);
		cout << endl;
		listaAutores[i] = new Autores(nome);
		}
	
	cout << endl << "Entre com a institui��o vinculada ao relat�rio: ";
	getline(cin, editora);
	cin.clear();
	fflush(stdin);
		
	cout << endl << "Entre com a descri��o relat�rio: ";
	getline(cin, descricao);
	cin.clear();
	fflush(stdin);
		
	cout << endl << "Entre com o local de publica��o: ";
	getline(cin, local);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o ano de publica��o: ";
	cin >> ano;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a quantidade de p�ginas do relat�rio: ";
	cin >> paginas;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o tamanho (em cm) do do relat�rio: ";
	cin >> cm;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o assunto do trabalho: ";
	getline(cin, assunto);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a palavra chave 1 do trabalho: ";
	getline(cin, palavChave_1);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a palavra chave 2 do trabalho: ";
	getline(cin, palavChave_2);
	cin.clear();
	fflush(stdin);
		
	int resul = 0;
	
		while(resul != 1){  //Repetir at� o CDU estar v�lido
		cout << endl << "Entre com o CDU do relat�rio: ";
		getline(cin, CDU);
		cin.clear();
		fflush(stdin);	
		
		int n = CDU.length();  //Transformar o CDU em Array para conferir 
		char cdu_array[n + 1];
		strcpy(cdu_array, CDU.c_str());
		
		resul = validar_CDU(cdu_array);
		
			if(resul != 1){  //Caso o CDU seja inv�lido
			cout << endl << "|CDU inv�lido!| " << endl;	
			}
		}
		
	resul = 0;	
	
		while(resul != 1){  //Repetir at� o ISBN estar v�lido
		cout << endl << "Entre com o ISBN do relat�rio: ";
		getline(cin, ISBN);
		cin.clear();
		fflush(stdin);	
		
		int n = ISBN.length();  //Transformar o ISBN em Array para conferir 
		char isbn_array[n + 1];
		strcpy(isbn_array, ISBN.c_str());
		
		resul = validar_ISBN(isbn_array);
		
			if(resul != 1){  //Caso o ISBN seja inv�lido
			cout << endl << "|ISBN inv�lido!| " << endl;	
			}
		}
		
	
	relatorio = new Relatorios(titulo, editora, local, ano, assunto, palavChave_1, palavChave_2, CDU, situacao, paginas, cm, ISBN, descricao, quant_aut);
	relatorio->setListaAutores(listaAutores);
	return relatorio;	
}
Periodicos* cadastra_Periodico(Periodicos* periodico){
periodico = NULL;

	string titulo; 
	string editora;  
	string local;  
	int ano;  
	string assunto;  
	string palavChave_1; 
	string palavChave_2; 
	string CDU; 
	int situacao;  //Inicializado como livre
	
	int paginas;
	float cm;
	
	string tipo;  //Revista ou jornal
	string ISSN;  
	string periodo;  
	int volume;  
	int edicao;
	
	cout << endl << "|CADASTRO DE PERI�DICOS|" << endl;
	
	int opcao = 0;
		while(opcao < 1 || opcao > 2){
			cout << endl << "1- Revista 2-Jornal";
			cout << endl << "Entre com o tipo do peri�dico: ";
			cin >> opcao;
			cin.clear();
			fflush(stdin);
			
			if(opcao < 1 || opcao > 2){  //Caso a op��o seja seja inv�lida
			cout << endl << "|Op��o inv�lida!| ";	
			}
		}
		
		if(opcao == 1){
		tipo = "Revista";
		}
		else if(opcao == 2){
		tipo = "Jornal";
		}
		
	cout << endl << "Entre com o t�tulo do peri�dico: ";
	getline(cin, titulo);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o local de publica��o: ";
	getline(cin, local);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o ano de publica��o: ";
	cin >> ano;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a editora do peri�dico: ";
	getline(cin, editora);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a edi��o do peri�dico: ";
	cin >> edicao;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o volume do peri�dico: ";
	cin >> volume;
	cin.clear();
	fflush(stdin);
	
	cout << endl <<  "Entre com o per�odo de publica��o do peri�dico: ";
	getline(cin, periodo);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a quantidade de p�ginas do peri�dico: ";
	cin >> paginas;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o tamanho (em cm) do do peri�dico: ";
	cin >> cm;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o assunto do peri�dico: ";
	getline(cin, assunto);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a palavra chave 1 do peri�dico: ";
	getline(cin, palavChave_1);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a palavra chave 2 do peri�dico: ";
	getline(cin, palavChave_2);
	cin.clear();
	fflush(stdin);
		
	int resul = 0;
	
		while(resul != 1){  //Repetir at� o CDU estar v�lido
		cout << endl << "Entre com o CDU do peri�dico: ";
		getline(cin, CDU);
		cin.clear();
		fflush(stdin);	
		
		int n = CDU.length();  //Transformar o CDU em Array para conferir 
		char cdu_array[n + 1];
		strcpy(cdu_array, CDU.c_str());
		
		resul = validar_CDU(cdu_array);
		
			if(resul != 1){  //Caso o CDU seja inv�lido
			cout << endl << "|CDU inv�lido!| " << endl;	
			}
		}

	resul = 0;	
	
		while(resul != 1){  //Repetir at� o ISSN estar v�lido
		cout << endl << "Entre com o ISSN do peri�dico: ";
		getline(cin, ISSN);
		cin.clear();
		fflush(stdin);	
		
		int n = ISSN.length();  //Transformar o ISBN em Array para conferir 
		char issn_array[n + 1];
		strcpy(issn_array, ISSN.c_str());
		
		resul = validar_ISSN(issn_array);
		
			if(resul != 1){  //Caso o ISBN seja inv�lido
			cout << endl << "|ISSN inv�lido!| " << endl;	
			}
		}
		
	
	periodico = new Periodicos(titulo, editora, local, ano, assunto, palavChave_1, palavChave_2, CDU, situacao, paginas, cm, tipo, ISSN, periodo, volume, edicao);
	return periodico;
}
Midia* cadastra_Midia(Midia *midia){
midia = NULL;

	string titulo; 
	string editora;  
	string local;  
	int ano;  
	string assunto;  
	string palavChave_1; 
	string palavChave_2; 
	string CDU; 
	int situacao;  //Inicializado como livre
	
	string tipo;  //Fita VHS, CD ou DVD
	string descricao;  
	float capacidade;
	
	cout << endl << "|CADASTRO DE M�DIAS|" << endl;
	
	int opcao = 0;
		while(opcao < 1 || opcao > 3){
			cout << endl << "1-Fita VHS 2-CD 3-DVD";
			cout << endl << "Entre com o tipo de m�dia: ";
			cin >> opcao;
			cin.clear();
			fflush(stdin);
			
			if(opcao < 1 || opcao > 3){  //Caso a op��o seja seja inv�lida
			cout << endl << "|Op��o inv�lida!| ";	
			}
		}
		
		if(opcao == 1){
		tipo = "Fita VHS";
		}
		else if(opcao == 2){
		tipo = "CD";
		}
		else if(opcao == 3){
		tipo = "DVD";
		}
		
	cout << endl << "Entre com o t�tulo da m�dia: ";
	getline(cin, titulo);
	cin.clear();
	fflush(stdin);
	
	int quant_aut = -1;	
	
		while(quant_aut <= 0 || quant_aut > 5){
			
			cout << endl << "Entre com a quantidade de autores da m�dia: ";
			cin >> quant_aut;
			cin.clear();
			fflush(stdin);
			
			if(quant_aut <= 0 || quant_aut > 5){  //Caso a quantidade seja seja inv�lida
			cout << endl << "|Quantidade inv�lida!| ";	
			}
		}
		
		Autores *listaAutores[num_aut];  //Cadastrar os autores
		for(int i = 0; i < quant_aut; i++){
		string nome;
	
		cout << endl << "Entre com autor " << i+1 << ": ";
		getline(cin, nome);
		cin.clear();
		fflush(stdin);
		cout << endl;
		listaAutores[i] = new Autores(nome);
		}
	
	cout << endl << "Entre com o local de publica��o: ";
	getline(cin, local);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o ano de publica��o: ";
	cin >> ano;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a institui��o respons�vel pela m�dia: ";
	getline(cin, editora);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a descri��o da m�dia: ";
	getline(cin, descricao);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a capacidade da m�dia: ";
	cin >> capacidade;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o assunto da m�dia: ";
	getline(cin, assunto);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a palavra chave 1 da m�dia: ";
	getline(cin, palavChave_1);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a palavra chave 2 da m�dia: ";
	getline(cin, palavChave_2);
	cin.clear();
	fflush(stdin);
	
	int resul = 0;
	
		while(resul != 1){  //Repetir at� o CDU estar v�lido
		cout << endl << "Entre com o CDU da m�dia: ";
		getline(cin, CDU);
		cin.clear();
		fflush(stdin);	
		
		int n = CDU.length();  //Transformar o CDU em Array para conferir 
		char cdu_array[n + 1];
		strcpy(cdu_array, CDU.c_str());
		
		resul = validar_CDU(cdu_array);
		
			if(resul != 1){  //Caso o CDU seja inv�lido
			cout << endl << "|CDU inv�lido!| " << endl;	
			}
		}
		
	midia = new Midia(titulo, editora, local, ano, assunto, palavChave_1, palavChave_2, CDU, situacao, tipo, descricao, capacidade, quant_aut);
	midia->setListaAutores(listaAutores);
	return midia;
}
Folheto* cadastra_Folheto(Folheto* folheto){
folheto = NULL;

	string titulo; 
	string editora;  
	string local;  
	int ano;  
	string assunto;  
	string palavChave_1; 
	string palavChave_2; 
	string CDU; 
	int situacao;  //Inicializado como livre
	
	string tipo;  //cartaz ou mapa
	string descricao;  
	string medidas;  
	
	cout << endl << "|CADASTRO DE FOLHETO|" << endl;
	
	int opcao = 0;
		while(opcao < 1 || opcao > 2){
			cout << endl << "1-Cartaz 2-Mapa";
			cout << endl << "Entre com o tipo de folheto: ";
			cin >> opcao;
			cin.clear();
			fflush(stdin);
			
			if(opcao < 1 || opcao > 2){  //Caso a op��o seja seja inv�lida
			cout << endl << "|Op��o inv�lida!| ";	
			}
		}
		
		if(opcao == 1){
		tipo = "Cartaz";
		}
		else if(opcao == 2){
		tipo = "Mapa";
		}
	
	cout << endl << "Entre com o t�tulo do folheto: ";
	getline(cin, titulo);
	cin.clear();
	fflush(stdin);
	
	int quant_aut = -1;	
	
		while(quant_aut <= 0 || quant_aut > 5){
			
			cout << endl << "Entre com a quantidade de autores do folheto: ";
			cin >> quant_aut;
			cin.clear();
			fflush(stdin);
			
			if(quant_aut <= 0 || quant_aut > 5){  //Caso a quantidade seja seja inv�lida
			cout << endl << "|Quantidade inv�lida!| ";	
			}
		}
		
		Autores *listaAutores[num_aut];  //Cadastrar os autores
		for(int i = 0; i < quant_aut; i++){
		string nome;
	
		cout << endl << "Entre com autor " << i+1 << ": ";
		getline(cin, nome);
		cin.clear();
		fflush(stdin);
		cout << endl;
		listaAutores[i] = new Autores(nome);
		}
	
	cout << endl << "Entre com o local de publica��o: ";
	getline(cin, local);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o ano de publica��o: ";
	cin >> ano;
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a editora do folheto: ";
	getline(cin, editora);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a descri��o do folheto: ";
	getline(cin, descricao);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com as medidas do folheto: ";
	getline(cin, medidas);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com o assunto do folheto: ";
	getline(cin, assunto);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a palavra chave 1 do folheto: ";
	getline(cin, palavChave_1);
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Entre com a palavra chave 2 do folheto: ";
	getline(cin, palavChave_2);
	cin.clear();
	fflush(stdin);
	
	int resul = 0;
	
		while(resul != 1){  //Repetir at� o CDU estar v�lido
		cout << endl << "Entre com o CDU do folheto: ";
		getline(cin, CDU);
		cin.clear();
		fflush(stdin);	
		
		int n = CDU.length();  //Transformar o CDU em Array para conferir 
		char cdu_array[n + 1];
		strcpy(cdu_array, CDU.c_str());
		
		resul = validar_CDU(cdu_array);
		
			if(resul != 1){  //Caso o CDU seja inv�lido
			cout << endl << "|CDU inv�lido!| " << endl;	
			}
		}
	
	folheto = new Folheto(titulo, editora, local, ano, assunto,  palavChave_1, palavChave_2, CDU, situacao, tipo, descricao, medidas, quant_aut);
	folheto->setListaAutores(listaAutores);
	return folheto;
}
int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "portuguese");
	system("chcp 1252 > nul");
	
	vector <Acervo *> listaAcervo;  //Vetor de itens do acervo
	
	int opcao = 0;
	int item = 0;
	int conf = 0;
	Acervo* acervo = NULL;
	string CDU;
	string cdu;
	
	do{  //O programa funciona at� pedir para parar seu funcionamento
	opcao = 0;
	item = 0;
	
		do{
		cout << endl << "----------ACERVO DA BIBLIOTECA----------" << endl;
		cout << endl << "|MENU DE OP��ES|";
		cout << endl << "1 - CADASTRAR";
		cout << endl << "2 - EMPRESTAR";
		cout << endl << "3 - DEVOLVER";
		cout << endl << "4 - PESQUISAR";
		cout << endl << "5 - IMPRIMIR";
		cout << endl << "6 - EXCLUIR";
		cout << endl << "7 - SAIR";
		cout << endl << "Escolha uma op��o: ";
		cin >> opcao;
		cin.clear();
		fflush(stdin);
		
			if(opcao <= 0 || opcao > 7){  //Caso a op��o n�o seja v�lida
			cout << endl << "Op��o inv�lida!" << endl;	
			}
			
		}while(opcao <= 0 || opcao > 7);  //Repetir at� a op��o ser v�lida
		
		switch(opcao){
			
			case 1:  //CADASTRAR 
			
				do{
					cout << endl << "|MENU DE OP��ES|";
					cout  << endl << "1-Livro, 2-Trabalho acad�mico, 3-Relat�rio, 4-Peri�dico, 5-Folheto, 6-M�dia";
					cout << endl << "Escolha uma op��o: ";
					cin >> item;
					cin.clear();
					fflush(stdin);
					if(item <= 0 || item > 6){  //Caso a op��o n�o seja v�lida
					cout << endl << "Op��o inv�lida!" << endl;	
					}
				}while(item <= 0 || item > 6);  //Repetir at� a op��o ser v�lida
				
					if(item == 1){  //Cadastrar livro
						acervo = new Livros();
						acervo = cadastra_Livro(dynamic_cast<Livros*>(acervo));
						listaAcervo.push_back(acervo);
						acervo->imprimirFicha();
						
					}
					else if(item == 2){  //Cadastrar Trabalho
						acervo = new TrabalhoAcademico();
						acervo = cadastra_Trabalho(dynamic_cast<TrabalhoAcademico*>(acervo));
						listaAcervo.push_back(acervo);
						acervo->imprimirFicha();
					}
					else if(item == 3){  //Cadastrar relat�rio
						acervo = new Relatorios();
						acervo = cadastra_Relatorio(dynamic_cast<Relatorios*>(acervo));
						listaAcervo.push_back(acervo);
						acervo->imprimirFicha();
					}
					else if(item == 4){  //Cadastrar peri�dico
						acervo = new Periodicos();
						acervo = cadastra_Periodico(dynamic_cast<Periodicos*>(acervo));
						listaAcervo.push_back(acervo);
						acervo->imprimirFicha();
					}
					else if(item == 5){  //Cadastrar Folheto
						acervo = new Folheto();
						acervo = cadastra_Folheto(dynamic_cast<Folheto*>(acervo));
						listaAcervo.push_back(acervo);
						acervo->imprimirFicha();
					}
					else if(item == 6){  //Cadastrar m�dia
						acervo = new Midia();
						acervo = cadastra_Midia(dynamic_cast<Midia*>(acervo));
						listaAcervo.push_back(acervo);
						acervo->imprimirFicha();
					}
				break;
				
			case 2:  //EMPRESTAR
			
				if(listaAcervo.size() > 0){  //Se o vetor tiver itens cadastrados
					cout << endl << "|EMPRESTAR ITEM|" << endl;  //Pesquisar itens por CDU do acervo
					cout << endl << "Entre com o CDU do item: ";
					getline(cin, CDU);
					cin.clear();
					fflush(stdin);
					
					conf = 0;
					for(vector <Acervo *>::iterator it = listaAcervo.begin(); it != listaAcervo.end(); it++){  //Percorrer itens da conta
					cdu = (*it)->getCDU();
						if(strcmp(cdu.c_str(), CDU.c_str()) == 0){  //Verificando
						
							if((*it)->getSituacao() == 1){   //Item n�o dispon�vel
							cout << endl << "Item n�o dispon�vel para empr�stimo!" << endl;
							
							}else{  //Emprestando o item
							
							(*it)->setSituacao(1);  //Emprestando o item
							(*it)->imprimirFicha();
							cout << endl << "Empr�stimo finalizado!" << endl;
							}
						conf = 1;
						break;
						}
					cout << endl;	
					}
					if(conf == 0){  //Caso o item n�o tenha sido encontrado
					cout << endl << "Item n�o encontrado!" << endl;
		
					}
				}else{  //Se o acervo n�o tiver itens
					cout << endl << "N�o h� itens no acervo!" << endl;
				}
				break;
				
			case 3:  //DEVOLVER
			
				if(listaAcervo.size() > 0){  //Se o vetor tiver itens cadastrados
					cout << endl << "|DEVOLVER ITEM|" << endl;  //Pesquisar itens por CDU do acervo
					cout << endl << "Entre com o CDU do item: ";
					getline(cin, CDU);
					cin.clear();
					fflush(stdin);
					
					conf = 0;
					for(vector <Acervo *>::iterator it = listaAcervo.begin(); it != listaAcervo.end(); it++){  //Percorrer itens da conta
					cdu = (*it)->getCDU();
						if(strcmp(cdu.c_str(), CDU.c_str()) == 0){  //Verificando
						
							if((*it)->getSituacao() == 0){   //Item j� est� no acervo
							cout << endl << "O item j� se encontra no acervo. N�o � poss�vel devolver!" << endl;
							}else{  //Devolvendo o item
							
							(*it)->setSituacao(0);  //Devolvendo o item o item
							(*it)->imprimirFicha();
							cout << endl << "Devolu��o finalizada!" << endl;
							}
						conf = 1;
						break;
						}
					cout << endl;	
					}
					if(conf == 0){  //Caso o item n�o tenha sido encontrado
					cout << endl << "Item n�o encontrado!" << endl;
		
					}
				}else{  //Se o acervo n�o tiver itens
					cout << endl << "N�o h� itens no acervo!" << endl;
				}
				break;
				
			case 4:  //PESQUISAR
			
				if(listaAcervo.size() > 0){  //Se o vetor tiver itens cadastrados
					cout << endl << "|PESQUISAR ITEM POR CDU|" << endl;  //Pesquisar itens por CDU do acervo
					cout << endl << "Entre com o CDU do item: ";
					getline(cin, CDU);
					cin.clear();
					fflush(stdin);
					
					conf = 0;
					for(vector <Acervo *>::iterator it = listaAcervo.begin(); it != listaAcervo.end(); it++){  //Percorrer itens da conta
					cdu = (*it)->getCDU();
						if(strcmp(cdu.c_str(), CDU.c_str()) == 0){  //Verificando
						cout << endl << "Item encontrado!" << endl;
						(*it)->imprimirFicha();
						cout << endl;
						conf = 1;
						break;
						}
					cout << endl;	
					}
					if(conf == 0){  //Caso o item n�o tenha sido encontrado
					cout << endl << "Item n�o encontrado!" << endl;
		
					}
				}else{  //Se o acervo n�o tiver itens
					cout << endl << "N�o h� itens no acervo!" << endl;
				}
				break;
				
			case 5:  //IMPRIMIR
			
				if(listaAcervo.size() > 0){  //Se o vetor tiver itens cadastrados
					cout << endl << "|Imprimir itens do acervo|" << endl;
					for(vector <Acervo *>::iterator it = listaAcervo.begin(); it != listaAcervo.end(); it++){  //Imprimir itens da conta
					(*it)->imprimirFicha();
					cout << endl;	
					}
				}else{  //Se o acervo n�o tiver itens
					cout << endl << "N�o h� itens no acervo!" << endl;
				}
				break;
				
			case 6:  //EXCLUIR
			
				if(listaAcervo.size() > 1){  //Se o vetor tiver itens cadastrados
					cout << endl << "|EXCLUIR ITEM POR CDU|" << endl;  //Pesquisar itens por CDU do acervo
					cout << endl << "Entre com o CDU do item: ";
					getline(cin, CDU);
					cin.clear();
					fflush(stdin);
					
					conf = 0;
					for(vector <Acervo *>::iterator it = listaAcervo.begin(); it != listaAcervo.end(); it++){  //Percorrer itens da conta
					cdu = (*it)->getCDU();
						if(strcmp(cdu.c_str(), CDU.c_str()) == 0){  //Verificando
			
							listaAcervo.erase(it);	
						cout << endl << "Item encontrado e excluido!" << endl;
						cout << endl;
						conf = 1;
						break;
						}
					cout << endl;	
					}
					if(conf == 0){  //Caso o item n�o tenha sido encontrado
					cout << endl << "Item n�o encontrado!" << endl;
					}
				}else{  //Se o acervo n�o tiver itens
					cout << endl << "N�o � poss�vel excluir!" << endl;
				}
				break;
			
			case 7:  //SAIR
				cout << endl << "Programa encerrado!" << endl;
				continue;
				
				 
		}
	}while(opcao != 7);
	
	for(vector <Acervo *>::iterator it = listaAcervo.begin(); it != listaAcervo.end(); it++){  //Deletar os itens
	delete(*it);	
	}
	delete(acervo);
	return 0;
}
