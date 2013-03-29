//
//  Tabuleiro.c
//  Chess
//
//  Created by Christian on 3/25/13.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#include <stdio.h>
#include "Tabuleiro.h"

Tabuleiro *criaTabuleiro(Peca pecas[], int numeroDePecas)
{
    Tabuleiro tabuleiro;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tabuleiro.pecas[i][j] = *pecaNula();
        }
    }
    for (int i = 0; i < numeroDePecas; i++)
    {
        Peca peca = pecas[i];
        tabuleiro.pecas[peca.coluna][peca.linha] = peca;
    }
    
    
//    for (int i = 0; i < 8; i++)
//    {
//        printf("|");
//        for (int j = 0; j < 8; j++)
//        {
//            Peca peca = tabuleiro.pecas[i][j];
//            if (peca.simbolo == 'x')
//            {
//                printf("  |");
//            }
//            else
//            {
//                char simbolo = peca.simbolo;
//                printf(" %c |",simbolo);
//            }
//        }
//        printf("\n------------------------\n");
//    }
    
    Tabuleiro *pointer = &tabuleiro;
    return pointer;
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

