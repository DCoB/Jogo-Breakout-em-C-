#ifndef AUXILIARES_H_INCLUDED
#define AUXILIARES_H_INCLUDED
#endif // AUXILIARES_H_INCLUDED


void textcolor (int cor);//FUN��O PARA MUDAR A COR DO TEXTO
int configtela(int X,int Y);//FUN��O QUE CONFIGURA O TAMANHO DA TELA E DO BUFFER
int hideCursor();//FUN��O PARA ESCONDER O CURSOR
void pausa(int ParX,int ParY);//FUN��O PARA PAUSAR O JOGO
void ContagemRegressiva(int x,int y);//FUN��O DE CONTAGEM REGRESSIVA
void gotoxy(int x, int y);//FUN��O PARA POSICIONAR O CURSOR NO X E Y DA TELA
int efeito_piscartexto(char texto[100],int i,int x,int y,int TEMPO);//FUN��O PARA FAZER O TEXTO FICAR PISCANDO
void apagar_texto(int x,int y,int tamanho);//FUN��O PARA APAGAR UM TEXTO

