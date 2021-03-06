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
//  Jogo.h

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
#include "ListaPeca.h"
#include "PilhaJogada.h"

/*  - Definindo o tamanho maximo para armazenar o nome    *
 *  de cada jogador                                       */
#define kComprimentoNome 30

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
    ListaPeca *lista;
    PilhaJogada *jogadas;
    char turno;
};

typedef struct _jogo Jogo;


/*          - Declarando os Headers da funcoes da TAD Jogo  */
Jogo *criaJogo(char *jog1, char *jog2, int carregaDoArquivo);
void display(Jogo *jogo, char *msg, int execJogada);
void executaJogada(Jogo *jogo);
void inverterTurno(Jogo *jogo);
void salvarJogo(Jogo *jogo);
void imprimirStats(Jogo *jogo);


#endif
