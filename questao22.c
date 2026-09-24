#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // biblioteca que contém a função qsort() e malloc(), além de clock() para medir o tempo de execução

int compararQsort(const void *a, const void *b) {  // função de comparação para qsort; recebe dois ponteiros genéricos e retorna um valor positivo, negativo ou zero
    return (*(int *)a - *(int *)b);
}

int compararCrescente(int a, int b) {  // função de comparação em ordem crescente; recebe dois inteiros e retorna um valor positivo, negativo ou zero
    return a - b; 
}

void meuSort(int *arr, int n, int (*compar)(int, int)) {  /* função de ordenação personalizada (Bubble Sort); recebe um array de inteiros, o número de elementos e um 
                                                            ponteiro para a função de comparação */
    int i, j, aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (compar(arr[j], arr[j + 1]) > 0) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

int main(void) {
    int n = 20000;  // definimos um tamanho grande para testar a eficiência dos métodos de ordenação

    int *arr1 = malloc(n * sizeof(int));  // aloca dinamicamente o espaço para o primeiro array de inteiros
    int *arr2 = malloc(n * sizeof(int));

    if (arr1 == NULL || arr2 == NULL) {  // verifica se a alocação de memória foi bem-sucedida
        printf("Erro na alocacao de memoria!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {  // inicializa os arrays com valores decrescentes para testar a ordenação
        arr1[i] = n - i;
        arr2[i] = n - i;
    }

    clock_t inicio, fim;  // variáveis para armazenar os tempos de início e fim da execução das funções de ordenação
    double tempoMeuSort, tempoQsort;

    // 1. medindo o tempo de execução da função de ordenação personalizada (Bubble Sort)
    inicio = clock();  // marca o tempo inicial
    meuSort(arr1, n, compararCrescente);
    fim = clock();  // marca o tempo final
    // calcula o tempo de execução em segundos
    tempoMeuSort = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // 2. medindo o tempo de execução da função nativa qsort()
    inicio = clock();  // marca o tempo inicial
    qsort(arr2, n, sizeof(int), compararQsort);
    fim = clock();  // marca o tempo final
    // calcula o tempo de execução em segundos
    tempoQsort = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // exibindo os tempos de execução das duas funções de ordenação
    printf("Tempo com nosso metodo personalizado (Bubble Sort): %.6f segundos\n", tempoMeuSort);  // exibe o tempo de execução da função de ordenação personalizada
    printf("Tempo com a funcao nativa qsort(): %.6f segundos\n", tempoQsort);  // exibe o tempo de execução da função nativa qsort()

    free(arr1);
    free(arr2);

    return 0;
}

// > O que se conclui disso? a função nativa qsort é bem mais rápida e eficiente do que o método manual implementado Bubble Sort, especialmente para volumes maiores de dados