#include <stdio.h>
#define MAX 50

int maior_elemento(int lista[], int n);

int main(){
    int lista[MAX];
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n;i++){
        scanf("%d", &lista[i]);
    }

    printf("%d", maior_elemento(lista, n));

    return 0;
}

int maior_elemento(int lista[], int n){
    int maior;

    if(n == 1){
        return lista[0];
    }else{
       maior = maior_elemento(lista, n-1);

       if(maior > lista[n-1]){
        return maior;
       }else{
        return lista[n-1];
       }
    }

}