#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <TIME.H>
#define DIREITA 77
#define ESQUERDA 75


int movimentacao_barra(char tecla,int x,int y,int parX,int tam_barra)
{
    int cont;

    if((tecla == DIREITA)&& (x<=parX-(tam_barra+2)))//MOVIMENTA플O DA BARRA PARA A DIREITA
    {
        gotoxy(x-1,y);
        for(cont=1; cont<=tam_barra-1; cont++)
        {
            printf(" ");
        }
        x = x + 2;
        gotoxy(x,y);
        for(cont=1; cont<=tam_barra; cont++)
        {
            printf("%c",61);
        }
    }
    if((tecla == ESQUERDA) && (x > 3))//MOVIMENTA플O DA BARRA PARA A ESQUERDA
    {
        gotoxy(x+1,y);
        for(cont=1; cont<=tam_barra-1; cont++)
        {
            printf(" ");
        }
        x = x - 2;
        gotoxy(x,y);
        for(cont=1; cont<=tam_barra; cont++)
        {
            printf("%c",61);
        }
    }
    if((tecla == 'd')&&(x<=parX-(tam_barra+2)))//MOVIMENTA플O DA BARRA PARA A DIREITA
    {
        gotoxy(x-1,y);
        for(cont=1; cont<=tam_barra-1; cont++)
        {
            printf(" ");
        }
        x = x + 2;
        gotoxy(x,y);
        for(cont=1; cont<=tam_barra; cont++)
        {
            printf("%c",61);
        }
    }
    if((tecla == 'a') && (x >3))//MOVIMENTA플O DA BARRA PARA A ESQUERDA
    {
        gotoxy(x+1,y);
        for(cont=1; cont<=tam_barra-1; cont++)
        {
            printf(" ");
        }
        x = x - 2;
        gotoxy(x,y);
        for(cont=1; cont<=tam_barra; cont++)
        {
            printf("%c",61);
        }
    }
    return x;
}

int x_da_bola(int bx,int direcao)
{
    if((direcao==0)||(direcao==2))
    {
        bx = bx + 1;
    }
    else if((direcao==1)||(direcao==3))
    {
        bx = bx - 1;
    }
    return bx;

}

int y_da_bola(int by,int direcao)
{
    if((direcao==0)||(direcao==1))
    {
        by = by - 1;
    }
    else if((direcao==2)||(direcao==3))
    {
        by = by + 1;
    }
    return by;
}

void movimentacao_bola(int bx,int by,int VELOCIDADE,int direcao)
{
    if(direcao==0)
    {
        gotoxy(bx,by);
        hideCursor();
        printf("@");//FAZ A MOVIMENTA?O DO "@"
        gotoxy(bx-1,by+1);
        Sleep(VELOCIDADE-15);
        printf(" ");//APAGA O "@" ANTERIOR

    }
    else if(direcao==1)
    {
        gotoxy(bx,by);
        hideCursor();
        printf("@");//FAZ A MOVIMENTA?O DO "@"
        gotoxy(bx+1,by+1);
        Sleep(VELOCIDADE-15);
        printf(" ");//APAGA O "@" ANTERIOR
    }
    else if(direcao==2)
    {
        gotoxy(bx,by);
        hideCursor();
        printf("@");//FAZ A MOVIMENTA?O DO "@"
        gotoxy(bx-1,by-1);
        Sleep(VELOCIDADE-15);
        printf(" ");//APAGA O "@" ANTERIOR
    }
    else if(direcao==3)
    {
        gotoxy(bx,by);
        hideCursor();
        printf("@");//FAZ A MOVIMENTA?O DO "@"
        gotoxy(bx+1,by-1);
        Sleep(VELOCIDADE-15);
        printf(" ");//APAGA O "@" ANTERIOR
    }
}
