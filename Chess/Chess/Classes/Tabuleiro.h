//
//  Tabuleiro.h
//  Chess
//
//  Created by Christian on 3/25/13.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
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
Peca getCasa(Tabuleiro *tabuleiro, int linha, int coluna);
Peca setCasa(Tabuleiro *tabuleiro, int linha, int coluna, Peca peca);

#endif
