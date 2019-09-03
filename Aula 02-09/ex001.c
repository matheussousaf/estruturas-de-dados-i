#include <stdio.h>
#define MAX 10

typedef struct{
	char nome[50];
}t_elementos;

typedef struct{
	t_elemento vetor[MAX];
	int pos;
}t_lista;

int main(){
	t_lista lista;
	
	int j;
	
	printf("Lista: ");
	for(j=0;j<lista->pos;j++){
		lista.teste[j] = j;
		printf("%d", lista.teste[j]);
	}
	
	return 0;
}

void mostraNomes(t_lista * lista, int pos){
	int i;
	for(i=0; i<lista->pos;i++){
		printf("%c", lista->teste[i]);
	}
}

void inserirNome(t_lista * lista){
	if(lista->pos == MAX || pos < 0 || )
}
