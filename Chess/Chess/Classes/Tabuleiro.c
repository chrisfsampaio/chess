//
// Projeto: Jogo de Xadrez
// Disciplina: Estrutura de Dados 3∫ Semestre
// Grupo: VoIP
// Integrantes:
//   -  Abner Silva Zanetti
//   -  Cássio Otávio Ferreira Perbelini Castilho
//   -  Jaqueline Campaci Silva
//   -  Leonardo Henrique Tsuda
//   -  Murilo Natã Komirchuk de Jesus
//
//  Tabuleiro.c

/*         - Tipo Abstrato de Dados -                   *
 *  - Arquivo que armazena todas as implementacoes das  *
 *   funcoes da TAD Tabuleiro.                          */

/*         - Incluindo as TADs e Bibliotecas -              *
 *  - Tablueiro.h                                           *
 *  - Bibliotecas que seram utilizadas durante as imple-    *
 *  mentacoes.                                              */
#include <stdio.h>
#include <stdlib.h>
#include "Tabuleiro.h"

/*         - Funcao criaTabuleiro() -                       *
 *  - Cria ponteiro para Tabuleiro e aloca tamanho da       *
 *  variavel Tabuleiro;                                     *
 *  - Preenche tabuleiro com valores apontador por          *
 *  pecaNula();                                             *
 *  - Preenche o lado de cada time com suas respectivas     *
 *  pecas;                                                  *
 *  - Retorna tabuleiro completo.                           */
Tabuleiro *criaTabuleiro(Peca *pecas[], int numeroDePecas)
{
    Tabuleiro *tabuleiro = (Tabuleiro *)malloc(sizeof(Tabuleiro));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tabuleiro->pecas[i][j] = NULL;
        }
    }
    for (int i = 0; i < numeroDePecas; i++)
    {
        Peca *peca = pecas[i];
        tabuleiro->pecas[peca->linha][peca->coluna] = pecas[i];
    }

    return tabuleiro;
}

/*         - Funcao getCasa() -                             *
 *  - Verifica se a casa nao ultrapassou as coodernadas do  *
 *  tabuleiro e envia mensagem caso ultrapasse;             *
 *  pecas;                                                  *
 *  - Retorna o endereco da jogada realizada.               */
Peca *getCasa(Tabuleiro *tabuleiro, int linha, int coluna)
{
    if (linha > 7 || coluna > 7 || linha < 0 || coluna < 0)
    {
        printf("Coordenada invalida!");
        return NULL;
    }
    return tabuleiro->pecas[linha][coluna];
}

/*         - Funcao setCasa() -                             *
 *  - Cria pecaDestino do tipo estrutura Peca e armazena    *
 *  o conteudo apontado por getCasa;                        *
 *  -   */
Peca *setCasa(Tabuleiro *tabuleiro, int linha, int coluna, Peca *peca)
{
    Peca *pecaDestino = getCasa(tabuleiro, linha, coluna);
    if (lado(peca) == lado(pecaDestino))
    {
        return -1;
    }
    tabuleiro->pecas[peca->linha][peca->coluna] = NULL;
    tabuleiro->pecas[linha][coluna] = peca;
    peca->linha = linha;
    peca->coluna = coluna;

    printf("peca modificada %p", peca);
    
    Peca *pecaRetorno = pecaDestino;
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
            Peca *pecaCaminho = tabuleiro->pecas[nextY][nextX];
            if (pecaCaminho != NULL)
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
            Peca *pecaCaminho = tabuleiro->pecas[nextY][nextX];
            if (pecaCaminho != NULL)
            {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}
