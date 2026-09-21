#include <stdio.h>

int main()
{
    int i, j, *p, *q;

    p = &i;
    *q = &j; //erro: pois você tá tetando colocar um endereço numa variável int
    p = &*&i; 
    i = (*&)j; //erro: pois você tá fazendo a referenciação e desrefenreciação em "nada"
    i = *&j;
    i = *&*&j;
    q = *p; //erro: pois esta fazendo praticamente int* = int
    i = (*p)++ + *q;

    return 0;
}