//
//  PilhaJogada.c
//  Chess
//
//  Created by Leonardo Tsuda on 2013-06-15.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "PilhaJogada.h"


PilhaJogada *criaPilhaJogada()
{
    PilhaJogada *pilha = (PilhaJogada *)malloc(sizeof(PilhaJogada));
    return pilha;
}

int addPilhaJogada(PilhaJogada *pilha, Jogada *jogada)
{
    
    int status = 1;
    
    // Verifica se a pilha de jogada foi criada
    if(pilha != NULL && jogada != NULL)
    {
        // Aloca memoria para nova jogada
        NodePilhaJogada *novoNodeJogada = criaNodePilhaJogada(jogada, NULL);
        
        // Verifica se a pilha esta vazia
        if (pilha->inicio == NULL)
        {
            novoNodeJogada->next = NULL;
        }
        else
        {
            novoNodeJogada->next = pilha->inicio;
        }
        pilha->inicio = novoNodeJogada;
    }
    else
    {
        status = -1;
    }
    
    return status;
}


