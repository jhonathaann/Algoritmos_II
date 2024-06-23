#include <stdio.h>
#include <math.h>

int main(){
    double l1, l2, l3, s, area;

    scanf("%lf %lf %lf", &l1, &l2, &l3);

    s = (l1 + l2 + l3) /2;
    area = sqrt(s*(s-l1) * (s - l2) * (s - l3));

   printf("Lados = %5.2f, %5.2f, %5.2f\n", l1, l2, l3);
   printf("Perímetro = %5.2f\n", l1+l2+l3);
   printf("Área = %5.2f\n", area);

   return 0;
}