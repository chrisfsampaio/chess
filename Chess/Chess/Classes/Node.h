//
//  Node.h
//  Chess
//
//  Created by Christian on 6/5/13.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#ifndef Chess_Node_h
#define Chess_Node_h
#include "Peca.h"

struct _node
{
    Peca *peca;
    struct _node *next;
};
typedef struct _node Node;

Node *criaNode(Peca *peca, Node *next);

#endif
