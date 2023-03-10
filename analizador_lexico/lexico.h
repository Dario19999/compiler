#ifndef LEXICO_H
#define LEXICO_H

#include <iostream>
#include <string>

using namespace std;

class SimboloTipo
{
public:
	static const int ERROR = -1;
	static const int IDENTIFICADOR = 0;
	static const int ENTERO = 1;
	static const int REAL = 2;
	static const int FOR = 3;
	static const int TIPOENTERO = 4;
	static const int OPSUMA = 5;
	static const int OPMUL = 6;
	static const int OPRELAC = 7;
	static const int OPOR = 8;
	static const int OPAND = 9;
	static const int OPNOT = 10;
	static const int OPIGUALDAD = 11;
	static const int PUNTOYCOMA = 12;
	static const int COMA = 13;
	static const int PARENTABIERTO = 14;
	static const int PARENTCERRADO = 15;
	static const int CORCHETEABIERTO = 16;
	static const int CORCHETECERRADO = 17;
	static const int ASIGNACION = 18;
	static const int IF = 19;
	static const int WHILE = 20;
	static const int RETURN = 21;
	static const int ELSE = 22;
	static const int FIN = 23;
	static const int OPDIV = 24;
	static const int OPRESTA = 25;
	static const int PUNTO = 26;
	static const int OPMODULO = 27;
	static const int TIPOREAL = 28;
	static const int TIPONULO = 29;
	static const int DO = 30;
};

class Lexico
{
public:
	string simbolo;
	int estado;

	Lexico(string fuente);
	Lexico();

	void entrada(string fuente);
	string tipoCad(int tipo);

	int sigSimbolo();
	bool terminado();

private:
	string fuente;
	int ind;
	bool continua;
	char c;
	int cont;
	string aux;

	char sigCaracter();
	void sigEstado(int estado);
	void aceptacion(int estado);
	bool esLetra(char c);
	bool esDigito(char c);
	bool esEspacio(char c);
	void retroceso();
};

#endif
