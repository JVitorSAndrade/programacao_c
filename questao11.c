#include <stdio.h>

struct teste {
int x = 3;  //você tá dando valor dentro da própria struct, isso não pode acontecer em C
char nome[] = "jose"; //novamente, dando valor dentro da struct

};

main() {

struct teste *s;  //aqui temos apenas um ponteiro que não aponta para nada
printf("%d", s->x);  //o certo seria criar uma variével do tipo struct teste e fazer s apontar para ela
printf("%s", s->nome);  

}

/*código corrigido:
#include <stdio.h>
#include <string.h>

struct teste {
int x;  //apenas x
char nome[100];  //apenas char nome[100]
};

main() {

struct teste t, *s;  //var struct teste t criada
s = &t;  //associar s ao endereço t
s -> x = 3;
strcpy(s->nome, "jose");  //strcpy: função da biblioteca string.h que nos permite copiar uma string para um array
printf("%d", s->x);  
printf("%s", s->nome);

}
*/