#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, delta, x1, x2;

    scanf("%lf %lf %lf", &a, &b, &c);
    
    delta = b*b - 4 * a * c;
    if(delta < 0){
        printf("A equação não possui raízes reais");
    }else{
        x1 = (-b + sqrt(delta))/ 2*a;
        x2 = (-b - sqrt(delta))/ 2*a;
        printf("%.2f, %.2f", x2, x1);
    }

    return 0;
}
