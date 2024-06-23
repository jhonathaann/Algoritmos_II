#include <stdio.h>

int vezes(int lista[], int n, int k);

int main(){
    int lista[50], *p, n, k;

    scanf("%d", &n);

    for(p = lista; p < lista + n; p++){
        scanf("%d", p);
    }

    scanf("%d", &k);

    printf("%d", vezes(lista, n, k));

    return 0;
}

int vezes(int lista[], int n , int k){

    if(n == 1){
        if(lista[0] == k){
            return 1;
        }else{
            return 0;;
        }
    }else{
        if(lista[n-1] == k){
            return 1 + vezes(lista, n-1, k);
        }else{
            vezes(lista, n-1, k);
        }
    }
}