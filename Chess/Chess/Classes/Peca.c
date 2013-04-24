//
//  Peca.c
//  Chess
//
//  Copyright (c) 2013 VoIP. All rights reserved.
//
/*         - Tipo Abstrato de Dados -                   *
 *  - Arquivo Header que armazena todas as definicoes   *
 *  da TAD Peca como: estrutura Peca que armazena os    *
 *  atributos das pecas.                                */

/*         - Incluindo as TADs e Bibliotecas -              *
 *  - Peca.h;                                 *
 *  - Bibliotecas que seram utilizadas durante as imple-    *
 *  mentacoes.                                              */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Peca.h"

/*         - Funcao criaPeca() -                            *
 *  - Cria uma variavel do tipo estrutura Peca do tamanho   *
 *  de Peca.                                                *
 *  - Seta as variaveis linha, coluna e simbolo de acordo   *
 *  com os valores recebidos por referencia.                *
 *  - Verifica o simbolo recebido e copia o nome para a     *
 *  variavel peca->simbolo para todos os simbolos.          *
 *  - Caso os simbolos sejam incorretos, imprime mensagem   *
 *  de erro.                                                *
 *  - Caso variavel peca->linha ou peca->coluna seja maior  *
 *  que o tabuleiro, imprime mensagem de erro.              */
Peca *criaPeca(int linha, int coluna, char simbolo)
{
    Peca *peca = (Peca *)malloc(sizeof(Peca));
    peca->linha = linha;
    peca->coluna = coluna;
    peca->simbolo = simbolo;
    if (peca->simbolo == 't' || peca->simbolo == 'T')
    {
        strcpy(peca->nome, "Torre");
    }
    else if (peca->simbolo == 'h' || peca->simbolo == 'H')
    {
        strcpy(peca->nome, "Cavalo");
    }
    else if (peca->simbolo == 'b' || peca->simbolo == 'B')
    {
        strcpy(peca->nome, "Bispo");
    }
    else if (peca->simbolo == 'q' || peca->simbolo == 'Q')
    {
        strcpy(peca->nome, "Rainha");
    }
    else if (peca->simbolo == 'k' || peca->simbolo == 'K')
    {
        strcpy(peca->nome, "Rei");
    }
    else if (peca->simbolo == 'p' || peca->simbolo == 'P')
    {
        strcpy(peca->nome, "Peao");
    }
    else
    {
        printf("Simbolo %c invalido!\nInicie a peca com um dos simbolos:\n t, T, h, H, b, B, q, Q, k, K, p, P\n", simbolo);
        return NULL;
    }
    if (peca->linha < 0 || peca->linha > 7){
        printf("Numero maximo de Linhas invalido! Numero maximo para Linhas deve estar entre 0-7\n");
        return NULL;
    }
    if (peca->coluna < 0 || peca->coluna > 7){
        printf("Numero maximo de Colunas invalido! Numero maximo para Colunas deve estar entre 0-7\n");
        return NULL;
    }
    return peca;
}

/*         - Funcao pecaNula() -                            *
 *  - Cria variavel peca do tipo estrutura Peca do tamanho  *
 *  de Peca.                                                *
 *  - Atribui a letra x para variavel peca->simbolo e       *
 *  retorna a estrutura peca.                               */
Peca *pecaNula()
{
    Peca *peca = (Peca *)malloc(sizeof(Peca));
    peca->simbolo = 'x';
    strcpy(peca->nome, "x");
    return peca;
}

/*         - Funcao lado() -                            *
 *  - Recebe a estrutura peca do tipo Peca.             *
 *  - Verifica se os simbolos sao caracteres minusculos *
 *  e retorna o simbolo P (pecas pretas). Se for        *
 *  simbolo 'x', retorna o caractere X, se nao retonra  *
 *  o caractere B (pecas brancas).                      */
char lado(Peca *peca)
{
    if (peca->simbolo == 't' ||
        peca->simbolo == 'h' ||
        peca->simbolo == 'b' ||
        peca->simbolo == 'q' ||
        peca->simbolo == 'k' ||
        peca->simbolo == 'p')
    {
        return 'P';
    }
    else if (peca->simbolo == 'x')
    {
        return 'X';
    }
    return 'B';
}

/*         - Funcao movePeca() -                            *
 *  - Recebe a estrutura Peca por referencia, a linha e     *
 *  coluna.                                                 *
 *  - Verifica se a linha ou coluna eh maior que o tabulei- *
 *  ro.                                                     *
 *  - Realiza o movimento de cada peca dependendo do simbo- *
 *  lo recebido na funcao.                                  */
int movePeca(Peca *peca, int linha, int coluna, int captura)
{
    if (linha > 7 || coluna > 7 || linha < 0 || coluna < 0)
    {
        return -1;
    }
    switch (peca->simbolo)
    {
        case 't':
        case 'T':
            if (abs(peca->coluna - coluna) == 0 || abs(peca->linha - linha == 0))
            {

                return 0;
            }
            break;

        case 'b':
        case 'B':
            if (abs(peca->coluna - coluna) == abs(peca->linha - linha))
            {

                return 0;
            }
            break;

        case 'h':
        case 'H':
            if ((abs(peca->linha - linha) == 2 && abs(peca->coluna - coluna) == 1) ||
                (abs(peca->linha - linha) == 1 && abs(peca->coluna - coluna) == 2))
            {

                return 0;
            }
            break;

        case 'q':
        case 'Q':
            if ((abs(peca->coluna - coluna) == 0 || abs(peca->linha - linha == 0)) ||
                (abs(peca->coluna - coluna) == abs(peca->linha - linha)))
            {

                return 0;
            }
            break;

        case 'k':
        case 'K':
            if (abs(peca->linha - linha) <= 1 && abs(peca->coluna - coluna) <= 1)
            {

                return 0;
            }
            break;

        case 'P':
            if (peca->linha == 1 &&
                (linha - peca->linha == 1 ||
                linha - peca->linha == 2) &&
                coluna == peca->coluna)
            {
                return 0;
            }

            if (peca->linha < 7 &&
                linha - peca->linha == 1 &&
                coluna == peca->coluna)
            {
                return 0;
            }
            
            if (abs(peca->coluna - coluna) == 1 &&
                abs(peca->linha - linha) == 1 &&
                captura == 1)
            {
                return 0;
            }
            break;

        case 'p':
            if (peca->linha == 6 &&
                (peca->linha - linha == 1 ||
                 peca->linha - linha == 2) &&
                coluna == peca->coluna)
            {
                return 0;
            }

            if (peca->linha > 1 &&
                peca->linha - linha == 1 &&
                coluna == peca->coluna)
            {
                return 0;
            }
            
            if (abs(peca->coluna - coluna) == 1 &&
                abs(peca->linha - linha) == 1 &&
                captura == 1)
            {
                return 0;
            }
            break;

        default:
            break;
    }
    return -1;
}

