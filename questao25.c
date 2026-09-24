/*
(C)
int f(char *data){
    void *s;

    s = malloc(50);

    int size = strlen(data);

    if (size > 50)
    return(-1);
    free(s);

    return 0;
}

> O trecho que apresenta um vazamento de memória é o (C). Nele, a função aloca dinamicamente 50 bytes de memória utilizando a função malloc(50) e
armazena o endereço em s. Em seguida, o código verifica se o tamanho da string (size) é maior que 50 e, caso seja verdadeiro, executa um
return(-1) de forma antecipada. Esse desvio faz com que a linha free(s) nunca seja alcançada quando a condição é atendida, deixando a memória
alocada sem possibilidade de liberação e gerando, portanto, um vazamento de memória (*memory leak*).
*/