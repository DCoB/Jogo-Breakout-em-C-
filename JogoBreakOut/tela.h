#ifndef TELA_H_INCLUDED
#define TELA_H_INCLUDED
#endif // TELA_H_INCLUDED

void status_incial(int ParX,int ParY,char nome[12]);//MOSTRA A TELA INICIAL DE STATUS
void status_atualizar(int ParX,int ParY,int jogo,int pontos,int vida,int combo);//ATUALIZA A TELA DE STATUS
int ConstrucaoTela(int parX,int parY);//CONSTROI O CAMPO
int abilidades(int parX,int parY,int abilidade_ativada);//EXIBI A TELA DE ABILIDADES
int Modo();//TELA DE SELEÇÃO DE MODO DE JOGO
void formar_quadrado(int largura,int altura,int x,int y);//FORMAR UMA MOLDURA
void montar_fase(int fase);//MONTAR O CAMPO DR ACORDO COM A FASE
