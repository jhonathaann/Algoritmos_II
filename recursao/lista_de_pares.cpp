/*Crie uma função recursiva que recebe um vetor A com n elementos (n <= 20)
e devolve (por parâmetro) a lista (vetor) dos elementos pares de A. Crie a
função com os parâmetros necessários para executar a tarefa. Crie um
programa para testar sua função.*/

#include <stdio.h>

void pares(int n, int *m, int v[], int v_pares[]);

int main(){
    int n, lista[20], lista_pares[20], m = 0;
    int *p;

    scanf("%d", &n);

    for(p = lista; p < lista + n;p++){
        scanf("%d", p);
    }

    pares(n, &m, lista, lista_pares);
    //printf("%d\n", m);

    for(p = lista_pares; p < lista_pares + m;p++){
        printf("%d ", *p);
    }
    
}

void pares(int n, int *m, int v[], int v_pares[]){

   if(n == 1){
    if(v[n-1] % 2 == 0){
        v_pares[*m] = v[n-1];
        (*m)++;
    }
   }else{

    if(v[n-1] % 2 == 0){
        v_pares[*m] = v[n-1];
        (*m)++;
        pares(n-1, m, v, v_pares);
    }else{
        pares(n-1, m, v, v_pares);
    }

   }
    
}