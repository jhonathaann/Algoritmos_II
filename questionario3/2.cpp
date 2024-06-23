#include <stdio.h>

double calcSalario(double valorhora, int numHoras);

int main(){
    int numeroFunc, horasTrab;
    double valorHora, aux;

    scanf("%d", &numeroFunc);
    scanf("%lf", &valorHora);
    scanf("%d", &horasTrab);

    aux = calcSalario(valorHora, horasTrab);

    printf("%d %d %.2lf %.2lf", numeroFunc, horasTrab, valorHora, aux);

    return 0;
}

double calcSalario(double valorhora, int numHoras){
    
    if(numHoras <= 40){
        return valorhora * numHoras;
    }else{
        return valorhora * 40 + (1.5 * (numHoras - 40) * valorhora);
        
    }
}