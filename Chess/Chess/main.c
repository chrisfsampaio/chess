//
//  main.c
//  Chess
//
//  Created by Christian on 3/25/13.
//  Copyright (c) 2013 Leonardo Henrique Tsuda. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "Jogo.h"
#include "Tabuleiro.h"
#include "Peca.h"

int main(int argc, const char * argv[])
{
    Jogo *novoJogo = criaJogo();
    display(novoJogo);

    
    return 0;
}

