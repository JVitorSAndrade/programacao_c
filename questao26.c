/*
#include <stdio.h>
int main()
{
    int a, b;
    int x, y, z;

    scanf("%d %d", &a, &b);

    x = a;
    y = b;
    z = a + b;

    while (a)
    {
        x = x | b;
        y = y ^ a;
        z = z & (a + b);
        a = a >> 1;
        b = b << 1;
    }

    printf ("%d %d %d \n", x, y, z);

    return 0;
}

> Resposta:
Entrada:
a = 10
b = 1

Inicialmente:
x = a = 10
y = b = 1
z = a + b = 11 

------------ 1ª ITERAÇÃO ------------
a = 10
b = 1

x = x | b
x = 10 | 1
x = 11

y = y ^ a
y = 1 ^ 10
y = 11
z = z & (a + b)
z = 11 & (10 + 1)
z = 11 & 11
z = 11

Agora: a = a >> 1
a = 10 >> 1
a = 5

b = b << 1
b = 1 << 1
b = 2

------------ 2ª ITERAÇÃO ------------
a = 5
b = 2

x = 11 | 2
x = 11

y = 11 ^ 5
y = 14

z = 11 & (5 + 2)
z = 11 & 7
z = 3

Agora: a = 5 >> 1 = 2
b = 2 << 1 = 4

------------ 3ª ITERAÇÃO ------------
a = 2
b = 4

x = 11 | 4
x = 15

y = 14 ^ 2
y = 12

z = 3 & (2 + 4)
z = 3 & 6
z = 2

Agora:
a = 2 >> 1 = 1
b = 4 << 1 = 8

-------------- 4ª ITERAÇÃO -------------
 a = 1
 b = 8
 
 x = 15 | 8
 x = 15
 
 y = 12 ^ 1
 y = 13
 
 z = 2 & (1 + 8)
 z = 2 & 9
 z = 0
 
 Agora:
 a = 1 >> 1 = 0
 b = 8 << 1 = 16
 
 Como a = 0, o while termina
 
 ------------ RESULTADO FINAL ------------
 x = 15
 y = 13
 z = 0
 Portanto, a saída do programa será: 15 13 0

 Os operadores utilizados são:
 | -> OR (OU bit a bit)
 ^ -> XOR (OU exclusivo bit a bit)
 & -> AND (E bit a bit)
 >> -> deslocamento de bits para a direita
 << -> deslocamento de bits para a esquerda
 */