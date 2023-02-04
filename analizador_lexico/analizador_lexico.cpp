#include <cstdlib>
#include <iostream>
#include <string>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <fstream>
#include "lexico.h"

using namespace std;

int main(int argc, char* argv[]) {
    fstream file;
    string line;
    file.open("tokens.txt", ios::in);

    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, line);
        }
        file.close();
    }

    Lexico lexico(line);
    cout << "[Simbolo]\t\t[Token]" << endl;

    while (lexico.simbolo.compare("$") != 0) {
        lexico.sigSimbolo();

        cout << lexico.simbolo << "\t\t\t" << lexico.tipoCad(lexico.estado) << endl;
    }

    cout << "=====================================";
    cin.get();

    return 0;
}