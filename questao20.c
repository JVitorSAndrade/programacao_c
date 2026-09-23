#include <stdio.h>
#include <stdlib.h>  // biblioteca que contém a função qsort() e malloc()

int comparando (const void *a, const void *b) {  /* primeiro, por que const void *a? a função qsort é genérica, ela nao sabe o tipo de dados que você quer
    comparar... Quando você chama a funcao comparando no qsort() você nao passa os parametros, o qsort ainda vai saber o tipo de dados, o uso do
    void é justamente para isso, void * é um ponteiro genérico. */
    
    float x = *(const float *)a;  // o ponteiro a é do tipo void, então precisamos trata-lo como um ponteiro p/ float e depois desreferenciar para pegar o valor de *a
    float y = *(const float *)b;  // o ponteiro b é do tipo void, então precisamos trata-lo como um ponteiro p/ float e depois desreferenciar para pegar o valor de *b

    if (x > y)
        return 1;  // retorna um valor positivo se *a > *b

    if (x < y)
        return -1;  // retorna um valor negativo se *a < *b

    return 0;  // retorna 0 se *a == *b

    /* 
    > existe todo um protocolo, uma lógica dentro da função qsort que sabe exatamente o que fazer com cada um desses retorno
    > não coloquei {} após cada if pois: se o primeiro for true, ele logo retorna 1 e sai da função, se for false para pro próximo if, se o segundo for true, ele logo
    retorna -1 e sai da função, se tudo for false, concluimos que x == y, logo retornamos 0 
    */
}

int main(void) {

    int n;  // criando uma variável do tipo inteiro

    printf("Quantos elementos do tipo float voce quer armazenar? ");
    scanf("%d", &n); // lê o valor de n elementos do tipo float que o usuário quer armazenar

    float *r;  // criando um ponteiro do tipo float

    r = malloc(n * sizeof(float)); // aloca/reserva um espaço na memória para n elementos do tipo float

    for (int i = 0; i < n; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &r[i]); // em C um ponteiro pode ser tratado como um array
    }

    qsort(r, n, sizeof(float), comparando);  // qsort(o primeiro parametro do vetor r, o n° de elementos de r, o tipo de elementos armazenados em r, a função de comparação);
    
    for (int i = 0; i < n; i++)
    {
        printf("[ %.2f ] ", r[i]);
    }

    printf("\n");
    free(r);  // free para liberar a memória alocada para r, agora que não precisamos mais dela

    return 0;
}