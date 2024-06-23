#include <stdio.h>

float media(float lista[], int n);

int main(){
    float lista[5], *p;
    int n;

    scanf("%d", &n);

    for(p = lista; p < lista + n;p++){
        scanf("%f", p);
    }

    printf("%.2f", media(lista, n)/n);

    return 0;
}

//"media"
float media(float lista[], int n){

    if(n == 0){
        return 0.0;
    }else{
        
        return lista[n-1] + media(lista, n-1);

    }
}