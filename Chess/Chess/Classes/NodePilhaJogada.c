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
//  NodePilhaJogada.c

#include <stdio.h>
#include <stdlib.h>
#include "NodePilhaJogada.h"

NodePilhaJogada *criaNodePilhaJogada(Jogada *jogada, NodePilhaJogada *next)
{
    NodePilhaJogada *node = (NodePilhaJogada *)malloc(sizeof(NodePilhaJogada));
    node->jogada = jogada;
    node->next = next;
    return node;
}

