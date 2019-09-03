#include <stdio.h>
#define MAX 10

typedef struct elementos {
    char nome[50];
    // Outros elementos
} t_elemento;

// Estrutura da lista
typedef struct lista {
    t_elemento vetor[MAX];//vet que armazena elem. da pilha
    int n; // posicao (indice) do ultimo elemento da lista
} t_lista; // tipo lista

int main(){
	t_lista lista;
	
	int i;
	
	for(i=0; i<3; i++)
	{
		scanf("%s", &lista.vetor[i].nome);
	}
	
	mostrarLista(&lista);
}

void mostrarLista(t_lista * lista){
	int i;
	
	for(i=0; lista->n; i++){
		printf("%s", lista->vetor[i].nome);
	}
}
