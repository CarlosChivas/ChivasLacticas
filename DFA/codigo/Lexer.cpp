#include "Lexer.h"
#include <iostream>

using namespace std;

vector<Token> Lexer::LexerAritmetico(string text)
{
    vector<Token> tokens;
    Token cToken;

    for (char cChar : text)
    {
        if(cToken.sType == Comentario){
            cToken.sText.append(1, cChar);
            continue;
        }

        switch (cChar)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if (cToken.sType == Whitespace)
                {
                    cToken.sType = Entero;
                    cToken.sText.append(1, cChar);
                } else if (cToken.sType == Flotante_exponencial_posible) {
                    cToken.sType = Flotante_exponencial_positivo;
                    cToken.sText.append(1, cChar);
                } else if (cToken.sType == Flotante_exponencial_negativo_posible){
                    cToken.sType = Flotante_exponencial_negativo;
                    cToken.sText.append(1, cChar);
                }
                else {
                    cToken.sText.append(1, cChar);
                }
            break;

            case '.':

                if (cToken.sType == Flotante_exponencial_posible || cToken.sType == Flotante_exponencial_negativo_posible) {
                    cToken.sType = Error_token;
                    addToken(cToken, tokens);
                }

                if(cToken.sType == Entero){
                    cToken.sType = Flotante;
                    cToken.sText.append(1, cChar);

                }
                else{
                    cToken.sType = Error_token;
                    cToken.sText.append(1, cChar);
                    addToken(cToken, tokens);
                }

                break;
            case '(':
                if(cToken.sType == Flotante_exponencial_posible || cToken.sType == Flotante_exponencial_negativo_posible){
                    cToken.sType = Error_token;
                    addToken(cToken, tokens);
                }
                addToken(cToken, tokens);
                cToken.sType = Parentesis_que_abre;
                cToken.sText.append(1, cChar);
                addToken(cToken, tokens);
                break;

            case ')':
                if(cToken.sType == Flotante_exponencial_posible || cToken.sType == Flotante_exponencial_negativo_posible){
                    cToken.sType = Error_token;
                    addToken(cToken, tokens);
                }
                addToken(cToken, tokens);
                cToken.sType = Parentesis_que_cierra;
                cToken.sText.append(1, cChar);
                addToken(cToken, tokens);
                break;

            case '=':
                if(cToken.sType == Flotante_exponencial_posible || cToken.sType == Flotante_exponencial_negativo_posible){
                    cToken.sType = Error_token;
                    addToken(cToken, tokens);
                }
                addToken(cToken, tokens);
                cToken.sType = Asignacion;
                cToken.sText.append(1, cChar);
                addToken(cToken, tokens);
                break;

            case '+':
                if(cToken.sType == Flotante_exponencial_posible || cToken.sType == Flotante_exponencial_negativo_posible){
                    cToken.sType = Error_token;
                    addToken(cToken, tokens);
                }
                addToken(cToken, tokens);
                cToken.sType = Suma;
                cToken.sText.append(1, cChar);
                addToken(cToken, tokens);
                break;

            case '-':
                if(cToken.sType == Flotante_exponencial_posible) {
                    cToken.sType = Flotante_exponencial_negativo_posible;
                    cToken.sText.append(1, cChar);
                } else if (cToken.sType == Flotante_exponencial_negativo_posible) {
                     cToken.sType = Error_token;
                     addToken(cToken, tokens);
                }
                if (cToken.sType == Whitespace) {
                    addToken(cToken, tokens);
                    cToken.sType = Resta;
                    cToken.sText.append(1, cChar);
                    addToken(cToken, tokens);
                }
                break;

            case '^':
                if(cToken.sType == Flotante_exponencial_posible || cToken.sType == Flotante_exponencial_negativo_posible){
                    cToken.sType = Error_token;
                    addToken(cToken, tokens);
                }
                addToken(cToken, tokens);
                cToken.sType = Potencia;
                cToken.sText.append(1, cChar);
                addToken(cToken, tokens);
                break;

            case '*':
                if(cToken.sType == Flotante_exponencial_posible || cToken.sType == Flotante_exponencial_negativo_posible){
                    cToken.sType = Error_token;
                    addToken(cToken, tokens);
                }
                addToken(cToken, tokens);
                cToken.sType = Multiplicacion;
                cToken.sText.append(1, cChar);
                addToken(cToken, tokens);
                break;

            case '/':
                if(cToken.sType == Flotante_exponencial_posible || cToken.sType == Flotante_exponencial_negativo_posible){
                    cToken.sType = Error_token;
                    addToken(cToken, tokens);
                }
                if(cToken.sType != Division){
                    addToken(cToken, tokens);
                    cToken.sType = Division;
                    cToken.sText.append(1, cChar);
                }
                else if(cToken.sType == Division){
                    cToken.sType = Comentario;
                    cToken.sText.append(1, cChar);
                }
                break;

            case ' ':
            case '\t':
                if(cToken.sType == Flotante_exponencial_posible || cToken.sType == Flotante_exponencial_negativo_posible){
                    cToken.sType = Error_token;
                    addToken(cToken, tokens);
                }
                addToken(cToken, tokens);
                break;

            case 'e':
            case 'E':
                if(cToken.sType == Flotante_exponencial_posible || cToken.sType == Flotante_exponencial_negativo_posible){
                    cToken.sType = Error_token;
                    addToken(cToken, tokens);
                }
                if(cToken.sType == Flotante){
                    cToken.sType = Flotante_exponencial_posible;
                    cToken.sText.append(1, cChar);
                    break;
                }

            default:
                if(cToken.sType == Flotante_exponencial_posible || cToken.sType == Flotante_exponencial_negativo_posible){
                    cToken.sType = Error_token;
                    addToken(cToken, tokens);
                }
                if (!isdigit(cChar) &&  !isalpha(cChar) && cChar != '_') {
                    addToken(cToken, tokens);
                    cToken.sType = Error_token;
                    cToken.sText.append(1, cChar);
                    addToken(cToken, tokens);
                } else {
                    if(cToken.sType != Variable){
                    addToken(cToken, tokens);
                    cToken.sType = Variable;
                    cToken.sText.append(1, cChar);
                    }
                    else{
                        cToken.sText.append(1, cChar);
                    }

                }
                break;
        }
    }
    addToken(cToken, tokens);
    return tokens;
}

void Lexer::addToken(Token &token, vector<Token> &tokens) {
    if (token.sType == Flotante_exponencial_posible || token.sType == Flotante_exponencial_negativo_posible) {
        token.sType = Error_token;
        tokens.push_back(token);
    } else if (token.sType != Whitespace) {
        tokens.push_back(token);
    }

    token.sType = Whitespace;
    token.sText.erase();
}

void Token::lPrint()
{
    cout << sText << "          " << TypeLArray[sType]<< endl;
}
