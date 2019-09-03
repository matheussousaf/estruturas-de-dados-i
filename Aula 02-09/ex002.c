#include <stdio.h>
#include <string.h>
#include <locale.h>
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

int procurarNome(t_lista * lista, char * nome);

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
    int i, acharNome;
    char nome[50];

    t_lista lista;

    t_elemento elemento1;
    t_elemento elemento2;
    t_elemento elemento3;

	printf("Insira o primeiro nome: ");
    gets(elemento1.nome);
    fflush(stdin);
    
    printf("Insira o segundo nome: ");
	gets(elemento2.nome);
	fflush(stdin);
	
	printf("Insira o terceiro nome: ");
    gets(elemento3.nome);
	fflush(stdin);
	
    inserir(&lista, 1, elemento1);
    inserir(&lista, 2, elemento2);
    inserir(&lista, 3, elemento3);
    
    printf("Insira o nome que voce quer procurar: ");
    gets(nome);
    acharNome = procurarNome(&lista, nome);
    if(acharNome == 1){
    	printf("%s foi encontrado!\n", nome);
	} else{
		printf("%s não foi encontrado\n", nome);
	}
	
	printf("Insira o nome que você quer deletar: ");
	gets(nome);
	acharNome = pegarPosicao(&lista, nome);
	if(acharNome == 1){
		remover(&lista, acharNome);
		printf("%s foi removido com sucesso!\n", nome);
	} else{
		printf("%s não pode ser deletado por que não existe!\n");
	}
    

    return 0;
}


int procurarNome(t_lista * lista, char * nome) {
    int i;

    for(i=0; i<lista->n+1; i++){
      if(strcmp(lista->vetor[i].nome, nome) == 0){
        return 1;
      }
    }
    
    return 0;
}

int pegarPosicao(t_lista * lista, char * nome) {
    int i;

    for(i=0; i<lista->n+1; i++){
      if(strcmp(lista->vetor[i].nome, nome) == 0){
        return i;
      }
    }
    
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

