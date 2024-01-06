#include <stdio.h>
#include <stdlib.h>

char L[2] = {'a', 'b'};
char regex1[3][2];
char regex2[2][3];  

int main() {
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            regex1[i * 2 + j][0] = L[i];
            regex1[i * 2 + j][1] = L[j];
        }
    }

    printf("(a|b)(a|b): {");
    for (i = 0; i < 4; i++) {
        if(i == 3) printf("%c%c}", regex1[i][0], regex1[i][1]);
        else printf("%c%c, ", regex1[i][0], regex1[i][1]);
    }
    printf("\n\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            regex2[i][0] = 'a';
            regex2[i][1] = L[j];
            regex2[i][2] = 'b';
        }
    }

    printf("a(a|b)b: {");
    for (i = 0; i < 2; i++) {
        if(i == 1) printf("%c%c%c}", regex2[i][0], regex2[i][1], regex2[i][2]);
        else printf("%c%c%c, ", regex2[i][0], regex2[i][1], regex2[i][2]);
    }
    printf("\n");

    return 0;
}
