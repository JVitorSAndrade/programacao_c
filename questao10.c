/*
10. O que fazem os seguintes programas em C?

A)
#include <stdio.h>
int main(){
    int vet[] = {4, 9, 13};     <- um array do tipo int é criado, de tamanho 3
    int i;      <- variável int i criada
    for(i=0;i<3;i++){       <- um for que varia i de 0 a 2
        printf("%d ", *(vet+i));        <- um printf que imprime: i = 0 - saída: 4; i = 1 - saída: 9; i = 2 - saída: 13
    }
}

B)
#include <stdio.h>
int main(){
    int vet[] = {4, 9, 13};     <- um array do tipo int é criado, de tamanho 3
    int i;      <- variável int i criada
    for(i=0;i<3;i++){       <- um for que varia i de 0 a 2
        printf("%X ",vet+i);        <- a referência %X imprime no formato hexadecimal, temos ali vet+i, porém sem parênteses e *, logo estamos lidando apenas com o endereço
                                        de memória de cada elemento de vet
    }
}
*/