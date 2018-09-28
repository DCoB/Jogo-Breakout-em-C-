#ifndef BLOCOS_H_INCLUDED
#define BLOCOS_H_INCLUDED
#endif // BLOCOS_H_INCLUDED

int y_do_bloco_colidido(int bloco,int campo);//"Y" INICIAL DO BLOCO QUE A BOLA COLIDIU
int x_do_bloco_colidido(int bloco,int campo);//"X" INICIAL DO BLOCO QUE A BOLA COLIDIU
void aparencia_bloco(int bloco,int vida,int campo);//MUDA A COR DO BLOCO OU APAGA O MESMO
int redirecinar_bola(int Xbola, int Ybola,int direcao,int Xbloco,int Ybloco,int vida_bloco[],int bloco,int campo);//REDIRECIONAR A BOLA DE ACORDO COM O LOCAL QUE ELA BATEU NO BLOCO
int colisao_bloco(int xbola,int y,int campo,int direcao);//CHECAR QUAL BLOCO A BOLA BATEU
int montagem_bloco(int campo,int fase);//MONTAR OS BLOCOS NO CAMPO
