#include <stdio.h>

//Quarto Exercício

/* 
	* Disciplina: Estrutura de Dados I
	* Professor: Walace Bonfim
*/ 

int main(){
	int i;
	
	unsigned long long int n = 1, soma = 0, ultimo;
	
	for(i=0;i<64;i++){
		ultimo = n;
		soma = soma + ultimo;
		n = 2 * n;
		ultimo = n;
	}

	printf("Numero: %llu", soma);
	
	return 0;
}
