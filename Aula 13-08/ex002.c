#include <stdio.h>
#include <locale.h>

//Segundo Exercício

/* 
	* Disciplina: Estrutura de Dados I
	* Professor: Walace Bonfim
*/ 

typedef struct{
	char nome[50];
	double area;
	double largura;
	double comprimento;
}REGISTRO;

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	REGISTRO registro[100];
	
	int i = 0;
	char pergunta;
	
	
	while(1){
		printf("Digite aqui o nome do cômodo: ");
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
		if(pergunta == 'N' || pergunta == 'n') break;
		
		printf("\n\n");
		i++;
	}
	
	int j;
	double areatotal = 0;
	
	printf("\n\n");
	
	for(j=0;j<=i;j++){
		printf("Nome do registro: %s\n", registro[j].nome);
		printf("Largura do registro: %.2lf m\n", registro[j].largura);
		printf("Comprimento do registro: %.2lf m\n", registro[j].comprimento);
		printf("Área do registro: %.2lf m²\n", registro[j].area);
		
		areatotal = areatotal + registro[j].area;
		
		printf("\n");
	}
	
	
	printf("\nÁrea total da casa: %.2lf m²", areatotal);
	
	
	return 0;
}
