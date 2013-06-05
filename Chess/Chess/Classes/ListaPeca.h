//
//  ListaPeca.h
//  Chess
//
//  Created by Christian on 6/4/13.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#ifndef Chess_ListaPeca_h
#define Chess_ListaPeca_h
#include "Node.h"
#include "Peca.h"

/* Estrutura header para a lista de pecas */
struct _listaPeca
{
    Node *inicio;
};
typedef struct _listaPeca ListaPeca;

ListaPeca* criaListaPeca();
int addPecaLista(ListaPeca *lista, Peca *peca);
Peca *pecaAtIndex(ListaPeca *lista, int index);

#endif
