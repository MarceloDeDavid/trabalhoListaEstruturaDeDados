#include <stdio.h>
#include <stdbool.h>

#define MAX 15

 typedef struct {
     int lista[MAX];
     int n;
 } Lista;
 
// Menus
void mostrarMenu(Lista *qualquer);
void mostrarMenuInsercoes(Lista *qualquer);
void mostrarMenuRemocoes(Lista *qualquer);
void mostrarMenuConsultas(Lista *qualquer);

// Operações Básicas
Lista CriaListaVazia();
bool verificaSeListaVazia(Lista *qualquer);
bool verificaSeListaCheia(Lista *qualquer);
int tamanhoLista(Lista *qualquer);

// Inserções
void insereNoInicio(Lista *qualquer);
void insereNoFinal(Lista *qualquer);
void insereEmPosicaoLivre(Lista *qualquer);

// Remoções
void removerDoInicio(Lista *qualquer);
void removerFinal(Lista *qualquer);
void removeEmPosicaoArbitraria(Lista *qualquer);
void removePorValor(Lista *qualquer);

// Consultas
int ConsultaPosicaoDoValor(Lista *qualquer);
void consultarPosicao(Lista *qualquer);
void exibeLista(Lista *qualquer);