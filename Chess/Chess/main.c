//
//  main.c
//  Chess
//
//
//  Copyright (c) 2013 NOME_DO_GRUPO. All rights reserved.
//
//

#include <stdio.h>
#include <string.h>
#include "Jogo.h"
#include "Tabuleiro.h"
#include "Peca.h"

int main(int argc, const char * argv[])
{
    Jogo *novoJogo = criaJogo();
    display(novoJogo, "");

    
    return 0;
}

