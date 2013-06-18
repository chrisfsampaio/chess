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

ListaPeca *carregaListaDoArquivo()
{
    ListaPeca *lista = criaListaPeca();
    
    FILE *fr;
    int ch = 0;
    int i =0;
    
    if((fr = fopen("./save.xdz", "rb")) != NULL)
    {
        while((ch = getc(fr)) && (!feof(fr)) && ungetc(ch, fr))
        {
            Peca *peca = (Peca *)malloc(sizeof(Peca));
            i = 0;
            ch = getc(fr);
            while(ch != '\0')
            {
                peca->nome[i++] = ch;
                ch = getc(fr);
            }
            
            peca->simbolo = getc(fr);
            
            fread(&peca->linha, sizeof(int), 1, fr);
            fread(&peca->coluna, sizeof(int), 1, fr);
            fread(&peca->capturada, sizeof(int), 1, fr);
            fread(&peca->pecaID, sizeof(int), 1, fr);
            
            addPecaLista(lista, peca);
        }
        fclose(fr);
    }
    
    return lista;
}

int saveListToFile(ListaPeca *lista)
{
    imprimirLista(lista);
    Node *first = lista->inicio;
    Node *node = NULL;
    
    FILE *file = fopen("./save.xdz", "wb");
    fclose(file);
    
    node = first;
    Peca *peca = first->peca;
    while (peca != NULL)
    {
        writePecaToFile(peca);
        node = node->next;
        peca = node != NULL ? node->peca : NULL;
    }
    
    return 0;
}

void destruirLista(ListaPeca *lista)
{
    Node *node = lista->inicio;
    while (node != NULL)
    {
        Node *freeNode = node;
        free(freeNode->peca);
        free(freeNode);
        node = node->next;
    }
}

void imprimirLista(ListaPeca *lista)
{
    Node *node = lista->inicio;
    while (node != NULL)
    {
        Peca *peca = node->peca;
        printf("Peca %c em linha: %d  coluna: %d\n",peca->simbolo, peca->linha, peca->coluna);
        node = node->next;
    }
}
