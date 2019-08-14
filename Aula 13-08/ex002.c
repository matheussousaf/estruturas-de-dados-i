#include <stdio.h>
#include <locale.h>

//Segundo Exercício

/* 
	* Disciplina: Estrutura de Dados I
	* Professor: Walace Bonfim

*/ 

typedef struct{
	char nome[50];
	int area;
	int largura;
	int comprimento;
}REGISTRO;

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	REGISTRO registro[100];
	
	int i = 0;
	char pergunta;
	
	
	while(1){
		printf("Digite aqui o nome do c�modo: ");
		fgets(&registro[i].nome, sizeof(registro[i].nome), stdin);
		
		printf("Digite a largura em cm: ");
		scanf("%d", &registro[i].largura);
		
		printf("Digite o comprimento em cm: ");
		scanf("%d", &registro[i].comprimento);
		
		registro[i].area = registro[i].comprimento * registro[i].largura;
		i++;
		
		printf("Deseja continuar? S/N: ");
		scanf("%c", &pergunta);
		
		if(pergunta == 'N' || pergunta == 'n') break;
	}
	
	//Inacabado
	
	
	printf("")
	
	
	return 0;
}
