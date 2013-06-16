//
// Projeto: Jogo de Xadrez
// Disciplina: Estrutura de Dados 3∫ Semestre
// Grupo: VoIP
// Integrantes:
//   -  Abner Silva Zanetti
//   -  Cássio Otávio Ferreira Perbelini Castilho
//   -  Jaqueline Campaci Silva
//   -  Leonardo Henrique Tsuda
//   -  Murilo Natã Komirchuk de Jesus
//
//  ListaPeca.h


#ifndef Chess_ListaPeca_h
#define Chess_ListaPeca_h
#include "Node.h"
#include "Peca.h"

/* Estrutura header para a lista de pecas */
struct _listaPeca
{
    Node *inicio;
};
typedef struct _listaPeca ListaPeca;

ListaPeca* criaListaPeca();
int addPecaLista(ListaPeca *lista, Peca *peca);
Peca *pecaAtIndex(ListaPeca *lista, int index);

#endif
