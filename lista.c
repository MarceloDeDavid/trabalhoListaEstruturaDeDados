#include <stdio.h>
#include <lista.h>
#include <stdbool.h>


    // ----------------------  OPERAÇÕES BÁSICAS   ----------------------

// mostrar menu.
void mostrarMenu(){
    printf("\n=== MENU ===\n");
    printf("1. Inserções\n");
    printf("2. Remoções\n");
    printf("3. Consultas\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}


// criar lista vazia.
Lista CriaListaVazia(){
    Lista novaLista;
    
    novaLista.n = 0;
    
    return novaLista;
}

// verificar se a lista está vazia.
bool VerificaSeListaVazia(Lista qualquer){

    if(qualquer.n == 0){
        return true;
    } else return false;
}

// verificar se a lista está cheia.
bool VerificaSeListaCheia(Lista qualquer){
    
    if(qualquer.n == MAX){
        return true;
    } else return false;
}

// obter tamanho da lista.
int tamanhoLista(Lista qualquer){
    return qualquer.n;
}


    // ----------------------   INSERÇÕES   ----------------------


// inserir no início.
Lista insereNoInicio(Lista qualquer){
    int x = 0;
    printf("Digite o número que você deseja inserir no início da sua lista: ");
    scanf("%d", &x);
    for(int i = qualquer.n; i>0; i--){
        qualquer.lista[i] = qualquer.lista[i-1];
    }
    qualquer.lista[0] = x;
    qualquer.n++;
    
    return qualquer;
}


// inserir no final.
Lista insereNoFinal(Lista qualquer){
    int x = 0;
    printf("Digite o número que você deseja inserir no final da sua lista: ");
    scanf("%d", &x);
    
    qualquer.lista[qualquer.n] = x;
    qualquer.n++;
    
    return qualquer;
}

// inserir em posição arbitrária.
Lista insereEmPosicaoLivre(Lista qualquer){
    int x = 0;
    int y = 0;
    printf("Digite o número que você deseja inserir na lista: ");
    scanf("%d", &x);
    printf("Agora digite em qual posição da lista você deseja inserir o número\n ");
    printf("(atualmente, você tem até a posição %d para inserir): ", qualquer.n+1);
    scanf("%d", &y);
    
    //nesse caso, não fiz a conversão de índice y-- porque assim eu permito
    //que seja inserido em qualquer lugar da lista inclusive ao final
    
    while(y < 1 || y > qualquer.n){ // y < 1 para não permitir índice negativo.
        printf("Posição inválida ou maior que o limite permitido da lista(%d), digite novamente:", qualquer.n-1);
        scanf("%d", &y);
    }
    
    y--;
    
    for( int k = qualquer.n; k > y; k--){
        
        qualquer.lista[k] = qualquer.lista[k-1];
    }   qualquer.lista[y] = x;
        qualquer.n++;
        return qualquer;
    }


    // ----------------------   REMOÇÕES   ----------------------

// remover no início.
Lista removerDoInicio(Lista qualquer) {
    if (qualquer.n > 0) {
        for (int i = 0; i < qualquer.n - 1; i++) {
            qualquer.lista[i] = qualquer.lista[i + 1];
        }
        qualquer.n--;
    }
    return qualquer;
}

// remover no final.
Lista removerFinal(Lista qualquer) {
    if (qualquer.n > 0) {
        qualquer.n--;
    }
    return qualquer;
}   

// remover em posição arbitrária.
Lista removeEmPosicaoArbitraria(Lista qualquer) {
    int posicao;
    printf("Digite a posição que você deseja remover: ");
    scanf("%d", &posicao);
    
    if (posicao < 1 || posicao > qualquer.n) {
        printf("Posição inválida.\n");
        return qualquer;
    }
    
    posicao--;
    
    for (int i = posicao; i < qualquer.n - 1; i++) {
        qualquer.lista[i] = qualquer.lista[i + 1];
    }
    
    qualquer.n--;
    return qualquer;
}

// remover elemento por valor.
Lista removePorValor(Lista qualquer) {
    int valor;
    printf("Digite o valor que você deseja remover: ");
    scanf("%d", &valor);

    for (int i = 0; i < qualquer.n; i++) {
        if (qualquer.lista[i] == valor) {
            for (int j = i; j < qualquer.n - 1; j++) {
                qualquer.lista[j] = qualquer.lista[j + 1];
            }
            qualquer.n--;
            return qualquer;
        }
    }

    printf("Valor não encontrado na lista.\n");
    return qualquer;
}

    // ----------------------   CONSULTAS   ----------------------


// buscar posição de um valor.
int ConsultaPosicaoDoValor(Lista qualquer) {
    int valor;
    printf("Digite o valor que você deseja consultar a posição: ");
    scanf("%d", &valor);

    for (int i = 0; i < qualquer.n; i++) {
        if (qualquer.lista[i] == valor) {
            printf("O valor %d está na posição %d.\n", valor, i + 1);
            return i + 1; // Retorna a posição (1-indexed)
        }
    }

    printf("Valor não encontrado na lista.\n");
    return -1; // Retorna -1 se o valor não for encontrado
}



// obter valor em uma posição.
void consultarPosicao(Lista qualquer) {
    int x = 0;
    printf("Digite a posição que você deseja consultar: (Max=%d) ", qualquer.n);
    scanf("%d", &x);
    x--;
    if(x > qualquer.n) {
        printf("Esta posição está ainda não foi preenchida. (Max=%d)", qualquer.n);
    } else {
        printf("%d\n", qualquer.lista[x]);
    }
}


// imprimir todos os elementos da lista.
void exibeLista(Lista qualquer){

    for(int i = 0; i<qualquer.n; i++){
        if(i==qualquer.n - 1){
           printf("%d ", qualquer.lista[i]); // porque na última repetição não quero imprimir a vírgula
        } else
        printf("%d, ", qualquer.lista[i]);
    }
}
