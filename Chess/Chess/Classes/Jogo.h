//
//  Jogo.h
//  Chess
//
//  Created by Christian on 3/25/13.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#ifndef Chess_Jogo_h
#define Chess_Jogo_h

#include "Tabuleiro.h"
#include "Peca.h"

#define kComprimentoNome 25

struct _jogo
{
    char jogador1[kComprimentoNome];
    char jogador2[kComprimentoNome];
    char titulo[(kComprimentoNome * 2) + 3];
    Tabuleiro *tabuleiro;
    Peca *pecas;
    char turno;
    //move in progress
};

typedef struct _jogo Jogo;

Jogo *criaJogo();
void display(Jogo *jogo);
void executaJogada(Jogo *jogo, Peca *peca, int coluna, int linha);


#endif
