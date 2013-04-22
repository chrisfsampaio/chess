//
//  Peca.h
//  Chess
//
//  Copyright (c) 2013 VoIP. All rights reserved.
//
/*         - Tipo Abstrato de Dados -                   *
 *  - Arquivo Header que armazena todas as definicoes   *
 *  da TAD Peca como: estrutura Peca que armazena os    *
 *  atributos das pecas.                                */

#ifndef Chess_Peca_h
#define Chess_Peca_h

/*         - Definindo a estrutura _peca -                  *
 *  - Estrutura _peca armazena os atributos das pecas como  *
 *  o nome, simbolo, e as coodenadas linha/coluna.          */
 struct _peca
{
    char nome[15];
    char simbolo;
    int linha;
    int coluna;
};
typedef struct _peca Peca;


/*          - Declarando os Headers da funcoes da TAD Peca  */
Peca *criaPeca(int linha, int coluna, char simbolo);
Peca *pecaNula();
int movePeca(Peca *peca, int linha, int coluna);

/*  Retorna um char que indica o lado da peca     *
 *  P' para pretas, e 'B' para brancas            */
char lado(Peca *peca);

#endif
