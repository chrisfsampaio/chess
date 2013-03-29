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

struct _jogo
{
    char titulo[50];
    //Pointer to the board
    //pieces array
    //move in progress
    //Turn (black or white)
};

typedef struct _jogo Jogo;

//Jogo criaJogo();
//void display(Jogo *jogo);
void executaJogada();



#endif
