#include<iostream>
#include<stdlib.h>

#include "LexCreator.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

int main(){

    extern FILE *yyin, *yyout;

    yyin = fopen("archivo_entrada.txt", "r");
    yyout = fopen("text_file.txt", "w");

    yylex();
    
    return 0;
}