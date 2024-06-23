#include <stdio.h>

int piso_log2(int n);

int main(){
    int n;

    scanf("%d", &n);

    printf("%d", piso_log2(n));

    return 0;
}

int piso_log2(int n){
    int base = 1, aux = 0;
    
    while(base <= n){
        aux++;
        base = base * 2;
    }

    
    if(base > n){
        aux--;
    }

    return aux;
}