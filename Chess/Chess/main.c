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
    char jogador1[kComprimentoNome];
    char jogador2[kComprimentoNome];
    int load = 10;

    #ifdef _WIN32
    system("mode 150, 50");
    do
    {
        printf("Deseja carregar um jogo salvo ou iniciar um novo Jogo? 1 - Salvo, 0 - Novo Jogo\n");
        scanf("%d", &load);
    } while (load != 1 && (load != 0));
    
    if (load == 1) {
        fflush(stdin);
        Jogo *novoJogo = criaJogo(jogador1, jogador2, load);
        display(novoJogo, "", 1);
    }
    else if (load == 0)
    {
    fflush(stdin);
    do
    {
        printf("Digite o nome do Jogador 1\n#ATENCAO# Deve conter pelo menos um caracter:\n");
        fgets(jogador1, sizeof(jogador1), stdin);
        strtok(jogador1, "\n");
    } while (jogador1[0] == '\n' || strlen(jogador1) < 1);

    do{
        printf("Digite o nome do Jogador 2\n#ATENCAO# Deve conter pelo menos um caracter:\n");
        fgets(jogador2, sizeof(jogador2), stdin);
        strtok(jogador2, "\n");
    } while (jogador2[0] == '\n' || strlen(jogador2) < 1);
    Jogo *novoJogo = criaJogo(jogador1, jogador2, load);
    display(novoJogo, "", 1);
    }

    #elif __APPLE__    
    do
    {
        printf("Deseja carregar o ultimo jogo salvo ou iniciar um novo Jogo? 1 - Salvo, 0 - Novo Jogo\n");
        load = getc(stdin);//("%d", &load);
    } while (load != '1' && (load != '0'));

    if (load == '1') {
        flush_in();
        Jogo *novoJogo = criaJogo(jogador1, jogador2, load);
        display(novoJogo, "", 1);
    }
    else if (load == '0')
    {
    flush_in();
    do
    {
    printf("Digite o nome do Jogador 1\n#ATENCAO# Deve conter pelo menos um caracter:\n");
    fgets(jogador1, sizeof(jogador1), stdin);
    strtok(jogador1, "\n");
    } while (jogador1[0] == '\n' || strlen(jogador1) < 1);

    do
    {
    printf("Digite o nome do Jogador 2\n#ATENCAO# Deve conter pelo menos um caracter:\n");
    fgets(jogador2, sizeof(jogador2), stdin);
    strtok(jogador2, "\n");
    } while (jogador2[0] == '\n' || strlen(jogador2) < 1);

    Jogo *novoJogo = criaJogo(jogador1, jogador2, load);
    display(novoJogo, "", 1);
    }
    #endif
    return 0;

}
