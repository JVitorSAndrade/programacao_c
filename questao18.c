/*
O que é um ponteiro para uma função?
> Um ponteiro que armazena o endereço de uma função.
> Após declararmos um ponteiro para função, podemos usar o mesmo como a própria função.
ex:
int *x;
int (*x)(int); // não precisamos usar & pois o próprio nome da função é o seu endereço
int x(int b, int c); // x recebe um int b e int c e retorna um int
*/

//exemplo: um alarme que dispara quando está de noite e há movimento
#include <stdio.h>

int sensor(int iluminacao, int movimento) {  // um sensor que liga o alarme quando a iluminacao é 0 e o movimento é 1

    if (iluminacao == 1 && movimento == 1) {  // if iluminacao é 1 (dia) e movimento é 1 (há movimento)
        return 0; // não liga o alarme
    } else if (iluminacao == 1 && movimento == 0) {  // if iluminacao é 1 (dia) e movimento é 0 (não há movimento)
        return 0; // não liga o alarme
    } else if (iluminacao == 0 && movimento == 1) {  // if iluminacao é 0 (noite) e movimento é 1 (há movimento)
        return 1; // liga o alarme
    } else if (iluminacao == 0 && movimento == 0) {  // if iluminacao é 0 (noite) e movimento é 0 (não há movimento)
        return 0; // não liga o alarme
    } else {  // valor invalido/ combinação de valores inválidos
        return 0; // não liga o alarme
    }
}

int main(void) {

    int iluminacao, movimento;  // declaando as variáveis

    int (*p)(int, int) = sensor; // p recebe o endereço da função sensor

    printf("Ta de dia (1) ou de noite (0)? ");  // o guardinha vai registrar se tá de noite (escuro ou de dia -- iluminacao)
    scanf("%d", &iluminacao);  // lê o valor de iluminacao
    printf("Ha movimento? Sim (1) ou Nao (0): ");  // o guardinha vai registrar se há movimento
    scanf("%d", &movimento);  // lê o valor de movimento

    if (p(iluminacao, movimento)) {
        printf("\npiiiiiiiiiiii! Alarme disparado! \n");  // se o sensor detectar que está de noite e há movimento, o alarme dispara
    } else {
        printf("\nTudo tranquilo! -_-\n");  //se o sensor detectar que está de dia ou tá de noite mas não há movimento, o alarme não dispara
    }

}