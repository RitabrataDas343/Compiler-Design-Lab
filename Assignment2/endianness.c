#include <stdio.h>

int main() {
    int num = 1;
    char *c = (char*) &num;
    if (*c) {
        printf("Little endian\n");
    } else {
        printf("Big endian\n");
    }
    return 0;
}
