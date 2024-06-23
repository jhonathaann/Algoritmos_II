#include <stdio.h>

void inverter(int n, int *m, int v[], int v_inv[]);

int main(){
    int n, lista1[10], lista2[10], m = 0;
    int *p;

    scanf("%d", &n);

    for(p = lista1; p < lista1 + n;p++){
        scanf("%d", p);
    }

    inverter(n, &m, lista1, lista2);

    for(p = lista2; p < lista2 + n;p++){
        printf("%d ", *p);
    }
}

void inverter(int n, int *m, int v[], int v_inv[]){

    if(n != 0){
        v_inv[*m] =  v[n -1];
        (*m)++;

        inverter(n-1, m, v, v_inv);
    }
}