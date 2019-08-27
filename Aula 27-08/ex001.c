#include <stdio.h>
#define MAX 10

typedef struct elementos {
    char nome[50];
    // Outros elementos
} t_elemento;

typedef struct{
	t_elemento vetor[MAX];
	int n;
} t_lista;

t_lista criar() {
    t_lista lista;

    lista.n = -1;

    return lista;
}


int main(){
	t_lista var;
	
	var = criar();
	
	printf("%d", var.n);
	
	return 0;
}
