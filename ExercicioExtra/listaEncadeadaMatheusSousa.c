#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct elementos {
    char nome[50];
} t_elemento;

typedef struct no {
    t_elemento dado;
    struct no  * prox;
} t_no;

typedef t_no* t_lista;


t_no * criaNo();


t_no * getNo(t_lista lista, int pos) {          // RETORNA O ENDERECO DO ATUAL NO ###
    int n = 0;

    if (pos < 0)                                  // POSICAO INEXOSTENTE
        return 0;

    while (lista != NULL) {                     // CONTADOR
        if (n==pos)
            return lista;                       // RETORNA O NO
        lista = lista->prox;
        n++;
    }

    return 0;
}



int getTamanho(t_lista lista) {
    int n = 0;

    while (lista != NULL) {
        lista = lista->prox;
        n++;
    }
    return n;
}


int inserir(t_lista* lista, int pos, t_elemento dado) {

    t_no * p, * novo;

    if (pos == 0) {
        novo = criaNo();
        if (novo == NULL)       // ERRO DE MEM�RIA
            return 0;
        novo->dado = dado;      // O DADO E COLOCADO NO NO
        novo->prox = * lista;   // NOVO->PROX = NULL;
        *lista = novo;         //
        return 1;
    }

    p = getNo(* lista, pos-1);  // PROCURA O ULTIMO NO DA LISTA

    if (p == NULL)              // VERIFICA SE A POSICAO EXISTE
         return 0;

    novo = criaNo();            // CRIA UM NOVO NO

    if (novo == NULL)           // ERRO DE MEMORIA INSUFICIENTE
        return 0;

    novo->dado = dado;          // NOVO->DADO RECEBE O DADO
    novo->prox = p->prox;       // NOVO->DADO ERECEBE NULL
    p->prox = novo;             // P->PROX APONTA PARA O NOVO NO

    return 1;
}


void exibirLista(t_lista lista){

    int c = 1;

    while(lista->prox != NULL){
        printf("\nNo[%d]: ", c);
        printf("\n\tDado: %s", lista->dado.nome);
        lista = lista->prox;
        c++;
    }

    putchar('\n');
}


t_no * criaNo() {
    t_no * no = (t_no*) malloc(sizeof(t_no));

    if (no)
        no->prox = NULL;

    return no;
}


int isVazia(t_lista lista) {
    return (lista == NULL);
}


int remover(t_lista * lista, int pos) {
    t_no *anterior, *p;
    if (isVazia(*lista)) return 0;
    if (pos < 0) return 0;

    if (pos == 0) {
        p = *lista;
        *lista = p->prox;
    } else {
        anterior = getNo(*lista, pos-1);
        if (anterior == NULL)
            return 0;
        p = anterior->prox;
        if (p == NULL)
            return 0;
        anterior->prox = p->prox;
    }
    free(p);
    return 1;
}


int compara(t_elemento dado1, t_elemento dado2) {
    return strcmp(dado1.nome, dado2.nome);
}


int getPosicao(t_lista lista, t_elemento dado) {
    int n = 0;

    while (lista != NULL) {
        if (compara(lista->dado, dado)== 0)
            return n;
        lista = lista->prox;
        n++;
    }

    return -1;
}

t_elemento * getElemento(t_lista lista, int pos){

    t_no * no = getNo(lista, pos);
    if (no != NULL)
        return &(no->dado);
    else
        return NULL;
}



int print_menu(){

    int opcao;

    printf("# Aluno: Matheus de Sousa Figueirêdo\n");
    printf("# Disciplina: Estrutura de Dados I\n");
    printf("# Professor: Walace Bonfim\n");
    putchar('\n');
    printf("\t\t---Editor de lista---\n");
    printf("    1 - Exibe lista\n");
    printf("    2 - Inserir ordenadamente\n");
    printf("    3 - Remove pelo dado\n");
    printf("    4 - Remove pela posição\n");
    printf("    5 - Remove em um intervalo\n");
    printf("    6 - Exibe elemento\n");
    printf("    7 - Exibe posição do elemento\n");
    printf("    8 - Esvaziar\n");
    printf("    0 - Sair\n");
    putchar('\n');
    printf("\t# Sua escolha: ");
    scanf("%d", &opcao);

    return opcao;
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    t_lista I = criaNo();
    t_elemento _dado;
    t_elemento * _dado2;
    int posicao, pos_inicial, pos_final, c;

    while(1){

        int opcao = print_menu();

        switch(opcao){

        case 0:
            exit(0);
            break;

        case 1:
            exibirLista(I);
            break;

        case 2:
            printf("\n# Informe um dado que você quer inserir na lista: ");
            scanf("%s", _dado.nome);
            posicao = getTamanho(I);
            inserir(&I, posicao-1, _dado);
            break;

        case 3:
            printf("\n# Informe o dado que você deseja remover:  ");
            scanf("%s", _dado.nome);
            posicao = getPosicao(I, _dado);
            remover(&I, posicao);
            break;

        case 4:
            printf("\n# Informe a posição do item que você deseja remover: ");
            scanf("%d", &posicao);
            remover(&I, posicao-1);
            break;

        case 5:
            printf("\n# Informe a posição inicial: ");
            scanf("%d", &pos_inicial);
            printf("\n# Informe a posição final: ");
            scanf("%d", &pos_final);

            for(c = pos_inicial; c <= pos_final; c++){
                remover(&I, c-1);
            }


            break;

        case 6:
            printf("\n# Posição do elemento: ");
            scanf("%d", &posicao);
            _dado2 = getElemento(I, posicao-1);
            printf("%s\n", _dado2->nome);
            break;

        case 7:
            printf("\n# Dado: ");
            scanf("%s", _dado.nome);
            posicao = getPosicao(I, _dado);
            printf("* Posição: %d\n", posicao+1);
            break;

        case 8:
            free(I);
            I = criaNo();
            break;
        default:
            printf("! Opção Inválida !\n");
            break;

        }
    }

}