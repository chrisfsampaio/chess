//
//  Jogada.h
//  Chess
//
//  Created by Leonardo Tsuda on 2013-06-15.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

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
