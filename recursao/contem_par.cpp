/* Crie um programa para ler um vetor A com n elementos (n <= 10) e imprimir
True se o vetor contém pelo menos um número par e False, caso contrário.
Para isso, o seu programa deve conter uma função recursiva contem_par
que recebe como argumento um vetor de n números inteiros, retorna True se
o vetor contém um número par e False, em caso contrário.
bool contem_par (int n, int V[])*/

#include <stdio.h>

bool contem_par(int n, int v[]);

int main(){
    int n, vetor[10];
    int *p;

    scanf("%d", &n);

    for(p = vetor; p < vetor + n; p++){
        scanf("%d", p);
    }

    printf("%d", contem_par(n, vetor));

    return 0;
}

bool contem_par(int n, int v[]){

    if(n == 1){
        if(v[n-1] % 2 == 0){
            return true;
        }else{
            return false;
        }
    }else{
       if(v[n-1] % 2 == 0){
        return true;
       }else{
        return contem_par(n-1, v);
       }
    }
}