//
//  Jogo.h
//  Chess
//
//  Copyright (c) 2013 VoIP. All rights reserved.
//
/*         - Tipo Abstrato de Dados -                   *
 *  - Arquivo Header que armazena todas as definicoes   *
 *  da TAD Jogo como: estrutura Jogo que armazena o     *
 *  estado do jogo em andamento.                        *
 *                                                      */

#ifndef Chess_Jogo_h
#define Chess_Jogo_h


/*         - Incluindo as TADs -    *
 *  - Tablueiro.h e Peca.h          */
#include "Tabuleiro.h"
#include "Peca.h"

/*  - Definindo o tamanho maximo para armazenar o nome    *
 *  de cada jogador                                       */
#define kComprimentoNome 25

/*         - Definindo a estrutura Jogo -                  *
 *  - Estrutura Jogo armazena o estado atual do jogo em    *
 *  andamento como: nome dos jogadores, titulo do jogo,    *
 *  o tabuleiro, as pecas e o turno (de quem eh a vez de   *
 *  jogar).                                                */
struct _jogo
{
    char jogador1[kComprimentoNome];
    char jogador2[kComprimentoNome];
    char titulo[(kComprimentoNome * 2) + 3];
    Tabuleiro *tabuleiro;
    Peca *pecas;
    char turno;
    //move in progress
};

typedef struct _jogo Jogo;


/*          - Declarando os Headers da funcoes da TAD Jogo  */
Jogo *criaJogo();
void display(Jogo *jogo, char *msg);
void executaJogada(Jogo *jogo);
void inverterTurno(Jogo *jogo);


#endif
