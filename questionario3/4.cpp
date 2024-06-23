#include <stdio.h>
#include <math.h>

int maxfator(int numero);

int main(){
    int num;

    scanf("%d", &num);

    printf("%d %d",num, maxfator(num));

    return 0;
}

int maxfator(int numero){
    int aux;

    numero = abs(numero);
    for(int i = 1; i <= numero / 2; i++){
        if(numero % i == 0){
            aux = i;
        }
    }
    
    return aux;

}