#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//Primeiro exerc�cio

/* 
	* Disciplina: Estrutura de Dados I
	* Professor: Walace Bonfim
*/

/*
	Um pouco mais fundo em aloca��o din�mica:
	
	Desafio:
	
	Fazer o exerc�cio da aula 6 com aloca��o din�mica, de forma que cada registro seja criado caso o usu�rio digite sim/n�o.
*/

//Defini��o pr�via de estrutura
struct REGISTRO;

typedef struct{
	char nome[50];
	double area;
	double largura;
	double comprimento;
	struct REGISTRO *prox;
}REGISTRO;


int main(){
	
	REGISTRO registro[100];
	
	int tamanhoLista;
	
	setlocale(LC_ALL, "Portuguese");
	
	armazenando_registros(registro);
	
	printf("\n\n");
	
	mostrando_registros(tamanhoLista, registro);
	
	return 0;
}


//Pr�ximo registro (para aloca��o din�mica)
int proximo_registro(char valor, struct REGISTRO **reg){
	if(valor == 'S' || valor == 's'){
		*reg = (REGISTRO *) malloc(sizeof(REGISTRO)); 
		return 1;
	}
	else return 0;
}

//Mostrar registros
void mostrando_registros(int i, REGISTRO *registro){
	int j;
	double areatotal = 0;
	
	for(j=0;j<=i;j++){
		printf("Nome do registro: %s\n", registro[j].nome);
		printf("Largura do registro: %.2lf m\n", registro[j].largura);
		printf("Comprimento do registro: %.2lf m\n", registro[j].comprimento);
		printf("�rea do registro: %.2lf m�\n", registro[j].area);
		
		areatotal = areatotal + registro[j].area;
		
		printf("\n");
	}
	
	printf("\n�rea total da casa: %.2lf m�", areatotal);
}

//Armazenar registros
void armazenando_registros(REGISTRO *registro){
	
	int i = 0, valor;
	
	char pergunta;
	
	
	while(1){
		printf("Digite aqui o nome do c�modo: ");
		gets(registro[i].nome);
		
		fflush(stdin);
		
		printf("Digite a largura em m: ");
		scanf("%lf", &registro[i].largura);
		
		fflush(stdin);
		
		printf("Digite o comprimento em m: ");
		scanf("%lf", &registro[i].comprimento);
		
		fflush(stdin);
		
		registro[i].area = registro[i].comprimento * registro[i].largura;
		
		printf("\n");
		printf("Deseja continuar? S/N: ");
		pergunta = getch();
		valor = proximo_registro(pergunta, &registro);
		
		if(valor == 0) break;
		
		printf("\n\n");
		i++;
	}	
}
