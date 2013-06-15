//
//  PilhaJogada.h
//  Chess
//
//  Created by Leonardo Tsuda on 2013-06-15.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

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
