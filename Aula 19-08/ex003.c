#include <stdio.h>

//Terceiro Exerc�cio

/* 
	* Disciplina: Estrutura de Dados I
	* Professor: Walace Bonfim
*/ 

int main(){
	int i, n1 = 1, n2 = 0, res = 0;

	/*
	
	* Sequ�ncia de Fibonacci:
	
	- O Algoritmo funciona dessa forma: 
	
	O resultado inicialmente � 0, o primeiro n�mero � 1 e o segundo n�mero � 0.
	
	A cada itera��o, o resultado vira o resultado do primeiro n�mero mais o segundo n�mero
	O primeiro n�mero "desaparece"(uma vez que n�o � mais necess�rio), o primeiro n�mero 
	recebe o valor do segundo n�mero e o segundo n�mero recebe o valor do resultado. 
	
	
	*/

	for(i=0; i<15;i++){
		printf("%d\n", res);
		res = n1 + n2;
		n1 = n2;
		n2 = res;
	}
	
	return 0;
}
