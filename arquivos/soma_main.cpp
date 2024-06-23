#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int soma = 0, numero;
    // primeiro posicao do argv (argv[0]) contem o nome do executavel. nesse caso, eh soma_main.exe
    for(int i = 1; i < argc;i++){
        numero = atoi(argv[i]);

        soma+= numero;
    }

    printf("soma = %d\n", soma);

    return 0;
}