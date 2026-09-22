#include <stdio.h>
#include <lista.h>
#include <stdbool.h>
#include <stdlib.h>


// ----------------------  MENUS  ----------------------

void mostrarMenu(Lista *qualquer) {
    int opcao;
    
    do {
        printf("\n--------------------------\n");
        printf("Lista atual: ");
        exibeLista(qualquer);
        printf("--------------------------\n");
        printf("\n=== MENU ===\n");
        printf("1. Inserções\n");
        printf("2. Remoções\n");
        printf("3. Consultas\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostrarMenuInsercoes(qualquer);
                break;
            case 2:
                mostrarMenuRemocoes(qualquer);
                break;
            case 3:
                mostrarMenuConsultas(qualquer);
                break;
            case 4:
                printf("Saindo do programa\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 4);
}

void mostrarMenuInsercoes(Lista *qualquer) {
    int opcao;
    do {
        printf("\n=== MENU DE INSERÇÕES ===\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no final\n");
        printf("3. Inserir em posição arbitrária\n");
        printf("4. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                insereNoInicio(qualquer);
                break;
            case 2:
                insereNoFinal(qualquer);
                break;
            case 3:
                insereEmPosicaoLivre(qualquer);
                break;
            case 4:
                return; 
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 4);
}

void mostrarMenuRemocoes(Lista *qualquer) {
    int opcao;
    do {
        printf("\n=== MENU DE REMOÇÕES ===\n");
        printf("1. Remover do início\n");
        printf("2. Remover do final\n");
        printf("3. Remover em posição arbitrária\n");
        printf("4. Remover por valor\n");
        printf("5. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                removerDoInicio(qualquer);
                break;
            case 2:
                removerFinal(qualquer);
                break;
            case 3:
                removeEmPosicaoArbitraria(qualquer);
                break;
            case 4:
                removePorValor(qualquer);
                break;
            case 5:
                return; 
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 5);
}

void mostrarMenuConsultas(Lista *qualquer) {
    int opcao;
    do {
        printf("\n=== MENU DE CONSULTAS ===\n");
        printf("1. Consultar posição de um valor\n");
        printf("2. Consultar valor em uma posição\n");
        printf("3. Exibir todos os elementos da lista\n");
        printf("4. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                ConsultaPosicaoDoValor(qualquer);
                break;
            case 2:
                consultarPosicao(qualquer);
                break;
            case 3:
                printf("Lista atual: ");
                exibeLista(qualquer);
                break;
            case 4:
                return; 
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 4);
}


// ----------------------  OPERAÇÕES BÁSICAS  ----------------------


bool verificaSeListaVazia(Lista *qualquer){
    return qualquer->n == 0;
}

bool verificaSeListaCheia(Lista *qualquer){
    return qualquer->n == MAX;
}

int tamanhoLista(Lista *qualquer){
    return qualquer->n;
}

// ----------------------  INSERÇÕES  ----------------------


void insereNoInicio(Lista *qualquer){
    if (verificaSeListaCheia(qualquer)) {
        printf("Erro: A lista esta cheia!\n");
        return;
    }
    
    int x = 0;
    printf("Digite o numero que deseja inserir no inicio: ");
    scanf("%d", &x);
    
    for(int i = qualquer->n; i > 0; i--){
        qualquer->lista[i] = qualquer->lista[i-1];
    }
    qualquer->lista[0] = x;
    qualquer->n++;
}

void insereNoFinal(Lista *qualquer){
    if (verificaSeListaCheia(qualquer)) {
        printf("Erro: A lista esta cheia!\n");
        return;
    }
    
    int x = 0;
    printf("Digite o numero que deseja inserir no final: ");
    scanf("%d", &x);
    
    qualquer->lista[qualquer->n] = x;
    qualquer->n++;
}

void insereEmPosicaoLivre(Lista *qualquer){
    if (verificaSeListaCheia(qualquer)) {
        printf("Erro: A lista esta cheia!\n");
        return;
    }
    
    int x = 0, y = 0;
    printf("Digite o numero que deseja inserir: ");
    scanf("%d", &x);
    
    printf("Digite a posicao de insercao (de 1 a %d): ", qualquer->n + 1);
    scanf("%d", &y);
    
    while(y < 1 || y > qualquer->n + 1){ 
        printf("Posicao invalida. Digite novamente (1 a %d): ", qualquer->n + 1);
        scanf("%d", &y);
    }
    
    y--; 
    
    for(int k = qualquer->n; k > y; k--){
        qualquer->lista[k] = qualquer->lista[k-1];
    }
    
    qualquer->lista[y] = x;
    qualquer->n++;
}


// ----------------------  REMOÇÕES  ----------------------

void removerDoInicio(Lista *qualquer) {
    if (verificaSeListaVazia(qualquer)) {
        printf("A lista ja esta vazia.\n");
        return;
    }
    
    for (int i = 0; i < qualquer->n - 1; i++) {
        qualquer->lista[i] = qualquer->lista[i + 1];
    }
    qualquer->n--;
    printf("Primeiro elemento removido.\n");
}

void removerFinal(Lista *qualquer) {
    if (verificaSeListaVazia(qualquer)) {
        printf("A lista ja esta vazia.\n");
        return;
    }
    
    qualquer->n--;
    printf("Ultimo elemento removido.\n");
}   

void removeEmPosicaoArbitraria(Lista *qualquer) {
    if (verificaSeListaVazia(qualquer)) {
        printf("A lista ja esta vazia.\n");
        return;
    }

    int posicao;
    printf("Digite a posicao que deseja remover (1 a %d): ", qualquer->n);
    scanf("%d", &posicao);
    
    if (posicao < 1 || posicao > qualquer->n) {
        printf("Posicao invalida.\n");
        return;
    }
    
    posicao--; 
    
    for (int i = posicao; i < qualquer->n - 1; i++) {
        qualquer->lista[i] = qualquer->lista[i + 1];
    }

    qualquer->n--;
    printf("Elemento da posicao removido.\n");
}

void removePorValor(Lista *qualquer) {
    if (verificaSeListaVazia(qualquer)) {
        printf("A lista ja esta vazia.\n");
        return;
    }

    int valor;
    printf("Digite o valor que voce deseja remover: ");
    scanf("%d", &valor);

    for (int i = 0; i < qualquer->n; i++) {
        if (qualquer->lista[i] == valor) {
            for (int j = i; j < qualquer->n - 1; j++) {
                qualquer->lista[j] = qualquer->lista[j + 1];
            }
            qualquer->n--;
            printf("Valor %d removido com sucesso.\n", valor);
            return;
        }
    }

    printf("Valor nao encontrado na lista.\n");
}


// ----------------------  CONSULTAS  ----------------------

int ConsultaPosicaoDoValor(Lista *qualquer) {
    int valor;
    printf("Digite o valor que deseja consultar a posicao: ");
    scanf("%d", &valor);

    for (int i = 0; i < qualquer->n; i++) {
        if (qualquer->lista[i] == valor) {
            printf("O valor %d esta na posicao %d.\n", valor, i + 1);
            return i + 1; 
        }
    }

    printf("Valor nao encontrado na lista.\n");
    return -1;
}

void consultarPosicao(Lista *qualquer) {
    int x = 0;
    if (verificaSeListaVazia(qualquer)) {
        printf("A lista esta vazia.\n");
        return;
    }

    printf("Digite a posicao que deseja consultar (1 a %d): ", qualquer->n);
    scanf("%d", &x);
    
    if(x < 1 || x > qualquer->n) {
        printf("Posicao invalida.\n");
    } else {
        printf("Valor na posicao %d: %d\n", x, qualquer->lista[x-1]);
    }
}

void exibeLista(Lista *qualquer){
    if (qualquer->n == 0) {
        printf("[ Vazia ]\n");
        return;
    }

    printf("[ ");
    for(int i = 0; i < qualquer->n; i++){
        if(i == qualquer->n - 1){
           printf("%d", qualquer->lista[i]);
        } else {
           printf("%d, ", qualquer->lista[i]);
        }
    }
    printf(" ]\n");
}