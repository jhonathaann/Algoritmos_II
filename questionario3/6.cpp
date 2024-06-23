#include <stdio.h>

bool testetri(double a, double b, double c);

int main(){
    double a, b, c;
    bool flag;

    scanf("%lf %lf %lf", &a, &b, &c);
    
    flag = testetri(a, b, c);
    if(flag == 0){
        printf("%.1lf %.1lf %.1lf não formam um triângulo retângulo\n", a, b, c);
    }else{
        printf("%.1lf %.1lf %.1lf formam um triângulo retângulo\n", a, b, c);
    }

    return 0;
}

bool testetri(double a, double b, double c){

    if(c*c == a*a + b*b){
        return 1;
    }else{
        return 0;
    }

}