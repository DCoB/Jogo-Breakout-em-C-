#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <TIME.H>
#include <conio.h>
#include "Auxiliares.h"
#include "tela.h"

void textcolor (int cor)
{
    /*LEGENDA
        0 = PRETO;
        1 = AZUL;
        2 = VERDE;
        3= CIANO;
        4= VERMELHO;
        5= ROXO;
        6= AMARELO;
        7= CINZA;
        8= CINZA;
        9= AZUL CLARO;
        10= VERDE NEON;
        11= CIANO NEON;
        12= VERMELHO SANGUE;
        13= ROSA;
        14= AMARELO NEON;
        15= BRANCO;
        16-31 = COR + FUNDO AZUL;
        31-46 = COR + FINDO VERDE;
        ...
    */

    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= cor);
}

int configtela(int X,int Y)//FUNÇÃO QUE CONFIGURA O TAMANHO DA TELA E DO BUFFER
{
    X = X+1;
    Y = Y+2;
    COORD outbuff;
    outbuff.X = X; //TEM QUE SER 1 MAIOR QUE O TAMANHO X
    outbuff.Y = Y; //TEM QUE SER 1 MAIOR QUE O TAMANHO Y
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(hConsole, outbuff);
    Sleep(130);
    SMALL_RECT windowSize = {0, 0, X-1, Y-1};
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

    return 0;
}

int hideCursor()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO i;
    i.dwSize = 100;
    i.bVisible = FALSE;
    SetConsoleCursorInfo(console,&i);

    return 0;
}

void pausa(int ParX,int ParY)
{
    int cont;

    gotoxy(ParX/2-20,ParY/2);
    system("pause");
    gotoxy(2,ParY/2);
    apagar_texto(2,ParY/2,50);
    status_atualizar(ParX,ParY,1,0,0,0);
}

void ContagemRegressiva(int x,int y)
{
    gotoxy(x,y);
    printf("3");
    Sleep(1000);
    apagar_texto(x,y,1);
    gotoxy(x,y);
    printf("2");
    Sleep(1000);
    apagar_texto(x,y,1);
    gotoxy(x,y);
    printf("1");
    Sleep(1000);
    apagar_texto(x,y,1);
    gotoxy(x,y);
    printf("GO!!!!!!!!");
    Sleep(500);
    apagar_texto(x,y,10);

}

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x-1,y-1
    });
}                  /* defini?o de gotoxy(x,y) */

int efeito_piscartexto(char texto[100],int i,int x,int y,int TEMPO)
{
    /*---------------------------------------------------------------------------

        ESSA FUNÇÃO RECEBE OS SEGUINTES PARÃMETROS:

        texto = TEXTO A SER EXIBIDO COM O EFEITO;
        i = TAMANHO DO TEXTO A SER EXIBIDO;
        x = POSIÇÃO 'X' DO TEXTO A SER EXIBIDO;
        y = POSIÇÃO 'Y' DO TEXTO A SER EXIBIDO;
        TEMPO = TEMPO QUE DEMORA COM O TEXTO APARECENDO E DESAPARECENDO;

        A FORMATAÇÃO PARA A CHAMADA DESSA FUNÇÃO SE DEFINE COM O SEGUINTE EXEMPLO:

        efeito_piscartexto("QUALQUE TEXTO",13,0,0,500);

    ----------------------------------------------------------------------------*/

    char tecla='i';
    short efeito_ativo = 1,loop;

    textcolor(12);
    while(efeito_ativo == 1)//LOPPING QUE FAZ O EFEITO
    {
        gotoxy(x,y);//POSICIONA O CURSOR NA POSIÇÃO DESEJADA
        hideCursor();//ESCONDE O CURSOR
        for(loop=0; loop<=i; loop++) //FAZ O TEXTO APARECER NA TELA
        {
            printf("%c",texto[loop]);
        }
        Sleep(TEMPO);//TEMPO QUE O TEXTO DEMORAR PARA APARECER E DESAPARECER
        apagar_texto(x,y,i+1);
        if(kbhit())//É ACIONADO SE USUÁRIO CLICAR EM ALGUMA TECLA
        {
            fflush(stdin);//LIMPA O BUFFET DO TECLADO
            tecla = getch();//RECUPERA O VALOR DA TECLA
            textcolor(15);
            return tecla;
            efeito_ativo = 0;//SAI DO LOOPING
        }
        Sleep(TEMPO);//TEMPO QUE O TEXTO DEMORAR PARA APARECER E DESAPARECER
        hideCursor();//ESCONDE O CURSOR
        apagar_texto(x,y,i+1);

        if(kbhit())//É ACIONADO SE USUÁRIO CLICAR EM ALGUMA TECLA
        {
            fflush(stdin);//LIMPA O BUFFET DO TECLADO
            tecla = getch();//RECUPERA O VALOR DA TECLA
            textcolor(15);
            return tecla;
            efeito_ativo = 0;//SAI DO LOOPING
        }
    }
    textcolor(15);
    return tecla;
}

void apagar_texto(int x,int y,int tamanho)
{
    int i;

    gotoxy(x,y);
    for(i=0; i<tamanho; i++)
    {
        printf(" ");
    }
}
