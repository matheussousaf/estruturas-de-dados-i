#include <stdio.h>
#include <locale.h>

//Primeiro Exerc�cio

/* 
	* Disciplina: Estrutura de Dados I
	* Professor: Walace Bonfim
*/ 

int main(){
	int i;
	
	long long int n = 1, soma = 0, ultimo;
	
	setlocale(LC_ALL, "Portuguese");
	
	for(i=0;i<64;i++){
		ultimo = n;
		soma = soma + ultimo;
		n = 2 * n;
		ultimo = n;
	}
	
	printf("N�mero: %lld", soma);
	
	return 0;
}
