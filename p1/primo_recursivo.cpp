#include <stdio.h>
#define MAX 50

int tem_primo(int lista[], int n);

int aux(int numero);

int main(){
    int lista[50],  n, aux;

    scanf("%d", &n);

    for(int i = 0; i < n;i++){
        scanf("%d", &lista[i]);
    }

    aux = tem_primo(lista, n);
    printf("%d\n", aux);
}

int aux(int numero){

    for(int i = 2; i < numero/2 + 1;i++){

        if(numero % i == 0){
            // nao eh primo
            return 0;
        }
    }

    // eh primo
    return 1;
}

int tem_primo(int lista[], int n){

    if(n == 1){
        return aux(lista[n-1]);
    }else{
        if(aux(lista[n-1]) == 1){
            return true;
        }else{
            return tem_primo(lista, n-1);
        }
    }
}

