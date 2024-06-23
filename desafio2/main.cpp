// incluindo o arquivo de cabeçalho com as declarações das funções
#include "funcoes.cpp"

// função para gerar um vetor de números aleatórios
void vetor_random(int *lista, int n);

// função para copiar um vetor para o outro
void copia_vetor(int *lista_original, int *lista_final, int n);

// função que calcula o tempo de execução de um algoritmo
void tempo_execucao(const char *nome_algoritmo, clock_t tempo_inicio, clock_t tempo_final);

int main(){
    // definindo uma lista que irá guardar o tamanho de cada entrada
    int tamanhos[] = {200000};

    // calculando quando elemtos há no vetor "tamanho"
    // não pode usar simplesmente strlen, porque isso é para string
    int quant_vetores = sizeof(tamanhos)/ sizeof(tamanhos[0]);

    // inicializa o gerador de numeros aleatorios com o tempo atual
    // passar '0' como argumento faz com que a função escreva o tempo atual na variável passada 
    // (se houvesse uma) ou, nesse caso, apenas retorne o tempo atual.
    // isso garante que os numeros gerados serão diferentes a cada execução do programa
    srand(time(0));

    // percorrendo cada um dos vetores da lista "tamanho"
    for(int i = 0; i < quant_vetores; i++){
        // definindo o tamanho atual do vetor
        int n = tamanhos[i];

        // alocando o vetor original e o auxiliar dinamicamente
        int *vetor = (int *) calloc(n, sizeof(int));
        int *aux = (int *) calloc(n, sizeof(int));

        if(vetor == NULL || aux == NULL){
            printf("Nao foi possivel alocar o(s) vetor(es) na memoria!\n");
            return -1;
        }

        // preenchendo o vetor com números aleatórios
        vetor_random(vetor, n);

        // -------- INSERTION SORT -----------

        copia_vetor(vetor, aux, n);

        // marca o tempo inicial
        clock_t tempo_inicio = clock();

        // chamando a função para ordenar o vetor
        insertion_sort(aux, n);

        // marca o tempo final
        clock_t tempo_final = clock();

        // imprimindo o tempo de execucao
        tempo_execucao("Insertion Sort", tempo_inicio, tempo_final);

        // ----------- SELECTION SORT ---------------

        copia_vetor(vetor, aux, n);

        // marca o tempo de inicio
        tempo_inicio =  clock();

        // chamando a função para ordenar o vetor
        selection_sort(aux, n);

        // marca o tempo final
        tempo_final = clock();

        //imprimindo o tempo de execução
        tempo_execucao("Selection Sort", tempo_inicio, tempo_final);


        // ------------- MERGE SORT -------------
        copia_vetor(vetor, aux, n);

        // marca o tempo de inicio
        tempo_inicio =  clock();

        // chamando a função para ordenar o vetor
        merge_sort(aux, 0, n);

        // marca o tempo final
        tempo_final = clock();

        //imprimindo o tempo de execução
        tempo_execucao("Merge Sort", tempo_inicio, tempo_final);

        // ------------- QUICK SORT ----------------------

        copia_vetor(vetor, aux, n);

        // marca o tempo de inicio
        tempo_inicio =  clock();

        // chamando a função para ordenar o vetor
        quick_sort(0, n-1, aux);

        // marca o tempo final
        tempo_final = clock();

        //imprimindo o tempo de execução
        tempo_execucao("Quick Sort", tempo_inicio, tempo_final);

        // desalocando os dois vetores
        free(vetor);
        free(aux);

    }

    return 0;

}

void vetor_random(int *lista, int n){
    int *p;

    for(p = lista; p < lista + n; p++){
        *p = rand() % 10000;
    }
    
}

void copia_vetor(int *lista_original, int *lista_final, int n){

    for(int i = 0; i < n; i++){
        *(lista_final + i) = *(lista_original + i);
    }
}

void tempo_execucao(const char *nome_algoritmo, clock_t tempo_inicial, clock_t tempo_final){
    // calcula o tempi passado em segundos
    double tempo_decorrido = ((double)(tempo_final - tempo_inicial)) / CLOCKS_PER_SEC;

    printf("Tempo de execucao do %s: %f segundos\n", nome_algoritmo, tempo_decorrido);
}