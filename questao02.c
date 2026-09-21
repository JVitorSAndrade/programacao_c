#include <stdio.h>

int main()
{

    int i = 5, *p;

    p = &i;
    printf("%p %p %d %d %d %d\n", p, p + 1, *p + 2, **&p, 3 * *p, **&p + 4);

    return 0;
}

/*
%p no printf exibe o endereço do que esta dentro de p;
%d vai printar valores inteiros

%p - p: printa 4094 (o endereço de i)
%p - p + 1: o + 1 avança 1 inteiro (2 bytes), printando 4096
%d - *p + 2: *p(5) + 2 = 7
%d - **&p: como já visto na Q01, "**&" = *, logo temos *p = 5
%d - 3 * *p: 3 * *p(5) = 15
%d - **&p + 4: **&p(*p = 5) + 4 = 9
*/