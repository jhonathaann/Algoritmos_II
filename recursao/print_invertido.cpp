/* Crie uma função recursiva que, dado um vetor de inteiros, inverta a posição
dos seus elementos. Crie um programa para testar sua função.
Entrada: A = <10,20,30,40,50>
Saída: A = <50,40,30,20,10>*/

#include <stdio.h>

void inverter(int n, int v[]);

int main(){
    int n, vetor[10];
    int *p;

    scanf("%d", &n);

    for(p = vetor; p < vetor + n;p++){
        scanf("%d", p);
    }

    inverter(n, vetor);

    return 0;
}

void inverter(int n, int v[]){

    if(n != 0){
        printf("%d ", v[n-1]);
        
        inverter(n-1,v);
    }
}