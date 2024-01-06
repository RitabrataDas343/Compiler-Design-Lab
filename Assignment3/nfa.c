#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIMIT 101

int main(){
    char str[MAX_LIMIT], arr[3];
    printf("Enter the string: ");
    fgets(str, MAX_LIMIT, stdin);
    int len = strlen(str) - 1;
    bool flag = true;

    if(len < 3) flag = false;

    if(flag){
        if(str[0] != 'a' || str[1] != 'b'){
            flag = false;
        }
        for(int i = 2; i < len; i++){
            if(str[i] != 'a'){
                flag = false;
            }
        }
    } 

    if(flag){
        printf("0-a-1-b-2-a-3-a+");
        printf("\nString Accepted.\n");
    } else {
        for(int i = 0; i < len; i++){
            if(i == len-1){
                printf("%d-%c", i, str[i]);
                break;
            }
            printf("%d-%c-", i, str[i]);
        }
        printf("\nString Rejected.\n");
    }
    return 0;
}

