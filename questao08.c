#include <stdio.h>

int main(void) {

    int pulo[5] = {1, 2, 3, 4, 5}; //vetor pulo

    int *p = pulo; //p aponta para pulo[0]

    printf ("%d", *(p + 2)); //faz o deslocamento e o * pega o valor contido naquele endereço
}

/*
8. Assumindo que pulo[] é um vetor do tipo int, qual das seguintes expressões referenciam o valor
do terceiro elemento do vetor?
◦ *(pulo + 2);
◦ *(pulo + 4);
◦ pulo + 4;
◦ pulo + 2;

RESP:
A posição de um ponteiro se inicia em 0 (pulo[0]), esse é a primeira posição do mesmo. Para irmos até sua posição, fazemos pulo + 2.
Porém, aqui temos duas respostas que se "assemelham" a isso que acabei de escrever: pulo + 2 e *(pulo + 2).
Porém sendo pulo um vetor inteiro, a opção correta para avançarmos os endereços dele e no fim imprimir o valor ali encontrado, é:*(pulo + 2).
*/