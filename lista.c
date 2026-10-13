#include <stdio.h>
#include <lista.h>
#include <stdbool.h>
#include <stdlib.h>


// ----------------------  MENUS  ----------------------

void mostrarMenu(Lista *qualquer, bool *listaFoiCriada) {
    int opcao;
    
    do {
        
        if (*listaFoiCriada) {
            
            printf("--------------------------\n");
            printf("Lista atual: ");
            exibeLista(qualquer);
            printf("--------------------------");
        } 
        
        printf("\n=== MENU ===\n");
        printf("1. Criar lista vazia\n");
        printf("2. Inserir\n");
        printf("3. Remover\n");
        printf("4. Remover por valor\n");
        printf("5. Consultas\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("\n\n");

        switch (opcao) {
            case 1:
                *qualquer = CriaListaVazia();
                *listaFoiCriada = true;
                break;
            case 2:
                if (!*listaFoiCriada) {
                    printf("Lista não criada. Crie uma lista antes de efetuar as operações.\n");
                    break;
                }
                inserir(qualquer);
                break;
            case 3:
                if (!*listaFoiCriada) {
                    printf("Lista não criada. Crie uma lista antes de efetuar as operações.\n");
                    break;
                }
                remover(qualquer);
                break;
            case 4:
                if (!*listaFoiCriada) {
                    printf("Lista não criada. Crie uma lista antes de efetuar as operações.\n");
                    break;
                }
                removerPorValor(qualquer);
                break;
            case 5:
                mostrarMenuConsultas(qualquer, listaFoiCriada);
                break;
            case 6:
                printf("Saindo do programa\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 6);
}

void mostrarMenuConsultas(Lista *qualquer, bool *listaFoiCriada) {
    int opcao;
    
    if (!*listaFoiCriada) {
        printf("Lista não criada. Crie uma lista antes de efetuar as operações.\n");
        return;
    }
    
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


Lista CriaListaVazia(){
    Lista novaLista;
    
    novaLista.n = 0;
    
    return novaLista;
}


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

void inserir(Lista *qualquer){
    if (verificaSeListaCheia(qualquer)) {
        printf("Erro: A lista está cheia!\n");
        return;
    }
    
    int x = 0, y = 0;
    printf("Digite o numero que deseja inserir: ");
    scanf("%d", &x);
    
    printf("Digite a posição de inserção (de 1 a %d): ", qualquer->n + 1);
    scanf("%d", &y);
    
    while(y < 1 || y > qualquer->n + 1){ 
        printf("Posição inválida. Digite novamente (1 a %d): ", qualquer->n + 1);
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

void remover(Lista *qualquer) {
    if (verificaSeListaVazia(qualquer)) {
        printf("A lista ja está vazia.\n");
        return;
    }

    int posicao;
    printf("Digite a posição que deseja remover (1 a %d): ", qualquer->n);
    scanf("%d", &posicao);
    
    if (posicao < 1 || posicao > qualquer->n) {
        printf("Posição inválida.\n");
        return;
    }
    
    posicao--; 
    
    for (int i = posicao; i < qualquer->n - 1; i++) {
        qualquer->lista[i] = qualquer->lista[i + 1];
    }

    qualquer->n--;
    printf("Elemento da posição %d removido.\n", posicao + 1);
}

void removerPorValor(Lista *qualquer) {
    if (verificaSeListaVazia(qualquer)) {
        printf("A lista ja está vazia.\n");
        return;
    }

    int valor;
    printf("Digite o valor que você deseja remover: ");
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

    printf("Valor %d não encontrado na lista.\n", valor);
}


// ----------------------  CONSULTAS  ----------------------

int ConsultaPosicaoDoValor(Lista *qualquer) {
    int valor;
    printf("Digite o valor que deseja consultar a posição: ");
    scanf("%d", &valor);

    for (int i = 0; i < qualquer->n; i++) {
        if (qualquer->lista[i] == valor) {
            printf("O valor %d esta na posição %d.\n", valor, i + 1);
            return i + 1; 
        }
    }

    printf("Valor %d não encontrado na lista.\n", valor);
    return -1;
}

void consultarPosicao(Lista *qualquer) {
    int x = 0;
    if (verificaSeListaVazia(qualquer)) {
        printf("A lista está vazia.\n");
        return;
    }

    printf("Digite a posição que deseja consultar (1 a %d): ", qualquer->n);
    scanf("%d", &x);
    
    if(x < 1 || x > qualquer->n) {
        printf("Posição inválida.\n");
    } else {
        printf("Valor na posição %d: %d\n", x, qualquer->lista[x-1]);
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
