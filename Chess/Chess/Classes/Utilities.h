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
//  Utilities.h

/*         - Tipo Abstrato de Dados -                   *
 *  - Arquivo Header que armazena todas as definicoes   *
 *  da TAD Utilities.                                   */

#ifndef Chess_Utilities_h
#define Chess_Utilities_h


struct _coordenada
{
    int linha;
    int coluna;    
};
typedef struct _coordenada Coordenada;

/*          - Declarando os Headers da funcoes da TAD Utilities  */
int letraParaNumero(char letra);
char numeroParaLetra(int numero);
void flush_in();
long timeNow();

#endif
