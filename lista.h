#include <stdio.h>
#include <stdbool.h>

#define MAX 15

 typedef struct {
     int lista[MAX];
     int n;
 } Lista;
 
 // OPERAÇÕES BÁSICAS
 Lista CriaListaVazia(void);
 bool VerificaSeListaVazia(Lista qualquer);
 bool VerificaSeListaCheia(Lista qualquer);
 int tamanhoLista(Lista qualquer);

 // INSERÇÕES
 Lista insereNoInicio(Lista qualquer);
 Lista insereNoFinal(Lista qualquer);
 Lista insereEmPosicaoLivre(Lista qualquer);

 // REMOÇÕES
 Lista removerDoInicio(Lista qualquer);
 Lista removerFinal(Lista qualquer);
 Lista removeEmPosicaoArbitraria(Lista qualquer);
 Lista removePorValor(Lista qualquer);

 // CONSULTAS
 int ConsultaPosicaoDoValor(Lista qualquer);
 void consultarPosicao(Lista qualquer);
 void exibeLista(Lista qualquer);
 void consultarValorPorPosicao(Lista qualquer);
 int ConsultaPosicaoDoValor(Lista qualquer);
