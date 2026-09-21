#include <stdio.h>

int main()
{
    int i = 3, j = 5;
    int *p, *q;
    p = &i;
    q = &j;

    return 0;
}

/*
1. p == &i; -- p guarda o endereço de i.

2. *p - *q; -- o * na frente de p e q indica que estamos lidando com os valores guardados naquele endereço para qual os ponteiros p e q apontam, sendo assim: *p - *q = -2.

3.**&p; -- é a mesma coisa que *(*(&p - o endereço onde está o ponteiro p) - o valor guardado no endereço de p, que é o endereço de &i) - o valor guardado no endereço de i. Logo, temos como saída o valor 3.

4.3 - *p/(*q) + 7; -- *p = 3 e *q = 5, fazemos primeiro a divisão *p/(*q), que resulta num numero quebrado, mas como temos 2 inteiros, result = 0. Logo, temos: 3 - 0 + 7 = 10.
*/