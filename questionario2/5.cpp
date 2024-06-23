#include <stdio.h>
#define MAX 10

int main(){
    int m, n, M[MAX][MAX], vet[MAX], vet_resul[MAX], soma;

    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &M[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    for(int i = 0; i < m; i++){
        soma = 0;
        for(int j = 0; j < n; j++){
            soma += M[i][j] * vet[j];
        }
        vet_resul[i] = soma;
    }

    for(int i = 0; i < m; i++){
        printf("%d ", vet_resul[i]);
    }
    
    return 0;
}