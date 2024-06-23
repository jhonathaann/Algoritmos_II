/*Informalmente, o logaritmo de um número em uma dada base é a quantidade
de vezes que devemos dividir esse número pela base até que o quociente da divisão seja 1.*/

#include <stdio.h>

int log2(int n);

int main(){
    int n;

    scanf("%d", &n);

    printf("%d", log2(n));

    return 0;
}

int log2(int n){

    if(n == 1){
        return 0;
    }else{
        return 1 + log2(n/2);
    }
}