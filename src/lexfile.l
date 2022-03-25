%{
%}
%%
\/\/.* {fprintf(yyout,"0 ");fprintf(yyout,yytext);fprintf(yyout,"\n");}
\#.* {fprintf(yyout,"1 ");fprintf(yyout,yytext);fprintf(yyout,"\n");}
"true"|"false"|"True"|"False" {fprintf(yyout,"2 ");fprintf(yyout,yytext);fprintf(yyout,"\n");}
"int"|"long"|"unsigned"|"auto"|"float" {fprintf(yyout,"3 ");fprintf(yyout,yytext);fprintf(yyout,"\n");}
"nullptr"|"None" {fprintf(yyout,"4 ");fprintf(yyout,yytext);fprintf(yyout,"\n");}
"break"|"if"|"throw"|"else"|"try"|"void"|"for"|"while"|"print" {fprintf(yyout,"5 ");fprintf(yyout,yytext);fprintf(yyout,"\n");}
\+|\-|\*|\/|\^ {fprintf(yyout,"6 ");fprintf(yyout,yytext);fprintf(yyout,"\n");}
\'|\"|\(|\)|\[|\]|\{|\}|\,|\:|\.|\; {fprintf(yyout,"7 ");fprintf(yyout,yytext);fprintf(yyout,"\n");}
\= {fprintf(yyout,"8 ");fprintf(yyout,yytext);fprintf(yyout,"\n");}
[0-9]* {fprintf(yyout,"9 ");fprintf(yyout,yytext);fprintf(yyout,"\n");}
[-+]?([0-9]+|[0-9]*\.[0-9]+([eE][-+]?[0-9]+)?) {fprintf(yyout,"10 ");fprintf(yyout,yytext);fprintf(yyout,"\n");}
. {fprintf(yyout,"11 ");fprintf(yyout,yytext);fprintf(yyout,"\n");}
%%
int yywrap(void){
	return 1;
}