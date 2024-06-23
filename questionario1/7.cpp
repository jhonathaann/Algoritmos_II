#include <stdio.h>

int main(){
    int num, aux, resto, count = 0;

    scanf("%d %d", &num, &aux);

    do{
        resto = num % 10;

        if(aux == resto){
            count++;
        }

        num = num / 10;

    }while(num > 0);

    printf("%d", count);

    return 0;

}