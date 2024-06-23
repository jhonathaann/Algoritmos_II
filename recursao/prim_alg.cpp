#include <stdio.h>

int prim_alg(int n);

int main(){
    int n;

    scanf("%d", &n);

    printf("%d", prim_alg(n));

    return 0;

}

int prim_alg(int n){

    if(n / 10 == 0){
        return n;
    }else{
        return prim_alg(n / 10);
    }
}