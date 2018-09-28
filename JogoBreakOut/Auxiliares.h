#ifndef AUXILIARES_H_INCLUDED
#define AUXILIARES_H_INCLUDED
#endif // AUXILIARES_H_INCLUDED


void textcolor (int cor);//FUN플O PARA MUDAR A COR DO TEXTO
int configtela(int X,int Y);//FUN플O QUE CONFIGURA O TAMANHO DA TELA E DO BUFFER
int hideCursor();//FUN플O PARA ESCONDER O CURSOR
void pausa(int ParX,int ParY);//FUN플O PARA PAUSAR O JOGO
void ContagemRegressiva(int x,int y);//FUN플O DE CONTAGEM REGRESSIVA
void gotoxy(int x, int y);//FUN플O PARA POSICIONAR O CURSOR NO X E Y DA TELA
int efeito_piscartexto(char texto[100],int i,int x,int y,int TEMPO);//FUN플O PARA FAZER O TEXTO FICAR PISCANDO
void apagar_texto(int x,int y,int tamanho);//FUN플O PARA APAGAR UM TEXTO

