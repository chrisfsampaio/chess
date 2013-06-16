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
//  Node.h


#ifndef Chess_Node_h
#define Chess_Node_h
#include "Peca.h"

struct _node
{
    Peca *peca;
    struct _node *next;
};
typedef struct _node Node;

Node *criaNode(Peca *peca, Node *next);

#endif
