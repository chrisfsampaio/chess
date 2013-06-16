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
//  PilhaJogada.h


#ifndef Chess_PilhaJogada_h
#define Chess_PilhaJogada_h

#include "NodePilhaJogada.h"

struct _pilhaJogada
{
    NodePilhaJogada *inicio;
};
typedef struct _pilhaJogada PilhaJogada;

PilhaJogada *criaPilhaJogada();
int addPilhaJogada(PilhaJogada *pilha, Jogada *jogada);

#endif
