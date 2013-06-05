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
    Peca _pieces[32];
    
    #ifdef _WIN32
    system("mode 150, 50");
    do{
        printf("Digite o nome do Jogador 1\n#ATENCAO# Deve conter pelo menos um caracter Alfa-numerico:\n");
        fgets(jogador1, sizeof(jogador1), stdin);
        strtok(jogador1, "\n");
    } while (jogador1[0] == '\n' || strlen(jogador1) < 1);
    
    do{
        printf("Digite o nome do Jogador 2\n#ATENCAO# Deve conter pelo menos um caracter Alfa-numerico:\n");
        fgets(jogador2, sizeof(jogador2), stdin);
        strtok(jogador2, "\n");
    } while (jogador2[0] == '\n' || strlen(jogador2) < 1);
    Jogo *novoJogo = criaJogo(jogador1, jogador2, _pieces);
    display(novoJogo, "");
    
    #elif __APPLE__        
    do{
    printf("Digite o nome do Jogador 1\n#ATENCAO# Deve conter pelo menos um caracter Alfa-numerico:\n");
    fgets(jogador1, sizeof(jogador1), stdin);
    strtok(jogador1, "\n");
    } while (jogador1[0] == '\n' || strlen(jogador1) < 1);
    
    do{
    printf("Digite o nome do Jogador 2\n#ATENCAO# Deve conter pelo menos um caracter Alfa-numerico:\n");
    fgets(jogador2, sizeof(jogador2), stdin);
    strtok(jogador2, "\n");
    } while (jogador2[0] == '\n' || strlen(jogador2) < 1);
    
    Jogo *novoJogo = criaJogo(jogador1, jogador2, _pieces);
    display(novoJogo, "");
    #endif
    return 0;

}
