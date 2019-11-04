#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define QUANTIDADE_NOME 50

typedef struct carro{
    char nome[QUANTIDADE_NOME];
} CARRO;

// Estrutura do nÃ³ do carro
typedef struct carro_no{
    CARRO carro;
    struct carro_no * prox;
} CARRO_NO;

// Estrutura do semÃ¡foro.
typedef struct semaforo{
    CARRO_NO * inicio;
    int quantidade;
    CARRO_NO * final;
} SEMAFORO;


// Cria o semÃ¡foro.
SEMAFORO * criaSemaforo(){
    SEMAFORO * semaforo = (SEMAFORO*) malloc(sizeof(SEMAFORO));
    if(semaforo){
        semaforo->inicio = semaforo->final = NULL;
        semaforo->quantidade = 0;
    }
    return semaforo;
}

// Gera um nÃºmero aleatÃ³rio de 1 a num.
int selecionaAleatorio(int num){
    int r = rand() % num;
    return r;
}

// Cria carro
CARRO_NO * criaCarro(){
    CARRO_NO * carro = (CARRO_NO*) malloc(sizeof(CARRO_NO));
    if(carro){
        carro->prox = NULL;
    }

    return carro;
}

// Insere um nome aleatÃ³rio no carro.
char * insereNomeCarro(){
    int escolha = selecionaAleatorio(3);

    switch(escolha){
        case 0:
            return "corsa";
        case 1:
            return "siena";
        case 2:
            return "uno";
    }
}


// Verifica se o semÃ¡foro estÃ¡ vazio
int isVazio(SEMAFORO * semaforo){
    return (semaforo->quantidade == 0); // Retorna true (1) se a quantidade for 0.
}


// Insere o carro no semÃ¡foro.
char * insereCarro(SEMAFORO * semaforo, CARRO carro){
    CARRO_NO *novo_carro;
    char nome_carro[QUANTIDADE_NOME];
    strcpy(nome_carro, insereNomeCarro());
    
    novo_carro = criaCarro();
    if(novo_carro == NULL) return 0;

    //Cria o novo carro
    novo_carro->carro = carro;
    strcpy(novo_carro->carro.nome, nome_carro);

    // Lida se o semÃ¡foro estÃ¡ vazio ou nÃ£o.
    if(isVazio(semaforo)){
        semaforo->inicio = novo_carro;
    } else { 
        (semaforo->final)->prox = novo_carro;
    }

    semaforo->final = novo_carro;
    semaforo->quantidade++;
    return nome_carro; // Retorna o nome do carro se inserido.
}

// Remove um carro.
CARRO removeCarro(SEMAFORO * semaforo){
    CARRO_NO *auxiliar;
    CARRO carro = { "" };

    if(isVazio(semaforo)){
        return carro; //semaforo vazio.
    }
    carro = (semaforo->inicio)->carro;
    if(semaforo->inicio == semaforo->final){
        semaforo->final = NULL;
    }
    auxiliar = semaforo->inicio;

    semaforo->inicio = (semaforo->inicio)->prox;
    free(auxiliar);
    semaforo->quantidade--;
    return carro;
}

// Print com letra demorada para dar efeito de digitação.
void escreverDigitando(char * frase){
	int i;
	for(i=0; i<strlen(frase); i++){
		Sleep(50);
		printf("%c", frase[i]);
	}
}

int main() {
    
    srand(time(NULL));   // Para deixar os nÃºmeros randomicos.
    setlocale(LC_ALL, "");

    int escolha_aleatoria = 0;
    int contador_iteracoes = 1;
    char nome[QUANTIDADE_NOME];
    int aux = 1;

    // Cria os dois semÃ¡foros
    SEMAFORO * sinalA;
    sinalA = criaSemaforo();
    SEMAFORO * sinalB;
    sinalB = criaSemaforo();
    
    escreverDigitando("ALUNO: Matheus de Sousa Figueirêdo\n");
    Sleep(100);
    escreverDigitando("DISCIPLINA: Estrutura de Dados I\n");
    Sleep(100);
    escreverDigitando("PROFESSOR: Walace Bonfim\n");
    
    printf("\n");
	
	Sleep(1000);
    escreverDigitando("Tudo estava vazio no cruzamento da Av. Walace Bonfim até que de repente...\n\n");
    // Loop infinito do semÃ¡foro.
    while(1){
    	Sleep(3500);
        escolha_aleatoria = selecionaAleatorio(3);
        CARRO carro;
        
        if(contador_iteracoes == 10){
        	aux = aux == 1 ? 0 : 1;
        	contador_iteracoes = 1;	
		}
        
        printf(aux == 1 ? "O sinal ativo é o sinal A\n" : "O sinal ativo é o sinal B\n");

        switch(escolha_aleatoria){
            case 0:
                strcpy(nome, insereCarro(sinalA, carro));
                printf("Um %s entrou no sinal A\n", nome);
                break;
            case 1:
                strcpy(nome, insereCarro(sinalB, carro));
                printf("Um %s entrou no sinal B\n", nome);
                break;
            case 2:
                printf("Nada aconteceu.\n");
        }
        
         if(aux == 1 && sinalA->quantidade != 0){
        	printf("Um carro saiu do sinal A\n");
        	removeCarro(sinalA);
		} else if(aux == 0 && sinalB->quantidade != 0){
			printf("Um carro saiu do sinal B\n");
			removeCarro(sinalB);
		}
        
        printf("Temos %d carros no sinal A e %d carros no sinal B.\n", sinalA->quantidade, sinalB->quantidade);
        printf("O trânsito está na %dª iteração...\n", contador_iteracoes);
        contador_iteracoes++;
        
        printf("\n");
    }

    return 0;
}
