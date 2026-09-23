#include <stdio.h>
#include <stdlib.h>

void ordenacao(float *r, int n) {

    for (int i = 0; i < n - 1; i++)  // lógica bubble sort
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (r[j] > r[j + 1])
            {
                float aux = r[j];
                r[j] = r[j + 1];
                r[j + 1] = aux;
            }
        }
    }
}

int main(void) {

    int n;

    printf("Quantos elementos do tipo float voce quer armazenar? ");
    scanf("%d", &n); // lê o valor de n

    float *r;

    r = malloc(n * sizeof(float)); // aloca um espaço na memória para n elementos do tipo float

    for (int i = 0; i < n; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &r[i]); // em C um ponteiro pode ser tratado como um array
    }

    ordenacao(r, n);

    printf("Elementos ordenados: ");
    for (int i = 0; i < n; i++)
    {
        printf("[ %.2f ] ", r[i]);
    }
    
    printf("\n");
    free(r);

    return 0;
}