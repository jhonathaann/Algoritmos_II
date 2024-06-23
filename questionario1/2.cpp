#include <stdio.h>

int main(){
    int numero, aux1, aux2;

    scanf("%d", &numero);

    aux1 = numero % 10;
    numero = numero / 10;
    aux2 = numero % 10;

    printf("%d", aux1 + aux2);

    return 0;
}