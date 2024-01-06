%{
#include <stdio.h>
char keyword[100],operator[100],identifier[100],number[100],symbol[100], lexeme_pattern[100];
%}

%%
int|char|if|else|while    {strcat(keyword,yytext);strcat(keyword,","); strcat(lexeme_pattern,yytext);}
[+\-*/%=<>!==]            {strcat(operator,yytext); strcat(operator,",");}
[a-zA-Z_][a-zA-Z0-9_]*    {strcat(identifier,yytext); strcat(identifier,",");}
[0-9]+                    {strcat(number,yytext); strcat(number,",");}
[(){};,]                  {strcat(symbol,yytext); strcat(symbol,","); strcat(lexeme_pattern,yytext);}
"\n"                      {return 0;}
%%

int main() {
    printf("Enter the code: \n");
    yylex();
    printf("\nKeywords:\n%s", keyword);
    printf("\nOperators:\n%s", operator);
    printf("\nIdentifiers:\n%s", identifier);
    printf("\nNumbers:\n%s", number);
    printf("\nSymbols:\n%s", symbol);
    printf("\nLexeme Pattern:\n%s\n", lexeme_pattern);
    return 0;
}