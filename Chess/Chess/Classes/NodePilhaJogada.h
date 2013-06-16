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
//  NodePilhaJogada.h


#ifndef Chess_NodePilhaJogada_h
#define Chess_NodePilhaJogada_h

#include "Jogada.h"

struct _nodePilhaJogada
{
    Jogada *jogada;
    struct _nodePilhaJogada *next;
};
typedef struct _nodePilhaJogada NodePilhaJogada;

NodePilhaJogada *criaNodePilhaJogada(Jogada *jogada, NodePilhaJogada *next);


#endif
