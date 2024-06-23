/* Crie uma função recursiva div que recebe como argumentos dois números
naturais m e n e devolve o resultado da divisão inteira de m por n. Neste
exercício você não pode recorrer às operações aritméticas de multiplicação,
divisão e resto da divisão inteira. Crie um programa para testar sua função.*/

#include <stdio.h>

int div(int m, int n);

int main(){
    int m, n;

    scanf("%d", &m);
    scanf("%d", &n);



    printf("%d\n", div(m,n));

    return 0;
}

int div(int m, int n){
    
    if(m < n)
        return 0;

    if(m == n)
        return 1;    

    return 1 + div(m - n, n);
    

}