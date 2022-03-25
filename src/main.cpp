#include<iostream>
#include<stdlib.h>

#include "LexCreator.h"
#include "HTMLcreator.h"

int main(){

    LexCreator lex("re_file.txt");
    lex.readRegularExpressions();
    lex.createLexFile();

    system("flex lexfile.l");
    system("g++ regular_expressions.cpp lex.yy.c -o regular_expression");
    
    system("regular_expression.exe");

    std::vector<std::string> re_vector = lex.getRe_vector();
    std::vector<std::string> token_vector = lex.getToken_vector();

    HTMLcreator html(re_vector,token_vector);
    html.createHTML();

    return 0;
}