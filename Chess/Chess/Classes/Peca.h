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
//  Peca.h

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
    int capturada; // 0=Nao 1=Sim
    struct _peca *prox;
};
typedef struct _peca Peca;


/* Estrutura header para a lista de pecas */
struct _listaPecas
{
    Peca *inicio;
};
typedef struct _listaPecas ListaPecas;


/*          - Declarando os Headers da funcoes da TAD Peca  */
Peca *criaPeca(int linha, int coluna, char simbolo);
Peca *pecaNula();
int movePeca(Peca *peca, int linha, int coluna, int captura);
ListaPecas* criaListaPecas();
int addPecaLista(ListaPecas *lista, int linha, int coluna, char simbolo);


/*  Retorna um char que indica o lado da peca     *
 *  P' para pretas, e 'B' para brancas            */
char lado(Peca *peca);

#endif
