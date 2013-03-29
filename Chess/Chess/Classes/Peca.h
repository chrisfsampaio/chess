//
//  Peca.h
//  Chess
//
//  Created by Christian on 3/25/13.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#ifndef Chess_Peca_h
#define Chess_Peca_h

struct _peca
{
    char nome[15];
    char simbolo;
    int linha;
    int coluna;
    
};

typedef struct _peca Peca;

Peca *criaPeca(int linha, int coluna, char simbolo);
Peca *pecaNula();

//retorna um char que indica o lado da peca
//'P' para pretas, e 'B' para brancas
char lado(Peca *peca);

#endif
