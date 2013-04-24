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
//  main.c

/*         - Verifica OS -                              *
 *  - Se for verificado que o sistema eh Windows,       *
 *  inclui a biblioteca windows.h e as outras abaixo do *
 *  #endif, se for verificado sistema da Apple, so      *
 *  inclui as bibliotecas abaixo do #endif.             */
#ifdef _WIN32
#include <windows.h>
#elif __APPLE__
#endif

#include <stdio.h>
#include <string.h>
#include "Jogo.h"
#include "Tabuleiro.h"
#include "Peca.h"

/*         - Funcao main() -                              *
 *  - Verifica se o sistema eh Windows e abre janela do   *
 * jogo do tamanho 150x50 e inicia o jogo. Se verificado  *
 * sistema Apple, inicia o jogo.                          */
int main(int argc, const char * argv[])
{
    #ifdef _WIN32
    system("mode 150, 50");
    Jogo *novoJogo = criaJogo();
    display(novoJogo, "");
    #elif __APPLE__
    Jogo *novoJogo = criaJogo();
    display(novoJogo, "");
    #endif
    return 0;

}
