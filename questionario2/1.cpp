#include <stdio.h>
#define MAX 100

int main(){
    int n, vetor[MAX], flag = 1;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    // n-1 para nao dar erro de acesso indevido do vetor
    for(int i = 0; i < n - 1; i++){
        if(vetor[i] >= vetor[i+1]){
            flag = 0;
            break;
        }
    }

    if(flag == 1){
        printf("verdadeiro");
    }else{
        printf("falso");
    }

    return 0;
}