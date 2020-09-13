#include <cstdio>

int main(void){

    char ucpc[5] = "UCPC";
    int i = 0;
    char c;
    while( i < 4 && scanf("%c",&c) != EOF){
        if(ucpc[i] == c){
            i++;
        }
    }
    if(i == 4){
        printf("I love UCPC\n");
    } else {
        printf("I hate UCPC\n");
    }

    return 0;
}