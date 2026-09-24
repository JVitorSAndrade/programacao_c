#include <stdio.h>
#include <stdlib.h>

int compararCrescente(int a, int b) {  // > função de comparação em ordem crescente; recebe dois inteiros e retorna um valor positivo, negativo ou zero
    return a - b; 
}

void meuSort(int *arr, int n, int (*compar)(int, int)) {
    int i, j, aux;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            /* aqui *compar é usado para decidir se os elementos devem trocar de posição. O ponteiro executa dinamicamente a função que passamos como
            parâmetro lá no main */

            if (compar(arr[j], arr[j + 1]) > 0) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

int main(void) {
    int n; 

    printf("Quantos elementos inteiros voce quer armazenar? ");
    scanf("%d", &n); // Lê o número de elementos inteiros

    int *r = malloc(n * sizeof(int)); // Aloca dinamicamente o espaço para o array de inteiros
    if (r == NULL) {  // Verifica se a alocação de memória foi bem-sucedida
        printf("Erro na alocacao de memoria!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &r[i]); // Lê cada elemento inteiro digitado
    }

    /* Chamamos nossa função de ordenação personalizada, passando:
       1. O ponteiro para o vetor (r)
       2. O número de elementos (n)
       3. O endereço/nome da função de comparação (compara_crescente) */
    meuSort(r, n, compararCrescente); 
    
    printf("\nArray ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("[ %d ] ", r[i]);
    }

    printf("\n");
    free(r); // Libera a memória alocada dinamicamente

    return 0;
}