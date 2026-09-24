#include <stdio.h>
#include <stdlib.h>

void somarVetores(int *v1, int *v2, int *res, int n) {  /* função que recebe dois vetores de inteiros (v1 e v2), um vetor de resultado (res) e o tamanho dos vetores (n)
    como parâmetros */
    for (int i = 0; i < n; i++) {
        res[i] = v1[i] + v2[i];  // realiza a soma dos elementos correspondentes dos dois vetores e armazena o resultado no vetor res
    }
}

int main(void) {
    int n;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);  // lê o tamanho dos vetores que o usuário deseja criar

    // aloca dinamicamente a memória para os três vetores (vet1, vet2 e resultado) com base no tamanho fornecido pelo usuário
    int *vet1 = malloc(n * sizeof(int));
    int *vet2 = malloc(n * sizeof(int));
    int *resultado = malloc(n * sizeof(int));

    // verifica se a alocação de memória foi bem sucedida para todos os vetores
    if (vet1 == NULL || vet2 == NULL || resultado == NULL) {
        printf("Erro na alocacao de memoria!\n");
        return 1;
    }

    // leitura dos valores do primeiro vetor
    printf("\n--- Elementos do Primeiro Vetor ---\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vet1[i]);
    }

    // leitura dos valores do segundo vetor
    printf("\n--- Elementos do Segundo Vetor ---\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vet2[i]);
    }

    // chama a função somarVetores para realizar a soma dos dois vetores e armazenar o resultado no vetor resultado
    somarVetores(vet1, vet2, resultado, n);

    // exibe o vetor resultante da soma dos dois vetores
    printf("\nVetor Resultante da Soma:\n");
    for (int i = 0; i < n; i++) {
        printf("[ %d ] ", resultado[i]);
    }
    printf("\n");

    free(vet1);
    free(vet2);
    free(resultado);

    return 0;
}