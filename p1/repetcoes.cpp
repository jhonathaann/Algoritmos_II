#include <stdio.h>
#define MAX 50

int rep(int lista[], int n);

int main(){
    int lista[MAX], *p, n;

    scanf("%d", &n);

    for(p = lista; p < lista + n;p++){
        scanf("%d", p);
    }

    printf("%d", rep(lista, n));

    return 0;
}

int rep(int lista[], int n){

    if(n == 2){
        if(lista[n-2] == lista[n-1]){
            return 1;
        }else{
            return 0;
        }
    }else{
        if(lista[n-2] == lista[n-1]){
            return 1 + rep(lista, n-1);
        }else{
            return rep(lista, n-1);
        }
    }
}