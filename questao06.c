#include <stdio.h>

void funcao(char **p) //p é um ponteiro do tipo char** que recebe o endereço a[0]
{
    char *t; //ponteiro t

    t = (p += sizeof(int))[-1]; /*traduzindo: p avança 4 posições devido o + sizeof(int)=4, saindo de a[0] para a[4], o - [1] retrocede uma posição e acessa a[3]=gh*/

    printf("%s\n", t); //t é um ponteiro char, logo só de colocar o %s espera-se que tenhamos como saída um char
}

int main()
{
    char *a[] = {"ab", "cd", "ef", "gh", "ij", "kl"}; //criação de um array de ponteiros char - a é um array de 6 ponteiros

    funcao(a); //chamamos a funcção "funcao" e passamos como parâmetro (endereço) a[0]

    return 0;
}