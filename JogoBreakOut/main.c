#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <TIME.H>
#include <conio.h>
#include "Menu.h"

int main()
{
    struct jogador
    {
        char nome[12];
        char vidas;
        char nivel;
        int pontos;
        int velocidade;
    };
    Menu();
    return 0;
}




