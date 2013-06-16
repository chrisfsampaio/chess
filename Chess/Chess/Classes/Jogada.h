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
//  Jogada.h


#ifndef Chess_Jogada_h
#define Chess_Jogada_h

#include "Peca.h"
#include "Utilities.h"

struct _jogada
{
    Peca *pecaMovida;
    Peca *pecaCapturada;
    Coordenada origem;
    Coordenada destino;
    long startTimestamp;
    long endTimestamp;
};
typedef struct _jogada Jogada;

Jogada *criaJogada();
void comecaTempo(Jogada *jogada);
void finalizaTempo(Jogada *jogada);
double tempoJogada(Jogada *jogada);

#endif
