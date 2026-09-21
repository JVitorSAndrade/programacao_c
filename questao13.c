#include <stdio.h>

void main()
{

    char x_char[4];     // 1 byte
    int x_int[4];       // 2 bytes -- no exercicio, normalmente é 4 byte
    float x_float[4];   // 4 bytes
    double x_double[4]; // 8 byte

    printf("x_char: %d;   x_char + 1: %d;   x_char + 2: %d;   x_char + 3: %d\n", &x_char[0], &x_char[0 + 1], &x_char[0 + 2], &x_char[0 + 3]);
    printf("\nx_int: %d;   x_int + 1: %d;   x_int + 2: %d;   x_int + 3: %d\n", &x_int[0], &x_int[0 + 1], &x_int[0 + 2], &x_int[0 + 3]);
    printf("\nx_float: %d;   x_float + 1: %d;   x_float + 2: %d;   x_float + 3: %d\n", &x_float[0], &x_float[0 + 1], &x_float[0 + 2], &x_float[0 + 3]);
    printf("\nx_double: %d;   x_double + 1: %d;   x_double + 2: %d;   x_double + 3: %d\n", &x_double[0], &x_double[0 + 1], &x_double[0 + 2], &x_double[0 + 3]);
}

/*
Notas:
> fazer x + 1 é avançar o tamanho de UM elemento de x_...
> para ponteiros usamos %p, mas fazendo eu coloquei %d pois fica muito mais visual a mudança

> Respostas esperadas:
1. char: como char tem o tamanho de 1 byte, fazer:
        x+1 = 4093   ,   x+3 = 4095
        x+2 = 4094

2. int: como int tem o tamanho de 2 byte, fazer:
        x+1 = 4094   ,   x+3 = 4098
        x+2 = 4096

3. float: como float tem o tamanho de 4 byte, fazer:
        x+1 = 4096   ,   x+3 = 4104
        x+2 = 4100

4. double: como double tem o tamanho de 8 byte, fazer:
        x+1 = 4100   ,   x+3 = 4116
        x+2 = 4108
*/