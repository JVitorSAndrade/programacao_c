#include <stdio.h>

#define TAM 10

// Busca linear
int funcao1(int vetor[], int v) {
    for (int i = 0; i < TAM; i++) {
        if (vetor[i] == v)
            return i;
    }

    return -1;
}

// Busca binária recursiva
int funcao2(int vetor[], int v, int i, int f) {
    int m = (i + f) / 2;

    if (v == vetor[m])
        return m;

    if (i >= f)
        return -1;

    if (v > vetor[m])
        return funcao2(vetor, v, m + 1, f);
    else
        return funcao2(vetor, v, i, m - 1);
}

int main(void) {

    int vetor[TAM] = {
        1, 3, 5, 7, 9,
        11, 13, 15, 17, 19
    };

    printf("%d - %d\n",
           funcao1(vetor, 15),
           funcao2(vetor, 15, 0, TAM - 1));

    return 0;
}

/*
RESOLUÇÃO:

O valor procurado é 15.

funcao1():
Busca linear → percorre os elementos um por um.
O 15 está no índice 7.
Resultado: 7.

funcao2():
Busca binária → divide o vetor pela metade.
Também encontra o 15 no índice 7.
Resultado: 7.

Saída:
7 - 7

I -> VERDADEIRA.

II -> FALSA.
A funcao1() é O(n), enquanto a funcao2() é O(log n).
Logo, a busca binária é mais eficiente no pior caso.

III -> FALSA.
A funcao2() chama a si mesma, portanto é recursiva,
e não iterativa.

Resposta: A) I, apenas.
*/