#include <stdio.h>
#include <math.h>

//Segundo Exercício

/* 
	* Disciplina: Estrutura de Dados I
	* Professor: Walace Bonfim
*/ 

int main(){
	int base, exp, i, res;
	
	printf("Base: ");
	scanf("%d", &base);
	
	printf("Expoente: ");
	scanf("%d", &exp);
	
	
	/*
	
	* Primeira forma: 
	
	Usando a função pow(base, expoente), da biblioteca math.h
	
	printf("Resultado %d\n", (pow(base, exp)));
	
	
	* Segunda forma:
	
	Recriando a função pow(base, expoente), da biblioteca math.h
	
	*/
	
	res = 1;
	
	for(i=0;i<exp;i++){
		res = res * base;
	}
	
	printf("Resultado: %d\n", res);
	
	
}
