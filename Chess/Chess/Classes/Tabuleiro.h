//
//  Tabuleiro.h
//  Chess
//
//  Copyright (c) 2013 NOME_DO_GRUPO. All rights reserved.
//
//

#ifndef Chess_Tabuleiro_h
#define Chess_Tabuleiro_h

#include "Peca.h"

struct _tabuleiro
{
    Peca pecas[8][8];
};

typedef struct _tabuleiro Tabuleiro;

Tabuleiro *criaTabuleiro(Peca pecas[], int numeroDePecas);
Peca *getCasa(Tabuleiro *tabuleiro, int linha, int coluna);
Peca *setCasa(Tabuleiro *tabuleiro, int linha, int coluna, Peca *peca);
int existePecaNoCaminho(Tabuleiro *tabuleiro, Peca *peca, int linha, int coluna);

#endif
