#include <stdio.h>

float serie(int k);

int main(){
    int n, k;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        printf("%.2f \n", serie(k));
    }
  

    return 0;
}

float serie(int k){

    if(k == 1){
        return 1.0;
    }else{
        double numerador = 1  + (k * k);
        double denominador = k;

        return numerador / denominador + serie(k-1);
        
    }
}