#include <stdio.h>
#define MAX 500

int main(){
    int n, vet[MAX], aux, flag = 1;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    aux = vet[0];
    for(int i = 1; i < n; i++){
        if(vet[i] >= aux){
            flag = 0;
            break;
        }
    }

    if(flag == 1){
        printf("true");
    }else{
        printf("false");
    }

    return 0;
}