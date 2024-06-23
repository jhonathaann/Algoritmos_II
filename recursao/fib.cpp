#include <stdio.h>

int fib(int n);

void imprime(int n);

int main(){
    int n;

    scanf("%d", &n);

    imprime(n);

    return 0;
}

int fib(int n){

    if(n <= 1){
        return 1;
    }else{
        return fib(n-1) + fib(n-2);   
    }
   
}

void imprime(int n){
    if(n <= 0){
        return;
    }

    imprime(n-1);

    printf("%d ", fib(n-1));

}