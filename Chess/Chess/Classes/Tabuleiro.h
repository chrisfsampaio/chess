//
//  Tabuleiro.h
//  Chess
//
//  Copyright (c) 2013 VoIP. All rights reserved.
//
/*         - Tipo Abstrato de Dados -                   *
 *  - Arquivo Header que armazena todas as definicoes   *
 *  da TAD Tabuleiro.                                   */

#ifndef Chess_Tabuleiro_h
#define Chess_Tabuleiro_h

/*         - Incluindo as TADs -    *
 *  - Peca.h                        */
#include "Peca.h"

/*         - Definindo a estrutura Tabuleiro -             *
 *  - Estrutura Tabuleiro armazena todas as informacoes    *
 *  do tabuleiro como a posicao de cada peca e seus movi-  *
 *  mentos.                                                */
struct _tabuleiro
{
    Peca pecas[8][8];
};

typedef struct _tabuleiro Tabuleiro;

/*         - Declarando os Headers da funcoes da TAD Tabuleiro  */
Tabuleiro *criaTabuleiro(Peca pecas[], int numeroDePecas);
Peca *getCasa(Tabuleiro *tabuleiro, int linha, int coluna);
Peca *setCasa(Tabuleiro *tabuleiro, int linha, int coluna, Peca *peca);
int existePecaNoCaminho(Tabuleiro *tabuleiro, Peca *peca, int linha, int coluna);

#endif
