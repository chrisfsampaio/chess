//
//  Tabuleiro.c
//  Chess
//
//  Copyright (c) 2013 NOME_DO_GRUPO. All rights reserved.
//
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

int existePecaNoCaminho(Tabuleiro *tabuleiro, Peca *peca, int linha, int coluna)
{
    int linhaOrigem = peca->linha;
    int colunaOrigem = peca->coluna;
    
    if (linhaOrigem != linha && colunaOrigem != coluna)
    {
        int dirX = coluna > colunaOrigem ? 1 : -1;
        int dirY = linha > linhaOrigem ? 1 : -1;
        for (int i = 1; i < abs(coluna - colunaOrigem); i++)
        {
            int nextX = colunaOrigem + i * dirX;
            int nextY = linhaOrigem + i * dirY;
            Peca *pecaCaminho = &tabuleiro->pecas[nextY][nextX];
            if (pecaCaminho->simbolo != 'x')
            {
                return 1;
            }
        }
        return 0;
    }
    else if (linhaOrigem == linha || colunaOrigem == coluna)
    {
        int dirX;
        if (coluna > colunaOrigem)
            dirX = 1;
        else if (coluna < colunaOrigem)
            dirX = -1;
        else if (coluna == colunaOrigem)
            dirX = 0;
        
        int dirY;
        if (linha > linhaOrigem)
            dirY = 1;
        else if (linha < linhaOrigem)
            dirY = -1;
        else if (linha == linhaOrigem)
            dirY = 0;
        
        int distance = coluna == colunaOrigem ? linha - linhaOrigem : coluna - colunaOrigem;
        
        for (int i = 1; i < abs(distance); i++)
        {
            int nextX = colunaOrigem + i * dirX;
            int nextY = linhaOrigem + i * dirY;
            Peca *pecaCaminho = &tabuleiro->pecas[nextY][nextX];
            if (pecaCaminho->simbolo != 'x')
            {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

