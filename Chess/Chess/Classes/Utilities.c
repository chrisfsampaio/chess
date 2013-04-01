//
//  Utilities.c
//  Chess
//
//  Copyright (c) 2013 NOME_DO_GRUPO. All rights reserved.
//
//
//

#include <stdio.h>
#include "Utilities.h"

int letraParaNumero(char letra)
{
    switch (letra)
    {
        case 'a':
        case 'A':
        case '0':
            return 0;
            break;
            
        case 'b':
        case 'B':
        case '1':
            return 1;
            break;
            
        case 'c':
        case 'C':
        case '2':
            return 2;
            break;
            
        case 'd':
        case 'D':
        case '3':
            return 3;
            break;
            
        case 'e':
        case 'E':
        case '4':
            return 4;
            break;
            
        case 'f':
        case 'F':
        case '5':
            return 5;
            break;
            
        case 'g':
        case 'G':
        case '6':
            return 6;
            break;
            
        case 'h':
        case 'H':
        case '7':
            return 7;
            break;
            
        default:
            return -1;
            break;
    }
    
    return -1;
}


char numeroParaLetra(int numero)
{
    switch (numero)
    {
        case 0:
            return 'A';
            break;
            
        case 1:
            return 'B';
            break;
            
        case 2:
            return 'C';
            break;
            
        case 3:
            return 'D';
            break;
            
        case 4:
            return 'E';
            break;
            
        case 5:
            return 'F';
            break;
            
        case 6:
            return 'G';
            break;
            
        case 7:
            return 'H';
            break;
            
        default:
            return 'X';
            break;
    }
    
    return 'X';
}

void flush_in()
{
    int ch;
    while((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    
    }
}



