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
    Coordenada Origem;
    Coordenada Destino;
    double  tempoJogada;
};
typedef struct _jogada Jogada;

Jogada *criaJogada();


#endif
