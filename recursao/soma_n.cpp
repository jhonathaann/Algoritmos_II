/*Crie um programa para ler um número inteiro N (N >= 1), calcular e imprimir a
soma 1+2+3+4+...+N. Faça uma função recursiva para realizar tal soma,
tendo a função o seguinte protótipo: int soma (int N)*/

#include <stdio.h>

int soma(int N);

int main(){
    int n;

    scanf("%d", &n);

    printf("%d\n", soma(n));

    return 0;
}

int soma(int N){

    if(N == 1){
        return N;
    }else{
        return N + soma(N-1);
    }
}