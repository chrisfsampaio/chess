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

    jogo->lista = criaListaPecas();
    addPecaLista(jogo->lista, 0, 0, 't');
    addPecaLista(jogo->lista, 0, 1, 'h');
    addPecaLista(jogo->lista, 0, 2, 'b');
    addPecaLista(jogo->lista, 0, 3, 'q');
    addPecaLista(jogo->lista, 0, 4, 'k');
    addPecaLista(jogo->lista, 0, 5, 'b');
    addPecaLista(jogo->lista, 0, 6, 'h');
    addPecaLista(jogo->lista, 0, 7, 't');
    addPecaLista(jogo->lista, 1, 0, 'p');
    addPecaLista(jogo->lista, 1, 1, 'p');
    addPecaLista(jogo->lista, 1, 2, 'p');
    addPecaLista(jogo->lista, 1, 3, 'p');
    addPecaLista(jogo->lista, 1, 4, 'p');
    addPecaLista(jogo->lista, 1, 5, 'p');
    addPecaLista(jogo->lista, 1, 6, 'p');
    addPecaLista(jogo->lista, 1, 7, 'p');
    addPecaLista(jogo->lista, 6, 0, 'P');
    addPecaLista(jogo->lista, 6, 1, 'P');
    addPecaLista(jogo->lista, 6, 2, 'P');
    addPecaLista(jogo->lista, 6, 3, 'P');
    addPecaLista(jogo->lista, 6, 4, 'P');
    addPecaLista(jogo->lista, 6, 5, 'P');
    addPecaLista(jogo->lista, 6, 6, 'P');
    addPecaLista(jogo->lista, 6, 7, 'P');
    addPecaLista(jogo->lista, 7, 0, 'T');
    addPecaLista(jogo->lista, 7, 1, 'H');
    addPecaLista(jogo->lista, 7, 2, 'B');
    addPecaLista(jogo->lista, 7, 3, 'Q');
    addPecaLista(jogo->lista, 7, 4, 'K');
    addPecaLista(jogo->lista, 7, 5, 'B');
    addPecaLista(jogo->lista, 7, 6, 'H');
    addPecaLista(jogo->lista, 7, 7, 'T');

    pieces[0] = *criaPeca(0, 0, 'T');
    pieces[1] = *criaPeca(0, 1, 'H');
    pieces[2] = *criaPeca(0, 2, 'B');
    pieces[3] = *criaPeca(0, 3, 'Q');
    pieces[4] = *criaPeca(0, 4, 'K');
    pieces[5] = *criaPeca(0, 5, 'B');
    pieces[6] = *criaPeca(0, 6, 'H');
    pieces[7] = *criaPeca(0, 7, 'T');
    pieces[8] = *criaPeca(1, 0, 'P');
    pieces[9] = *criaPeca(1, 1, 'P');
    pieces[10] = *criaPeca(1, 2, 'P');
    pieces[11] = *criaPeca(1, 3, 'P');
    pieces[12] = *criaPeca(1, 4, 'P');
    pieces[13] = *criaPeca(1, 5, 'P');
    pieces[14] = *criaPeca(1, 6, 'P');
    pieces[15] = *criaPeca(1, 7, 'P');
    pieces[16] = *criaPeca(6, 0, 'p');
    pieces[17] = *criaPeca(6, 1, 'p');
    pieces[18] = *criaPeca(6, 2, 'p');
    pieces[19] = *criaPeca(6, 3, 'p');
    pieces[20] = *criaPeca(6, 4, 'p');
    pieces[21] = *criaPeca(6, 5, 'p');
    pieces[22] = *criaPeca(6, 6, 'p');
    pieces[23] = *criaPeca(6, 7, 'p');
    pieces[24] = *criaPeca(7, 0, 't');
    pieces[25] = *criaPeca(7, 1, 'h');
    pieces[26] = *criaPeca(7, 2, 'b');
    pieces[27] = *criaPeca(7, 3, 'q');
    pieces[28] = *criaPeca(7, 4, 'k');
    pieces[29] = *criaPeca(7, 5, 'b');
    pieces[30] = *criaPeca(7, 6, 'h');
    pieces[31] = *criaPeca(7, 7, 't');

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
void display(Jogo *jogo, char *msg)
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
            Peca peca = jogo->tabuleiro->pecas[i][j];
            if (peca.simbolo == 'x')
            {
                printf("\t\t|");
            }
            else
            {
                char simbolo = peca.simbolo;
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

    executaJogada(jogo);
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
    char jogada[6];
    char msgJogador[100];
    jogo->turno == 'B' ? strcpy(msgJogador, jogo->jogador2) : strcpy(msgJogador, jogo->jogador1);
    jogo->turno == 'B' ? strcat(msgJogador, ", digite a sua jogada (ex: 2a 3b) - Brancas (minusculas)\n")   :
    strcat(msgJogador, ", digite a sua jogada (ex: 2a 3b) - Pretas (maiusculas)\n");    
    printf("%s",msgJogador);
    
    fgets(jogada, sizeof(jogada), stdin);
    flush_in();
    fflush(stdin);
    
    int linhaOrigem = (7-(((int)jogada[0] - '0') - 1));
    int colunaOrigem = letraParaNumero(jogada[1]);

    int linhaDestino = (7-(((int)jogada[3] - '0') - 1));
    int colunaDestino = letraParaNumero(jogada[4]);

    int jogadaOk = 0;
    int fimDeJogo = 0;
    int captura = 0;
    Peca peca = jogo->tabuleiro->pecas[linhaOrigem][colunaOrigem];
    if (linhaDestino <= 7 && linhaDestino >= 0 && colunaDestino <= 7 && colunaDestino >= 0)
    {
        if (lado(&jogo->tabuleiro->pecas[linhaDestino][colunaDestino]) != lado(&peca) &&
            jogo->tabuleiro->pecas[linhaDestino][colunaDestino].simbolo != 'x')
        {
            captura = 1;
        }
    }
    char msg[200];
    strcpy(msg, "");
    if (peca.simbolo != 'x' && lado(&peca) == jogo->turno)
    {
        if (movePeca(&peca, linhaDestino, colunaDestino, captura) == 0)
        {
            int pecaNoCaminho = existePecaNoCaminho(jogo->tabuleiro, &peca, linhaDestino, colunaDestino);
            if (peca.simbolo == 'h' || peca.simbolo == 'H' || pecaNoCaminho == 0)
            {
                Peca *pecaRetorno = setCasa(jogo->tabuleiro, linhaDestino, colunaDestino, &peca);
                if (pecaRetorno == 0)
                {
                    strcat(msg, "Jogada invalida, existe uma peca sua no destino");
                }
                else
                {
                    jogadaOk = 1;
                    Peca pecaCapturada = *pecaRetorno;
                    if (pecaCapturada.simbolo != 'x')
                    {
                        strcat(msg, "A peca -");
                        strcat(msg, pecaCapturada.nome);
                        strcat(msg, "- de -");
                        strcat(msg, jogo->turno == 'B' ? jogo->jogador2 : jogo->jogador1);
                        strcat(msg, "- foi capturada!");
                        if (pecaCapturada.simbolo == 'k' || pecaCapturada.simbolo == 'K')
                        {
                            strcat(msg, "\nO jogador -");
                            strcat(msg, jogo->turno == 'B' ? jogo->jogador1 : jogo->jogador2);
                            strcat(msg, "- venceu!!");
                            fimDeJogo = 1;
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
            strcat(msg, peca.nome);
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
    display(jogo, msg);
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

