#include <stdio.h>

void imprime(int n);

int main(){
     int n;

    scanf("%d", &n);

    imprime(n);

    return 0;
}

void imprime(int n){

    if(n != 1){
        imprime(n-1);
    }

    printf("%d ", n);
}