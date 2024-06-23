#include <stdio.h>

float soma(int n);

int main(){
    int n;

    scanf("%d", &n);

    printf("%.2f", soma(n));

    return 0;
}

float soma(int n){

    if(n == 1){
        return 1;
    }else{
        return 1.0 / n + soma(n-1);
    }
}
