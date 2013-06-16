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
//  Jogada.c


#include <stdio.h>
#include <stdlib.h>
#include "Jogada.h"
#include <time.h>

Jogada  *criaJogada()
{
    Jogada *jogada = (Jogada *)malloc(sizeof(Jogada));
    return jogada;
}

double tempoJogada(Jogada *jogada)
{
    double tempo = (double)jogada->endTimestamp - jogada->startTimestamp;
    return tempo;
}

