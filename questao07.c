#include <stdio.h>

int main(void)
{
    float vet[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float *f;
    int i;

    f = vet; //f é um ponteiro que aponta para o 1° endereço de vet = vet[0]

    printf("contador/valor/valor/endereco/endereco\n");

    for (i = 0; i <= 4; i++)
    {
        //seja i = 1
        printf("i = %d", i); //print i = 1
        printf(" vet[%d] = %.1f", i, vet[i]); //print vet[1] = 2.2
        printf(" *(f + %d) = %.1f", i, *(f + i)); //print *(f + 1) = 2.2, pois f = a[0], somando + 1 avançamos 4 bytes na memória e * recupera o valor guardado lá
        printf(" &vet[%d] = %X", i, &vet[i]); // print &vet[1] = endereço no formato hexadecimal de vet[1]
        printf(" (f + %d) = %X", i, f + i); // print (f + 1) = endereço no formato hexadecimal de vet[1]

        printf("\n");
    }
}