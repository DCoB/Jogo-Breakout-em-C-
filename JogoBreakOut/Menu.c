#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <TIME.H>
#include "Menu.h"
#include "Auxiliares.h"
#include "Jogo.h"
#include "Ranking.h"
#include "tela.h"


#define NOP 0
#define QQ 219
#define DGD 178
#define dGd 177
#define dgd 176
#define Ver 186
#define Hor 205
#define QSE 201
#define QIE 200
#define QSD 187
#define QID 188
#define Hb 203
#define Hc 202
#define Pp 175
#define CDLH 135


// Link para tabela ASCII http://www.thortech.ind.br/img/products/505d181f53.pdf

int Menu()
{
    system("cls");
    configtela(44,23);
    char op,BreakOut[8][32];
    //char blA[4][15];
    int Vamos_Jogar(),Placar(),op_ant=1,loop;
    int Configuracao(),Ajuda();
    int i,j;
    for(i=0; i<8; ++i)
    {
        for(j=3; j<32; ++j)
        {
            BreakOut[i][j]=NOP;
        }
    }
    for(i=0; i<5; ++i)
    {
        for(j=0; j<15; ++j)
        {
            BreakOut[i][j]=NOP;
        }
    }
    {
        // AQUI É ONDE COMEÇA A IMPRIMIR O NOME "BREAKOUT"
        //B
        for(i=0; i<3; ++i)
        {
            for(j=0; j<3; ++j)
            {
                BreakOut[i][j]=DGD;
            }
        }
        BreakOut[0][2]=NOP;
        BreakOut[2][1]=NOP;
        for(i=3; i<6; ++i)
        {
            for(j=0; j<3; ++j)
            {
                BreakOut[i][j]=dGd;
            }
        }
        BreakOut[3][2]=NOP;
        BreakOut[4][2]=NOP;
        BreakOut[5][1]=NOP;
        for(i=6; i<8; ++i)
        {
            for(j=0; j<3; ++j)
            {
                BreakOut[i][j]=dgd;
            }
        }
        BreakOut[7][2]=NOP;
        printf("\n\t");
        //r
        for(i=3; i<6; ++i)
        {
            for(j=4; j<7; ++j)
            {
                BreakOut[i][j]=dGd;
            }
        }
        BreakOut[3][5]=NOP;
        BreakOut[3][6]=NOP;
        BreakOut[5][5]=NOP;
        BreakOut[6][4]=dgd;
        BreakOut[7][4]=dgd;
        //k
        BreakOut[2][16]=DGD;
        BreakOut[2][18]=DGD;
        for(i=3; i<6; ++i)
        {
            for(j=16; j<19; ++j)
            {
                BreakOut[i][j]=dGd;
            }
        }
        BreakOut[3][17]=NOP;
        BreakOut[4][18]=NOP;
        BreakOut[5][17]=NOP;
        BreakOut[6][18]=dgd;
        BreakOut[7][18]=dgd;
        BreakOut[6][16]=dgd;
        BreakOut[7][16]=dgd;
        //u
        for(i=3; i<6; ++i)
        {
            BreakOut[i][24]=dGd;
            BreakOut[i][26]=dGd;
        }
        BreakOut[6][24]=dgd;
        BreakOut[6][26]=dgd;
        BreakOut[7][25]=dgd;
        BreakOut[7][24]=dgd;
        BreakOut[7][26]=dgd;
        //t
        for(i=3; i<6; ++i)
        {
            BreakOut[i][29]=dGd;
        }
        BreakOut[4][28]=dGd;
        BreakOut[4][30]=dGd;
        for(j=29; j<31; ++j)
        {
            BreakOut[7][j]=dgd;
        }
        BreakOut[6][29]=dgd;
        //O
        for(i=3; i<6; ++i)
        {
            BreakOut[i][20]=dGd;
            BreakOut[i][22]=dGd;
        }
        BreakOut[0][21]=DGD;
        BreakOut[7][21]=dgd;
        for(i=0; i<3; ++i)
        {
            BreakOut[i][20]=DGD;
            BreakOut[i][22]=DGD;
        }
        for(i=6; i<8; ++i)
        {
            BreakOut[i][20]=dgd;
            BreakOut[i][22]=dgd;
        }
        //a
        for(i=3; i<6; ++i)
        {
            for(j=12; j<15; ++j)
            {
                BreakOut[i][j]=dGd;
            }
        }
        BreakOut[4][12]=NOP;
        BreakOut[4][13]=NOP;
        for(i=6; i<8; ++i)
        {
            for(j=12; j<15; ++j)
            {
                BreakOut[i][j]=dgd;
            }
        }
        BreakOut[6][13]=NOP;
        //e
        for(i=3; i<6; ++i)
        {
            for(j=8; j<11; ++j)
            {
                BreakOut[i][j]=dGd;
            }
        }
        BreakOut[4][9]=NOP;
        for(j=8; j<11; ++j)
        {
            BreakOut[7][j]=dgd;
        }
        BreakOut[6][8]=dgd;
    }
    //AQUI É ONDE TERMINA DE IMPRIMIR O NOME "BREAKOUT"

    do
    {
        srand(time(NULL));//GARANTIR QUE O NÚMERO POSTERIOR NÃO SERÁ IGUAL AO ANTERIOR
        loop = rand()%16;//GERAR UM NÚMERO ALETÓRIO PARA A VARIÁVEL LOOP
        if(loop!=0)//COR DIFERENTE DE PRETO
        {
            textcolor(loop);//IMPRIMIR O NOME "BREAKOUT" COM A COR ALEATÓRIA
        }
    }
    while(loop==0); //PARA QUE GARANTE QUE NUNCA SEJA SELECIONADA A COR PRETA
    for(i=0; i<8; ++i)//IMPRIMIR O NOME "BREAKOUT"
    {
        for(j=0; j<32; ++j)
        {
            printf("%c",BreakOut[i][j]);
        }
        printf("\n\t");
    }
    textcolor(15);//MUDAR A COR DO TEXTO PARA BRANCO
    while(1)//LOOPING QUE FAZ O MOVIMENTO DAS OPÇÕES
    {

        if(op_ant == 1)//CASO A OPÇÃO EM SELEÇÃO SEJA A PRIMEIRA
        {

            gotoxy(16,14);
            printf("   PLACAR");
            gotoxy(16,16);
            printf("   AJUDA");
            gotoxy(16,18);
            printf("   SAIR");
            op = efeito_piscartexto("-> JOGAR",7,16,12,200);//OPÇÃO EM SELEÇÃO COM O EFEITO DE PISCAR O TEXTO
        }
        else if(op_ant == 2)//CASO A OPÇÃO EM SELEÇÃO SEJA A SEGUNDA
        {
            gotoxy(16,12);
            printf("   JOGAR");
            gotoxy(16,16);
            printf("   AJUDA");
            gotoxy(16,18);
            printf("   SAIR");
            op = efeito_piscartexto("-> PLACAR",8,16,14,200);//OPÇÃO EM SELEÇÃO COM O EFEITO DE PISCAR O TEXTO
        }
        else if(op_ant == 3)//CASO A OPÇÃO EM SELEÇÃO SEJA A TERCEIRA
        {
            gotoxy(16,12);
            printf("   JOGAR");
            gotoxy(16,14);
            printf("   PLACAR");
            gotoxy(16,18);
            printf("   SAIR");
            op = efeito_piscartexto("-> AJUDA",7,16,16,200);//OPÇÃO EM SELEÇÃO COM O EFEITO DE PISCAR O TEXTO
        }
        else if(op_ant == 4)//CASO A OPÇÃO EM SELEÇÃO SEJA A QUARTA
        {
            gotoxy(16,12);
            printf("   JOGAR");
            gotoxy(16,14);
            printf("   PLACAR");
            gotoxy(16,16);
            printf("   AJUDA");
            op = efeito_piscartexto("-> SAIR",8,16,18,200);//OPÇÃO EM SELEÇÃO COM O EFEITO DE PISCAR O TEXTO
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
                Vamos_Jogar();
                break;
            case 2:
                Placar();
                break;
            case 3:
                Ajuda();
                break;
            case 4:
                Sair();
                break;
            }
        }
    }

    //FIM OPÇÕES
    return 0;
}

int Vamos_Jogar()
{
    system("cls");
    jogo();
    return 0;
}

int Placar()
{
    system("cls");
    char AA, placar[5][23];
    int i,j;
    for(i=0; i<5; ++i)
    {
        for(j=0; j<22; ++j)
        {
            placar[i][j]=NOP;
        }
    }
    {
        //PLACAR
        for(j=0; j<24; ++j)
        {
            if(j<3||j==4||j==8||j==9||j==10||j==12||j==13||j==14||j==16||j==17||j==18||j==20||j==21||j==22)placar[0][j]=QQ;
        }
        for(j=0; j<24; ++j)
        {
            if(j==0||j==2||j==4||j==8||j==10||j==12||j==16||j==18||j==20||j==22)placar[1][j]=QQ;
        }
        for(j=0; j<24; ++j)
            if(j<3||j==4||j==8||j==9||j==10||j==12||j==16||j==17||j==18||j==20||j==21)placar[2][j]=QQ;
        for(j=0; j<24; ++j)
            if(j==0||j==4||j==8||j==10||j==12||j==16||j==18||j==20||j==22)placar[3][j]=QQ;
        for(j=0; j<24; ++j)
        {
            if(j==0||j==4||j==5||j==6||j==8||j==10||j==12||j==13||j==14||j==16||j==18||j==20||j==22)placar[3][j]=QQ;
        }


        printf("\n\n\t\t");
        for(i=0; i<5; ++i)
        {
            for(j=0; j<23; ++j)
            {
                placar[4][22]=NOP;
                placar[2][22]=NOP;
                //placar[2][22]==' ';
                printf("%c",placar[i][j]);
            }
            printf("\n\t\t");
        }
    }
    configtela(60,24);
    gotoxy(6,8);
    printf("NOME");
    gotoxy(28,8);
    printf("PONTOS");
    gotoxy(48,8);
    printf("MODO");

    DadosJogadoresPassados(1);
    printf("\n\n PARA VOLTAR OU MENU DIGITE QUALQUER TECLA");
    AA=getch();

    if(AA==13)
    {
        ZeraRanking();
        system("cls");
        Placar();
    }
    else
    {
        system("cls");
        Menu();
    }
    return 0;
}

int Ajuda()
{
    char AA, ajuda[5][19];
    int i,j;
    for(i=0; i<5; ++i)
    {
        for (j=0; j<19; ++j)
        {
            ajuda[i][j]=NOP;
        }
    }

    /*0*/  for(j=0; j<19; ++j)
    {
        if(j<3||j==6||j==8||j==10||j==12||j==13||j==16||j==17||j==18) ajuda[0][j]=QQ;
    }
    /*1*/  for(j=0; j<19; ++j)
    {
        if(j==0||j==2||j==6||j==8||j==10||j==12||j==14||j==16||j==18) ajuda[1][j]=QQ;
    }
    /*2*/  for(j=0; j<19; ++j)
    {
        if(j<3||j==6||j==8||j==10||j==12||j==14||j==16||j==17||j==18) ajuda[2][j]=QQ;
    }
    /*3*/  for(j=0; j<19; ++j)
    {
        if(j==0||j%2==0)ajuda[3][j]=QQ;
    }
    /*4*/  for(j=0; j<19; ++j)
    {
        if(j==0||j==0||j==2||j==4||j==5||j==6||j==8||j==9||j==10||j==12||j==13||j==16||j==18)ajuda[4][j]=QQ;
    }

    system("cls");
    configtela(80,100);
    printf("\n\n\t\t");
    for(i=0; i<5; ++i)
    {
        for (j=0; j<19; ++j)
        {
            printf("%c",ajuda[i][j]);
        }
        printf("\n\t\t");
    }

    formar_quadrado(77,18,3,10);
    gotoxy(5,12);
    textcolor(2);
    printf("COMANDOS:");
    textcolor(15);
    gotoxy(5,14);
    printf("PRESSIONE 'D' OU 'DIREITA' --> MOVIMENTAR A BARRA PARA A DIREITA");
    gotoxy(5,16);
    printf("PRESSIONE 'A' OU 'ESQUERDA' --> MOVIMENTAR A BARRA PARA A ESQUERDA");
    gotoxy(5,18);
    printf("PRESSIONE 'P' --> PAUSAR/DESPAUSAR O JOGO");
    gotoxy(5,20);
    printf("PRESSIONE 'Q' --> ATIVAR A PRIMEIRA ABILIDADE");
    gotoxy(5,22);
    printf("PRESSIONE 'W' --> ATIVAR A SEGUNDA ABILIDADE");
    gotoxy(5,24);
    printf("PRESSIONE 'E' --> ATIVAR A TERCEIRA ABILIDADE");

    formar_quadrado(77,12,3,29);
    gotoxy(5,31);
    textcolor(12);
    printf("HABILIDADES ESPECIAIS:");
    textcolor(15);
    gotoxy(5,33);
    printf("KBOMMM (Q) --> ELIMINA UM BLOCO ALEAT%cRIO DO CAMPO E CUSTA ",181);
    textcolor(12);
    printf("200 PONTOS");
    textcolor(15);
    gotoxy(5,35);
    printf("EXPANDIR (W) --> AUMENTA A BARRA DURANTE 10 SEG E CUSTA ");
    textcolor(12);
    printf("50 PONTOS");
    textcolor(15);
    gotoxy(5,37);
    printf("TARTARUGA (E) --> DIMINUI A VELOCIDADE DA BOLA EM 10 SEG E CUSTA ");
    textcolor(12);
    printf("20 PONTOS");
    textcolor(15);

    formar_quadrado(77,19,3,42);
    gotoxy(5,44);
    textcolor(5);
    printf("BLOCOS:");
    textcolor(15);
    gotoxy(5,46);
    printf("TODOS OS BLOCOS POSSUEM POR PADRÃO 3 DE VIDA,E PEDEM VIDA CONFORME");
    gotoxy(5,47);
    printf("S%cO ATINGIDOS, AO SEREM ATINGIDOS ELES MUDAM DE APAR%cNCIA",199,210);

    gotoxy(5,49);
    printf("3 DE VIDA:");
    gotoxy(5,50);
    textcolor(15);
    printf("%c------%c",201,187);
    gotoxy(5,51);
    printf("|%c %c%c %c|\n",92,47,92,47);
    gotoxy(5,52);
    printf("|%c %c%c %c|\n",47,92,47,92);
    gotoxy(5,53);
    printf("%c------%c",200,188);
    textcolor(15);

    gotoxy(20,49);
    printf("2 DE VIDA:");
    gotoxy(20,50);
    textcolor(6);
    printf("%c------%c",201,187);
    gotoxy(20,51);
    printf("|%c    %c|\n",92,47);
    gotoxy(20,52);
    printf("|  %c%c  |\n",92,47);
    gotoxy(20,53);
    printf("%c------%c",200,188);
    textcolor(15);

    gotoxy(35,49);
    printf("1 DE VIDA:");
    gotoxy(35,50);
    textcolor(4);
    printf("%c------%c",201,187);
    gotoxy(35,51);
    printf("|      |");
    gotoxy(35,52);
    printf("|      |");
    gotoxy(35,53);
    printf("%c------%c",200,188);
    textcolor(15);

    gotoxy(5,56);
    printf("TAMB%cM EST%cO PRESENTES NO JOGO ALGUMAS '%cREAS FANTASMAS'",144,199,181);
    gotoxy(5,57);
    printf("ENT%cO N%co SE ASSUSTE SE A BOLA ATRAVESSAR ALGUNS BLOCOS!",199,199);

    formar_quadrado(77,14,3,62);
    gotoxy(5,64);
    textcolor(3);
    printf("MODOS DE JOGO:");
    textcolor(15);
    gotoxy(5,66);
    printf("CL%cSSICO --> ESTILO DE JOGO PADR%cO",181,199);
    gotoxy(5,68);
    printf("ARCADE --> VELOCIDADE DA BOLA ALTA E BARRA DESLIZANTE");
    gotoxy(5,70);
    printf("HARDCORE --> VELOCIDADE DA BOLA ALTA, BARRA DESLIZANTE E BLOCOS INVIS%cVEIS",214);
    gotoxy(5,72);
    printf("IMPOSSIBLE --> NEM TENTE");

    textcolor(14);
    formar_quadrado(77,15,3,77);
    textcolor(15);
    gotoxy(26,79);
    printf("TIME DE DESENVOLVIMENTO");
    gotoxy(5,81);
    printf("ALUNOS: Daniel Barbosa, Matheus Alves,Jo%co Miguel, Silas Nunes",198);
    gotoxy(5,83);
    printf("DISCIPLINA: LINGUAGEM DE PROGRAMA%c%co IMPERATIVA",128,199);
    gotoxy(5,85);
    printf("PROFESSOR ORIENTADOR: Joabe Jesus");
    gotoxy(5,87);
    printf("INSTITUI%c%cO: UPE/POLI",128,199);
    gotoxy(5,89);
    printf("2017");
    hideCursor();

    gotoxy(2,93);
    printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");

    AA=getch();
    if(AA!=NOP)
    {
        system("cls");
        Menu();
    }
    return 0;
}

int Sair()
{
    exit(0);
}


