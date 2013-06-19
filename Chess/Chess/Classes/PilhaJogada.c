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
#include <float.h>
#include "PilhaJogada.h"


PilhaJogada *criaPilhaJogada()
{
    PilhaJogada *pilha = (PilhaJogada *)malloc(sizeof(PilhaJogada));
    pilha->inicio = NULL;
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

int numJogadasPretas(PilhaJogada *pilha)
{
    int count = 0;
    NodePilhaJogada *node = pilha->inicio;
    while (node != NULL)
    {
        Jogada *jogada = node->jogada;
        if (jogada == NULL)
        {
            break;
        }
        Peca *pecaMovida = jogada->pecaMovida;
        if (pecaMovida == NULL)
        {
            break;
        }
        if (lado(jogada->pecaMovida) == 'P')
        {
            count++;
        }
        node = node->next;
    }
    return count;
}

int numJogadasBrancas(PilhaJogada *pilha)
{
    int count = 0;
    NodePilhaJogada *node = pilha->inicio;
    while (node != NULL)
    {
        Jogada *jogada = node->jogada;
        if (lado(jogada->pecaMovida) == 'B')
        {
            count++;
        }
        node = node->next;
    }
    return count;
}

Jogada *jogadaMaisRapida(PilhaJogada *pilha)
{
    double fasterTime = DBL_MAX;
    Jogada *jogadaRapida = NULL;
    NodePilhaJogada *node = pilha->inicio;
    while (node != NULL)
    {
        Jogada *jogada = node->jogada;
        double tempo = tempoJogada(jogada);
        if (tempo < fasterTime)
        {
            fasterTime = tempo;
            jogadaRapida = jogada;
        }
        node = node->next;
    }
    return jogadaRapida;
}

Jogada *jogadaMaisDemorada(PilhaJogada *pilha)
{
    double longerTime = 0;
    Jogada *jogadaDemorada = NULL;
    NodePilhaJogada *node = pilha->inicio;
    while (node != NULL)
    {
        Jogada *jogada = node->jogada;
        double tempo = tempoJogada(jogada);
        if (tempo > longerTime)
        {
            longerTime = tempo;
            jogadaDemorada = jogada;
        }
        node = node->next;
    }
    return jogadaDemorada;
}

void imprimirPilhaJogada(PilhaJogada *pilha)
{
    NodePilhaJogada *node = pilha->inicio;
    while (node != NULL)
    {
        Jogada *jogada = node->jogada;
        if (jogada == NULL)
        {
            break;
        }
        printf("%p", jogada);
        node = node->next;
    }
}

Jogada *tresJogadasMaisRapidasBrancas(PilhaJogada *pilha)
{
    
}

Jogada *tresJogadasMaisRapidasPretas(PilhaJogada *pilha)
{
    
}

