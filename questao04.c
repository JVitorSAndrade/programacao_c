#include <stdio.h>

int main() {
    int valor;
    int *p1;
    float temp;
    float *p2;
    char aux;
    char *nome = "Ponteiros";
    char *p3;
    int idade;
    int vetor[3];
    int *p4;
    int *p5;

    /* (a) */
    valor = 10;
    p1 = &valor;
    *p1 = 20;
    printf("%d \n", valor);

    /* (b) */
    temp = 26.5;
    p2 = &temp;
    *p2 = 29.0;
    printf("%.1f \n", temp);

    /* (c) */
    p3 = &nome[0];
    aux = *p3;
    printf("%c \n", aux);

    /* (d) */
    p3 = &nome[4];
    aux = *p3;
    printf("%c \n", aux);

    /* (e) */
    p3 = nome;
    printf("%c \n", *p3);

    /* (f) */
    p3 = p3 + 4;
    printf("%c \n", *p3);

    /* (g) */
    p3--;
    printf("%c \n", *p3);

    /* (h) */
    vetor[0] = 31;
    vetor[1] = 45;
    vetor[2] = 27;
    p4 = vetor;
    idade = *p4;
    printf("%d \n", idade);

    /* (i) */
    p5 = p4 + 1;
    idade = *p5;
    printf("%d \n", idade);

    /* (j) */
    p4 = p5 + 1;
    idade = *p4;
    printf("%d \n", idade);

    /* (l) */
    p4 = p4 - 2;
    idade = *p4;
    printf("%d \n", idade);

    /* (m) */
    p5 = &vetor[2] - 1;
    printf("%d \n", *p5);

    /* (n) */
    p5++;
    printf("%d \n", *p5);
    return(0);
}

/*
OBS: se tratando de uma var char, o uso do * não se faz necessário pois entendemos que cada letra do nome esta dispersa como em um array (que em muitos casos tbm não se faz necessário o uso 
do * para igualar), por isso em algumas onde iguala-se *p3 com alguma var char, não da erro a falta do *

a) esperado = 20: ao fazer p1 = &valor, você concetou os dois, assim, se mudar *p1, muda valor
b) esperado = 29.0: mesma coisa de a)
c) esperado = P: p3 = &nome[0] pegou somente a letra P localizada em nome[0]
d) esperado = e: p3 = &nome[4] <=> p3 = e, logo, fazendo p3 = aux e printando aux, temos e
e) esperado = ou não vai exibir nada ou vai printar P: p3 vê nome como uma matriz, mas como não estamos indicando se é pra printar tudo, ela exibe somente a primeria letra, no caso nome[0] = P
f) esperado = e: da e), *p3 = P, "subindo" 4 casas que p3 + 4 = e
g) esperado = t: p3-- = p3 - 1, retrocedendo um indice na string
h) esperado = 31: igual na e), como você não especificou, é exibido o primeiro valor do array, que é 31
i) esperado = 45: p4(vetor[0] = 31) + 1 = o próximo valor do array que é 45
j) esperado = 27: você subiu pra próxima casa do array que é 27
l) esperado = 31 você desceu 2 casas anteriores do array que é justamente o valor 31
m) esperado = 45: pegar o endereço de vetor[2] e subtrair 1 faz o ponteiro recuar uma posição inteira
n) esperado = 27: em m) o p5 assumiu o valor do vetor[1] após subtrair 1, aqui, somando 1 assumimos o valor de vetor[2] = 27
*/