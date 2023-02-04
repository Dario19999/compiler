#include "lexico.h"

Lexico::Lexico(string fuente)
{
	ind = 0;
	this->fuente = fuente;
}

Lexico::Lexico()
{
	ind = 0;
}

string Lexico::tipoCad(int tipo)
{
	string cad = "";

	switch (tipo)
	{
	case SimboloTipo::IDENTIFICADOR:
		cad = "Identificador";
		break;

	case SimboloTipo::ENTERO:
		cad = "Numero Entero";
		break;

	case SimboloTipo::REAL:
		cad = "Numero Real";
		break;

	case SimboloTipo::FOR:
		cad = "Palabra Reservada";
		break;

	case SimboloTipo::TIPOENTERO:
		cad = "Tipo Entero";
		break;

	case SimboloTipo::TIPOREAL:
		cad = "Tipo Real";
		break;

	case SimboloTipo::TIPONULO:
		cad = "Tipo Retorno Nulo";
		break;

	case SimboloTipo::OPSUMA:
		cad = "Operador Suma";
		break;

	case SimboloTipo::OPRESTA:
		cad = "Operador Resta";
		break;

	case SimboloTipo::OPMUL:
		cad = "Operador Multiplicacion";
		break;

	case SimboloTipo::OPDIV:
		cad = "Operador Division";
		break;

	case SimboloTipo::OPMODULO:
		cad = "Operador Modulo";
		break;

	case SimboloTipo::OPRELAC:
		cad = "Operador Relacional";
		break;

	case SimboloTipo::OPOR:
		cad = "Operador OR";
		break;

	case SimboloTipo::OPAND:
		cad = "Operador AND";
		break;

	case SimboloTipo::OPNOT:
		cad = "Operador NOT";
		break;

	case SimboloTipo::OPIGUALDAD:
		cad = "Operador de Igualdad";
		break;

	case SimboloTipo::PUNTO:
		cad = "Punto";
		break;

	case SimboloTipo::PUNTOYCOMA:
		cad = "Punto y Coma";
		break;

	case SimboloTipo::COMA:
		cad = "Coma";
		break;

	case SimboloTipo::PARENTABIERTO:
		cad = "Parentesis abierto";
		break;

	case SimboloTipo::PARENTCERRADO:
		cad = "Parentesis cerrado";
		break;

	case SimboloTipo::CORCHETEABIERTO:
		cad = "Corchete Abierto";
		break;

	case SimboloTipo::CORCHETECERRADO:
		cad = "Corchete Cerrado";
		break;

	case SimboloTipo::ASIGNACION:
		cad = "Operador de Asignacion";
		break;

	case SimboloTipo::IF:
		cad = "Palabra Reservada";
		break;

	case SimboloTipo::WHILE:
		cad = "Palabra Reservada";
		break;

	case SimboloTipo::RETURN:
		cad = "Palabra Reservada";
		break;

	case SimboloTipo::ELSE:
		cad = "Palabra Reservada";
		break;

	case SimboloTipo::DO:
		cad = "Palabra Reservada";
		break;

	case SimboloTipo::FIN:
		cad = "Fin de Codigo";
		break;
	}

	return cad;
}

int Lexico::sigSimbolo()
{
	estado = 0;
	continua = true;
	simbolo = "";
	cont = 0;
	//aux = simbolo;
	while (continua)
	{
		c = sigCaracter();

		switch (estado)
		{
		case 0:
			if (esLetra(c)) {
				estado = 1;
				simbolo += c;
			}
			if (esDigito(c)) {
				estado = 2;
				simbolo += c;
			}
			if (c == '+') {
				aceptacion(5);
			}
			if (c == '-') {
				aceptacion(25);
			}
			if (c == '*')aceptacion(6);
			if (c == '/')aceptacion(24);
			if (c == '%')aceptacion(27);
			if (c == '<' || c == '>') {
				estado = 5;
				simbolo += c;
			}
			if (c == '|') {
				estado = 6;
				simbolo += c;
			}
			if (c == '&') {
				estado = 7;
				simbolo += c;
			}
			if (c == '!') {
				estado = 8;
				simbolo += c;
			}
			if (c == '.') aceptacion(26);
			if (c == ';') aceptacion(12);
			if (c == ',') aceptacion(13);
			if (c == '(') aceptacion(14);
			if (c == ')') aceptacion(15);
			if (c == '{') aceptacion(16);
			if (c == '}') aceptacion(17);
			if (c == '=') {
				estado = 9;
				simbolo += c;
			}
			else {
				if (c == '$')aceptacion(23);
			}
			break;

		case 1:
			if (esLetra(c) || esDigito(c)) {
				estado = 1;
				simbolo += c;

			}
			else if (!esLetra(c) || !esDigito(c))
			{
				aux = simbolo;
				if (aux == "int") {
					aceptacion(4);
				}
				else {
					aceptacion(0);
				}
				if (aux == "float") {
					aceptacion(28);
				}
				if (aux == "void") {
					aceptacion(29);
				}
				if (aux == "if") {
					aceptacion(19);
				}
				if (aux == "while") {
					aceptacion(20);
				}
				if (aux == "return") {
					aceptacion(21);
				}
				if (aux == "else") {
					aceptacion(22);
				}
				if (aux == "do") {
					aceptacion(30);
				}
				if (aux == "for") {
					aceptacion(3);
				}

			}
			break;

		case 2:
			if (esDigito(c)) {
				estado = 2;
				simbolo += c;
			}
			else if (c == '.') {
				estado = 3;
				simbolo += c;
			}
			else if (c != '.' || !esDigito(c)) {
				aceptacion(1);
			}
			break;
		case 3:
			if (esDigito(c)) {
				estado = 4;
				simbolo += c;
			}
			break;
		case 4:
			if (esDigito(c)) {
				estado = 4;
				simbolo += c;
			}
			else {
				aceptacion(2);
			}
			break;
		case 5:
			if (c != '=') {
				aceptacion(7);
			}
			else if (c == '=') {
				aceptacion(7);
			}
			break;
		case 6:
			if (c != '|') {
				aceptacion(23);
			}
			else if (c == '|') {
				aceptacion(8);
			}
			break;
		case 7:
			if (c != '&') {
				aceptacion(23);
			}
			else if (c == '&') {
				aceptacion(9);
			}
			break;
		case 8:
			if (c != '=') {
				aceptacion(10);
			}
			else if (c == '=') {
				aceptacion(11);
			}
			break;
		case 9:
			if (c != '=') {
				aceptacion(18);
			}
			else if (c == '=') {
				aceptacion(11);
			}
			break;
		}

	}

	return estado;

}

char Lexico::sigCaracter()
{
	if (terminado()) return '$';

	return fuente[ind++];
}

void Lexico::sigEstado(int estado)
{
	this->estado = estado;
	if (estado != 0)
	{
		simbolo += c;
	}
}

void Lexico::aceptacion(int estado)
{
	sigEstado(estado);
	continua = false;
}

bool Lexico::terminado()
{
	return ind >= fuente.length();
}

bool Lexico::esLetra(char c)
{
	return c >= 'a' && c <= 'z' || c == '_' || c >= 'A' && c <= 'Z';
}

bool Lexico::esDigito(char c)
{
	return isdigit(c);
}


bool Lexico::esEspacio(char c)
{
	return c == ' ' || c == '\t';
}

void Lexico::retroceso()
{
	if (c != '$') ind--;
	continua = false;
}


