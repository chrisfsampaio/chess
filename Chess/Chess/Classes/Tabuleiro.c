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
        tabuleiro->pecas[peca.coluna][peca.linha] = peca;
    }
    
    return tabuleiro;
}


#warning Mike: Implementar get e set casa
//Peca getCasa(Tabuleiro *tabuleiro, int linha, int coluna)
//{
//
//}

//Peca setCasa(Tabuleiro *tabuleiro, int linha, int coluna, Peca peca);
//{
//
//}

