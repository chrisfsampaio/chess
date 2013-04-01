//
//  Peca.h
//  Chess
//
//  Copyright (c) 2013 NOME_DO_GRUPO. All rights reserved.
//
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
int movePeca(Peca *peca, int linha, int coluna);

//retorna um char que indica o lado da peca
//'P' para pretas, e 'B' para brancas
char lado(Peca *peca);


#endif
