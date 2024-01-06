#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char L[2] = {'a', 'b'};
char regex[100];
int curr;

void generate(int len) {
    if (len == 0) {
        printf("%s\n", regex);
        return;
    }

    int i;
    for (i = 0; i < 2; i++) {
        regex[curr] = L[i];
        curr++;
        generate(len - 1);
        curr--;
    }
}

int main() {
    printf("Enter the regular expression: ");
    scanf("%s", regex);

    int len = strlen(regex);
    curr = 0;
    generate(len);

    return 0;
}

