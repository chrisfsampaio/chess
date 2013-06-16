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
//  PilhaJogada.c


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


