#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "Ranking.h"
#include "arquivo.h"
#include "Auxiliares.h"

#define ENTER 13
//Variáveis e funções globais
extern int i,j,k;
extern void gotoxy(int x,int y);
extern void textcolor(int cor);
struct jogador //Jogador atual
{
    char nome[12];
    char vidas;
    char nivel;
    int pontos;
    int velocidade;
};
extern struct jogador player;//Jogador atual

//Variável de dados sobre jogadores passados
struct JOGADORES
{
    char nome[20];
    char nivel;
    int pontos;
};//tipo JOGADOR
struct JOGADORES JogadoresRanking[10];//Comporta no máximo 10 jogadas anteriores
char mesmojogador=1;
//variável que mostra ranking
char MostreRanking=0;//bug que duplicava o resultado anterior (resolvido)
char iniciou=1;//permite que o programa leia o arquivo apenas uma vez

void DadosJogadorAtual() //Impressão dos dados dos jogadores
{
    while(1) //não deixa que usuario digite um nome alem do limite
    {
        //DesenhoMenu(14,70,1);
        gotoxy(4,3);
        printf("INFORME O SEU NOME:");
        gotoxy(6,4);
        gets(player.nome);
        if(strlen(player.nome)>13)
        {
            system("cls");
            gotoxy(4,10);
            printf("TAMANHO M%cXIMO EXCEDIDO",181);
            gotoxy(4,12);
            system("pause");
            apagar_texto(4,10,24);
            apagar_texto(4,12,50);
            continue;
        }
        else if(strlen(player.nome)==0)
        {
            system("cls");
            gotoxy(4,10);
            printf("N%cO %c PERMITIDO NOME EM BRANCO",199,144);
            gotoxy(4,12);
            system("pause");
            apagar_texto(4,10,31);
            apagar_texto(4,12,50);
            continue;
        }
        else
        {
            system("cls");
            break;
        }
    }
}
void FormaDadosJogadores() //Geração dos dados iniciais dos jogadores
{
    int i;
    for(i=0; i<10; i++)
    {
        strcpy(JogadoresRanking[i].nome,"-----");
        JogadoresRanking[i].pontos=0;
        JogadoresRanking[i].nivel=0;
    }
}
void MesmoJogador()
{
    int i,j;
    for(i=0; i<10; i++)
    {
        if(!strcmp(JogadoresRanking[i].nome,player.nome)) //atualizando valor do mesmo jogador
        {
            JogadoresRanking[i].pontos=player.pontos;
            JogadoresRanking[i].nivel=player.nivel;
            for(j=0; j<10; j++) //Eliminando dados do jogador antigo
            {
                if(!strcmp(JogadoresRanking[i].nome,JogadoresRanking[j].nome))
                {
                    strcpy(JogadoresRanking[j].nome,JogadoresRanking[j+1].nome);
                    JogadoresRanking[j].pontos=JogadoresRanking[j+1].pontos;
                    JogadoresRanking[j].nivel=JogadoresRanking[j+1].nivel;
                    break;
                }
            }
        }
    }
}
void AtualizaDadosJogadores()
{
    int i,j;
    for(i=0; i<10; i++)
    {
        if(player.pontos>JogadoresRanking[i].pontos&&player.pontos!=1) //atualizada dados com novo jogador
        {
            for(j=9; j>i; j--) //Atualiza lista, mantendo-a em ordem descrescente (pontos)
            {
                strcpy(JogadoresRanking[j].nome,JogadoresRanking[j-1].nome);
                JogadoresRanking[j].pontos=JogadoresRanking[j-1].pontos;
                JogadoresRanking[j].nivel=JogadoresRanking[j-1].nivel;
            }
            strcpy(JogadoresRanking[i].nome,player.nome);//dados do jogador que teve a maior pontuação
            JogadoresRanking[i].pontos=player.pontos;
            JogadoresRanking[i].nivel=player.nivel;
            player.pontos=1;
            break;
        }
    }
}
void ZeraRanking() //Função que apaga todos os dados sobre os jogadores
{
    //DesenhoMenu(14,64,1);
    system("cls");
    gotoxy(20,3);
    printf("APAGAR RANKING");
    gotoxy(6,5);
    printf("--> UMA VEZ APAGADO,");
    gotoxy(6,6);
    printf("OS DADOS N%cO PODEM SER RESGATADOS.",199);
    gotoxy(4,9);
    textcolor(12);
    printf("TEM CERTEZA QUE DESEJA APAGAR O RANKING?");
    textcolor(15);
    gotoxy(6,12);
    printf("-> TECLE ENTER PARA CONFIRMAR");
    gotoxy(6,13);
    printf("-> TECLE QUALQUER OUTRA TECLA PARA CANCELAR");
    fflush(stdin);
    if(getch()==13)
    {
        //DesenhoMenu(14,64,1);
        system("cls");
        gotoxy(20,3);
        printf("RANKING APAGADO.");
        Sleep(1000);
        FormaDadosJogadores();
        SaveFile();
    }
}
void DadosJogadoresPassados(int print) //Dados existentes na partida atual (também serve para resgatar os dados em arquivos)
{
    int i;

    if(player.pontos==0)
        FormaDadosJogadores();
    if(iniciou==1)
    {
        LoadFile();//Efetua leitura do ranking no arquivo
        iniciou=0;
    }
    AtualizaDadosJogadores();
    if(print==1)
    {
        for(i=0; i<10; i++)
        {
            if((i==0)&&(strcmp(JogadoresRanking[0].nome,"-----")!=0))
            {
                textcolor(14);
            }
            else if((i==1)&&(strcmp(JogadoresRanking[1].nome,"-----")!= 0))
            {
                textcolor(9);
            }
            else if((i==2)&&(strcmp(JogadoresRanking[2].nome,"-----")!=0))
            {
                textcolor(12);
            }
            gotoxy(2,10+i);
            printf("%d",i+1);
            gotoxy(5,10+i);
            puts(JogadoresRanking[i].nome);
            gotoxy(30,10+i);
            printf("%d",JogadoresRanking[i].pontos);
            gotoxy(50,10+i);
            if(JogadoresRanking[i].nivel==1)
            {
                printf("CL%cSSICO",181);
            }
            else if(JogadoresRanking[i].nivel==2)
            {
                printf("ARCADE");
            }
            else if(JogadoresRanking[i].nivel==3)
            {
                printf("HARDCORE");
            }
            else if(JogadoresRanking[i].nivel==4)
            {
                printf("IMPOSSIBLE");
            }
            else
                printf("%d",JogadoresRanking[i].nivel);
                textcolor(15);
        }
        gotoxy(2,22);
        printf("TECLE ENTER PARA APAGAR O RANKING.");
    }

    SaveFile();
}

