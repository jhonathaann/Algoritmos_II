#include <stdio.h>
#include <string.h>
#define MAX 20

void mediaAr(float media, float notaAP, char mensagem[MAX]);

int main(){
    float media, nota;
    char aux[MAX];

    scanf("%f", &media);
    scanf("%f", &nota);

    if(nota >= media){
        strcpy(aux, "Aprovado");
        mediaAr(media, nota, aux);
    }else{
        strcpy(aux, "Reprovado");
        mediaAr(media, nota, aux);
    }

    return 0;
}

void mediaAr(float media, float notaAP, char mensagem[MAX]){
     
     printf("%.1f %s",notaAP, mensagem);
}