#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <TIME.H>
#include "arquivo.h"
#include "Auxiliares.h"
#include "Blocos.h"
#include "Jogo.h"
#include "Menu.h"
#include "Movimentacao.h"
#include "Ranking.h"
#include "tela.h"

struct jogador
{
    char nome[12];
    char vidas;
    char nivel;
    int pontos;
    int velocidade;
};

struct jogador player;

int jogo()
{
#define DIREITA 77
#define ESQUERDA 75

    int parX,parY,x,y,cont,bx,by,VELOCIDADE,VELOCIDADE_INICIAL,DIR,LOOPING=0,tam_barra,vel_barra;
    int campo = 0,fase=0,vida_bloco[50],bloco_colidido,quant_bloco,pont=0,combo=1,blocos_destruidos=0,vida_jogador=4,abilidade_ativada[2],abilidade_tempo[3],modo;
    char tecla;
    system("cls");
    //efeito_piscartexto("TESTE 11",6,parX/2,parY/2,500);

    /*
        NA SELEÇÃO DO TAMANHO DO CAMPO TEM QUE RESPEITAR AS SEGUINTES REGRAS:

        1- A PAREDE DE CIMA E DE BAIXO NÃO PODEM ULTRAPASSAR O VALOR DE 84
        2- A PAREDE DO LADO DIREITO E DO LADO ESQUERDO NÃO PODEM ULTRAPASSAR O VALOR DE 79

        O TAMANHO DA BARRA DÓ PODE SER MÚLTIPLO DE "3"
    */

    modo = Modo();
    if(fase==0)
    {
        if((modo==1)||(modo==2))
        {
            VELOCIDADE=25;
            vel_barra=2;
        }
        else if(modo==3)
        {
            VELOCIDADE=20;
            vida_jogador=1;
            vel_barra=1;
        }
        else
        {
            VELOCIDADE=30;
            vel_barra=3;

        }
        if((modo==2)||(modo==3))
            tam_barra=6;
        else
            tam_barra=12;
        abilidade_ativada[0]=0;
        abilidade_ativada[1]=0;
        abilidade_tempo[2]=0;
    }
    if(campo==0)
    {
        parX=51;
        parY=50;
        do
        {
            srand(time(NULL));
            bx = rand()%parX-3;//FAZER COM QUE A BOLA COMEÇE EM UMA POSIÇÃO ALEATÓRIA
        }
        while(bx<4);
        do
        {
            srand(time(NULL));
            by = 25+(rand()%((parY-4)/2));//FAZER COM QUE A BOLA COMEÇE EM UMA POSIÇÃO ALEATÓRIA
        }
        while((by<25)&&(by>6));
    }

    VELOCIDADE_INICIAL = VELOCIDADE;
    configtela(parX+20,parY+4);
    ConstrucaoTela(parX,parY);


    player.nivel=modo+1;
    player.pontos=pont;
    player.vidas=vida_jogador;
    player.velocidade=VELOCIDADE;
    DadosJogadorAtual();
    while(1)
    {
        textcolor(15);
        gotoxy(parX/2-15,parY/2-1);
        printf("SEJA BEM-VINDO AO JOGO BREAKOUT");
        gotoxy(parX/2-18,parY/2);
        printf("PARA INICIAR O JOGO PRESSIONE A TECLA 'I'");
        hideCursor();
        tecla = getch();
        if(tecla == 'i'|| tecla == 'I')
        {
            break;
        }
        else
            continue;
    }
    ConstrucaoTela(parX,parY);
    status_incial(parX,parY,player.nome);
    if(modo==3)
        status_atualizar(parX,parY,1,0,vida_jogador,0);
    abilidades(parX,parY,0);
    if((modo==2)||(modo==3))
    {
        quant_bloco=24;
    }
    else
        quant_bloco = montagem_bloco(campo,fase);
    for(cont=1; cont<=quant_bloco; cont++) //PREENCHER A VIDA DE TODOS OS BLOCOS COM 3 DE VIDA
    {
        vida_bloco[cont]=3;
    }
    ContagemRegressiva((parX/2)-1,(parY/2)+5);
    x=3;
    y=parY;
    gotoxy(x,y);
    for(cont=0; cont<=tam_barra; cont++)
    {
        printf("%c",61);
    }
    gotoxy(bx,by);
    printf("@");
    DIR = 0;
    VELOCIDADE = VELOCIDADE_INICIAL;

    while(1)//EXECU?O DO JOGO
    {

        if(kbhit())
        {
            tecla = getch();
            fflush(stdin);
        }


        //LIMITACAO DA MOVIMENTA?O DA BOLA
        //SUBINDO PARA A DIREITA = 0
        //SUBINDO PARA A ESQUERDA = 1
        //DESCENDO PARA A DIREITA = 2
        //DESCENDO PARA A ESQUERDA = 3


        if(by == parY-1)//A BOLA BATEU NA BARRINHA DE MOVIMETANÇÃO || O JOGO ACABOU
        {
            if((x+tam_barra>=bx)&&(x<=bx))
            {
                cont = x+(tam_barra-((tam_barra*2)/3));
                if(x+(tam_barra-((tam_barra*2)/3))>=bx)//CASO A BOLA BATA NA PONTA ESQUERDA DA BARRA
                {
                    if(DIR == 2)//CASO A BOLA VENHA PARA A ESQUERDA ELA IRÁ REBATER PARA O MESMO LADO
                    {
                        DIR = 1;
                    }
                    else if(DIR == 3)//CASO A BOLA VENHA PARA A DIREITA ELA IRÁ REBATER PARA A DIREITA
                    {
                        DIR = 1;
                    }
                }
                else if((x+((tam_barra/3)+tam_barra))/2<bx)//CASO A BOLA BATA NA PONTA DIREITA DA BARRA
                {
                    if(DIR == 2)//CASO A BOLA VENHA PARA A ESQUERDA ELA IRÁ REBATER PARA A DIREITA
                    {
                        DIR = 0;
                    }
                    else if(DIR == 3)//CASO A BOLA VENHA PARA A DIREITA ELA IRÁ REBATER PARA O MESMO LADO
                    {
                        DIR = 0;
                    }
                }
                else if((x+((tam_barra/3)+tam_barra)/2>bx)&&(x+(tam_barra-((tam_barra*2)/3)<=bx)))//CASO A BOLA BATA NO MEIO DA BARRINHA
                {
                    if(DIR == 2)//CASO A BOLA VENHA PARA A ESQUERDA ELA IRÁ REBATER PARA A DIREITA
                    {
                        DIR = 0;
                    }
                    else if(DIR == 3)//CASO A BOLA VENHA PARA A DIREITA ELA IRÁ REBATER PARA A ESQUERDA
                    {
                        DIR = 1;
                    }
                }

            }
            else//O USUÁRIO PERDEU O JOGO
            {
                combo=1;
                --vida_jogador;
                status_atualizar(parX,parY,3,0,vida_jogador,combo);
                if(vida_jogador==0)
                {
                    player.nivel=modo+1;
                    player.pontos=pont;
                    player.vidas=vida_jogador;
                    player.velocidade=VELOCIDADE;
                    gotoxy((parX/2)-13,parY/2);
                    printf("SUA PONTUA%c%cO FINAL FOI: %i",128,199,pont);
                    gotoxy((parX/2)-20,(parY/2)+3);
                    system("pause");
                    DadosJogadoresPassados(0);
                    Menu();
                    break;
                }
                gotoxy(parX/2-3,parY/2-3);
                printf("FIM DE JOGO");
                gotoxy(parX/2-15,parY/2);
                printf("PRESSIONE A TECLA 'I' PARA REINICIAR");
                gotoxy(parX/2-10,parY/2+1);
                printf("OU A TECLA 'S' PARA SAIR");
                Sleep(2000);//DAR UM TEMPO PARA O USUÁRIO ESCOLHER A SUA OPÇÃO
                setbuf(stdin,NULL);// LIMPAR O BUFFER DO TECLADO
                while(1)
                {
                    tecla = getch();
                    if((tecla == 'i') || (tecla == 'I'))//CASO O USUÁRIO QUEIRA REINICIAR O JOGO
                    {
                        apagar_texto(bx,by,1);
                        apagar_texto(parX/2-3,parY/2-3,11);
                        apagar_texto(parX/2-15,parY/2,36);
                        apagar_texto(parX/2-10,parY/2+1,24);
                        status_atualizar(parX,parY,1,0,vida_jogador,combo);

                        do
                        {
                            srand(time(NULL));
                            bx = rand()%parX-3;//FAZER COM QUE A BOLA COMEÇE EM UMA POSIÇÃO ALEATÓRIA
                        }
                        while(bx<4);
                        do
                        {
                            srand(time(NULL));
                            by = 25+(rand()%((parY-4)/2));//FAZER COM QUE A BOLA COMEÇE EM UMA POSIÇÃO ALEATÓRIA
                        }
                        while((by<25)&&(by>6));
                        gotoxy(bx,by);
                        printf("@");
                        DIR = 0;
                        break;
                    }
                    else if((tecla == 's') || (tecla == 'S'))//CASO O USUÁRIO QUEIRA FINALIZAR O JOGO
                    {
                        apagar_texto(parX/2-3,parY/2-3,11);
                        apagar_texto(parX/2-15,parY/2,36);
                        apagar_texto(parX/2-10,parY/2+1,24);

                        player.nivel=modo+1;
                        player.pontos=pont;
                        player.vidas=vida_jogador;
                        player.velocidade=VELOCIDADE;
                        gotoxy((parX/2)-13,parY/2);
                        printf("SUA PONTUA%c%cO FINAL FOI: %i",128,199,pont);
                        gotoxy((parX/2)-20,(parY/2)+3);
                        system("pause");
                        DadosJogadoresPassados(0);
                        Menu();
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                if((tecla == 's') || (tecla == 'S'))//CASO O USUÁRIO QUEIRA FINALIZAR O JOGO
                {
                    break;
                }
            }
        }
        if(bx == parX)//A BOLA BATEU NA PAREDE LATERAL DIREITA
        {
            if(DIR == 0)
            {
                DIR = 1;
            }
            else if(DIR == 2)
            {
                DIR = 3;
            }
        }
        else if(bx == 2)//A BOLA BATEU NA PAREDE LATERAL ESQUERDA
        {
            if(DIR == 1)
            {
                DIR = 0;
            }
            else if(DIR == 3)
            {
                DIR = 2;
            }
        }
        else if(by == 2)//A BOLA BATEU NA PAREDE DE CIMA
        {
            if(DIR == 0)
            {
                DIR = 2;
            }
            else if(DIR == 1)
            {
                DIR = 3;
            }


            //TRATAMENTO DE EXCESSÕES
        }
        if(((bx == 2)&&(by==2)) || ((bx==parX-1)&&(by==2)))//CASO A BOLA BATA NO CANTO SUPERIOR DIREITO OU NO CANTO SUPERIOR ESQUERDO
        {
            if(DIR == 1)
            {
                DIR = 3;
            }
            if(DIR == 0)
            {
                DIR = 2;
            }
        }

        //MOVIMENTA?O DA BARRA
        x = movimentacao_barra(tecla,x,y,parX,tam_barra);

        if(LOOPING%vel_barra==0)//FAZER A BARRA TER O 4X DA VELOCIDADE DA BOLA
        {


            if((by<=18)&&(bx>=4))//SE A BOLA PASSOU Do VALOR Y=18 DA TELA
            {
                bloco_colidido = colisao_bloco(bx,by,campo,DIR);//RETORNA QUAL BLOCO A BOLA COLIDIU
                if((vida_bloco[bloco_colidido]==0)&&(vida_bloco[bloco_colidido+1]!=0))//CASO O BLOCO DA LINHA QUE A BOLA ENTROU ESTEJA APAGADO E O POSTERIOR ESTEJA COM VIDA
                {
                    bloco_colidido = colisao_bloco(bx+1,by,campo,DIR);//RETORNA QUAL BLOCO A BOLA COLIDIU
                }
                else if((vida_bloco[bloco_colidido]==0)&&(vida_bloco[bloco_colidido-1]!=0))//CASO O BLOCO DA LINHA QUE A BOLA ENTROU ESTEJA APAGADO E O ANTERIOR ESTAJA COM VIDA
                {
                    bloco_colidido = colisao_bloco(bx-1,by,campo,DIR);//RETORNA QUAL BLOCO A BOLA COLIDIU
                }
                if((bloco_colidido!=0)&&(vida_bloco[bloco_colidido]!=0))//A BOLA BATEU EM ALGUM BLOCO E ESSE BLOCO EXISTE
                {
                    aparencia_bloco(bloco_colidido,vida_bloco[bloco_colidido],campo);//MUDAR A APARÊNCIA DO BLOCO, OU APAGAR O BLOCO
                    DIR = redirecinar_bola(bx,by,DIR,x_do_bloco_colidido(bloco_colidido,campo),y_do_bloco_colidido(bloco_colidido,campo),vida_bloco,bloco_colidido,campo);//MUDAR A DIREÇÃO DA BOLA DE ACORDO COM O LOCAL QUE A BOLA BATEU
                    vida_bloco[bloco_colidido]--;//DIMINUI A VIDA DO BLOCO QUE A BOLA BATEU
                    pont += 10*combo;
                    if(vida_bloco[bloco_colidido]==0)//O BLOCO FOI DESTUÍDO
                    {
                        blocos_destruidos++;
                        if(blocos_destruidos%2==0)//A CADA 4 BLOCOS DESTRUÍDOS O COMBO AUMENTA
                        {
                            combo++;
                        }
                    }
                    status_atualizar(parX,parY,0,pont,0,combo);
                }
            }

            //MOVIMENTAÇÃO DA BOLA
            bx=x_da_bola(bx,DIR);
            by=y_da_bola(by,DIR);
            movimentacao_bola(bx,by,VELOCIDADE,DIR);

        }

        if(((tecla == 'p')||(tecla == 'P'))&&(tecla!=80))
        {
            status_atualizar(parX,parY,2,0,0,0);
            pausa(parX,parY);
        }

        if((tecla == 'q')||(tecla == 'Q')||(tecla == 'w')||(tecla == 'W')||(tecla == 'e')||(tecla == 'E'))
        {
            if((((tecla == 'q')||(tecla == 'Q'))&&(pont>=200))&&(abilidade_tempo[2]>500))
            {
                cont=0;
                do
                {
                    cont=abilidades(parX,parY,1)+1;
                }
                while(vida_bloco[cont]==0);
                vida_bloco[cont]=1;
                aparencia_bloco(cont,vida_bloco[cont],campo);//MUDAR A APARÊNCIA DO BLOCO, OU APAGAR O BLOCO
                vida_bloco[cont]--;
                abilidade_tempo[2]=0;
                pont=pont-100;
                status_atualizar(parX,parY,0,pont,0,0);
            }
            else if(((tecla == 'w')||(tecla == 'W'))&&(pont>=50)&&(abilidade_ativada[0]==0))
            {
                abilidade_ativada[0]=1;
                abilidade_tempo[0]=0;
                tam_barra+=abilidades(parX,parY,2);
                pont=pont-50;
                status_atualizar(parX,parY,0,pont,0,0);
            }
            else if((((tecla == 'e')||(tecla == 'E'))&&(pont>=20))&&(abilidade_ativada[1]==0))
            {
                abilidade_ativada[1]=1;
                abilidade_tempo[1]=0;
                VELOCIDADE +=abilidades(parX,parY,3);
                pont=pont-20;
                status_atualizar(parX,parY,0,pont,0,0);
            }
        }

        if((abilidade_ativada[0]==1)&&(abilidade_tempo[0]==200))
        {
            abilidade_ativada[0]=0;
            abilidades(parX,parY,5);
            tam_barra -=6;
            gotoxy(x+(tam_barra),y);
            printf("      ");
        }
        else if((abilidade_ativada[1]==1)&&(abilidade_tempo[1]==100))
        {
            abilidade_ativada[1]=0;
            abilidades(parX,parY,6);
            VELOCIDADE -= 20;
        }
        else if(abilidade_tempo[2]==500)
        {
            abilidades(parX,parY,4);
            blocos_destruidos++;
        }
        if((modo==1)||(modo==3))
        {

        }
        else
            tecla = '0';//MODO DE MOVIMENTA?O DA BARRA DIFERENTE

        if(blocos_destruidos==24)
        {
            pont*=vida_jogador;

            player.nivel=modo+1;
            player.pontos=pont;
            player.vidas=vida_jogador;
            player.velocidade=VELOCIDADE;
            gotoxy((parX/2)-13,parY/2);
            printf("SUA PONTUA%c%cO FINAL FOI: %i",128,199,pont);
            gotoxy((parX/2)-20,(parY/2)+3);
            system("pause");
            DadosJogadoresPassados(0);
            Menu();
            break;
        }

        if((LOOPING%500==0)&&(VELOCIDADE>=16)&&(modo==0))
        {
            VELOCIDADE--;
        }

        setbuf(stdin,NULL);// LIMPAR O BUFFER DO TECLADO
        Sleep(VELOCIDADE);
        abilidade_tempo[0]++;
        abilidade_tempo[1]++;
        abilidade_tempo[2]++;
        LOOPING++;
    }
    return 0;
}


