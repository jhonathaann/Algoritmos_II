#include <stdio.h>
#define MAX 500

int busca(int n, int lista[], int numero);

int main(){
    int tam1, tam2, lista1[MAX], lista2[MAX], lista3[MAX], flag, j = 0;

    // leitura dos dados
    scanf("%d", &tam1);

    for(int i = 0; i < tam1; i++){
        scanf("%d", &lista1[i]);
    }

    scanf("%d", &tam2);
    for(int i = 0; i < tam2; i++){
        scanf("%d", &lista2[i]);
    }

    //--------------------------------------------------------------------------

    for(int i = 0; i < tam1; i++){
        flag = busca(tam2, lista2, lista1[i]);

        if(flag == 1){
            lista3[j] = lista1[i];
            j++;
        }else if (flag > 1){
            for(int k = j; k < flag; k++){
                lista3[j] = lista1[i];
                j++;
            }
        }
    }

    if(j != 0){

        for(int i = 0; i < j; i++){
            printf("%d ", lista3[i]);
        }
    }else{
        printf("vazia");
    }
    
    return 0;

}

int busca(int n, int lista[], int numero){
    int vezes = 0;

    for(int i = 0; i < n; i++){
        if(numero == lista[i]){
            vezes++;
        }
    }

    return vezes;
}