//
//  Peca.c
//  Chess
//
//  Created by Christian on 3/25/13.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Peca.h"

//o Torre:'t'
//o Cavalo:'h'
//o Bispo:'b'
//o Rainha:'q'
//o Rei:'k'
//o Peão:'p'


Peca *criaPeca(int linha, int coluna, char simbolo)
{
    Peca *peca = (Peca *)malloc(sizeof(Peca));
    peca->linha = linha;
    peca->coluna = coluna;
    peca->simbolo = simbolo;
    if (peca->simbolo == 't' || peca->simbolo == 'T')
    {
        strcpy(peca->nome, "Torre");
    }
    else if (peca->simbolo == 'h' || peca->simbolo == 'H')
    {
        strcpy(peca->nome, "Cavalo");
    }
    else if (peca->simbolo == 'b' || peca->simbolo == 'B')
    {
        strcpy(peca->nome, "Bispo");
    }
    else if (peca->simbolo == 'q' || peca->simbolo == 'Q')
    {
        strcpy(peca->nome, "Rainha");
    }
    else if (peca->simbolo == 'k' || peca->simbolo == 'K')
    {
        strcpy(peca->nome, "Rei");
    }
    else if (peca->simbolo == 'p' || peca->simbolo == 'P')
    {
        strcpy(peca->nome, "Peao");
    }
    else
    {
        printf("Simbolo %c invalido!\nInicie a peca com um dos simbolos:\n t, T, h, H, b, B, q, Q, k, K, p, P\n", simbolo);
        return pecaNula();
    }
    
#warning Mike: Validar numero maximo da linha e coluna seguindo o exemplo de como foi feita a validacao de simbolo
    
    return peca;
}

Peca *pecaNula()
{
    Peca *peca = (Peca *)malloc(sizeof(Peca));
    peca->simbolo = 'x';
    strcpy(peca->nome, "x");
    return peca;
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
        return 'P';
    }
    else if (peca->simbolo == 'x')
    {
        return 'X';
    }
    return 'B';
}

int movePeca(Peca *peca, int linha, int coluna)
{
    if (linha > 7 || coluna > 7)
    {
        return -1;
    }
    switch (peca->simbolo)
    {
        case 't':
        case 'T':
            if (abs(peca->coluna - coluna) == 0 || abs(peca->linha - linha == 0))
            {

                return 0;
            }            
            break;
            
        case 'b':
        case 'B':
            if (abs(peca->coluna - coluna) == abs(peca->linha - linha))
            {

                return 0;
            }
            break;
        
        case 'h':
        case 'H':
            if ((abs(peca->linha - linha) == 2 && abs(peca->coluna - coluna) == 1) ||
                (abs(peca->linha - linha) == 1 && abs(peca->coluna - coluna) == 2))
            {

                return 0;
            }
            break;
            
        case 'q':
        case 'Q':
            if ((abs(peca->coluna - coluna) == 0 || abs(peca->linha - linha == 0)) ||
                (abs(peca->coluna - coluna) == abs(peca->linha - linha)))
            {

                return 0;
            }
            break;
        
        case 'k':
        case 'K':
            if (abs(peca->linha - linha) <= 1 && abs(peca->coluna - coluna) <= 1)
            {

                return 0;
            }
            break;
        
        case 'P':
            if (peca->linha == 1 &&
                (linha - peca->linha == 1 ||
                linha - peca->linha == 2) &&
                coluna == peca->coluna)
            {
                return 0;
            }
            break;
            
        case 'p':
            if (peca->linha == 6 &&
                (peca->linha - linha == 1 ||
                 peca->linha - linha == 2) &&
                coluna == peca->coluna)
            {
                return 0;
            }
            break;
            
        default:
            break;
    }
    return -1;
}

