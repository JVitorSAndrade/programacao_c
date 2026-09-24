#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int altura, largura, profundidade;

    printf("Digite altura, largura e profundidade: ");
    scanf("%d %d %d", &altura, &largura, &profundidade);

    // Aloca as dimensões da matriz 3D
    int ***m = malloc(altura * sizeof(int **));

    for (int i = 0; i < altura; i++) {
        m[i] = malloc(largura * sizeof(int *));

        for (int j = 0; j < largura; j++) {
            m[i][j] = malloc(profundidade * sizeof(int));
        }
    }

    // Inicializa todos os elementos com 0
    for (int i = 0; i < altura; i++)
        for (int j = 0; j < largura; j++)
            for (int k = 0; k < profundidade; k++)
                m[i][j][k] = 0;

    // Exemplo: modifica um elemento
    m[0][0][0] = 1;

    // Acesso: m[i][j][k]
    // i = altura, j = largura, k = profundidade

    // Imprime o primeiro plano da matriz
    printf("\nPrimeiro plano:\n");

    for (int j = 0; j < largura; j++) {
        for (int k = 0; k < profundidade; k++)
            printf("%d ", m[0][j][k]);

        printf("\n");
    }

    // Libera a memória
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++)
            free(m[i][j]);

        free(m[i]);
    }

    free(m);

    return 0;
}

/*
A matriz é acessada usando:

m[i][j][k]

i -> altura
j -> largura
k -> profundidade

Exemplo:

m[2][3][1] = 1;

significa colocar o valor 1 na posição:
altura = 2
largura = 3
profundidade = 1
*/