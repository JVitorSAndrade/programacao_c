#include <stdio.h>

char *a[] = {"AGOSTINHO", "MEDEIROS", "BRITO", "JUNIOR"};

char **b[] = {a + 3, a + 2, a + 1, a};

char ***c = b;

int main() {

    // c aponta para b[0].
    // ++c faz c apontar para b[1].
    // b[1] = a + 2, então **c = a[2] = "BRITO".
    printf("%s ", **++c);

    // ++c -> b[2] -> a + 1.
    // --*++c faz o ponteiro voltar para a.
    // a[0] = "AGOSTINHO".
    // +3 avança 3 caracteres: "STINHO".
    printf("%s ", *--*++c + 3);

    // c[-2] = b[0] = a + 3.
    // *c[-2] = a[3] = "JUNIOR".
    // +3 avança 3 caracteres: "IOR".
    printf("%s ", *c[-2] + 3);

    // c[-1] = b[1] = a + 2.
    // c[-1][-1] acessa a posição anterior de "BRITO",
    // o que gera comportamento indefinido em C.
    printf("%s ", c[-1][-1] + 1);

    return 0;
}

/*
SAÍDA OBSERVADA:

BRITO STINHO IOR EDEIROS

Atenção: a última parte não é garantida pelo C,
pois o programa acessa uma posição de memória
anterior ao início da string "BRITO".
*/