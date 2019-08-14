#include <stdio.h>
#include <locale.h>

//Primeiro Exercício

/* 
	* Disciplina: Estrutura de Dados I
	* Professor: Walace Bonfim

*/ 

int main(){
	int i, soma = 0, ultimo;
	
	signed long int n = 1;
	
	setlocale(LC_ALL, "Portuguese");
	
	for(i=0;i<64;i++){
		ultimo = n;
		soma = soma + ultimo;
		n = n * 2;
		ultimo = n;
	}
	
	printf("N�mero: %hi", n);
	
	return 0;
}
