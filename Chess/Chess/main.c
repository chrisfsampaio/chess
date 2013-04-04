//
//  main.c
//  Chess
//
//
//  Copyright (c) 2013 NOME_DO_GRUPO. All rights reserved.
//
//

//#ifdef TARGET_OS_MAC

#include <stdio.h>
#include <string.h>
#include "Jogo.h"
#include "Tabuleiro.h"
#include "Peca.h"
/*#endif

#ifdef _WIN32
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "Jogo.h"
#include "Tabuleiro.h"
#include "Peca.h"
#endif*/



int main(int argc, const char * argv[])
{
    /*#ifdef _WIN32
    HANDLE hOut; //Windows output handle
    SMALL_RECT newScreenSize; //Rectangle containing the new dimensions

    //Defining the dimensions of our window
    newScreenSize.Left = 0; //(Upper left)
    newScreenSize.Right = 10; //(Bottom right)
    newScreenSize.Top = 0;
    newScreenSize.Bottom = 20; //Height of window
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); //Loading the handle
    SetConsoleWindowInfo(hOut, TRUE, &newScreenSize); //Actually setting it
    //The true is for absolute dimensions vs. relative to the old dimensions
    system("mode 150, 50");//Defining the dimension of our Console Window Application 

    Jogo *novoJogo = criaJogo();
    display(novoJogo, "");
    }
    #endif

    #ifdef TARGET_OS_MAC*/
        Jogo *novoJogo = criaJogo();
        display(novoJogo, "");
 //   #endif
    return 0;

}
