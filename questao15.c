#include <stdio.h>

int main () {

    unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6},  
                            {7, 8, 9}, {10, 11, 12}};
/*
> normalmente vemos x[5], por exemplo. Quando fazemos x + 1, avançamos um tamanho do elemento que é x 
> quando x = x[4][3], se fazemos x + 1, avançamos as linhas de x 
                                                        
Obs:
x[5] = [ l0 ][ l1 ][ l2 ][ l3 ][ l4 ]  --  cada elemento de x é um bloquinho
x[4][3] = [][][]  -- x[0]  -- veja assim  --  cada elemento de x é um LINHA INTEIRA
          [][][]  -- x[1]
          [][][]  -- x[2]
          [][][]  -- x[3]
*/
    printf ("%u, %u, %u", x+3, *(x+3), *(x+2)+3);

/*
PRIMEIRO:
> x+3 aponta x[3], aqui temos o endereço de x[3]

> *(x+3) = *(endereço de x[3]) => o * se encarrega de pegar o elemento para onde x+3 aponta (a linha inteira). Um array usado
em uma expressão vira o ponteiro do seu primeiro elemento (se você nao especificar a posição), que é 10

> *(x+2)+3 = *(endereço de x[2])+3 => x[2] + 3 =  (avance 3 unsigned int = 4 bytes) => avançando
4 bytes chegamos no primeiro componente de x[3], que é 10

SEGUNDO:
> no printf temos %u, e %u espera receber um unsigned int, não ponteiros, logo temos como saída a representação
númerica do endereço desses ponteiros
*/
}