/*intercala dois vetores de mesmo tamanho*/

#include <stdio.h>

void intercala(int lista1[], int lista2[], int lista3[], int n, int m);

int main(){
    int lista1[50], lista2[50], lista3[100], *p, n;

    scanf("%d", &n);
    
    for(p = lista1; p < lista1 + n;p++){
        scanf("%d", p);
    }

    for(p = lista2; p < lista2 + n;p++){
        scanf("%d", p);
    }

    intercala(lista1, lista2, lista3, n, n+n);

    n = n + n;
    for(p = lista3; p < lista3 + n;p++){
        printf("%d ", *p);
    }

    return 0;
}

void intercala(int lista1[], int lista2[], int lista3[], int n, int m){

    if(n == 1){
        lista3[m-1] = lista1[n-1];
    
        lista3[m] = lista2[n-1];
    }else{
        
        intercala(lista1, lista2, lista3, n-1, m+1);

        lista3[m] = lista1[n-1];
        lista3[m+1] = lista2[n-1];
    }
}

