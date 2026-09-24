#include <stdio.h>
#include <stdlib.h>

// função para multiplicar duas matrizes A e B, armazenando o resultado em C
void multiplicarMatrizes(int *A, int *B, int *C, int linhasA, int colA_linB, int colB) {
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colB; j++) {
            C[i * colB + j] = 0;  // inicializa o elemento C[i][j] com zero antes de somar os produtos
            for (int k = 0; k < colA_linB; k++) {
                // realiza a multiplicação e acumula o resultado na posição C[i][j]
                C[i * colB + j] += A[i * colA_linB + k] * B[k * colB + j];
            }
        }
    }
}

int main(void) {
    // definindo as dimensões das matrizes A (2x3) e B (3x4)
    int linhasA = 2;
    int colA_linB = 3;
    int colB = 4;

    // alocando dinamicamente a memória para as matrizes A, B e C
    int *A = malloc(linhasA * colA_linB * sizeof(int));
    int *B = malloc(colA_linB * colB * sizeof(int));  // alocando espaço para a matriz B (3x4)
    int *C = malloc(linhasA * colB * sizeof(int));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Erro na alocação de memória!\n");  // verifica se a alocação de memória foi bem-sucedida
        return 1;
    }

    // Preenchendo a Matriz A (2x3) com valores de teste
    int valA[2][3] = {{1, 2, 3}, 
                      {4, 5, 6}};
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colA_linB; j++) {
            A[i * colA_linB + j] = valA[i][j];
        }
    }

    // Preenchendo a Matriz B (3x4) com valores de teste
    int valB[3][4] = {{10, 11, 12, 13}, 
                      {14, 15, 16, 17}, 
                      {18, 19, 20, 21}};
    for (int i = 0; i < colA_linB; i++) {
        for (int j = 0; j < colB; j++) {
            B[i * colB + j] = valB[i][j];
        }
    }

    // chamando a função para multiplicar as matrizes A e B, armazenando o resultado em C
    multiplicarMatrizes(A, B, C, linhasA, colA_linB, colB);

    // imprimindo a matriz A
    printf("Matriz A (%dx%d):\n", linhasA, colA_linB);
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colA_linB; j++) {
            printf("%4d ", A[i * colA_linB + j]);
        }
        printf("\n");
    }

    // imprimindo a matriz B
    printf("\nMatriz B (%dx%d):\n", colA_linB, colB);
    for (int i = 0; i < colA_linB; i++) {
        for (int j = 0; j < colB; j++) {
            printf("%4d ", B[i * colB + j]);
        }
        printf("\n");
    }

    // imprimindo a matriz C resultante (2x4)
    printf("\nMatriz C = A x B (%dx%d):\n", linhasA, colB);
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colB; j++) {
            printf("%5d ", C[i * colB + j]);
        }
        printf("\n");
    }

    free(A);
    free(B);
    free(C);

    return 0;
}