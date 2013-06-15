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
//  Jogo.c

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
#include <ctype.h>
#include <unistd.h>

#ifdef _WIN32
#define CLEAR_WIN() system("cls");
#elif __APPPLE__
#define CLEAR_MAC() system("clear");
#endif

/*         - Funcao criaJogo() -                            *
 *  - Cria estrutura do tipo Jogo do tamanho de Jogo        *
 *  - Armazena e mostra na tela o nome de cada jogador e    *   
 *  o titulo do jogo;                                       *
 *  - Verifica se os nomes do jogadores sao diferentes;     *
 *  - Cria todas as pecas e armazena no vetor pecas[32];    *
 *  - Cria tabuleiro e coloca as pecas nos lugares;         *
 *  - Inicia o turno das pecas Brancas (Regra do Xadrez).   */
Jogo *criaJogo(char *jog1, char *jog2, Peca *pieces)
{
    Jogo *jogo  = (Jogo *)malloc(sizeof(Jogo));
    
    strcpy(jogo->jogador1, jog1);
    strcpy(jogo->jogador2, jog2);    

    strcpy(jogo->titulo, "+JOGO DE XADREZ+");

    jogo->lista = criaListaPeca();
    jogo->jogadas = criaPilhaJogada();
    addPecaLista(jogo->lista, criaPeca(0, 0, 'T', 1));
    addPecaLista(jogo->lista, criaPeca(0, 1, 'H', 2));
    addPecaLista(jogo->lista, criaPeca(0, 2, 'B', 3));
    addPecaLista(jogo->lista, criaPeca(0, 3, 'Q', 4));
    addPecaLista(jogo->lista, criaPeca(0, 4, 'K', 5));
    addPecaLista(jogo->lista, criaPeca(0, 5, 'B', 6));
    addPecaLista(jogo->lista, criaPeca(0, 6, 'H', 7));
    addPecaLista(jogo->lista, criaPeca(0, 7, 'T', 8));
    addPecaLista(jogo->lista, criaPeca(1, 0, 'P', 9));
    addPecaLista(jogo->lista, criaPeca(1, 1, 'P', 10));
    addPecaLista(jogo->lista, criaPeca(1, 2, 'P', 11));
    addPecaLista(jogo->lista, criaPeca(1, 3, 'P', 12));
    addPecaLista(jogo->lista, criaPeca(1, 4, 'P', 13));
    addPecaLista(jogo->lista, criaPeca(1, 5, 'P', 14));
    addPecaLista(jogo->lista, criaPeca(1, 6, 'P', 15));
    addPecaLista(jogo->lista, criaPeca(1, 7, 'P', 16));
    addPecaLista(jogo->lista, criaPeca(6, 0, 'p', 17));
    addPecaLista(jogo->lista, criaPeca(6, 1, 'p', 18));
    addPecaLista(jogo->lista, criaPeca(6, 2, 'p', 19));
    addPecaLista(jogo->lista, criaPeca(6, 3, 'p', 20));
    addPecaLista(jogo->lista, criaPeca(6, 4, 'p', 21));
    addPecaLista(jogo->lista, criaPeca(6, 5, 'p', 22));
    addPecaLista(jogo->lista, criaPeca(6, 6, 'p', 23));
    addPecaLista(jogo->lista, criaPeca(6, 7, 'p', 24));
    addPecaLista(jogo->lista, criaPeca(7, 0, 't', 25));
    addPecaLista(jogo->lista, criaPeca(7, 1, 'h', 26));
    addPecaLista(jogo->lista, criaPeca(7, 2, 'b', 27));
    addPecaLista(jogo->lista, criaPeca(7, 3, 'q', 28));
    addPecaLista(jogo->lista, criaPeca(7, 4, 'k', 29));
    addPecaLista(jogo->lista, criaPeca(7, 5, 'b', 30));
    addPecaLista(jogo->lista, criaPeca(7, 6, 'h', 31));
    addPecaLista(jogo->lista, criaPeca(7, 7, 't', 32));

    //insere os ponteiros de pecas na matrix que vai ser inserida no tabuleiro
    for (int i = 0; i < 32; i++)
    {
        pieces[i] = *pecaAtIndex(jogo->lista, 31 - i);
    }

    Tabuleiro *tabuleiro = criaTabuleiro(pieces, 32);
    jogo->tabuleiro = tabuleiro;
    jogo->turno = 'B';

    return jogo;
}

/*         - Funcao display() -                            *
 *  - Mostra na tela o tabuleiro que contem as linhas e    *
 *  colunas nomeadas, todas as pecas posicionadas corre    *
 *  tamente e nome dos dois jogares nos devidos times;     *
 *  - Chama funcao executaJogada,passando estrutura jogo   *
 *  por valor.                                             */
void display(Jogo *jogo, char *msg, int execJogada)
{
    #ifdef _WIN32
    CLEAR_WIN();
    #elif __APPPLE__
    CLEAR_MAC();
    #endif

    /*Peca *ptrProximoNode = jogo->lista->inicio->prox;
    Peca oProximoNode = *ptrProximoNode;
    printf("%i", oProximoNode.linha);*/

    #ifdef _WIN32
    printf("\n\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n\t*%70s\t\t\t\t\t\t\t\t*\n\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n", jogo->titulo);
    printf("\t%56s\t X\t %s", jogo->jogador1, jogo->jogador2);
    printf("\n\n\n\n\t\t\t\t\t\t\t\t%10s\n\t", jogo->jogador1);
    #elif __APPLE__
    printf("\n\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n\t*%35s\t\t\t\t\t\t\t*\n\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n", jogo->titulo);
    printf("\t%26s\t X\t %s", jogo->jogador1, jogo->jogador2);
    printf("\n\n\n\n\t\t\t\t\t\t\t\t%s\n\t", jogo->jogador1);
    #endif

    for (int i = 0; i < 8; i++)
    {
        char letra = numeroParaLetra(i);
        printf("\t%c\t", letra);
    }
    #ifdef _WIN32
    printf("\n\t+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+\n");
    #elif __APPLE__
    printf("\n\t+-------+-------+-------+-------+-------+-------+-------+-------+\n");
    #endif
    for (int i = 0; i < 8; i++)
    {
        printf("\t|");
        for (int j = 0; j < 8; j++)
        {
            printf("\t\t|");
        }
        printf("\n%d\t|",(9-(i + 1)));
        for (int j = 0; j < 8; j++)
        {
            Peca *peca = jogo->tabuleiro->pecas[i][j];
            if (peca == NULL)
            {
                printf("\t\t|");
            }
            else
            {
                char simbolo = peca->simbolo;
                printf("\t%c\t|",simbolo);
            }
        }
        printf("\t%d\n\t|",(9-(i + 1)));
        for (int j = 0; j < 8; j++)
        {
            printf("\t\t|");
        }
        #ifdef _WIN32
        printf("\n\t---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+\n");
        #elif __APPLE__
        printf("\n\t+-------+-------+-------+-------+-------+-------+-------+-------+\n");
        #endif
    }
    printf("\t");
    for (int i = 0; i < 8; i++)
    {
        char letra = numeroParaLetra(i);
        printf("\t%c\t", letra);
    }

    #ifdef _WIN32
    printf("\n\t\t\t\t\t\t\t\t%10s\n%s\n", jogo->jogador2, msg);
    #elif __APPLE__
    printf("\n\t\t\t\t\t\t\t\t%s\n%s\n", jogo->jogador2, msg);
    #endif
    
    if (execJogada) {
        executaJogada(jogo);
    }
}

/*         - Funcao executaJogada() -                       *
 *  - Cria variavel char para receber a jogada;             *
 *  - Cria variavel char para mensagem dos Jogadores;       *
 *  - Verifica se eh o turno das pecas Brancas e envia men- *
 *  sagem para o jogador realizar a jogada, se nao eh o     *
 *  turno das pecas Pretas;                                 *
 *  - Recebe a jogada e atruibui os valores origem/destino  *
 *  para as variaveis correspondentes;                      *
 *  - Inveter o turno a cada jogada;                        *
 *  - Realiza todos os movimentos das pecas, verificando    *
 *  se os movimentos sao validos e verifica Xeque Mate.     */
void executaJogada(Jogo *jogo)
{
    long tempo = timeNow();
    char jogada[6];
    char msgJogador[100];
    do{
        jogo->turno == 'B' ? strcpy(msgJogador, jogo->jogador2) : strcpy(msgJogador, jogo->jogador1);
        jogo->turno == 'B' ? strcat(msgJogador, ", digite a sua jogada (ex: 2a 3b) - Brancas (minusculas)\n")   :
        strcat(msgJogador, ", digite a sua jogada (ex: 2a 3b) - Pretas (maiusculas)\n");
        printf("%s",msgJogador);
        fgets(jogada, sizeof(jogada), stdin);
    } while (jogada[0] == '\n' || strlen(jogada) < 1);
    fflush(stdin);
    flush_in();


    int linhaOrigem = (7-(((int)jogada[0] - '0') - 1));
    int colunaOrigem = letraParaNumero(jogada[1]);

    int linhaDestino = (7-(((int)jogada[3] - '0') - 1));
    int colunaDestino = letraParaNumero(jogada[4]);

    int jogadaOk = 0;
    int fimDeJogo = 0;
    int captura = 0;
    Peca *peca = jogo->tabuleiro->pecas[linhaOrigem][colunaOrigem];
    if (linhaDestino <= 7 && linhaDestino >= 0 && colunaDestino <= 7 && colunaDestino >= 0)
    {
        if (lado(jogo->tabuleiro->pecas[linhaDestino][colunaDestino]) != lado(peca) &&
            jogo->tabuleiro->pecas[linhaDestino][colunaDestino] != NULL)
        {
            captura = 1;
        }
    }
    char msg[200];
    strcpy(msg, "");
    if (peca != NULL && lado(peca) == jogo->turno)
    {
        if (movePeca(peca, linhaDestino, colunaDestino, captura) == 0)
        {
            int pecaNoCaminho = existePecaNoCaminho(jogo->tabuleiro, peca, linhaDestino, colunaDestino);
            if (peca->simbolo == 'h' || peca->simbolo == 'H' || pecaNoCaminho == 0)
            {
                Peca *pecaRetorno = setCasa(jogo->tabuleiro, linhaDestino, colunaDestino, peca);
                if ((int)pecaRetorno == -1)
                {
                    strcat(msg, "Jogada invalida, existe uma peca sua no destino");
                }
                else
                {
                    display(jogo, "Confirmar jogada? S = Sim, N = Nao\n", 0);
                    char confirma = 'A';
                    while (toupper(confirma) != 'N' && toupper(confirma) != 'S')
                    {
                        confirma = fgetc(stdin);
                    }
                    confirma = toupper(confirma);
                    if (confirma == 'N')
                    {
                        jogadaOk = 0;
                        setCasa(jogo->tabuleiro, linhaOrigem, colunaOrigem, peca);
                        setCasa(jogo->tabuleiro, linhaDestino, colunaDestino, pecaRetorno);
                        strcat(msg, "");
                    }
                    else
                    {
                        jogadaOk = 1;
                        Jogada *jogada = criaJogada();
                        jogada->startTimestamp = tempo;
                        jogada->endTimestamp = timeNow();
                        jogada->pecaCapturada = pecaRetorno;
                        jogada->pecaMovida = peca;
                        jogada->origem = (Coordenada){linhaOrigem, colunaOrigem};
                        jogada->destino = (Coordenada){linhaDestino, colunaDestino};
                        addPilhaJogada(jogo->jogadas, jogada);
                        Peca *pecaCapturada = pecaRetorno;
                        if (pecaCapturada != NULL)
                        {
                            strcat(msg, "A peca -");
                            strcat(msg, pecaCapturada->nome);
                            strcat(msg, "- de -");
                            strcat(msg, jogo->turno == 'B' ? jogo->jogador1 : jogo->jogador2);
                            strcat(msg, "- foi capturada!");
                            if (pecaCapturada->simbolo == 'k' || pecaCapturada->simbolo == 'K')
                            {
                                strcat(msg, "\nO jogador -");
                                strcat(msg, jogo->turno == 'B' ? jogo->jogador2 : jogo->jogador1);
                                strcat(msg, "- venceu!!");
                                fimDeJogo = 1;
                            }
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
            strcat(msg, peca->nome);
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
    display(jogo, msg, 1);
}

/*         - Funcao inverterTurno() -                       *
 *  - Inverte o turno dos jogadores.                        */
void inverterTurno(Jogo *jogo)
{
    if (jogo->turno == 'B')
        jogo->turno = 'P';
    else
        jogo->turno = 'B';
}

