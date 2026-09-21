#include <stdio.h>

int main(void)
{
    int mat[4] = {2, 2, 3, 4}, *p, x;

    p = mat + 1; //válida: você tá atribuindo a p o endereço de mat[0]+1 = mat[1]
    //p = mat++; // = mat + 1 - mat é o endereço inicial desse vetor, ele não é uma variável para você simplesmente ir lá e modificar somando 1
    //p = ++mat; // mesmo motivo de mat++
    x = (*mat); //válida: você atribuiu o valor do endereço de mat[0] a x, mas devido o * desreferencia o endereço e atribui o valor guardado ali

    printf("%p\n", p);
    printf("%d", x);
}