#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <TIME.H>
#include "tela.h"
#include "Auxiliares.h"


void status_incial(int ParX,int ParY,char nome[12])
{
    int linha,coluna;

    //BARRAS
    for(coluna=0; coluna<40; coluna++)
    {
        gotoxy(ParX+2,ParY/2-18+coluna);

        for(linha=0; linha<20; linha++)
        {
            if((linha==19)||(coluna==0)||(coluna==39))
            {
                printf("%c",219);
            }
            else
                printf(" ");
        }
    }

    //TEXTOS
    textcolor(15);
    gotoxy(ParX+7,9);
    printf("BREAKOUT");

    textcolor(6);
    gotoxy(ParX+3,13);
    printf("JOGADOR:");
    textcolor(15);
    gotoxy(ParX+3,15);
    printf("%s",nome);

    gotoxy(ParX+3,19);
    printf("STATUS DO JOGO:");
    gotoxy(ParX+4,21);
    textcolor(2);
    printf("JOGO EM EXECU%c%cO",128,199);
    textcolor(15);

    gotoxy(ParX+3,25);
    printf("PONTUA%c%cO:",128,199);
    gotoxy(ParX+4,27);
    textcolor(12);
    printf("0");
    textcolor(15);

    gotoxy(ParX+3,33);
    printf("VIDAS:");
    gotoxy(ParX+4,35);
    textcolor(12);
    printf("%c ",3);
    textcolor(2);
    printf("4");
    textcolor(15);

    gotoxy(ParX+3,41);
    printf("COMBO:");
    gotoxy(ParX+4,43);
    textcolor(6);
    printf("%c1",88);
    textcolor(15);

    textcolor(9);
    gotoxy(ParX+8,45);
    printf("%s",__TIME__);
    textcolor(15);

}

void status_atualizar(int ParX,int ParY,int jogo,int pontos,int vida,int combo)
{
    if(jogo!=0)
    {
        if(jogo==1)
        {
            gotoxy(ParX+4,21);
            textcolor(2);
            printf("JOGO EM EXECU%c%cO",128,199);
            textcolor(15);
        }
        if(jogo==2)
        {
            gotoxy(ParX+4,21);
            textcolor(7);
            printf("JOGO PAUSADO    ");
            textcolor(15);
        }
        if(jogo==3)
        {
            gotoxy(ParX+4,21);
            textcolor(4);
            printf("PERDEU O JOGO   ");
            textcolor(15);
        }
    }
    if(pontos!=0)
    {
        gotoxy(ParX+4,27);
        textcolor(7);
        printf("%i",pontos);
        textcolor(15);
    }
    if(vida!=0)
    {
        gotoxy(ParX+4,35);
        textcolor(12);
        printf("%c ",3);
        textcolor(4);
        printf("%i",vida);
        textcolor(15);
    }
    if(combo!=0)
    {
        gotoxy(ParX+4,43);
        textcolor(6);
        printf("%c%i",88,combo);
        textcolor(15);
    }
}

int ConstrucaoTela(int parX,int parY)
{
    int x,y;
    system("cls");

    for(x=0; x-1<parX; x++) //PAREDE DE CIMA
    {
        printf("%c",219);
    }

    printf("\n");
    for(x=0; x<parY; x++)
    {
        printf("%c",219);
        for(y=0; y<parX-1; y++)
        {
            printf(" ");
        }
        printf("%c\n",219);
    }
    gotoxy(0,parY-1);
    for(x=0; x<=parX; x++) //PAREDE DE BAIXO
    {
        printf("%c",219);
    }

    return 0;
}

int abilidades(int parX,int parY,int abilidade_ativada)
{
    int linha,coluna;

    textcolor(15);
    if(abilidade_ativada==0)
    {
        for(coluna=0; coluna<4; coluna++)
        {
            gotoxy(parX-(parX-2),parY+3+coluna);
            for(linha=0; linha<50; linha++)
            {
                if((linha==0)||(linha==49)||(coluna==3))
                {
                    printf("%c",219);
                }
                else
                {
                    printf(" ");
                }
            }
        }
    }


    if((abilidade_ativada==0)||(abilidade_ativada==1)||(abilidade_ativada==4))
    {

        if(abilidade_ativada==1)
        {
            textcolor(12);
        }
        else if(abilidade_ativada==0)
        {
            textcolor(12);
        }
        else
            textcolor(7);
        gotoxy(parX-(parX-5),parY+3);
        printf("%c        %c\n",218,191);
        gotoxy(parX-(parX-6),parY+4);
        printf("Q ");
        printf("KBOMMM\n");
        gotoxy(parX-(parX-5),parY+5);
        printf("%c        %c\n",192,217);
        textcolor(15);
        if(abilidade_ativada==1)
        {
            return rand()%23;
        }
    }

    if((abilidade_ativada==0)||(abilidade_ativada==2)||(abilidade_ativada==5))
    {
        if(abilidade_ativada==2)
        {
            textcolor(12);
        }
        else
        {
            textcolor(7);
        }
        gotoxy(parX-(parX-20),parY+3);
        printf("%c          %c\n",218,191);
        gotoxy(parX-(parX-21),parY+4);
        printf("W ");
        printf("EXPANDIR");
        gotoxy(parX-(parX-20),parY+5);
        printf("%c          %c\n",192,217);
        textcolor(15);
        if(abilidade_ativada==2)
        {
            return 6;
        }
    }

    if((abilidade_ativada==0)||(abilidade_ativada==3)||(abilidade_ativada==6))
    {
        if(abilidade_ativada==3)
        {
            textcolor(12);
        }
        else
        {
            textcolor(7);
        }
        gotoxy(parX-(parX-36),parY+3);
        printf("%c           %c\n",218,191);
        gotoxy(parX-(parX-37),parY+4);
        printf("E ");
        printf("TARTARUGA");
        gotoxy(parX-(parX-36),parY+5);
        printf("%c           %c\n",192,217);
        textcolor(15);
        if(abilidade_ativada==3)
        {
            return 20;
        }
    }
    return 0;
}

int Modo()
{
    gotoxy(3,8);
    printf("ESCOLHA O MODO PARA JOGAR:");
    char op;
    int op_ant=1;

    while(1)//LOOPING QUE FAZ O MOVIMENTO DAS OPÇÕES
    {

        if(op_ant == 1)//CASO A OPÇÃO EM SELEÇÃO SEJA A PRIMEIRA
        {

            gotoxy(16,14);
            printf("   ARCADE");
            gotoxy(16,16);
            printf("   HARDCORE");
            gotoxy(16,18);
            printf("   IMPOSSIBLE");
            op = efeito_piscartexto("-> CLASSICO",12,16,12,200);//OPÇÃO EM SELEÇÃO COM O EFEITO DE PISCAR O TEXTO
        }
        else if(op_ant == 2)//CASO A OPÇÃO EM SELEÇÃO SEJA A SEGUNDA
        {
            gotoxy(16,12);
            printf("   CL%cSSICO",181);
            gotoxy(16,16);
            printf("   HARDCORE");
            gotoxy(16,18);
            printf("   IMPOSSIBLE");
            op = efeito_piscartexto("-> ARCADE",9,16,14,200);//OPÇÃO EM SELEÇÃO COM O EFEITO DE PISCAR O TEXTO
        }
        else if(op_ant == 3)//CASO A OPÇÃO EM SELEÇÃO SEJA A TERCEIRA
        {
            gotoxy(16,12);
            printf("   CL%cSSICO",181);
            gotoxy(16,14);
            printf("   ARCADE");
            gotoxy(16,18);
            printf("   IMPOSSIBLE");
            op = efeito_piscartexto("-> HARDCORE",11,16,16,200);//OPÇÃO EM SELEÇÃO COM O EFEITO DE PISCAR O TEXTO
        }
        else if(op_ant == 4)//CASO A OPÇÃO EM SELEÇÃO SEJA A QUARTA
        {
            gotoxy(16,12);
            printf("   CL%cSSICO",181);
            gotoxy(16,14);
            printf("   ARCADE");
            gotoxy(16,16);
            printf("   HARDCORE");
            op = efeito_piscartexto("-> IMPOSSIBLE",13,16,18,200);//OPÇÃO EM SELEÇÃO COM O EFEITO DE PISCAR O TEXTO
        }

        switch(op)  // MUDAR O VALOR DA OPÇÃO SE O USÁRIO ESCOLHER "SETA PARA CIMA" OU "SETA PARA BAIXO"
        {
        case 80:
            //op_ant + 1;//SETA PARA BAIXO
            op_ant++;
            break;
        case 72:
            //op_ant -1;//SETA PARA CIMA
            op_ant--;
            break;
        case 'w':
            op_ant--;//SETA PARA CIMA
            break;
        case 'W':
            op_ant--;//SETA PARA CIMA
            break;
        case 's':
            op_ant++;//SETA PARA BAIXO
            break;
        case 'S':
            op_ant++;//SETA PARA BAIXO
            break;
        }

        switch(op_ant)//PARA PODER FAZER A TRANSIÇÃO DA ÚLTIMA OPÇÃO PARA A PRIMEIRA, CASO O USUÁRIO CLIQUE PARA BAIXO NA ÚLTIMA OPÇÃO
        {
        case 0:
            op_ant = 4;//USUÁRIO CLICOU PARA CIMA NA PRIMEIRA OPÇÃO, REDIRECIONA PARA A ÚLTIMA OPÇÃO
            break;
        case 5:
            op_ant = 1;//USUÁRIO CLICOU PARA BAIXO NA ÚLTIMA OPÇÃO, REDIRECIONA PARA A PRIMEIRA OPÇÃO
            break;
        }

        if(op == 13)// USUÁRIO CLICOU ENTER EM ALGUMA DAS OPÇÕES
        {
            switch(op_ant)
            {
            case 1:
                return 0;
                break;
            case 2:
                return 1;
                break;
            case 3:
                return 2;
                break;
            case 4:
                return 3;
                break;
            }
        }
    }
    return 0;
}

void formar_quadrado(int largura,int altura,int x,int y)
{
    int i,j;

    gotoxy(x,y);
    for(i=0; i<altura; i++)
    {
        for(j=0; j<largura; j++)
        {
            if(i==1 || i==(altura-1))
                printf("%c",219);
            else if(j==0 || j==(largura-1))
                printf("%c",219);
            else
                printf(" ");

        }
        gotoxy(x,y+i);
    }
}

void montar_fase(int fase)
{
    char cor[25];

    if(fase==0)
    {

        //PRIMEIRA LINHA DE BLOCOS
        cor[1] = 0;
        cor[2] = 0;
        cor[3] = 0;
        cor[4] = 0;
        cor[5] = 0;
        cor[6] = 0;

        //SEGUNDA LINHA DE BLOCOS
        cor[7] = 0;
        cor[8] = 0;
        cor[9] = 0;
        cor[10] = 0;
        cor[11] = 0;
        cor[12] = 0;

        //TERCEIRA LINHA DE BLOCOS
        cor[13] = 0;
        cor[14] = 0;
        cor[15] = 0;
        cor[16] = 0;
        cor[17] = 0;
        cor[18] = 0;

        //QUARTA LINHA DE BLOCOS
        cor[19] = 0;
        cor[20] = 0;
        cor[21] = 0;
        cor[22] = 0;
        cor[23] = 0;
        cor[24] = 0;

    }

return cor;
}
