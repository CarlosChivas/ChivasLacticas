// Referencia: https://github.com/uliwitness/simpleparser

#include <iostream>
#include "Lexer.h"
#include "Lexer.cpp"
#include <vector>
#include <string>
#include <fstream>

using namespace std;
void iniciarHtml(ofstream &archivo);
void cerrarHtml(ofstream &archivo);
void escribirToken(ofstream &archivo, string datos[2]);
void enter(ofstream &archivo);
void iniciarRenglon(ofstream &archivo);
void terminarRenglon(ofstream &archivo);

int main(int argc, char *argv[])
{
    if (!argc)
    {
        cout << "Hace falta el argumento" << endl;
        return 0;
    }
    Lexer Lexer1;
    vector<Token> tokens;

    ifstream ip(argv[1]);
    string mes;
    //--------------------------------------------------------------------
    ofstream archivo;
    string filename = argv[1];
    const size_t last_slash_idx = filename.find_last_of("\\/");
    if (std::string::npos != last_slash_idx)
    {
        filename.erase(0, last_slash_idx + 1);
    }
    const size_t period_idx = filename.rfind('.');
    if (std::string::npos != period_idx)
    {
        filename.erase(period_idx);
    }
    archivo.open("C:\\Users\\Carlos\\Desktop\\Hilos\\Resultados\\" + filename + ".html", ios::out);
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return 0;
    }
    string datos[2];
    iniciarHtml(archivo);
    //-----------------------------------------------------------------
    while (!ip.fail())
    {
        iniciarRenglon(archivo);
        getline(ip, mes, '\n');
        if (ip.fail())
        {
            break;
        }
        tokens = Lexer1.LexerAritmetico(mes);
        for (Token currToken : tokens)
        {
            currToken.lPrint(datos);
            escribirToken(archivo, datos);
        }
        terminarRenglon(archivo);
        enter(archivo);
    }
    cerrarHtml(archivo);
    archivo.close();
    return 0;
}

void iniciarHtml(ofstream &archivo)
{
    archivo << "<!DOCTYPE html>";
    archivo << "<html lang='en'>";
    archivo << "<head>";
    archivo << "<title>Document</title>";
    archivo << "<link rel='stylesheet' type='text/css' href='estilos.css'/>";
    archivo << "</head>";
    archivo << "<body>";
}
void cerrarHtml(ofstream &archivo)
{
    archivo << "</body>";
    archivo << "</html>";
}

void escribirToken(ofstream &archivo, string datos[2])
{
    archivo << "<pre class='" << datos[1] << "'>" << datos[0] << "</pre>" << endl;
}

void enter(ofstream &archivo)
{
    archivo << "<br>" << endl;
}

void iniciarRenglon(ofstream &archivo)
{
    archivo << "<div class='inline'>";
}
void terminarRenglon(ofstream &archivo)
{
    archivo << "</div>";
}