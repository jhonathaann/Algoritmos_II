#include <stdio.h>

void binario(int n);

int main(){
    int n;

    scanf("%d", &n);

    binario(n);

    return 0;
}

void binario(int n){

    if(n / 2 != 0){
        binario(n / 2);
    }

    printf("%d ", n % 2);
}