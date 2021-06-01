#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include <string>

using namespace std;

enum TypeL
{
    Whitespace,
    Entero,
    Flotante,
    Flotante_exponencial_posible,
    Flotante_exponencial_negativo_posible,
    Flotante_exponencial_negativo,
    Flotante_exponencial_positivo,
    Asignacion,
    Suma,
    Resta,
    Multiplicacion,
    Division,
    Potencia,
    Variable,
    Parentesis_que_abre,
    Parentesis_que_cierra,
    Comentario,
    Simbolo,
    Logico_posible,
    Logico,
    Error_token,
    Reservada,
    Espacio
};

static const char *TypeLArray[] = {
    "Whitespace",
    "Entero",
    "Flotante",
    "Flotante_exponencial_posible",
    "Flotante_exponencial_negativo_posible",
    "Flotante_exponencial_negativo",
    "Flotante_exponencial_positivo",
    "Asignacion",
    "Suma",
    "Resta",
    "Multiplicacion",
    "Division",
    "Potencia",
    "Variable",
    "Parentesis_que_abre",
    "Parentesis_que_cierra",
    "Comentario",
    "Simbolo",
    "Logico_posible",
    "Logico",
    "Error_token",
    "Reservada",
    "Espacio"
    };

class Token
{
public:
    enum TypeL sType
    {
        Whitespace
    };
    string sText;
    void lPrint(string arr[2]);
};

class Lexer
{
private:
    void addToken(Token &token, vector<Token> &tokens);

public:
    vector<Token> LexerAritmetico(string text);
};

#endif