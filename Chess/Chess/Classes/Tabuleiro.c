//
//  Tabuleiro.c
//  Chess
//
//  Created by Christian on 3/25/13.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Tabuleiro.h"

Tabuleiro *criaTabuleiro(Peca pecas[], int numeroDePecas)
{
    Tabuleiro *tabuleiro = (Tabuleiro *)malloc(sizeof(Tabuleiro));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tabuleiro->pecas[i][j] = *pecaNula();
        }
    }
    for (int i = 0; i < numeroDePecas; i++)
    {
        Peca peca = pecas[i];
        tabuleiro->pecas[peca.linha][peca.coluna] = peca;
    }
    
    return tabuleiro;
}

Peca *getCasa(Tabuleiro *tabuleiro, int linha, int coluna)
{
    if (linha > 7 || coluna > 7 || linha < 0 || coluna < 0)
    {
        printf("Coordenada invalida!");
        return pecaNula();
    }
    return &tabuleiro->pecas[linha][coluna];
}

Peca *setCasa(Tabuleiro *tabuleiro, int linha, int coluna, Peca *peca)
{
    Peca pecaDestino = *getCasa(tabuleiro, linha, coluna);
    if (lado(peca) == lado(&pecaDestino))
    {
        return NULL;
    }
    tabuleiro->pecas[peca->linha][peca->coluna] = *pecaNula();
    tabuleiro->pecas[linha][coluna] = *peca;
    tabuleiro->pecas[linha][coluna].linha = linha;
    tabuleiro->pecas[linha][coluna].coluna = coluna;
    
    Peca *pecaRetorno = &pecaDestino;
    return pecaRetorno;
}

