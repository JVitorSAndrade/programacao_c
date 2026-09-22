/*
O que eh memory leak?
Eh o vazamento de memória que ocorre quando alocamos/reservamos um espaco na memorio com malloc, por exemplo, e nao liberamos
esse espaco alocado no fim do codigo/quando nao se faz mais necessario o uso daquele espaco.
*/

// exemplo:
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int *x;

    x = malloc(sizeof(int));  //alocando um espaço na memória para um inteiro

    scanf("%d", x);  //recebendo um valor para ser guardado no espaço alocado para x -- obs: nao usamos &x pois x ja guarda o endereço de memoria alocado

    printf("Valor digitado: %d \n", *x);  //imprimindo o valor guardado no espaço alocado para x

    free(x);  // precisamos desse free(x) para liberar o espaço alocado a x 

    return 0;
}

/*
exemplo incorreto (sem free):
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x;
    x = malloc(sizeof(int));  //alocando um espaço na memória para um inteiro

    scanf("%d", x);  //recebendo um valor para ser guardado no espaço alocado para x

    printf("Valor digitado: %d \n", *x);  //imprimindo o valor guardado no espaço alocado para x

    ?sem free(x)? => espaco reservado para x nao foi liberado => memory leak

    return 0;
}
*/