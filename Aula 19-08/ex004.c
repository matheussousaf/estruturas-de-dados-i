#include <stdio.h>

//Quarto Exerc�cio

/* 
	* Disciplina: Estrutura de Dados I
	* Professor: Walace Bonfim
*/ 

int main(){
	int i;
	
	long long int n = 1, soma = 0, ultimo;
	
	for(i=0;i<64;i++){
		ultimo = n;
		soma = soma + ultimo;
		n = 2 * n;
		ultimo = n;
	}
	
	//Obs.: Embora o algoritmo esteja correto, o n�mero � grande demais para caber em uma vari�vel, at� mesmo long long int.
	
	printf("Numero: %lli", soma);
	
	return 0;
}
