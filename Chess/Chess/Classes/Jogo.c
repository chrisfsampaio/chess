//
//  Jogo.c
//  Chess
//
//  Created by Christian on 3/25/13.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Jogo.h"


///Christian TODO: clear screen whether on Windos or POSIX
//#ifdef _WIN32
//#define CLEAR() system("cls");
//#else
//#define CLEAR() system("clear");
//#endif

Jogo *criaJogo()
{
    Jogo *jogo  = (Jogo *)malloc(sizeof(Jogo));
    
    printf("Digite o nome do Jogador 1\n");
    fgets(jogo->jogador1, sizeof(jogo->jogador1), stdin);
    
    printf("\nDigite o nome do Jogador 2\n");
    fgets(jogo->jogador2, sizeof(jogo->jogador2), stdin);
    
    strcpy(jogo->titulo, strcat(jogo->jogador1, " X "));
    strcpy(jogo->titulo, strcat(jogo->titulo, jogo->jogador2));
    
    Peca pecas[0];
    Tabuleiro *tabuleiro = criaTabuleiro(pecas, 0);
    jogo->tabuleiro = tabuleiro;
    jogo->turno = 'B';
    
    return jogo;
}

void display(Jogo *jogo)
{
    printf("\n\n\n\n");
    for (int i = 0; i < 8; i++)
    {
        printf("|");
        for (int j = 0; j < 8; j++)
        {
            Peca peca = jogo->tabuleiro->pecas[i][j];
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
}