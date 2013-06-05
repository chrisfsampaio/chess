//
//  Node.c
//  Chess
//
//  Created by Christian on 6/5/13.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

Node *criaNode(Peca *peca, Node *next)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->peca = peca;
    node->next = next;
    return node;
}