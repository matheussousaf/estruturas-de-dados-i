#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>

#define TAMANHO_LISTA_DISCIPLINAS 3
#define TAMANHO_LISTA_ALUNOS 60

//Tipos
typedef struct Aluno Aluno;
typedef struct Disciplina Disciplina;

struct Disciplina{
    char nome[30];
    float nota;
    Aluno *alunoReferente;
};

struct Aluno{
    char matricula[15];
    Disciplina disciplinas[TAMANHO_LISTA_DISCIPLINAS];
};

typedef struct lista_Aluno{
    Aluno alunos[TAMANHO_LISTA_ALUNOS];
    int i;
}lista_Aluno;


//Funcionalidades
lista_Aluno criar(); //Cria a lista
Aluno cadastroAluno(Aluno *aluno); //Cadastra o aluno
void cadastrarNovoAluno(lista_Aluno *listaDeAlunos); //Opção de cadastrar no menu
void verHistorico(char matricula[], lista_Aluno *listaDeAlunos); //Opção de ver o histórico no menu

//Funções auxiliares
void clear();
void printMenu();

int main(){

    //Mudando typeset pra Português
    setlocale(LC_ALL, "Portuguese");

    //Inicializando a lista de alunos
    lista_Aluno listaDeAlunos = criar();

    int esc = 4;
    char matricula[15];

    //Cabeçalho
    printf("Aluno: Matheus de Sousa Figueirêdo\n");
    printf("Matrícula: 1820023833\n");
    printf("Ciências da Computação - Terceiro Período\n");
    printf("\n");

    //Loop principal
    while(1){
        if(esc == 0) break;
        
        //Printando o menu
        printf("\n");
        printMenu();
        printf("\n");

        printf("-> Escolha uma opção: ");
        scanf("%d", &esc);
        clear();

        switch (esc){
        case 0:
            printf("# Você saiu do programa!\n");
            break;
        case 1:
            cadastrarNovoAluno(&listaDeAlunos);
            break;
        case 2:
            printf("# Digite a matrícula: ");
            scanf("%s", matricula);
            clear();
            verHistorico(matricula, &listaDeAlunos);
            break;
        default:
            printf("# Comando não existente!\n");
        }
    }
    return 0;
}

void printMenu(){
    printf("===== MENU DE OPÇÕES =====\n");
    printf("1 - Cadastrar um aluno\n");
    printf("2 - Exibir históricos (por matricula)\n");
    printf("0 - Sair\n");
    printf("==========================\n");
}

Aluno cadastroAluno(Aluno *aluno){
    int i;

    printf("Digite aqui a matrícula: ");
    scanf("%s", aluno->matricula);
    clear();

    for (i = 0; i < 3; i++){
        printf("Nome da %dª disciplina: ", i+1); 
        scanf("%s" , aluno->disciplinas[i].nome);

        printf("Nota: "); 
        scanf("%f", &aluno->disciplinas[i].nota);
        clear();
    }

    return *aluno;
}

void cadastrarNovoAluno(lista_Aluno *listaDeAlunos){
    char esc = 's';

    //Preenchendo o listaAlunos
    while(1){
        if(esc == 'N' || esc == 'n') break;
        listaDeAlunos->alunos[listaDeAlunos->i] = cadastroAluno(&listaDeAlunos->alunos[listaDeAlunos->i]);
        listaDeAlunos->i++;

        printf("Deseja continuar? [S/N]: "); 
        scanf("%c", &esc);
        clear();
    }
}

void verHistorico(char *matricula, lista_Aluno *listaDeAlunos){
    int i, j;

    printf("# Pesquisando por matrícula '%s' em %d registros...\n", matricula, listaDeAlunos->i);
    sleep(1);

    for (i = 0; i < listaDeAlunos->i; i++){
        if(strcmp(matricula, listaDeAlunos->alunos[i].matricula) == 0){
        	printf("\n");
            printf("# Matrícula encontrada!\n");

            for (j = 0; j < 3; j++){
                printf("%dª Disciplina: %s\n", j+1, listaDeAlunos->alunos[i].disciplinas[j].nome);
                printf("Nota: %.2f\n", listaDeAlunos->alunos[i].disciplinas[j].nota);
            }
            return;
        }
        else printf("Posição atual: %d\n", i);
    }
    printf("# Nenhum aluno encontrado na base de dados!\n");
}

lista_Aluno criar(){
    lista_Aluno lista;
    lista.i = 0;

    return lista;
}

void clear(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
    fflush(stdin);
}
