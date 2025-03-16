#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

int palindromo(){
    char palavra[30], copia[30];
    int i, tamanho, iguais = 0;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    tamanho = strlen(palavra);
    for(i = 0; i < strlen(palavra); i++){
        copia[i] = palavra[tamanho - 1];
        tamanho--;
    }

    copia[i] = '\0';
    tamanho = strlen(palavra);

    printf("Original: %s\nCopia: %s\n", palavra, copia);

    for(i = 0; i < tamanho; i++){
        if(palavra[i] == copia[i])
            iguais++;
    }
    if(tamanho == iguais)
        printf("\nEh palindroma...\n");
    else
        printf("\nNao eh palindroma...\n");

    return 0;
}

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, int valor) {
    if (estaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
        exit(EXIT_FAILURE);
    }
    p->dados[++p->topo] = valor;
}

int desempilhar(Pilha *p) {
    if (estaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        exit(EXIT_FAILURE);
    }
    return p->dados[p->topo--];
}

void inverterPilha(Pilha *p) {
    Pilha auxiliar1, auxiliar2;
    inicializar(&auxiliar1);
    inicializar(&auxiliar2);
    while (!estaVazia(p)) {
        empilhar(&auxiliar1, desempilhar(p));
    }
    while (!estaVazia(&auxiliar1)) {
        empilhar(&auxiliar2, desempilhar(&auxiliar1));
    }

    while (!estaVazia(&auxiliar2)) {
        empilhar(p, desempilhar(&auxiliar2));
    }
}

void imprimirPilha(Pilha *p) {
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

void menu(){
 Pilha p;
 inicializar(&p);
 int opcao, valor;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Imprimir\n");
        printf("4. Inverter\n");
        printf("5. Palindromo\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                system("cls||clear");
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                empilhar(&p,valor);
                break;
            case 2:
                system("cls||clear");
                printf("Elemento removido: %d\n",desempilhar(&p));
                break;
            case 3:
                imprimirPilha(&p);
                break;
            case 4:
                inverterPilha(&p);
                break;
            case 5:
                system("cls||clear");
                palindromo();
                break;
            case 6:
                return;
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
