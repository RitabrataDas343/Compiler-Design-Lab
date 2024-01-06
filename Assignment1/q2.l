%{
#include <stdio.h>
int flag = 0;
%}

%%

"\F="[0-9]+"\*"[0-9]+"\*"[0-9]+"\/"[0-9]+"\^"2 {flag = 1;}
. {flag = 0;}
"quit" {return 0;}

"\n" {if(flag){printf("String accepted\n");}else{printf("String rejected\n");};flag = 0;}

%%

int main(){
	yylex();
    return 0;
}
