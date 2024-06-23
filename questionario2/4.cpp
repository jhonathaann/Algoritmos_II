#include <stdio.h>
#define MAX 100

int main(){
    int m, n, A[MAX][MAX], B[MAX][MAX], S[MAX][MAX];

    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &A[i][j]);
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &B[i][j]);
        }
    }

     for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            S[i][j] = A[i][j] + B[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", S[i][j]);
        }
        printf("\n");
    }

    return 0;
}