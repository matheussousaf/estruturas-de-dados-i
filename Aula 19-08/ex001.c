#include <stdio.h>
#include <math.h>

//Primeiro Exercício

/* 
	* Disciplina: Estrutura de Dados I
	* Professor: Walace Bonfim
*/ 

//Função cópia da função pow
int pow_copy(int base, int expoente);

int main(){
	int i;
	long int res;
	
	/*
	
	* Primeira forma:
	
	Usando a função pow(base, expoente) da biblioteca math.h
	
	for(i=0;i<16;i++){
		res = pow(3, i);
		printf("3 elevado a %d = %li\n", i, res);
		res = 0;
	}
	
	* Segunda forma:
	
	Recriando a função pow(base, expoente) da biblioteca math.h
	
	*/
	
	for(i=0;i<16;i++){
		res = pow_copy(3, i);
		printf("3 elevado a %d = %li\n", i, res);
		res = 0;
	}
	
	
	return 0;
}


int pow_copy(int base, int expoente){
	int i, res;
	
	res = 1;
	
	for(i=0;i<expoente;i++){
		res = res * base;
	}
	
	return res;
}
