#include <stdio.h>

//Terceiro Exercício

/* 
	* Disciplina: Estrutura de Dados I
	* Professor: Walace Bonfim
*/ 

int main(){
	int i, n1 = 1, n2 = 0, res = 0;

	/*
	
	* Sequência de Fibonacci:
	
	- O Algoritmo funciona dessa forma: 
	
	O resultado inicialmente é 0, o primeiro número é 1 e o segundo número é 0.
	
	A cada iteração, o resultado vira o resultado do primeiro número mais o segundo número
	O primeiro número "desaparece"(uma vez que não é mais necessário), o primeiro número 
	recebe o valor do segundo número e o segundo número recebe o valor do resultado. 
	
	
	*/

	for(i=0; i<15;i++){
		printf("%d\n", res);
		res = n1 + n2;
		n1 = n2;
		n2 = res;
	}
	
	return 0;
}
