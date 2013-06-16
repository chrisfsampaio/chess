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
//  Lista.c

#include <stdio.h>
#include <stdlib.h>
#include "ListaPeca.h"

/*          - Funcao: criaListaPecas -                              *
 * Descricao: inicia a lista de pecas                               *
 * Retorno: ListaPecas lista - ponteiro para a lista de pecas criada*/
ListaPeca *criaListaPeca()
{
    ListaPeca *lista = (ListaPeca *)malloc(sizeof(ListaPeca));
    lista->inicio = NULL;
    return lista;
}


/*          - Funcao: addPecaLista -                            *
 * Descricao: adiciona uma nova peca na lista de pecas.         *
 * Parametros:                                                  *
 *  1. ListaPecas *lista - ponteiro para a lista de pecas       *
 *  2. int linha - numero da linha da peca                      *
 *  3. int coluna - numero da coluna da peca                    *
 *  4. char simbolo - o simbolo representativo da pecas         *
 * Retorno: int status - codigo da operacao efetuada            */
int addPecaLista(ListaPeca *lista, Peca *peca)
{

    int status = 1;

    // Verifica se a lista de pecas foi criada
    if(lista != NULL && peca != NULL)
    {
        // Aloca memoria para nova peca
        Node *novoNoPeca = criaNode(peca, NULL);

        // Verifica se a lista esta vazia
        if (lista->inicio == NULL)
        {
            novoNoPeca->next = NULL;
        }
        else
        {
            novoNoPeca->next = lista->inicio;
        }
        lista->inicio = novoNoPeca;
    }
    else
    {
        status = -1;
    }

    return status;
}


Peca *pecaAtIndex(ListaPeca *lista, int index)
{
    int i = 0;
    Node *node = lista->inicio;

    while (i < index)
    {
        node = node->next;
        i++;
    }

    return node->peca;
}
