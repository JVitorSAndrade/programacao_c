#include <stdio.h>

int f(int a, int *pb, int **ppc)
{
    int b, c;
    **ppc += 1; //ppc aponta para a, cujo conteúdo aponta para b, e b aponta para c que tem o valor 5, logo **ppc+=1 => ppc + 1 = 6  --  alteramos o valor de c
    c = **ppc; // c = **ppc => c = 6
    *pb += 2; //pb aponta para b, que aponta para c, cujo valor é agora é 6 (linha anterior), logo *pb+=2 => pb + 2 = 8
    b = *pb; //b = *pb => b = 8
    a += 3; /*aqui, a recebe c, que naquele momento do main era 5...  a não acompanha a mudança de c pois quando chamamos a funcao, naquele instante,
     a recebeu um inteiro 5, e não o endereço de c, logo, a guardou naquele instante o valor 5 de que recebeu de c, logo aqui temos a = 5 + 3 = 8*/
    return a + b + c; // 8 + 8 + 6 = 22
}

void main()
{
    int c, *b, **a;
    c = 5;
    b = &c;
    a = &b;
    printf("%d\n", f(c, b, a)); //c é passado apenas como o valor contido nele, que é 5, não seu endereço de memória -- justificando a += 3 = 8 na linha 10
    getchar();
}