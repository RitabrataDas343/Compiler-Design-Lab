%{
    #include<stdio.h>
    int count_unsigned = 0;
    int count_identifiers = 0;
%}

%%
[a-zA-z]([0-9a-zA-z_$])* {count_identifiers++;printf("Identifier = %s\n",yytext);}
[0-9]+ {count_unsigned++; printf("Unsigned number = %s\n",yytext);} 
[0-9]+[0-9a-zA-z_$]+ ;
[-][0-9]+ ;
[+][0-9]+ ;
. {return 0;}
%%

int main()
{
    yylex();
    printf("Number of unsigned numbers : %d \n",count_unsigned);
    printf("Number of identifiers : %d \n",count_identifiers);
}
