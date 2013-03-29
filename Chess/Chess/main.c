//
//  main.c
//  Chess
//
//  Created by Christian on 3/25/13.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "Jogo.h"
#include "Tabuleiro.h"
#include "Peca.h"

int main(int argc, const char * argv[])
{
    Peca pecas[3];
    pecas[0] = *criaPeca(0, 0, 'b');
    pecas[1] = *criaPeca(3, 3, 'q');
    pecas[2] = *criaPeca(6, 2, 'K');
    
    Tabuleiro *tabuleiro = criaTabuleiro(pecas, 3);
    
    for (int i = 0; i < 8; i++)
    {
        printf("|");
        for (int j = 0; j < 8; j++)
        {
            Peca peca = tabuleiro->pecas[i][j];
            if (peca.simbolo == 'x')
            {
                printf("  |");
            }
            else
            {
                char simbolo = peca.simbolo;
                printf(" %c |",simbolo);
            }
        }
        printf("\n------------------------\n");
    }
    
    printf("");
    return 0;
}

