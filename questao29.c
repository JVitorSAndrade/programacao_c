#include <stdio.h>

int main(void) {

    unsigned char m[8][8] = {  // Matriz 8x8 com valores binários
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {1,0,1,0,1,0,1,0},
        {1,0,1,0,1,0,1,0}
    };

    unsigned long long estado = 0;

    // Percorre os 64 bits da matriz
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            // Desloca para a esquerda e adiciona o bit atual
            estado = (estado << 1) | m[i][j];
        }
    }

    printf("Estado codificado: %llu\n", estado);  // Imprime o valor codificado da matriz como um número inteiro de 64 bits

    return 0;
}

/*
A matriz possui 8 x 8 = 64 bits.

A cada posição:
    estado << 1 -> abre espaço para um novo bit
    | m[i][j]   -> coloca o bit da matriz

Assim, os primeiros bits da matriz ficam nos bits
mais significativos e os últimos ficam nos menos
significativos.
*/