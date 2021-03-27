// Referencia: https://github.com/uliwitness/simpleparser

#include <iostream>
#include "Lexer.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main () {
    Lexer Lexer1;
    vector<Token> tokens;

    ifstream ip("archivo.txt");
    string mes;

    cout << endl << "--TOKEN--          --TIPO--\n"<< endl;

     while(!ip.fail()) {
        getline(ip, mes, '\n');
         if(ip.fail()){
            break;
        }
        tokens = Lexer1.LexerAritmetico(mes);
        for(Token currToken : tokens) {
        currToken.lPrint();
        }

    }
    return 0;
}