#include <stdio.h>
#include <stdbool.h>

#define MAX 10

 typedef struct {
     int lista[MAX];
     int n;
 } Lista;
 
// Menus
void mostrarMenu(Lista *qualquer, bool *listaFoiCriada);
void mostrarMenuConsultas(Lista *qualquer, bool *listaFoiCriada);

// Operações Básicas
Lista CriaListaVazia();
bool verificaSeListaVazia(Lista *qualquer);
bool verificaSeListaCheia(Lista *qualquer);
int tamanhoLista(Lista *qualquer);

// Inserções
void inserir(Lista *qualquer);

// Remoções
void remover(Lista *qualquer);
void removerPorValor(Lista *qualquer);

// Consultas
int ConsultaPosicaoDoValor(Lista *qualquer);
void consultarPosicao(Lista *qualquer);
void exibeLista(Lista *qualquer);
