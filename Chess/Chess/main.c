//
//  main.c
//  Chess
//
//
//  Copyright (c) 2013 VoIP. All rights reserved.
//
//


#ifdef _WIN32
#include <windows.h>
#elif __APPLE__
#endif

#include <stdio.h>
#include <string.h>
#include "Jogo.h"
#include "Tabuleiro.h"
#include "Peca.h"


int main(int argc, const char * argv[])
{
    #ifdef _WIN32
    system("mode 150, 50");//Defining the dimension of our Console Window Application
    Jogo *novoJogo = criaJogo();
    display(novoJogo, "");
    #elif __APPLE__
    Jogo *novoJogo = criaJogo();
    display(novoJogo, "");
    #endif
    return 0;

}
