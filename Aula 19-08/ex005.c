#include <stdio.h>

//Quinto Exercício

/* 
	* Disciplina: Estrutura de Dados I
	* Professor: Walace Bonfim
*/ 

int main(){
	int n[5], i, maior, menor;
	
	int length = (sizeof(n)/sizeof(n[0])); // -> Length do vetor
	
	//Armazenando os valores no vetor
	for(i=0;i<length;i++){
		scanf("%d", &n[i]);
	}
	
	//Verificando qual valor é maior e menor
	for(i=0;i<length;i++){
		if(i==0){
			maior = n[i];
			menor = n[i];	
		}
		else{
			if(n[i] > maior) maior = n[i];
			if(n[i] < menor) menor = n[i];
		}
	}
	
	printf("Maior: %d\n", maior);
	printf("Menor: %d\n", menor);
	
	return 0;
}
