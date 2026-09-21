#include <stdio.h>

void main(){  //primeiramente, o programa nem compila, motivos a seguir

int const *x = 3; /*x é um ponteiro, e ponteiros devem receber apenas endereços de memória => o programa aqui já nem compila, da erro */

printf("%d", ++(*x)); /*int const *x - caso estivesse tudo certinho nas linhas acima, x ainda é um ponteiro de valor imutável, e aqui vc estaria somando
 + 1 a valor de x => +1 erro */

}

/*
OBSs:
1. int const *x ou const int *x - x é um ponteiro que aponta para algum endereço de conteúdo constante, MAS, pode ser apontado para outro endereço.

2. int * const x - x é um ponteiro que aponta para um endereço sempre, você não pode reendereçá- lo... mas seu conteúdo pode ser mudado

3. const int * const x - tanto o ponteiro quanto o endereço são IMUTÁVEIS.
*/