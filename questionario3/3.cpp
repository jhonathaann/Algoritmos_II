    #include <stdio.h>
    #define MAX 100

    int crescente(int v[MAX], int tam);

    int main(){
        int vetor[MAX], n, flag;

        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &vetor[i]);
        }

        flag = crescente(vetor, n);
        if(flag == 0){
            printf("falso\n");
        }else{
            printf("verdadeiro\n");
        }
    }

    int crescente(int v[MAX], int tam){
        

        for(int i = 0; i < tam - 1; i++){
            if(v[i] >= v[i+1]){
                return 0;
            }
        }

        return 1;
    }