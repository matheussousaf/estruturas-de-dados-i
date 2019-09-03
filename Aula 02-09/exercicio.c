#include <stdio.h>
#include <string.h>
#define	MAX 10

//T-Elemento
typedef struct elementos {
    char nome[50];
} t_elemento;

//T-Lista
typedef struct lista {
    t_elemento vetor[MAX];
    int n;
} t_lista;

int main(){
    int i;

    t_lista lista;

    t_elemento elemento1;
    t_elemento elemento2;
    t_elemento elemento3;

    gets(elemento1.nome);
    gets(elemento2.nome);
    gets(elemento3.nome);

    inserir(lista, 0, elemento1);
    inserir(lista, 1, elemento2);
    inserir(lista, 2, elemento3);

    return 0;
}


int isCheia(t_lista * lista) {
    return (lista->n == MAX-1);
}

int inserir (t_lista * lista, int pos, t_elemento dado) {
    if ( isCheia(lista) || (pos > lista->n + 1) || (pos < 0) )
        return 0;

    deslocaDireita(lista, pos);
    lista->vetor[pos] = dado;
    (lista->n)++;
    return 1;
}

int remover (t_lista *lista, int pos) {
    if ( (pos > lista->n) || (pos < 0) )
        return 0;

    deslocaEsquerda(lista, pos);

    (lista->n)--;
    return 1;
}

int deslocaDireita(t_lista * lista, int pos) {
    int i;

    for (i=lista->n + 1; i>pos; i--)
        lista->vetor[i] = lista->vetor[i-1];

    return 1;
}

int deslocaEsquerda(t_lista * lista, int pos) {
    int i;

    for (i=pos; i<(lista->n); i++)
        lista->vetor[i] = lista->vetor[i+1];

    return 1;
}

char * procuraNome(t_lista * lista, char * nome) {
    int i;

    for(i=0; i<lista->n; i++){
      if(strcmp(lista->vetor[i].nome, nome) == 0){
        return nome, "foi encontrado!";
      }
    }
    return "O nome não foi encontrado";
}
