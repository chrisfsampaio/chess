//
//  NodePilhaJogada.c
//  Chess
//
//  Created by Leonardo Tsuda on 2013-06-15.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "NodePilhaJogada.h"

NodePilhaJogada *criaNodePilhaJogada(Jogada *jogada, NodePilhaJogada *next)
{
    NodePilhaJogada *node = (NodePilhaJogada *)malloc(sizeof(NodePilhaJogada));
    node->jogada = jogada;
    node->next = next;
    return node;
}

