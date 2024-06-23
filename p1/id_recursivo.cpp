#include <stdio.h>
#define MAX 50

int busca_id(int lista[], int n);

int main(){
    int lista[100], *p, n;

    scanf("%d", &n);

    for(p = lista; p < lista + n; p++){
        scanf("%d", p);
    }

    printf("%d", busca_id(lista, n));

    return 0;
}

int busca_id(int lista[], int n){
    
    if(n == 1){
        if(lista[n-1] % 100 == 24){
            return 1;
        }else{
            return 0;
        }
    }else{

        if(lista[n-1] % 100 == 24){
            return 1 + busca_id(lista, n-1);
        }else{
            return busca_id(lista, n-1);
        }
    }
}