#include <stdio.h>

void main () {

    float aloha[10], coisas[10][5], *pf, value = 2.2; int i=3;

    aloha[2] = value;  //valido
    scanf("%f", &aloha);  //valido, porem errado, visto que &aloha eh um endereco de memoria, e o %f espera receber um float * (que seria o valor ali contido ou um escalar mesmo)
    aloha = "value";  //invalido - aloha eh um vetor do tipo float, nele voce nao pode armazenar strings 
    printf("%f", aloha);  //invalido - aloha eh um vetor, voce nao pode simplesmente printar um vetor em UM printf
    coisas[4][4] = aloha[3];  //valido
    coisas[5] = aloha;  //invalido - nao da pra copiar os valores de um vetor para outro usando =, alem de q coisas tem 5 elementos e aloha 10
    pf = value;  //invalido - pf eh um ponteiro, o que significa que nao pode receber nada alem de enderecos de memoria
    pf = aloha;  //valido

}