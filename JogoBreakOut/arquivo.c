#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "arquivo.h"

//vari�veis globais
extern int i,j,k;
extern struct JOGADORES
{
    char nome[20];
    char nivel;
    int pontos;
};
extern struct JOGADORES JogadoresRanking[10];//estrutura que ir� conter os dados salvos no jogo
struct JOGADORES *pJogadoresRanking;//ponteiro para modificar a estrutura do ranking (arquivos)
char count=0;//vari�vel de apoio para leitura e escrita
//vari�vel para abertura e fechamento do arquivo
FILE *savegame;
void LoadFile() //Efetua a leitura dos dados, caso arquivo n�o exista, um novo � criado
{
    int i;

    savegame=fopen("RankingBreakOut.ranking","r+b");
    for(i=0; i<10; i++) //leitura de membro a membro
    {
        fread(&JogadoresRanking[i],sizeof (struct JOGADORES),1,savegame);
    }
    fclose(savegame);
}
void SaveFile() //Efetua o salvamento dos dados, caso arquivo n�o consiga, erro � mostrado
{
    int i;
    savegame=fopen("RankingBreakOut.ranking","wb");
    if(savegame==NULL) //Caso true, um novo arquivo ter� de ser criado
    {
        savegame=fopen("RankingBreakOut.ranking","w+b");//Arquivo � aberto para efetuar a leitura dos dados, leitura desde o inicio
    }
    for(i=0; i<10; i++) //salvamento de membro a membro - uso de ponteiros
    {
        pJogadoresRanking=&JogadoresRanking[i];
        fwrite(pJogadoresRanking,sizeof (struct JOGADORES),1,savegame);
    }
    fclose(savegame);
}
void Abertura() //informa��es sobre abertura de arquivo
{
    int i;
    savegame=fopen("RankingBreakOut.ranking","rb");
    if(savegame==NULL) //Caso true, um novo arquivo ter� de ser criado
    {
        printf("[Problema na leitura do arquivo. Novo arquivo criado]");
        savegame=fopen("RankingBreakOut.ranking","wb");
    }
    else
        printf("[Arquivo de salvamento encontrado]\n");
    if(fclose(savegame)!=0)//fechamento do arquivo
        printf("[Problema ao fechar o arquivo. Favor verificar a causa!]\n");
}




