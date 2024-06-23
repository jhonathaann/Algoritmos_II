#include <stdio.h>

int main() {
    char opc;
    float saldo, aux;

    
    scanf("%f %c %f", &saldo, &opc, &aux);
    if (opc == 'D') {
        printf("Saldo atual: R$%+10.2f\n", saldo + aux);
    } else if (opc == 'S') {
        printf("Saldo atual: R$%+10.2f\n", saldo - aux);
    } else {
        printf("Saldo atual: R$%+10.2f\n", saldo);
    }

    return 0;
}
