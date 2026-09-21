#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void funcao(char **str)
{
    (*str)++;
}

int main()
{
    char *str = malloc(50 * sizeof(char));

    strcpy(str, "Agostinho");

    funcao(&str);

    puts(str);

    free(str);

    return 0;
}

/* 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void funcao(char** str){     <- aqui, funcao recebe o endereço de str do main
   str++;     <- aqui, o str ->local<- avança para a próxima posição de memória, e É POR ISSO 
que temos como saída "Agostinho" ao invés de "gostinho", pois estamos modificando a variável
local de “funcao”, não de main, logo, se queremos que a saída seja "gostinho", precisamos fazer
(*str)++;, pois aqui, estamos modificando o valor do main.
*/