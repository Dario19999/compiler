#include <cstdlib>
#include <iostream>
#include <string>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include "lexico.h"

using namespace std;

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "");

    Lexico lexico("jona 13 2.54 for int + * = || && == ! ; , ( ) { } if while return else / - . % float void ");

    cout << "\t[ANALIZADOR LEXICO]" << endl << endl;
    cout << "[Simbolo]\t\t[Tipo]" << endl;

    while (lexico.simbolo.compare("$") != 0) {
        lexico.sigSimbolo();

        cout << lexico.simbolo << "\t\t" << lexico.tipoAcad(lexico.tipo) << endl;
    }
    cout << "=====================================";
    cin.get();

    return 0;
}