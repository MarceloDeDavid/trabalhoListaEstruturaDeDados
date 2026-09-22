#include <stdio.h>
#include <lista.h>
#include <stdbool.h>

// Código feito por Vitor Mendes e Marcelo De David

int main(){
    
    Lista listaC = {
    .lista = {1, 2, 3, 4, 5},
    .n = 5
};
    
    mostrarMenu(&listaC);
    
    return 0;
}
