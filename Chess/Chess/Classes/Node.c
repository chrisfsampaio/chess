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
//  Node.c

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

Node *criaNode(Peca *peca, Node *next)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->peca = peca;
    node->next = next;
    return node;
}
