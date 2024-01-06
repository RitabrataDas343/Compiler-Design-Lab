%{
#include<stdio.h>
#include<string.h>
int num_count = 0, id_count = 0;
%}

digit [0-9]
letter [A-Za-z]
operator [=*+/^]
separator [(){}|,;]
whitespace [ ] 

id {letter}({letter}|{digit})*
u_int ^[-+]{digit}+
s_int [-+]{digit}+

EOF [$]

%%
{u_int} {num_count++;}
{id} {id_count++;}
{EOF} {return 0;}
. {}

"\n" {printf("\nUnsigned number count: %d\nIdentifier count: %d\n", num_count, id_count); 
      num_count = 0; id_count = 0;}

%%

int main() {
    printf("Enter the expression: ");
    yylex();
    return 0;
}
