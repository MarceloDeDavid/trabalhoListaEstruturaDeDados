#include <stdio.h>
#include <lista.h>
#include <stdbool.h>

// Código feito por Vitor Mendes e Marcelo De David

int main(){
    
    Lista listaC = {
    .lista = {1, 2, 3, 4, 5},
    .n = 5
};
    
    Lista listaA = CriaListaVazia();
    Lista listaB = CriaListaVazia();
    //listaC = insereNoInicio(listaC);
    //listaC = insereNoFinal(listaC);
    listaC = insereEmPosicaoLivre(listaC);

    //printf("Quantidade da lista A: %d\n", listaA.n);
    //printf("Quantidade da lista B: %d\n", listaB.n);
    
   exibeLista(listaC);
    return 0;
}
