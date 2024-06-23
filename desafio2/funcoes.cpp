// arquivo que irá conter o corpo de cada uma das funções no arquivo de cabecalho
#include "cabecalho.h"

void insertion_sort(int *lista, int n){
    int aux, i, j; 

    // loop para percorrer a lista a partir do segundo elemento, ja que uma lista de tamanho 1 ja esta ordenada 
    for(i = 1; i < n; i++){ 
        // armazena o elemento atual em uma variável auxiliar
        aux = lista[i]; 
        
        // loop interno para mover os elementos maiores que o elemento atual para a direita
        for(j = i - 1; j >= 0 && lista[j] > aux;  j--){ 
            
            // move o elemento para a direita se nos ainda estivermos elementos a esquerda da nossa chave (aux)
            // E se o que esta na posição j for maior que a nossa chave (aux)
            lista[j+1] = lista[j];
        }

        // insere o elemento atual na posição correta
        lista[j+1] = aux; 
    }
}

void selection_sort(int *lista, int n){ 
    int min, aux; // Declaração de variáveis para armazenar o índice mínimo e uma variável auxiliar para troca de elementos

    // loop mais externo, que percorrerá ate a penultima posiçao da lista
    for(int i = 0; i < n-1; i++){

        // define que o indice onde se encontra o menor da minha lista é o meu indice atual

        min = i;
        // loop para encontrar qual é de fato o indice do menor elemento disponivel na lista

        for(int j = i+1; j < n; j++){ 

            // se o elemento atual for menor que o mínimo atual
            if(lista[j] < lista[min]){

                // atualiza o indice do mínimo
                min = j; 
            }
        }
        // guarda o elemento atual em uma variavel auxiliar
        aux = lista[i]; 
        // substitui o elemento atual pelo mínimo encontrado
        lista[i] = lista[min];
        // substitui o mínimo encontrado pelo elemento atual da lista
        lista[min] = aux;
    }
}

// função gerar a intercalação, ordenada, entre "dois" vetores
void intercala(int *lista, int inicio, int meio, int fim){
    int i, j, k, W[fim];

    i = inicio;
    j = meio;
    k = 0;

    // enquanto ainda houver elementos nas duas metades da lista
    while(i < meio && j < fim){

        // se o elemento na primeira metade for menor que o elemento na segunda metade
        if(*(lista + i) < *(lista + j)){

            // coloca o elemento na posição correta em W
            *(W + k) = *(lista + i);
            i++;
        }else{
             // coloca o elemento na posição correta em W
            *(W + k) = *(lista + j);
            j++;
        }
        k++;
    }

    // sobraram valores na primeira parte do vetor
    while(i < meio){

        // coloca os elementos restantes na posição correta em W
        *(W + k) = *(lista + i);
        i++;
        k++;
    }

    // sobraram valores na segunda parte do vetor
    while(j < fim){

        // coloca os elementos restantes na posição correta em W
        *(W + k) = *(lista + j);
        j++;
        k++;
    }

    // copia o auxiliar (W) para o vetor original
    for(i = inicio; i < fim; i++){
        *(lista + i) = *(W+i-inicio);
    }
}

void merge_sort(int *lista, int comeco, int fim){

    int particao;

    // verifica se a lista tem mais de um elemento
    if(comeco < fim -1){
        particao = (comeco + fim) / 2;

        // ordena a primeira metade da lista
        merge_sort(lista, comeco, particao);
        // ordena a segunda metade da lista
        merge_sort(lista, particao, fim);

        // combina a duas metades ordenadas
        intercala(lista, comeco, particao, fim);
    }   

}

// função para separar os elementos da lista em torno de um pivô
int separa(int comeco, int fim, int *lista) {
    int x, i, j;

    // define o pivô como o elemento no índice "comeco"
    x = *(lista + comeco);  // lista[comeco]

    // inicializa o índice 'i' antes do começo da lista
    i = comeco - 1;
    // inicializa o índice 'j' após o final da lista
    j = fim + 1;

    // loop infinito para iterar até que a separação seja concluída
    while (1) {
        
        // encontra um elemento maior ou igual ao pivô, a partir do final da lista
        do {
            j--;
        } while (*(lista + j) > x);  // lista[j]

        // encontra um elemento menor ou igual ao pivô, a partir do começo da lista
        do {
            i++;
        } while (*(lista + i) < x);  // lista[i]

        // se os índices 'i' e 'j' não se cruzarem
        if (i < j) {
            // troca os elementos nos índices 'i' e 'j'
            int aux = *(lista + i);
            *(lista + i) = *(lista + j);
            *(lista + j) = aux;
        } else {
            // retorna o índice 'j' que indica a posição do pivô
            return j;
        }
    }
}

void quick_sort(int comeco, int fim, int *lista) {
    int particao;

    // se o começo é menor que o fim (ainda há elementos para ordenar)
    if (comeco < fim) {
        // realiza a partição e obtém o índice do pivô
        particao = separa(comeco, fim, lista);

        // ordena recursivamente a parte esquerda do pivô
        quick_sort(comeco, particao, lista);
        // ordena recursivamente a parte direita do pivô
        quick_sort(particao + 1, fim, lista);
    }
}
