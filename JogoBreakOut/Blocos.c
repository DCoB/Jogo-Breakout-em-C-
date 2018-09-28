#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <TIME.H>
#include "Auxiliares.h"
#include "Blocos.h"

int y_do_bloco_colidido(int bloco,int campo)//"Y" INICIAL DO BLOCO QUE A BOLA COLIDIU
{
    int y;
    if(campo==0)
    {
        //PRIMEIRA LINHA DE BLOCOS
        if((bloco==1)||(bloco==2)||(bloco==3)||(bloco==4)||(bloco==5)||(bloco==6))
            y=2;
        //SEGUNDA LINHA DE BLOCOS
        else if((bloco==7)||(bloco==8)||(bloco==9)||(bloco==10)||(bloco==11)||(bloco==12))
            y=6;
        //TERCEIRA LINHA DE BLOCOS
        else if((bloco==13)||(bloco==14)||(bloco==15)||(bloco==16)||(bloco==17)||(bloco==18))
            y=10;
        //QUARTA LINHA DE BLOCOS
        else if((bloco==19)||(bloco==20)||(bloco==21)||(bloco==22)||(bloco==23)||(bloco==24))
            y=14;
        else if(bloco==49)
            y=0;
    }
    return y;
}

int x_do_bloco_colidido(int bloco,int campo)//"X" INICIAL DO BLOCO QUE A BOLA COLIDIU
{
    int x;

    if(campo==0)
    {
        if((bloco==1)||(bloco==7)||(bloco==13)||(bloco==19))
            x=3;
        else if((bloco==2)||(bloco==8)||(bloco==14)||(bloco==20))
            x=11;
        else if((bloco==3)||(bloco==9)||(bloco==15)||(bloco==21))
            x=19;
        else if((bloco==4)||(bloco==10)||(bloco==16)||(bloco==22))
            x=27;
        else if((bloco==5)||(bloco==11)||(bloco==17)||(bloco==23))
            x=35;
        else if((bloco==6)||(bloco==12)||(bloco==18)||(bloco==24))
            x=43;
        else if(bloco==49)
            x=0;

    }
    return x;

}

void aparencia_bloco(int bloco,int vida,int campo)//MUDA A COR DO BLOCO OU APAGA O MESMO
{
    int x,y,cont;

    if(campo == 0)
    {

        if(bloco==49)
        {

        }
        else if(vida == 1)//APAGA O BLOCO
        {
            for(cont=0; cont<=3; cont++)
            {
                gotoxy(x_do_bloco_colidido(bloco,campo),y_do_bloco_colidido(bloco,campo)+cont);
                printf("        ");
            }
        }
        else
        {
            if(vida==3)
            {
                textcolor(6);//MUDA A COR PARA VERDE
                for(cont=0; cont<=3; cont++)
                {
                    gotoxy(x_do_bloco_colidido(bloco,campo),y_do_bloco_colidido(bloco,campo)+cont);
                    if(cont == 0 )
                    {
                        printf("%c------%c",201,187);
                    }
                    else if(cont ==3)
                    {
                        printf("%c------%c",200,188);
                    }
                    else if(cont==1)
                        printf("|%c    %c|\n",92,47);
                    else
                        printf("|  %c%c  |\n",92,47);
                }
            }
            else
            {
                textcolor(4);//MUDA A COR PARA AZUL
                for(cont=0; cont<=3; cont++)
                {
                    gotoxy(x_do_bloco_colidido(bloco,campo),y_do_bloco_colidido(bloco,campo)+cont);
                    if(cont == 0 )
                    {
                        printf("%c------%c",201,187);
                    }
                    else if(cont ==3)
                    {
                        printf("%c------%c",200,188);
                    }
                    else if(cont==1)
                        printf("|      |\n");
                    else
                        printf("|      |\n");
                }
            }

            textcolor(15);

        }


    }
}

int redirecinar_bola(int Xbola, int Ybola,int direcao,int Xbloco,int Ybloco,int vida_bloco[],int bloco,int campo)
{
    int Xmax,Ymax;
    if(campo==0)
    {
        Xmax=43;
        Ymax=14;
    }


    if((Xbola>Xbloco)&&(Xbola<Xbloco+7))//A BOLA BATEU OU NA PARTE DE CIMA OU NA PARTE DE BAIXO DO BLOCO
    {
        if(Ybola==Ybloco-1)//A BOLA BATEU NA PARTE DE CIMA DO BLOCO
        {
            if(direcao==3)//DESCENDO PARA A ESQUERDA
            {
                direcao = 1;//SUBINDO PARA A ESQUERDA
            }
            else if(direcao ==2)//DESCENDO PARA A DIREITA
            {
                direcao = 0;//SUBINDO PARA A DIREITA
            }
        }
        else//A BOLA BATEU NA PARTE DE BAIXO DO BLOCO
        {
            if(direcao == 0)//SUBINDO PARA A DIREITA
            {
                direcao = 2;//DESCENDO PARA A DIREITA
            }
            else if(direcao ==1) //SUBINDO PARA A ESQUERDA
            {
                direcao =3;//DESCENDO PARA A ESQUERDA
            }
        }
    }
    else if(Xbola==Xbloco)//A BOLA BATEU NOS CANTOS ESQUERDOS POR CIMA OU POR BAIXO
    {
        if(Ybola==Ybloco-1)//A BOLA BATEU NO CANTO SUPERIOR ESQUERDO VINDO POR CIMA
        {
            if((Ybloco!=2)&&(Xbloco!=3)&&(vida_bloco[bloco-7]!=0))//TRATAMENTO DE EXCESSÃO CASO A BOLA BATA EXATAMENTE NO ENCONTRO ENTRE O CANTO INFERIOR E SUPERIOR DE 2 BLOCOS
            {
                direcao = 0;//SUBINDO PARA A DIREITA
            }
            else if(direcao==3)//DESCENDO PARA A ESQUERDA
            {
                direcao = 1;//SUBINDO PARA A ESQUERDA
            }
            else if(direcao==2)//DESCENDO PARA A DIREITA
            {
                direcao=0;//SUBINDO PARA A DIREITA
            }
        }
        else if(Ybola==Ybloco+4)//A BOLA BATEU NO CANTO INFERIOR ESQUERDO VINDO POR BAIXO
        {
            if((Ybloco!=Ymax)&&(Xbloco!=3)&&(vida_bloco[bloco+5]!=0))//TRATAMENTO DE EXCESSÃO CASO A BOLA BATA EXATAMENTE NO ENCONTRO ENTRE O CANTO INFERIOR E SUPERIOR DE 2 BLOCOS
            {
                direcao = 2;//DESCENDO PARA A DIREITA
            }
            else if(direcao==0)//SUBINDO PARA A DIREITA
            {
                direcao=2;//DESCENDO PARA A DIREITA
            }
            else if(direcao==1)//SUBINDO PARA A ESQUERDA
            {
                direcao=3;//DESCENDO PARA A ESQUERDA
            }
        }
    }
    else if(Xbola==Xbloco-1)//A BOLA BATEU NOS CANTOS ESQUERDOS VINDO DA ESQUERDA OU A BOLA BATEU NA LATERAL ESQUERDA DO BLOCO
    {
        if((Ybola==Ybloco)||(Ybola==Ybloco+3))//A BOLA BATEU NO CANTO SUPERIOR OU INFERIOR ESQUERDO
        {
            if(direcao==0)//SUBINDO PARA A DIREITA
            {
                direcao=1;//SUBINDO PARA A ESQUERDA
            }
            else if(direcao==2)//DESCENDO PARA A DIREITA
            {
                direcao=3;//DESCENDO PARA A ESQUERDA
            }
        }
        else if(Ybola == Ybloco+4)//A BOLA NA DIAGONAL INFERIOR DO BLOCO
        {
            direcao=3;//DESCENDO PARA A ESQUERDA
        }
        else if(Ybola == Ybloco-1)//A BOLA NA DIAGONAL SUPERIOR DO BLOCO
        {
            direcao=1;//SUBINDO PARA A ESQUERDA
        }
        else if((Ybola>Ybloco)&&(Ybola<Ybloco+3))//A BOLA BATEU NA LATERAL ESQUERDA DO BLOCO
        {
            if(direcao==2)//DESCENDO PARA A DIREITA
            {
                direcao=3;//DESCENDO PARA A ESQUERDA
            }
            else if(direcao==0)//SUBINDO PARA A DIREITA
            {
                direcao=1;//SUBINDO PARA A ESQUERDA
            }
        }
    }
    else if(Xbola==Xbloco+7)//A BOLA BATEU NOS CANTOS DIREITOS POR CIMA OU POR BAIXO
    {
        if(Ybola==Ybloco-1)//A BOLA BATEU NO CANTO SUPERIOR DIREITO
        {
            if((Ybloco!=2)&&(Xbloco!=Xmax)&&(vida_bloco[bloco-5]!=0))//TRATAMENTO DE EXCESSÃO CASO A BOLA BATA EXATAMENTE NO ENCONTRO ENTRE O CANTO INFERIOR E SUPERIOR DE 2 BLOCOS
            {
                direcao = 1;//SUBINDO PARA A ESQUERDA
            }
            else if(direcao==3)//DESCENDO PARA A ESQUERDA
            {
                direcao = 1;//SUBINDO PARA A ESQUERDA
            }
            else if(direcao==2)//DESCENDO PARA A DIREITA
            {
                direcao=0;//SUBINDO PARA A DIREITA
            }
        }
        else if(Ybola==Ybloco+4)//A BOLA BATEU NO CANTO INFERIOR DIREITO
        {
            if((Ybloco!=Ymax)&&(Xbloco!=Xmax)&&(vida_bloco[bloco+7]!=0))//TRATAMENTO DE EXCESSÃO CASO A BOLA BATA EXATAMENTE NO ENCONTRO ENTRE O CANTO INFERIOR E SUPERIOR DE 2 BLOCOS
            {
                direcao = 3;//DESCENDO PARA A ESQUERDA
            }
            else if(direcao==0)//SUBINDO PARA A DIREITA
            {
                direcao=2;//DESCENDO PARA A DIREITA
            }
            else if(direcao==1)//SUBINDO PARA A ESQUERDA
            {
                direcao=3;//DESCENDO PARA A ESQUERDA
            }
        }
    }
    else if(Xbola==Xbloco+8)//A BOLA BATEU NOS CANTOS DIREITOS POR BAIXO OU A BOLA BATEU NA LATERAL DIREITA DO BLOCO
    {
        if((Ybola==Ybloco)||(Ybola==Ybloco+3))//A BOLA BATEU NO CANTO SUPERIOR OU INFERIOR DIREITO
        {
            if(direcao==1)//SUBINDO PARA A ESQUERDA
            {
                direcao=0;//SUBINDO PARA A DIREITA
            }
            else if(direcao==3)//DESCENDO PARA A ESQUERDA
            {
                direcao=2;//DESCENDO PARA A DIREITA
            }
        }
        else if(Ybola == Ybloco+4)//A BOLA NA DIAGONAL INFERIOR DIREITA DO BLOCO
        {
            direcao=2;//DESCENDO PARA A DIREITA
        }
        else if(Ybola == Ybloco-1)//A BOLA NA DIAGONAL SUPERIOR DIREITA DO BLOCO
        {
            direcao=0;//SUBINDO PARA A DIREITA
        }
        else if((Ybola>Ybloco)&&(Ybola<Ybloco+3))//A BOLA BATEU NA LATERAL DIREITA DO BLOCO
        {
            if(direcao==1)//SUBINDO PARA A ESQUERDA
            {
                direcao=0;//SUBINDO PARA A DIREITA
            }
            else if(direcao==3)//DESCENDO PARA A ESQUERDA
            {
                direcao=2;//DESCENDO PARA A DIREITA
            }
        }
    }
    else if(bloco==49)//A BOLA BATEU ENTRE EXATAMENTE NO ENCONTRO ENTRA O BLOCO E A PAREDE ESQUERDA OU DIREITA
    {
        if((Ybola==18)&&(Ybola==14)&&(Ybola==10)&&(Ybola==6))
        {
            if(direcao==0)
            {
                direcao=3;
            }
            else if(direcao==2)
            {
                direcao=1;
            }
            else if(direcao==1)
            {
                direcao=2;
            }
            else if(direcao==3)
            {
                direcao=0;
            }
        }
    }

    return direcao;
}

int colisao_bloco(int xbola,int y,int campo,int direcao)//CHECAR QUAL BLOCO A BOLA BATEU
{
    int bloco_colidido=0,x=xbola;

    if(campo == 0)
    {
        for(x; x%8!=3; x--)
        {
        }

        if((y == 13)&&(xbola!=x)&&(xbola!=x+7))//A BOLA ESTÁ NA QUARTA LINHA DE BLOCOS: CASO SEJA 18 -> BATEU EM BAIXO, CASO SEJA 13 -> BATEU EM CIMA
        {
            switch(x)
            {
            case 3:
                bloco_colidido=19;
                break;
            case 11:
                bloco_colidido=20;
                break;
            case 19:
                bloco_colidido=21;
                break;
            case 27:
                bloco_colidido=22;
                break;
            case 35:
                bloco_colidido=23;
                break;
            case 43:
                bloco_colidido=24;
                break;
            }
        }
        else if(y == 18)
        {
            switch(x)
            {
            case 3:
                bloco_colidido=19;
                break;
            case 11:
                bloco_colidido=20;
                break;
            case 19:
                bloco_colidido=21;
                break;
            case 27:
                bloco_colidido=22;
                break;
            case 35:
                bloco_colidido=23;
                break;
            case 43:
                bloco_colidido=24;
                break;
            }
        }
        else if((y>14)&&(y<18))//A BOLA ESTÁ ENTRE A QUARTA E TERCEIRA LINHA
        {
            if((direcao==1)||(direcao==3))//A BOLA ESTÁ NA LATERAL DIREITA DE ALGUM BLOCO
            {
                if((x==11)&&(x==xbola))
                    bloco_colidido=19;
                else if((x==19)&&(x==xbola))
                    bloco_colidido=20;
                else if((x==27)&&(x==xbola))
                    bloco_colidido=21;
                else if((x==35)&&(x==xbola))
                    bloco_colidido=22;
                else if((x==43)&&(x==xbola))
                    bloco_colidido=23;
            }
            else if((direcao==0)||(direcao==2))//A BOLA ESTÁ NA LATERAL ESQUERDA DE ALGUM BLOCO
            {
                if((x==3)&&(x+7==xbola))
                    bloco_colidido=20;
                else if((x==11)&&(x+7==xbola))
                    bloco_colidido=21;
                else if((x==19)&&(x+7==xbola))
                    bloco_colidido=22;
                else if((x==27)&&(x+7==xbola))
                    bloco_colidido=23;
                else if((x==35)&&(x+7==xbola))
                    bloco_colidido=24;

            }
        }
        else if((y == 14)||(y == 9))//A BOLA ESTÁ NA TERCEIRA LINHA DE BLOCOS: CASO SEJA 14 -> BATEU EM BAIXO, CASO SEJA 9 -> BATEU EM CIMA
        {
            switch(x)
            {
            case 3:
                bloco_colidido=13;
                break;
            case 11:
                bloco_colidido=14;
                break;
            case 19:
                bloco_colidido=15;
                break;
            case 27:
                bloco_colidido=16;
                break;
            case 35:
                bloco_colidido=17;
                break;
            case 43:
                bloco_colidido=18;
                break;
            }
        }
        else if((y>10)&&(y<14))//A BOLA ESTÁ ENTRE A TERCEIRA E A SEGUNDA LINHA
        {
            if((direcao==1)||(direcao==3))//A BOLA ESTÁ NA LATERAL DIREITA DE ALGUM BLOCO
            {
                if((x==11)&&(x==xbola))
                    bloco_colidido=13;
                else if((x==19)&&(x==xbola))
                    bloco_colidido=14;
                else if((x==27)&&(x==xbola))
                    bloco_colidido=15;
                else if((x==35)&&(x==xbola))
                    bloco_colidido=16;
                else if((x==43)&&(x==xbola))
                    bloco_colidido=17;

            }
            else if((direcao==0)||(direcao==2))//A BOLA ESTÁ NA LATERAL ESQUERDA DE ALGUM BLOCO
            {
                if((x==3)&&(x+7==xbola))
                    bloco_colidido=14;
                else if((x==11)&&(x+7==xbola))
                    bloco_colidido=15;
                else if((x==19)&&(x+7==xbola))
                    bloco_colidido=16;
                else if((x==27)&&(x+7==xbola))
                    bloco_colidido=17;
                else if((x==35)&&(x+7==xbola))
                    bloco_colidido=18;

            }
        }
        else if((y == 10)||(y == 5))//A BOLA ESTÁ NA SEGUNDA LINHA DE BLOCOS: CASO SEJA 10 -> BATEU EM BAIXO, CASO SEJA 5 -> BATEU EM CIMA
        {
            switch(x)
            {
            case 3:
                bloco_colidido=7;
                break;
            case 11:
                bloco_colidido=8;
                break;
            case 19:
                bloco_colidido=9;
                break;
            case 27:
                bloco_colidido=10;
                break;
            case 35:
                bloco_colidido=11;
                break;
            case 43:
                bloco_colidido=12;
                break;
            }
        }
        else if((y>6)&&(y<10))//A BOLA ESTÁ ENTRE A SEGUNDA E A PRIMEIRA LINHA
        {
            if((direcao==1)||(direcao==3))//A BOLA ESTÁ NA LATERAL DIREITA DE ALGUM BLOCO
            {
                if((x==11)&&(x==xbola))
                    bloco_colidido=7;
                else if((x==19)&&(x==xbola))
                    bloco_colidido=8;
                else if((x==27)&&(x==xbola))
                    bloco_colidido=9;
                else if((x==35)&&(x==xbola))
                    bloco_colidido=10;
                else if((x==43)&&(x==xbola))
                    bloco_colidido=11;

            }
            else if((direcao==0)||(direcao==2))//A BOLA ESTÁ NA LATERAL ESQUERDA DE ALGUM BLOCO
            {
                if((x==3)&&(x+7==xbola))
                    bloco_colidido=8;
                else if((x==11)&&(x+7==xbola))
                    bloco_colidido=9;
                else if((x==19)&&(x+7==xbola))
                    bloco_colidido=10;
                else if((x==27)&&(x+7==xbola))
                    bloco_colidido=11;
                else if((x==35)&&(x+7==xbola))
                    bloco_colidido=12;

            }
        }
        else if(y == 6)//A BOLA ESTÁ NA PRIMEIRA LINHA DE BLOCOS
        {
            switch(x)
            {
            case 3:
                bloco_colidido=1;
                break;
            case 11:
                bloco_colidido=2;
                break;
            case 19:
                bloco_colidido=3;
                break;
            case 27:
                bloco_colidido=4;
                break;
            case 35:
                bloco_colidido=5;
                break;
            case 43:
                bloco_colidido=6;
                break;
            }
        }
        else if((y>1)&&(y<6))//A BOLA ESTÁ ENTRE A PRIMEIRA LINHA E O TETO
        {
            if((direcao==1)||(direcao==3))//A BOLA ESTÁ NA LATERAL DIREITA DE ALGUM BLOCO DESCENDO OU SUBINDO
            {
                if((x==11)&&(x==xbola))
                    bloco_colidido=1;
                else if((x==19)&&(x==xbola))
                    bloco_colidido=2;
                else if((x==27)&&(x==xbola))
                    bloco_colidido=3;
                else if((x==35)&&(x==xbola))
                    bloco_colidido=4;
                else if((x==43)&&(x==xbola))
                    bloco_colidido=5;

            }
            else if((direcao==0)||(direcao==2))//A BOLA ESTÁ NA LATERAL ESQUERDA DE ALGUM BLOCO DESCENDO OU SUBINDO
            {
                if((x==3)&&(x+7==xbola))
                    bloco_colidido=2;
                else if((x==11)&&(x+7==xbola))
                    bloco_colidido=3;
                else if((x==19)&&(x+7==xbola))
                    bloco_colidido=4;
                else if((x==27)&&(x+7==xbola))
                    bloco_colidido=5;
                else if((x==35)&&(x+7==xbola))
                    bloco_colidido=6;

            }
        }
        else if((xbola==2)||(xbola==48))
        {
            if((y==7)||(y=11)||(y=15)||(y=19))
                bloco_colidido=49;
            else
            {

            }
        }
    }

    return bloco_colidido;
}


int montagem_bloco(int campo,int fase)
{
    /*
        LEGENDA:

        VARIÁVEL fase:

        case = 0 -> PRIMEIRA FASE;
        case = 1 -> SEGUNDA FASE;
        case = 2 -> TERCEIRA FASE;
        BREAK;

        VARIÁVEL campo:

        case = 0 -> CAMPO 51x50;
        case = 0 -> CAMPO

    */

    int i,l,cont;

    if(campo == 0)//CASO O TAMANHO DO CAMPO ESCOLHIDO FOR 51x50
    {
        if(fase == 0)//CASO A FASE SELECIONADA SEJA A PRIMEIRA FASE
        {
            for(cont = 2; cont<=15; cont+=4)//IMPRIMIR O TAMANHO DE 3 LINHAS DE BLOCOS
            {
                textcolor(cont+1);
                for(i=2; i<=50; i++)//IMPRIME A LINHA DE BLOCO
                {
                    if((i%8!=2)&&(i%8!=3))
                    {
                        gotoxy(i,cont);
                        printf("-");

                        if((i%8==1)||(i%8==6))
                        {
                            gotoxy(i,cont+1);
                            printf("%c",47);
                            gotoxy(i,cont+2);
                            printf("%c",92);
                        }
                        else if((i%8==7)||(i%8==4))
                        {
                            gotoxy(i,cont+1);
                            printf("%c",92);
                            gotoxy(i,cont+2);
                            printf("%c",47);
                        }
                        gotoxy(i,cont+3);
                        printf("-");
                    }
                    else if((i%8==2&&(i!=2)))
                    {
                        gotoxy(i,cont+1);
                        printf("|");
                        gotoxy(i,cont+2);
                        printf("|");

                        gotoxy(i,cont);
                        printf("%c",187);

                        gotoxy(i,cont+3);
                        printf("%c",188);
                    }
                    else if(i%8==3)
                    {
                        gotoxy(i,cont+1);
                        printf("|");
                        gotoxy(i,cont+2);
                        printf("|");

                        gotoxy(i,cont);
                        printf("%c",201);

                        gotoxy(i,cont+3);
                        printf("%c",200);
                    }
                }
            }
            textcolor(15);
        }
        return 24;
    }
    else
        return 0;
}
