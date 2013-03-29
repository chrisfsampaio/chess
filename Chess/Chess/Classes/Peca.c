//
//  Peca.c
//  Chess
//
//  Created by Christian on 3/25/13.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#include <stdio.h>
#include "Peca.h"
#include <string.h>

//o Torre:'t'
//o Cavalo:'h'
//o Bispo:'b'
//o Rainha:'q'
//o Rei:'k'
//o Peão:'p'


Peca *criaPeca(int linha, int coluna, char simbolo)
{
    Peca peca;
    peca.linha = linha;
    peca.coluna = coluna;
    peca.simbolo = simbolo;
    if (peca.simbolo == 't' || peca.simbolo == 'T')
    {
        strcpy(peca.nome, "Torre");
    }
    else if (peca.simbolo == 'h' || peca.simbolo == 'H')
    {
        strcpy(peca.nome, "Cavalo");
    }
    else if (peca.simbolo == 'b' || peca.simbolo == 'B')
    {
        strcpy(peca.nome, "Bispo");
    }
    else if (peca.simbolo == 'q' || peca.simbolo == 'Q')
    {
        strcpy(peca.nome, "Rainha");
    }
    else if (peca.simbolo == 'k' || peca.simbolo == 'K')
    {
        strcpy(peca.nome, "Rei");
    }
    else if (peca.simbolo == 'p' || peca.simbolo == 'P')
    {
        strcpy(peca.nome, "Peao");
    }
    else
    {
        printf("Simbolo invalido!\nInicie a peca com um dos simbolos:\nt, T, h, H, b, B, q, Q, k, K, p, P");
        return NULL;
    }
    
#warning Mike: Validar numero maximo da linha e coluna seguindo o exemplo de como foi feita a validacao de simbolo
    
    Peca *pointer = &peca;
    return pointer;
}

Peca *pecaNula()
{
    Peca peca;
    peca.simbolo = 'x';
    Peca *pointer = &peca;
    return pointer;
}

char lado(Peca *peca)
{
    if (peca->simbolo == 't' ||
        peca->simbolo == 'h' ||
        peca->simbolo == 'b' ||
        peca->simbolo == 'q' ||
        peca->simbolo == 'k' ||
        peca->simbolo == 'p')
    {
        return 'B';
    }
    return 'P';
}