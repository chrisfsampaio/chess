
//
//  Jogada.c
//  Chess
//
//  Created by Leonardo Tsuda on 2013-06-15.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Jogada.h"
#include <time.h>

Jogada  *criaJogada()
{
    Jogada *jogada = (Jogada *)malloc(sizeof(Jogada));
    return jogada;
}

double tempoJogada(Jogada *jogada)
{
    double tempo = (double)jogada->endTimestamp - jogada->startTimestamp;
    return tempo;
}

