//
//  NodePilhaJogada.h
//  Chess
//
//  Created by Leonardo Tsuda on 2013-06-15.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#ifndef Chess_NodePilhaJogada_h
#define Chess_NodePilhaJogada_h

#include "Jogada.h" 

struct _nodePilhaJogada
{
    Jogada *jogada;
    struct _nodePilhaJogada *next;
};
typedef struct _nodePilhaJogada NodePilhaJogada;

NodePilhaJogada *criaNodePilhaJogada(Jogada *jogada, NodePilhaJogada *next);


#endif
