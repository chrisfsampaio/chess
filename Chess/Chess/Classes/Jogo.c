//
//  Jogo.c
//  Chess
//
//  Copyright (c) 2013 NOME_DO_GRUPO. All rights reserved.
//
/*         - Tipo Abstrato de Dados -                   *
 *  - Arquivo que armazena todas as implementacoes das  *
 *   funcoes da TAD Jogo.                               */


/*         - Incluindo as TADs e Bibliotecas -              *
 *  - Tablueiro.h e Peca.h;                                 *
 *  - Bibliotecas que seram utilizadas durante as imple-    *
 *  mentacoes.                                              */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Jogo.h"
#include "Utilities.h"


///Christian TODO: clear screen whether on Windos or POSIX
//#ifdef _WIN32
//#define CLEAR() system("cls");
//#else
//#define CLEAR() system("clear");
//#endif

/*         - Funcao criaJogo() -                            *
 *  - Cria estrutura do tipo Jogo do tamanho de Jogo        *
 *  - Armazena e mostra na tela o nome de cada jogador e    *
 *  o titulo do jogo;                                       *
 *  - Verifica se os nomes do jogadores sao diferentes;     *
 *  - Cria todas as pecas e armazena no vetor pecas[32];    *
 *  - Cria tabuleiro e coloca as pecas nos lugares;         *
 *  - Inicia o turno das pecas Brancas (Regra do Xadrez).   */
Jogo *criaJogo()
{
    Jogo *jogo  = (Jogo *)malloc(sizeof(Jogo));
        
    printf("Digite o nome do Jogador 1\n");
    fgets(jogo->jogador1, sizeof(jogo->jogador1), stdin);
    
    do {
    printf("\nDigite o nome do Jogador 2\nOBS: Deve ser diferente do Jogador 1\n");
    fgets(jogo->jogador2, sizeof(jogo->jogador2), stdin);
    } while (strcmp(jogo->jogador1, jogo->jogador2) == 0);
    
    
    //strcpy(jogo->titulo, strcat(jogo->jogador1, " X "));
    //strcpy(jogo->titulo, strcat(jogo->titulo, jogo->jogador2));
    
    Peca pecas[32];
    pecas[0] = *criaPeca(0, 0, 'T');
    pecas[1] = *criaPeca(0, 1, 'H');
    pecas[2] = *criaPeca(0, 2, 'B');
    pecas[3] = *criaPeca(0, 3, 'Q');
    pecas[4] = *criaPeca(0, 4, 'K');
    pecas[5] = *criaPeca(0, 5, 'B');
    pecas[6] = *criaPeca(0, 6, 'H');
    pecas[7] = *criaPeca(0, 7, 'T');
    pecas[8] = *criaPeca(1, 0, 'P');
    pecas[9] = *criaPeca(1, 1, 'P');
    pecas[10] = *criaPeca(1, 2, 'P');
    pecas[11] = *criaPeca(1, 3, 'P');
    pecas[12] = *criaPeca(1, 4, 'P');
    pecas[13] = *criaPeca(1, 5, 'P');
    pecas[14] = *criaPeca(1, 6, 'P');
    pecas[15] = *criaPeca(1, 7, 'P');
    pecas[16] = *criaPeca(6, 0, 'p');
    pecas[17] = *criaPeca(6, 1, 'p');
    pecas[18] = *criaPeca(6, 2, 'p');
    pecas[19] = *criaPeca(6, 3, 'p');
    pecas[20] = *criaPeca(6, 4, 'p');
    pecas[21] = *criaPeca(6, 5, 'p');
    pecas[22] = *criaPeca(6, 6, 'p');
    pecas[23] = *criaPeca(6, 7, 'p');
    pecas[24] = *criaPeca(7, 0, 't');
    pecas[25] = *criaPeca(7, 1, 'h');
    pecas[26] = *criaPeca(7, 2, 'b');
    pecas[27] = *criaPeca(7, 3, 'q');
    pecas[28] = *criaPeca(7, 4, 'k');
    pecas[29] = *criaPeca(7, 5, 'b');
    pecas[30] = *criaPeca(7, 6, 'h');
    pecas[31] = *criaPeca(7, 7, 't');
    
    Tabuleiro *tabuleiro = criaTabuleiro(pecas, 32);
    jogo->tabuleiro = tabuleiro;
    jogo->turno = 'B';
    
    return jogo;
}

void display(Jogo *jogo, char *msg)
{
    printf("\n\n\n\n\t\t\t\t\t\t\t\t%s\n\t", jogo->jogador1);
    for (int i = 0; i < 8; i++)
    {
        char letra = numeroParaLetra(i);
        printf("\t%c\t", letra);
    }
    printf("\n\t-----------------------------------------------------------------\n");
    for (int i = 0; i < 8; i++)
    {
        printf("\t|");
        for (int j = 0; j < 8; j++)
        {
            printf("\t\t|");
        }
        printf("\n%d\t|",i + 1);
        for (int j = 0; j < 8; j++)
        {
            Peca peca = jogo->tabuleiro->pecas[i][j];
            if (peca.simbolo == 'x')
            {
                printf("\t\t|");
            }
            else
            {
                char simbolo = peca.simbolo;
                printf("\t%c\t|",simbolo);
            }
        }
        printf("\t%d\n\t|",i + 1);
        for (int j = 0; j < 8; j++)
        {
            printf("\t\t|");
        }        
        printf("\n\t-----------------------------------------------------------------\n");
    }
    printf("\t");
    for (int i = 0; i < 8; i++)
    {
        char letra = numeroParaLetra(i);
        printf("\t%c\t", letra);
    }
    printf("\n\t\t\t\t\t\t\t\t%s\n%s\n", jogo->jogador2, msg);
    executaJogada(jogo);
}

void executaJogada(Jogo *jogo)
{
    char jogada[6];
    char msgJogador[40];
    jogo->turno == 'B' ? strcpy(msgJogador, jogo->jogador1) : strcpy(msgJogador, jogo->jogador2);
    strcat(msgJogador, ", digite a sua jogada (ex: 2a 3b)\n");
    printf("%s",msgJogador);
    
    fgets(jogada, sizeof(jogada), stdin);
    flush_in();
    fflush(stdin);
    
    int linhaOrigem = ((int)jogada[0] - '0') - 1;
    int colunaOrigem = letraParaNumero(jogada[1]);
    
    int linhaDestino = ((int)jogada[3] - '0') - 1;
    int colunaDestino = letraParaNumero(jogada[4]);
    
    
//#warning Christian: implement the rules to move a piece
    
    int jogadaOk = 0;
    int fimDeJogo = 0;
    Peca peca = jogo->tabuleiro->pecas[linhaOrigem][colunaOrigem];
    char msg[200];
    strcpy(msg, "");
    if (peca.simbolo != 'x' && lado(&peca) == jogo->turno)
    {
        if (movePeca(&peca, linhaDestino, colunaDestino) == 0)
        {
            int pecaNoCaminho = existePecaNoCaminho(jogo->tabuleiro, &peca, linhaDestino, colunaDestino);
            if (peca.simbolo == 'h' || peca.simbolo == 'H' || pecaNoCaminho == 0)
            {
                Peca *pecaRetorno = setCasa(jogo->tabuleiro, linhaDestino, colunaDestino, &peca);
                if (pecaRetorno == 0)
                {
                    strcat(msg, "Jogada invalida, existe uma peca sua no destino");
                }
                else
                {
                    jogadaOk = 1;
                    Peca pecaCapturada = *pecaRetorno;
                    if (pecaCapturada.simbolo != 'x')
                    {
                        strcat(msg, "A peca -");
                        strcat(msg, pecaCapturada.nome);
                        strcat(msg, "- de -");
                        strcat(msg, jogo->turno == 'B' ? jogo->jogador2 : jogo->jogador1);
                        strcat(msg, "- foi capturada!");
                        if (pecaCapturada.simbolo == 'k' || pecaCapturada.simbolo == 'K')
                        {
                            strcat(msg, "\nO jogador -");
                            strcat(msg, jogo->turno == 'B' ? jogo->jogador1 : jogo->jogador2);
                            strcat(msg, "- venceu!!");
                            fimDeJogo = 1;
                        }
                    }
                }
            }
            else
            {
                strcat(msg, "Existe uma peca no caminho.");
            }
        }
        else
        {
            strcat(msg, "A peca -");
            //strcat(msg, peca.nome);
            strcat(msg, "- nao consegue fazer o movimento solicitado");
        }
    }
    else
    {
        strcat(msg, "Cordenada de origem invalida.");
    }
    
    if (jogadaOk)
    {
        inverterTurno(jogo);
    }
    if (fimDeJogo)
    {
        printf("%s", msg);
        exit(0);
    }
    display(jogo, msg);
}

void inverterTurno(Jogo *jogo)
{
    if (jogo->turno == 'B')
        jogo->turno = 'P';
    else
        jogo->turno = 'B';
}

