#include <stdio.h>

void inverter(int n, int *m, int metade, int v[]);

int main(){
    int n, lista[10], m = 0;
    int *p;

    scanf("%d", &n);
    for(p = lista; p < lista + n;p++){
        scanf("%d", p);
    }

    inverter(n, &m,  n/2, lista);

    for(p = lista; p < lista + n;p++){
        printf("%d ", *p);
    }

}

void inverter(int n, int *m, int metade, int v[]){

    if(n != metade){
        if (n != 0)
        {
            int aux = v[*m];
            v[*m] = v[n - 1];
            v[n - 1] = aux;

            (*m)++;

            inverter(n - 1, m, metade, v);
        }
    }
    
}